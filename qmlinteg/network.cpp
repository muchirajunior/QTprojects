#include "network.h"

Network::Network()
{
    mydata();
}



void Network::mydata()
{
    //connecting to a localhost
    QUrl url("127.0.0.1:5000/");
    manager=new QNetworkAccessManager(this);
    QNetworkRequest request(url);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dataslot(QNetworkReply*)));
    manager->get(request);
}
void Network::dataslot(QNetworkReply *reply)
{

    QByteArray array=reply->readAll();
    QString data=QString(array);
    qDebug()<<data;
}
