#ifndef MyClient_H
#define MyClient_H

#include <QMainWindow>
#include<QWidget>
#include <QTcpSocket>
class QTextEdit;
class QLineEdit;
#include<QWidget>
#include <QTcpServer>
#include <QDataStream>
#include <QTextEdit>
#include <QMessageBox>
#include <QBoxLayout>
#include<QByteArray>
#include <QLabel>
#include<QLine>
#include<QPushButton>
#include<QVBoxLayout>
#include <QDataStream>
#include <QTcpSocket>
#include<QTime>
#include<QString>
class QTextEdit;
class QLineEdit;
class MyClient : public QWidget
{
    Q_OBJECT
private:
    QTcpSocket* m_pTcpSocket;
    QTextEdit* m_pTcpInfo;
    QLineEdit* m_pTcpInput;
    qint16 m_nNextBlockSize;
public:
    MyClient(const QString& strHost, int nPort, QWidget* pwgt=0);

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotConnected();
};

#endif // MyClient_H
