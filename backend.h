#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QVector3D>
#include <vector>
#include <iostream>

using namespace std;


class BackEnd : public QObject
{
    int counter = 126;
    int original_num = counter;
    int index = 0;
    int last_marked =0;
    vector< vector< int>> map;
    Q_OBJECT
    Q_PROPERTY(QVector3D location READ getLocation WRITE setLocation NOTIFY notifyLocation)
    Q_PROPERTY(int spread READ getSpread WRITE setSpread NOTIFY notifySpread)



public:
    explicit BackEnd(QObject *parent = nullptr){
    }
    int spread = 2;

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


    QVector3D getLocation() {
        if(counter == original_num)
        {
            map.push_back({0,0,0});
            counter--;
            vector<int> cartesian = {map.at(0).at(0), map.at(0).at(1), lattice_points.at(0).at(2)};
            QVector3D coordinates = QVector3D(cartesian.at(0),cartesian.at(1), cartesian.at(2));
            return coordinates;
        }
        else
        {
            index++;

            vector< vector<int> > surface;
            for(int i =0; i < (int)lattice_points.size(); i++)
            {
                cout << "map\n";
                surface.push_back({lattice_points.at(i).at(0) + map.at(last_marked).at(0),
                                   lattice_points.at(i).at(1) + map.at(last_marked).at(1),
                                   lattice_points.at(i).at(2) + map.at(last_marked).at(2)});
            }
            for(int j = 0; j<surface.size(); j++)
            {
                if(std::find(map.begin(), map.end(), surface.at(j)) == map.end()) {
                    map.push_back(surface.at(j));
                }
            }
            last_marked++;
            cout << "here\n";
            cout << index << " - index" << map.size() << " - map" ;
            vector<int> cartesian = {map.at(index).at(0), map.at(index).at(1), map.at(index).at(2)};
            QVector3D coordinates = spread * QVector3D(cartesian.at(0),cartesian.at(1), cartesian.at(2));
            cout << "end\n\n";
            return coordinates;
        }

    }
    void setLocation(const QVector3D &var){}

    int getSpread()
    {
        return spread;
    }
    void setSpread(const int &shrink)
    {
        if(spread != shrink){
            spread = shrink;
            emit notifySpread();
        }
    }

signals:
    void notifyLocation();
    void notifySpread();

private:


    //vector< vector<int>> lattice_points = {{0, 1, 1},{1, 0, 1},{1, 1, 0},{0, -1, 1},{-1, 0, 1},{0, 1, -1},{1, 0, -1},{1, -1, 0}, {0, -1, -1}, {-1, 0, -1}, {-1, -1, 0}, {-1, 1, 0}};
};
#endif // BACKEND_H
