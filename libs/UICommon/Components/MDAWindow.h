#ifndef MDAWINDOW_H
#define MDAWINDOW_H

#include <QObject>
#include <QQuickWindow>
#include <QtAppManLauncher/private/applicationmanagerwindow_p.h>

namespace uicommon::components
{

class MDAWindow : public QtAM::ApplicationManagerWindow
{
    Q_OBJECT
public:
    MDAWindow(QWindow* window = nullptr);
    virtual ~MDAWindow();


};

}

#endif //MDAWINDOW_H
