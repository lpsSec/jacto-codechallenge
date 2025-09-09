#ifndef RECEIVER_H
#define RECEIVER_H

#include <QDBusAbstractAdaptor>
#include <QObject>

class Receiver: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.example.Jacto.Receber")
    Q_PROPERTY(QString topic READ getTopic WRITE setTopic NOTIFY topicChanged)
    Q_PROPERTY(QString content READ getContent WRITE setContent NOTIFY contentChanged)

public:
    QString getTopic() const { return _topic; }
    void setTopic(const QString& value) { _topic = value; emit topicChanged(); }

    QString getContent() const { return _content; }
    void setContent(const QString& value) { _content = value; emit contentChanged(); }

    Receiver(QObject *parent = nullptr) : QDBusAbstractAdaptor(parent) { }

private:
    QString _topic;
    QString _content;

signals:
    void topicChanged();
    void contentChanged();

public slots:
    void receiveData(const QString& topic, const QString& content)
    {
        setTopic( topic );
        setContent( content );
    }
};

#endif // RECEIVER_H
