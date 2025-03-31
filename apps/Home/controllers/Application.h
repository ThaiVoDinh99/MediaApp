#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QtAppManManager/application.h>

namespace home
{

class Application : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QUrl icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(ApplicationState state READ state WRITE setState NOTIFY stateChanged)
public:
    explicit Application(const QString& id, QtAM::Application* app, QObject* parent = nullptr);
    ~Application();

    enum ApplicationState {
        NotRunning,
        StartingUp,
        Running,
        ShuttingDown,
    };
    Q_ENUM(ApplicationState)

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    QString id() const;
    void setId(const QString &newId);

    QUrl icon() const;
    void setIcon(const QUrl &newIcon);

    ApplicationState state() const;
    void setState(ApplicationState newState);

public slots:

    QString name() const;
    void setName(const QString &newName);

signals:
    void iconChanged();
    void nameChanged();

    void idChanged();

    void stateChanged();

private:
    QtAM::Application* m_application {nullptr};
    QString m_name {""};
    QString m_id {""};
    ApplicationState m_state {ApplicationState::NotRunning};
    QUrl m_icon;
};

}


#endif //APPLICATION_H
