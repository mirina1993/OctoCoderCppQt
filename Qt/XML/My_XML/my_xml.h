#ifndef MY_XML_H
#define MY_XML_H
#include<QApplication>
#include<QBoxLayout>
#include<QFrame>//QLabel
#include<QObject>
#include<QLabel>
#include<QPushButton>
#include<QtXml/QDomDocument>
#include<QtXml/QDomElement>
#include<QFile>
#include<QTextStream>
#include<QIODevice>
#include<QString>
//namespace Ui {
//class Counter;
//}
QDomElement contact(QDomDocument& domDoc,
                    const QString& strName,
                    const QString& strPhone,
                    const QString& strEmail);
QDomElement makeElement(QDomDocument& domDoc,
                       const QString& strName,
                       const QString& strAttr,
                       const QString& strText);
#endif // MY_XML_H
