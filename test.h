#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "model.h"

class Test : public QObject {
    Q_OBJECT

    Q_PROPERTY(AnimalModel* model READ get_model)

public:
    explicit Test(QObject *parent = 0) : QObject(parent), m_model(new AnimalModel(this)) {}
    AnimalModel* get_model() {qDebug() << "Returning model"; return m_model;}
public slots:
    void initialize() {
        m_model->addAnimal(Animal("Wolf", "Medium"));
        m_model->addAnimal(Animal("Polar bearawr", "Large"));
        m_model->addAnimal(Animal("Quoll", "Small"));
        emit init_finished();
    }
signals:
    void init_finished();
private:
    AnimalModel* m_model;
};

#endif // TEST_H
