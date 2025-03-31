#include <QtAppManCommon/global.h>
#include <QtAppManCommon/logging.h>
#include <QtAppManMain/main.h>
#include <QtAppManMain/configuration.h>
#include <QtAppManPackage/packageutilities.h>
#include <QtAppManManager/sudo.h>
#include "HomeEngine.h"
#include <QStringList>

QT_USE_NAMESPACE_AM

using namespace Qt::StringLiterals;

int main(int argc, char** argv) {

    QCoreApplication::setApplicationName("HomeApp");
    QCoreApplication::setApplicationVersion("1.0");

    Logging::initialize(argc, argv);
    Sudo::forkServer(Sudo::DropPrivilegesPermanently);

    try {
        Main main(argc, argv);
        Configuration cfg;

        cfg.parseWithArguments(QCoreApplication::arguments());

        QStringList list = cfg.builtinAppsManifestDirs();

        for (auto it : list) {
            qWarning() << it << "\n";
        }

        main.setup(&cfg);
        main.loadQml(cfg.loadDummyData());

        home::HomeEngine homeEngine(main.qmlEngine());
        main.showWindow(cfg.fullscreen() && !cfg.noFullscreen());

        return MainBase::exec();
    } catch (const std::exception &error) {
        qCritical(LogSystem) << "ERROR: " << error.what();
        return 2;
    }
}
