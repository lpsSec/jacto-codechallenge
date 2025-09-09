#include "enviarcomando.h"

#include <QCoreApplication>
#include <QDBusReply>

#include <QtDBus/QDBusServiceWatcher>

EnviarComando::EnviarComando( QObject* parent ) : QObject { parent } {

    if (!QDBusConnection::sessionBus().isConnected()) {
        fprintf(stderr, "Cannot connect to the D-Bus session bus.\n"
                         "To start it, run:\n"
                         "\teval `dbus-launch --auto-syntax`\n");
    }

    _serviceWatcher = new QDBusServiceWatcher("org.example.JactoExample", QDBusConnection::sessionBus(),
                                        QDBusServiceWatcher::WatchForRegistration);

    QObject::connect(_serviceWatcher, &QDBusServiceWatcher::serviceRegistered, &_sender, &Sender::start );
}

void Sender::start(const QString &name)
{
    if (name != "org.example.JactoExample")
        return;

    iface = new QDBusInterface("org.example.JactoExample", "/", "org.example.Jacto.Receber",
                                QDBusConnection::sessionBus(), this);
    if (!iface->isValid()) {
        fprintf(stderr, "%s\n",
                 qPrintable(QDBusConnection::sessionBus().lastError().message()));
    }
}

void EnviarComando::sendMessage(const QString &topic, const QString &content)
{
    QDBusReply<void> reply = _sender.iface->call("receiveData", topic, content);
    if ( reply.isValid() )
        qInfo() << "DBus call 'receiveData' handled.";
    else
        qCritical() << "DBus call 'receiveData' error: " << reply.error().message();
}
