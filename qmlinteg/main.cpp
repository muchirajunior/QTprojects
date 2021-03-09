#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <network.h>
#include <QQmlContext>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    Network *net=new Network;
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("name",net);
    QStringList dataList;
       dataList.append("Item 1");
       dataList.append("Item 2");
       dataList.append("Item 3");
       dataList.append("Item 4");
       engine.rootContext()->setContextProperty("myModel",QVariant::fromValue(dataList));
       engine.rootContext()->setContextProperty("mydel",QVariant::fromValue(dataList));
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
