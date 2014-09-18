#ifndef COUNTER_H
#define COUNTER_H
#include<QApplication>
#include <QApplication>
#include <QWidget>
#include<QObject>
#include<QLabel>
#include<QPushButton>
//namespace Ui {
//class Counter;
//}

class Counter: public QObject{
  Q_OBJECT
private:
    int m_nValue;
public:
    Counter();
public slots:
    void slotInc();
signals:
    void goodBye();
    void counterChanget(int);
};
#endif // COUNTER_H
