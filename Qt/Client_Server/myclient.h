#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QWidget>

namespace Ui {
class MyClient;
}

class MyClient : public QWidget
{
    Q_OBJECT

public:
    explicit MyClient(QWidget *parent = 0);
    ~MyClient();

private:
    Ui::MyClient *ui;
};

#endif // MYCLIENT_H
