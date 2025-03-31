#include "HeaderBarInterface.h"

namespace uicommon::systems
{

static HeaderBarInterface* g_instance = nullptr;

HeaderBarInterface::HeaderBarInterface(const QString &service,
                                       const QString &path,
                                       const char* interface,
                                       const QDBusConnection &connection,
                                       QObject *parent)
    : QDBusAbstractInterface(service, path, interface, connection, parent)
{

}

HeaderBarInterface::~HeaderBarInterface()
{
}

HeaderBarInterface *HeaderBarInterface::initialize(const QString &service, const QString &path, const char* interface, const QDBusConnection &connection, QObject *parent)
{
    if (g_instance == nullptr) {
        g_instance = new HeaderBarInterface(service, path, interface, connection, parent);
    }
    return g_instance;
}

HeaderBarInterface &HeaderBarInterface::getInstance()
{
    if (g_instance == nullptr) {
        throw "Need to initialize instance of HeaderBarInterface first";
    }
    return *g_instance;
}

}
