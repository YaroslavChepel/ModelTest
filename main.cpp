#include <QtGui/QApplication>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"
#include "MeeShopApplicationModel.h"
#include "information_processor.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterType<MeeShop::MeeShopApplicationModel>("IarChep.MeeShop", 1, 0, "ApplicationModel");
    qmlRegisterType<MeeShop::information_processor>("IarChep.MeeShop", 1, 0, "Repository");
    qRegisterMetaType<MeeShop::MeeShopApplicationModel*>();


    QmlApplicationViewer viewer;

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
    viewer.setMainQmlFile(QLatin1String("qml/model_test/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
