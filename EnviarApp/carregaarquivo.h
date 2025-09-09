#ifndef CARREGAARQUIVO_H
#define CARREGAARQUIVO_H

#include <QFile>
#include <QTextStream>

class CarregaArquivo : public QObject
{
    Q_OBJECT
public:
    explicit CarregaArquivo( QObject* parent = nullptr );

    Q_INVOKABLE QString readFile(const QString &path);
};

#endif // CARREGAARQUIVO_H
