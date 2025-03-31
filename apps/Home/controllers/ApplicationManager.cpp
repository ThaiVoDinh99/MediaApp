#include "ApplicationManager.h"

namespace home 
{

static ApplicationManager* g_instance = nullptr;

ApplicationManager::ApplicationManager(QObject* parent) 
    : QAbstractListModel(parent)
{
    QtAM::ApplicationManager* appsManager = QtAM::ApplicationManager::instance();
    if (appsManager != nullptr) {
        for (int i = 0; i < appsManager->count(); i++) {
            QtAM::Application* appAm = appsManager->application(i);
            Application* app = new Application(appAm->id(), appAm);
            m_appList.push_back(app);
        }
    }
}

ApplicationManager::~ApplicationManager()
{

}

ApplicationManager* ApplicationManager::initialize(QObject* parent)
{
    if (g_instance == nullptr) {
        g_instance = new ApplicationManager(parent);
    }
    return g_instance;
}

ApplicationManager& ApplicationManager::getInstance() 
{
    if (g_instance == nullptr) {
        throw "[Home] - Need to initialize instance of Home first";
    }
    return *g_instance;
}

int ApplicationManager::rowCount(const QModelIndex &parent) const
{
    return m_appList.count();
}

QVariant ApplicationManager::data(const QModelIndex &index, int role) const
{
    Application* app = m_appList[index.row()];

    if (app == nullptr) {
        return QVariant{};
    }

    switch (static_cast<ApplicationInfo>(role)) {
    case ApplicationInfo::Id:
        return QVariant(app->id());
        break;
    case ApplicationInfo::Name:
        return QVariant(app->name());
        break;
    case ApplicationInfo::Icon:
        return QVariant(app->icon());
        break;
    case ApplicationInfo::State:
        return QVariant(app->state());
        break;
    default:
        break;
    }

    return QVariant{};
}

QHash<int, QByteArray> ApplicationManager::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ApplicationInfo::Id] = "Id";
    roles[ApplicationInfo::Name] = "Name";
    roles[ApplicationInfo::Icon] = "Icon";
    roles[ApplicationInfo::State] = "State";
    return roles;
}

void ApplicationManager::start() 
{
    for (int i = 0; i < m_appList.count(); i++) {
        Application* app = m_appList[i];
        if (app != nullptr) {
            app->start();
        }
    }
}

}
