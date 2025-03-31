#ifndef VIDEOENGINE_H
#define VIDEOENGINE_H

#include <AbstractEngine.h>

namespace video
{

class VideoEngine : public uicommon::cores::AbstractEngine
{
    Q_OBJECT
public:
    VideoEngine(QQmlEngine* engine, QObject* parent = nullptr);
    ~VideoEngine();

    void initialize() final;
    void finitialize() final;
};

}

#endif //VIDEOENGINE_H
