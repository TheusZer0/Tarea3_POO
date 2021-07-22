#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include <string>
#include <QRandomGenerator>
using namespace std;
class Comuna;
class Pedestrian {
private:
    double x, y, speed, angle, deltaAngle;
    double x_tPlusDelta, y_tPlusDelta;
    Comuna &comuna;
    QRandomGenerator myRand; // see https://doc.qt.io/qt-5/qrandomgenerator.html

public:
    Pedestrian(Comuna &com, double speed, double deltaAngle);
    static string getStateDescription() {
        return "x, \ty";
    };
    string getState() const;
    void computeNextState(double delta_t);
    void updateState();

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);
};

#endif // PEDESTRIAN_H
