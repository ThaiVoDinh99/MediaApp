#ifndef HEADERBARINTERFACE_H
#define HEADERBARINTERFACE_H

#include <QDBusAbstractInterface>

namespace uicommon::systems
{

class HeaderBarInterface : public QDBusAbstractInterface
{
    Q_OBJECT
public:
    virtual ~HeaderBarInterface();
    static HeaderBarInterface* initialize(const QString &service,
        const QString &path,
        const char* interface,
        const QDBusConnection &connection = QDBusConnection::sessionBus(), 
        QObject *parent = nullptr);
    static HeaderBarInterface& getInstance();

private:
    HeaderBarInterface(const QString &service, 
        const QString &path, 
        const char* interface,
        const QDBusConnection &connection = QDBusConnection::sessionBus(), 
        QObject *parent = nullptr);
};

}

#endif //HEADERBARINTERFACE_H
