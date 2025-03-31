#include "HomeEngine.h"
#include "ApplicationManager.h"
#include "LayerManager.h"

namespace home {

HomeEngine::HomeEngine(QQmlEngine* engine, QObject* parent)
    : QObject(parent)
    , m_engine(engine)
{
    startTimer(200);
}   

HomeEngine::~HomeEngine() 
{
}

void HomeEngine::doInitialize()
{
    qmlRegisterSingletonInstance<ApplicationManager>("Home.Cores", 1, 0, "ApplicationManager", ApplicationManager::initialize());
    qmlRegisterSingletonInstance<LayerManager>("Home.Cores", 1, 0, "LayerManager", LayerManager::initialize());
}

void HomeEngine::doFinitialize()
{

}

void HomeEngine::showCentralScreen()
{
    QQmlComponent* centralScreen = new QQmlComponent(m_engine, QUrl("qrc:/screens/central/CentralScreen.qml"));
    if (centralScreen->isError()) {
        for (auto it : centralScreen->errors()) {
            qWarning() << it.toString();
        }
        return;
    }
    QObject* winObj = centralScreen->create();
    QQuickWindow* win = qobject_cast<QQuickWindow*>(winObj);
    win->show();
}

void HomeEngine::addLayers()
{
    LayerManager* layerMan = &LayerManager::getInstance();

    layerMan->addLayer("DesktopLayer", QUrl("qrc:/DesktopLayer.qml"));
    // layerMan->addLayer("PopupLayer", QUrl("qrc:/PopupLayer.qml"));
}

void HomeEngine::timerEvent(QTimerEvent* event)
{
    switch (m_state)
    {
    case HomeState::Idle:
    {
        setState(Startup);
        break;
    }
    case HomeState::Startup:
    {
        doInitialize();
        addLayers();
        showCentralScreen();
        setState(BootApps);
        break;
    }
    case HomeState::BootApps:
    {
        ApplicationManager::getInstance().start();
        setState(Running);
        break;
    }
    case HomeState::Running:
    {
        if (m_isTerminate) {
            setState(Terminated);
        }
        break;
    }
    case HomeState::Terminated:
    {
        qWarning() << "[Home] - Terminated";
        m_engine->exit(0);
        break;
    }
    default:
        break;
    }
}

void HomeEngine::setState(HomeState state) 
{
    if (m_state != state) {
        m_state = state;
    }
}

}

