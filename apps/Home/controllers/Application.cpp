#include "Application.h"

namespace home {

Application::Application(const QString &id, QtAM::Application *app, QObject *parent)
    : m_id(id)
    , m_application(app)
    , QObject(parent)
{
    if (m_application != nullptr) {
        m_icon = m_application->icon();
        m_name = m_application->name();
    }
}

Application::~Application()
{

}

void Application::start()
{
    if (m_state == NotRunning) {
        m_application->start();
    }
}

void Application::stop()
{
    if (m_state == Running) {
        m_application->stop();
    }
}

QString Application::name() const
{
    return m_name;
}

void Application::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

QString Application::id() const
{
    return m_id;
}

void Application::setId(const QString &newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

QUrl Application::icon() const
{
    return m_icon;
}

void Application::setIcon(const QUrl &newIcon)
{
    if (m_icon == newIcon)
        return;
    m_icon = newIcon;
    emit iconChanged();
}

Application::ApplicationState Application::state() const
{
    return m_state;
}

void Application::setState(ApplicationState newState)
{
    if (m_state == newState)
        return;
    m_state = newState;
    emit stateChanged();
}

}
