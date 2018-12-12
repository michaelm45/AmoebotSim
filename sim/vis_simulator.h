#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>
#include <QString>
#include <QList>
#include <QVector3D>
#include <vector>
#include <iostream>

using namespace std;

class Vis_Simulator : public QObject {
    Q_OBJECT
    Q_PROPERTY(QVariant model READ getModel WRITE setModel NOTIFY modelSignal)
    //pass the model as QVariant(QList<QList<QVariant(QList = {vec3d head, vec3d tail, color, etc.}) >>)

public:
    QVariant getModel() const {
        return QVariant(vec);
    }
    void setModel(QVariant &var){}

private:
    QList<QVariant> vec{QVariant(QVector3D(0,0,0)), QVariant(QVector3D(1,1,1)), QVariant(QVector3D(2,2,2))};

signals:
    void modelSignal();
};

#endif // SIMULATOR_H
