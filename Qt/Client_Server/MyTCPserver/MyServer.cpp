#include <QtGui>
#include "MyTCP.h"
MyServer::MyServer(int nPort,QWidget *pwg): QWidget(pwg),m_nNextBlockSize(0){
    m_ptcpServer= new QTcpServer(this);
    if(!m_ptcpServer->listen(QHostAddress::Any,nPort)){
        QMessageBox::critical(0,"Server error!","Unable to start the server:"+m_ptcpServer->errorString());
        m_ptcpServer->close();
        return;
    }
    connect(m_ptcpServer,SIGNAL(newConnection()),this, SLOT(slotNewConnection()));
    m_ptxt=new QTextEdit;
    m_ptxt->setReadOnly(true);
    QBoxLayout *pvbxLayout= new QVBoxLayout;
    pvbxLayout->addWidget(new QLabel("<H1>Server</H1>"));
    pvbxLayout->addWidget(m_ptxt);
    setLayout(pvbxLayout);
}
void MyServer:: slotReadClient(){
    QTcpSocket *pClientSocket=(QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_4_5);
    for(;;){
        if(!m_nNextBlockSize){
            if(pClientSocket->bytesAvailable()<sizeof(qint16)){
                break;
            }
            in>>m_nNextBlockSize;
        }
        if(pClientSocket->bytesAvailable()<m_nNextBlockSize){
            break;
        }
        QTime time;
        QString str;
        in>>time>>str;
        QString strMessage=time.toString()+" "+"Client has sent-"+str;
        m_ptxt->append(strMessage);
        m_nNextBlockSize=0;
        sendToClient(pClientSocket,"Server Response: Received\""+str+"\"");
    }
}
void MyServer::sendToClient(QTcpSocket *pSocket, const QString &str){
    QByteArray arrBlock;
    QDataStream out(&arrBlock,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out<<qint16(0)<<QTime::currentTime()<<str;
    out.device()->seek(0);
    out<<qint16(arrBlock.size()-sizeof(qint16));
    pSocket->write(arrBlock);
}
void MyServer::slotNewConnection(){
    QTcpSocket *pClientSocket=m_ptcpServer->nextPendingConnection();
    connect(pClientSocket,SIGNAL(disconnected()),pClientSocket,SLOT(deleteLater()));
    connect(pClientSocket,SIGNAL(readyRead()),this, SLOT(slotReadClient()));
    sendToClient(pClientSocket,"Server response: Connected!");
}

