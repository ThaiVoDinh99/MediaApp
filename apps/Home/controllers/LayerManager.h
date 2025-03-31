#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include <QObject>
#include <QAbstractListModel>
#include "Layer.h"

namespace home
{
class LayerManager : public QAbstractListModel
{
    Q_OBJECT
public:
    ~LayerManager();
    static LayerManager* initialize(QObject* parent = nullptr);
    static LayerManager& getInstance();

    enum LayerInfo {
        LayerID,
        LayerSource
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addLayer(const QString id, const QUrl& source);

protected:
    QVector<Layer*> m_layerList;

private:
    LayerManager(QObject* parent = nullptr);
};
}

#endif //LAYERMANAGER
