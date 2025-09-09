#ifndef ENVIARCOMANDO_H
#define ENVIARCOMANDO_H

#include <QDBusServiceWatcher>
#include <QObject>

#include <QtDBus/qdbusinterface.h>

class Sender: public QObject
{
    Q_OBJECT

public slots:
    void start(const QString &name);

public:
    QDBusInterface *iface = nullptr;
};

class EnviarComando : public QObject
{
    Q_OBJECT
public:
    explicit EnviarComando( QObject* parent = nullptr );
    Q_INVOKABLE void sendMessage( const QString& topic, const QString& content );

private:
    Sender _sender;
    QDBusServiceWatcher* _serviceWatcher;
};

#endif // ENVIARCOMANDO_H
