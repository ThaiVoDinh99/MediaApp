#ifndef LAYER_H
#define LAYER_H

#include <QObject>
#include <QUrl>

namespace home 
{

class Layer : public QObject 
{
    Q_OBJECT
    Q_PROPERTY(QString layerId READ layerId WRITE setLayerId NOTIFY layerIdChanged)
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(bool visible READ visible WRITE setVisible NOTIFY visibleChanged)
public:
    Layer(const QString& layerId, const QUrl& source, QObject* parent = nullptr);
    ~Layer();

    QString layerId() const;
    void setLayerId(const QString &newLayerId);
    QUrl source() const;
    void setSource(const QUrl &newSource);

    bool visible() const;
    void setVisible(bool newVisible);

signals:
    void layerIdChanged();
    void sourceChanged();

    void visibleChanged();

private:
    QString m_layerId;
    QUrl m_source {""};
    bool m_visible;
};

}

#endif //LAYER_H
