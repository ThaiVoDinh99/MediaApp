#ifndef ABSTRACTENGINE_H
#define ABSTRACTENGINE_H

#include <QObject>
#include <QQmlEngine>

namespace uicommon::cores
{

class AbstractEngine : public QObject
{
    Q_OBJECT
public:
    AbstractEngine(QQmlEngine* engine, QObject* parent = nullptr);
    ~AbstractEngine();

    virtual void initialize() = 0;
    virtual void finitialize() = 0;
protected:
    QQmlEngine* m_engine {nullptr};
};

}

#endif //ABSTRACTENGINE_H
