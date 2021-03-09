#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class Network:public QObject
{
    Q_OBJECT
    QNetworkAccessManager *manager;
public:
    Network();


signals:

    void mydata();

public slots:
    void dataslot(QNetworkReply*);

private:



};

#endif // NETWORK_H
