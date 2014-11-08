#include"my_xml.h"
QDomElement contact(QDomDocument& domDoc,
                    const QString& strName,
                    const QString& strPhone,
                    const QString& strEmail){
    static int number=1;
    QDomElement domElement = makeElement(domDoc,"contact"," ",QString().setNum(number));
    domElement.appendChild(makeElement(domDoc,"name"," ", strName));
    domElement.appendChild(makeElement(domDoc,"phone"," ", strPhone));
    domElement.appendChild(makeElement(domDoc,"email"," ", strEmail));
    number++;
    return domElement;
}
QDomElement makeElement(QDomDocument& domDoc,
                       const QString& strName,
                       const QString& strAttr,
                       const QString& strText){
    QDomElement domElement=domDoc.createElement(strName);
    if(!strAttr.isEmpty()){
        QDomAttr domAttr=domDoc.createAttribute("number");
        domAttr.setValue(strAttr);
        domElement.setAttributeNode(domAttr);
    }
    if(!strText.isEmpty()){
        QDomText domText=domDoc.createTextNode(strText);
        domElement.appendChild(domText);
    }
    return domElement;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDomDocument dok("myXML");
    QDomElement domElement= dok.createElement("myXML_Book");
    dok.appendChild(domElement);
    QDomElement contact1=contact(dok,"Robby","8-921-36-59-137","robby99@gmail.com");
   QDomElement contact2=contact(dok,"Nina","8-911-99-59-007","nina@gmail.com");
   domElement.appendChild(contact1);
   domElement.appendChild(contact2);
   QFile file("myXML_Book.xml");
   if(file.open(QIODevice::WriteOnly)){
        QTextStream(&file)<<dok.toString();
        file.close();
    }
    return a.exec();
}
