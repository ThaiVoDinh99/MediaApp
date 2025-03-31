#ifndef SETTINGENGINE_H
#define SETTINGENGINE_H

#include <AbstractEngine.h>

namespace setting
{

class SettingEngine : public uicommon::cores::AbstractEngine
{
    Q_OBJECT
public:
    SettingEngine(QQmlEngine* engine, QObject* parent = nullptr);
    ~SettingEngine();

    void initialize() final;
    void finitialize() final;
};

}

#endif //SETTINGENGINE_H
