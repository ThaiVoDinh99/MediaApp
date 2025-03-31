#ifndef MUSICENGINE_H
#define MUSICENGINE_H

#include <AbstractEngine.h>

namespace music
{

class MusicEngine : public uicommon::cores::AbstractEngine
{
    Q_OBJECT
public:
    MusicEngine(QQmlEngine* engine, QObject* parent = nullptr);
    ~MusicEngine();

    void initialize() final;
    void finitialize() final;
};

}

#endif //MUSICENGINE_H
