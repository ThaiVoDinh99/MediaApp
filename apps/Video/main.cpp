#include <QObject>
#include <QCoreApplication>

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    qWarning() << "[Video started]";
    return app.exec();
}