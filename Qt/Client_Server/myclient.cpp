#include "myclient.h"
#include "ui_myclient.h"

MyClient::MyClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyClient)
{
    ui->setupUi(this);
}

MyClient::~MyClient()
{
    delete ui;
}
