#include <QtGui/QApplication>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"
#include "model.h"
#include "test.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));


    qmlRegisterType<Test>("IarChep.MeeShop", 1, 0, "Test");
    qmlRegisterType<AnimalModel>("IarChep.MeeShop", 1, 0, "AnimalModel");
    qRegisterMetaType<AnimalModel*>();



    QmlApplicationViewer viewer;

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/model_test/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
Q_DECLARE_METATYPE(QList<Animal>)
