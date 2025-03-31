#include "AbstractEngine.h"

namespace uicommon::cores
{

AbstractEngine::AbstractEngine(QQmlEngine* engine, QObject *parent)
    : m_engine(engine)
    , QObject(parent)
{

}

AbstractEngine::~AbstractEngine()
{

}

}
