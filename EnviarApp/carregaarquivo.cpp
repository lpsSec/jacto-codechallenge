#include "carregaarquivo.h"

#include <QUrl>

CarregaArquivo::CarregaArquivo( QObject* parent ) : QObject { parent } {}

QString CarregaArquivo::readFile(const QString &path)
{
    QFile file(QUrl(path).toLocalFile()); // .toLocalFile() will truncate file:///
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return QString();

    QTextStream in(&file);
    return in.readAll();
}
