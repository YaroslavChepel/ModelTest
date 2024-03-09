#include <QtGui/QApplication>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"
#include "app_model.h"
#include "information_processor.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterType<MeeShop::information_processor>("IarChep.MeeShop", 1, 0, "InfoManager");
    qRegisterMetaType<MeeShop::app_model*>();
    qmlRegisterType<MeeShop::app_model>("IarChep.MeeShop", 1, 0, "ApplicationModel");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/model_test/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
