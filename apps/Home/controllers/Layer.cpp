#include "Layer.h"

namespace home
{

Layer::Layer(const QString &layerId, const QUrl &source, QObject *parent)
    : m_layerId(layerId)
    , m_source(source)
    , QObject(parent)
{

}

Layer::~Layer()
{

}

QString Layer::layerId() const
{
    return m_layerId;
}

void Layer::setLayerId(const QString &newLayerId)
{
    if (m_layerId == newLayerId)
        return;
    m_layerId = newLayerId;
    emit layerIdChanged();
}

QUrl Layer::source() const
{
    return m_source;
}

void Layer::setSource(const QUrl &newSource)
{
    if (m_source == newSource)
        return;
    m_source = newSource;
    emit sourceChanged();
}

bool Layer::visible() const
{
    return m_visible;
}

void Layer::setVisible(bool newVisible)
{
    if (m_visible == newVisible)
        return;
    m_visible = newVisible;
    emit visibleChanged();
}

    
}
