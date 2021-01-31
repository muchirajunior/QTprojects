void Netwotk::allfarmers(QString url)
{
    QUrl qurl(url);
    manager=new QNetworkAccessManager(this);
    QNetworkRequest request(qurl);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(getallfarmers(QNetworkReply*)));
    manager->get(request);
}
void Netwotk::getallfarmers(QNetworkReply *reply)
{
    QByteArray bytearray=reply->readAll();
    QJsonDocument doc=QJsonDocument::fromJson(bytearray);
    QJsonObject object=doc.object();
    QJsonValue value=object.value("data");
    QJsonArray array=value.toArray();

    farmers.clear();
    for (int i=0; i<array.size();i++){
        farmers.append(array[i].toString());
    }

}
