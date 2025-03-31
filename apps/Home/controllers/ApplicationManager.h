#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <QObject>
#include <QVector>
#include <QtAppManManager/applicationmanager.h>
#include <QAbstractListModel>
#include "Application.h"

namespace home 
{

class ApplicationManager : public QAbstractListModel 
{
    Q_OBJECT
public:
    ~ApplicationManager();
    static ApplicationManager* initialize(QObject* parent = nullptr);
    static ApplicationManager& getInstance();

    enum ApplicationInfo {
        Id,
        Name,
        Icon,
        State
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void start();

private:
    QVector<Application*> m_appList;

private:
    explicit ApplicationManager(QObject* parent);
};

}

#endif //APPLICATIONMANAGER_H
