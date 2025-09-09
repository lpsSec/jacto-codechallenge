#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "carregaarquivo.h"
#include "enviarcomando.h"
int
main( int argc, char* argv[] )
{
    QGuiApplication app( argc, argv );
    QQmlApplicationEngine engine;

    CarregaArquivo carregaArquivo;
    EnviarComando enviarComando;
    engine.rootContext()->setContextProperty("CarregarArquivo", &carregaArquivo);
    engine.rootContext()->setContextProperty("EnviarComando", &enviarComando);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit( -1 ); },
        Qt::QueuedConnection );

    engine.loadFromModule( "EnviarApp", "Main" );

    return app.exec();
}
