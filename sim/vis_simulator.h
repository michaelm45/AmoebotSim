#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>
#include <QString>
#include <QVector3D>
#include <vector>
#include <iostream>

using namespace std;

class Vis_Simulator : public QObject {
    Q_OBJECT

    Q_PROPERTY(QList<QVector3D> model READ getModel WRITE setModel NOTIFY notifyModel)

    vector< vector<int>> lattice_points = {{0, 1, 1},
                                           {1, 0, 1},
                                           {1, 1, 0},
                                           {0, -1, 1},
                                           {-1, 0, 1},
                                           {0, 1, -1},
                                           {1, 0, -1},
                                           {1, -1, 0},
                                           {0, -1, -1},
                                           {-1, 0, -1},
                                           {-1, -1, 0},
                                           {-1, 1, 0}
                                          };

    QList<QVector3D> getModel() {
        QList<QVector3D> vec;
        vec.push_back(QVector3D(0,0,0));
        vec.push_back(QVector3D(1,1,1));
        vec.push_back(QVector3D(2,2,2));
        return vec;

    }
    void setModel(const QList<QVector3D> &var){}
signals:
    void notifyModel();


};
#endif // SIMULATOR_H
