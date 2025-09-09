#include <QDBusConnection>
#include <QDBusError>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "receiver.h"

int
main( int argc, char* argv[] )
{
    QGuiApplication app( argc, argv );

    QQmlApplicationEngine engine;

    QObject obj;
    Receiver receiver(&obj);
    engine.rootContext()->setContextProperty("receiver", &receiver);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit( -1 ); },
        Qt::QueuedConnection );
    engine.loadFromModule( "ReceberApp", "Main" );

    // DBus
    receiver.setProperty("topic", "");
    receiver.setProperty("content", "");

    QDBusConnection::sessionBus().registerObject("/", &obj);

    if (!QDBusConnection::sessionBus().registerService("org.example.JactoExample")) {
        fprintf(stderr, "%s\n",
                 qPrintable(QDBusConnection::sessionBus().lastError().message()));
        exit(1);
    }

    return app.exec();
}
