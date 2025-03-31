#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QObject>

namespace uicommon::cores
{

class WindowManager : public QObject 
{
    Q_OBJECT
public:
    ~WindowManager();
    static WindowManager* initialize(QObject* parent = nullptr);
    static WindowManager& getInstance();

private:
    WindowManager(QObject* parent = nullptr);
};

}

#endif //WINDOWMANAGER_H