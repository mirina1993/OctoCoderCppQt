#ifndef MYSERVER_H
#define MYSERVER_H
#include<QWidget>
#include <QTcpServer>
#include <QDataStream>
#include <QTextEdit>
#include <QMessageBox>
#include <QBoxLayout>
#include <QLabel>
#include <QDataStream>
#include <QTcpSocket>
class QTcpServer;
class QTextEdit;
class QTcpSocket;
class MyServer: public QWidget{
    Q_OBJECT
private:
    QTcpServer* m_ptcpServer;
    QTextEdit *m_ptxt;
    qint16 m_nNextBlockSize;
    void sendToClient(QTcpSocket *pSocket,const QString &str);
public:
    MyServer(int nPort,QWidget *pwg=0);
public slots:
    virtual void slotNewConnection();
    void slotReadClient();
};
#endif // MYSERVER_H
