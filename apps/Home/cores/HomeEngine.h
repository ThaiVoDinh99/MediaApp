#ifndef HOMEENGINE_H
#define HOMEENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>

namespace home {
class HomeEngine : public QObject 
{
    Q_OBJECT
public:
    HomeEngine(QQmlEngine* engine, QObject* parent = nullptr);
    ~HomeEngine();

    enum HomeState {
        Idle,
        Startup,
        Prepare,
        BootApps,
        Running,
        Terminated
    };

    void doInitialize();
    void doFinitialize();

    void showCentralScreen();
    void addLayers();

    void timerEvent(QTimerEvent* event) override;
    void setState(HomeState state);
private:
    QQmlEngine* m_engine {nullptr};
    HomeState m_state {Idle};
    bool m_isTerminate {false};
};

}

#endif //HOMEENGINE_H
