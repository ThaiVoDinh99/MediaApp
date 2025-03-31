#include "LayerManager.h"

namespace home
{

static LayerManager* g_instance = nullptr;

LayerManager::LayerManager(QObject *parent)
{

}

LayerManager::~LayerManager()
{

}

LayerManager *LayerManager::initialize(QObject *parent)
{
    if (g_instance == nullptr) {
        g_instance = new LayerManager();
    }
    return g_instance;
}

LayerManager &LayerManager::getInstance()
{
    if (g_instance == nullptr) {
        throw "Need to initialize LayerManager first";
    }
    return *g_instance;
}

int LayerManager::rowCount(const QModelIndex &parent) const
{
    return m_layerList.count();
}

QVariant LayerManager::data(const QModelIndex &index, int role) const
{
    Layer* layer = m_layerList[index.row()];
    if (layer == nullptr) {
        return QVariant{};
    }

    switch (static_cast<LayerInfo>(role))
    {
    case LayerInfo::LayerID:
        return QVariant(layer->layerId());
        break;
    case LayerInfo::LayerSource:
        return QVariant(layer->source());
        break;
    default:
        break;
    }
    return QVariant{};
}

QHash<int, QByteArray> LayerManager::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[LayerID] = "layerId";
    roles[LayerSource] = "layerSource";
    return roles;
}

void LayerManager::addLayer(const QString id, const QUrl &source)
{
    Layer* newLayer = new Layer(id, source);
    if (newLayer != nullptr)
    {
        m_layerList.push_back(newLayer);
    }
}

}
