#include"counter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;
    QLabel lbl("0");
    QPushButton cmd("ADD");
    QBoxLayout* box= new QBoxLayout(QBoxLayout::LeftToRight);
    box->addWidget(&lbl,1);
    box->addWidget(&cmd,2);
    Counter counter;
    wgt.setWindowTitle("My counter to 5");
    wgt.setWindowFlags(Qt::Window|Qt::WindowTitleHint);
    wgt.setLayout(box);
    wgt.resize(500,100);
    wgt.show();
    QObject::connect(&cmd, SIGNAL(clicked()),&counter, SLOT(slotInc()));
    QObject::connect(&counter, SIGNAL(counterChanget(int)),&lbl, SLOT(setNum(int)));
    QObject::connect(&counter, SIGNAL(goodBye()),&a, SLOT(quit()));

    return a.exec();
}
