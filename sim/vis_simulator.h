#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>
#include <QString>
#include <QList>
#include <QVector3D>
#include <vector>
#include <iostream>
#include "core/system.h"

using namespace std;

class Vis_Simulator : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<QVariant> model READ getModel WRITE setModel NOTIFY modelSignal)
    //pass the model as QVariant(QList<QList<QVariant(QList = {vec3d head, vec3d tail, color, etc.}) >>)

public:
    QList<QVariant> getModel() const {

        return vec;
    }
    void setModel(QList<QVariant> &var){}

private:
    QList<QVariant> vec{
        QVariant({QVariant(QVector3D(0,0,0)), QVariant(QVector3D(0,0,1))}),
        QVariant({QVariant(QVector3D(2,2,2)), QVariant(QVector3D(3,2,2))}),
        QVariant({QVariant(QVector3D(1,1,1)), QVariant(QVector3D(1,2,1))}),
        };


signals:
    void modelSignal();
};

#endif // SIMULATOR_H
