#include <QObject>
#include <QCoreApplication>
#include <QDebug>
#include "MusicEngine.h"

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    qWarning() << "[Music started]";
    QQmlEngine engine;
    music::MusicEngine music(engine);
    return app.exec();
}
