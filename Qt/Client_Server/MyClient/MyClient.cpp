#include "MyClient.h"
//#include "ui_mainwindow.h"

MyClient::MyClient(const QString& strHost, int nPort, QWidget* pwgt /*=0*/) :
    QWidget(pwgt),
    m_nNextBlockSize(0)
{
    m_pTcpSocket= new QTcpSocket(this);
    m_pTcpSocket->connectToHost(strHost,nPort);
    connect(m_pTcpSocket,SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket,SIGNAL(readyRead()),SLOT(slotReadyRead()));
    connect(m_pTcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,
            SLOT(slotError(QAbstractSocket::SocketError)));
    m_pTcpInfo=new QTextEdit;
    m_pTcpInput=new QLineEdit;
    m_pTcpInfo->setReadOnly(true);
    QPushButton* pcmd= new QPushButton("&Send");
    connect(pcmd,SIGNAL(clicked()),SLOT(slotSendToServer()));
    connect(m_pTcpInput,SIGNAL(returnPressed()),this,SLOT(slotSendToServer()));
    //Setup
    QVBoxLayout* pvbxLayout= new QVBoxLayout;
    pvbxLayout->addWidget(new QLabel("<H1>Client</H1>"));
    pvbxLayout->addWidget(m_pTcpInfo);
    pvbxLayout->addWidget(m_pTcpInput);
    pvbxLayout->addWidget(pcmd);
    setLayout();
}
void MyClient::slotReadyRead(){
    QDataStream in(m_pTcpSocket);
    in.setVersion(QDataStream::Qt_4_5);
    for(;;){
        if(!m_nNextBlockSize){
            if(m_pTcpSocket->bytesAvailable()<sizeof(qint16))
                break;
            in>> m_nNextBlockSize;
        }
        if(m_pTcpSocket->bytesAvailable()<m_nNextBlockSize)
            break;
        QTime time;
        QString str;
        in>>time>>str;
        m_pTcpInfo->append(time.toString()+" "+str);
        m_nNextBlockSize=0;
    }
}
void MyClient::slotError(QAbstractSocket::SocketError err){
QString strError="Error"+(err==QAbstractSocket::HostNotFoundError ? "The host was not found.":
                          err==QAbstractSocket::RemoteHostClosedError ? "The remote host is closed.":
                          err=QAbstractSocket::ConnectionRefusedError ? "The connection was refused.":
                          QString(m_pTcpSocket->errorString()));
m_pTcpInfo->append(strError);
}
void MyClient::slotSendToServer(){
    QByteArray* arrBlock;
    QDataStream out(&arrBlock,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out<<qint16(0)<<QTime::currentTime()<<m_pTcpInput->text();
    out.device()->seek(0);
    out<<qint16(arrBlock->size()-sizeof(qint16));
    m_pTcpSocket->write(arrBlock);
    m_pTcpInput->setText("");
}
void MyClient::slotConnected(){
    m_pTcpInfo->append("Received the connected() signal");
}
