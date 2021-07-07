#include <QtMath> // for M_PI and functions, see https://doc.qt.io/qt-5/qtmath.html
#include <string>
#include "Comuna.h"
#include "Pedestrian.h"

Pedestrian::Pedestrian (Comuna &com, double speed, double deltaAngle) : comuna(com) /*....*/{
    myRand = QRandomGenerator::securelySeeded();
    this->speed = speed*(0.9+0.2*myRand.generateDouble());
// .....
}

string Pedestrian::getState() const {
    string s=to_string(x) + ",\t";
    s+= to_string(y);
    return s;
}
void Pedestrian::computeNextState(double delta_t) {
    double r=myRand.generateDouble();
    angle+=deltaAngle*(1-2*r);
    x_tPlusDelta=x+speed*qCos(angle)*delta_t;
    y_tPlusDelta=y+speed*qSin(angle)*delta_t;
//...
}
void Pedestrian::updateState(){
    x=x_tPlusDelta;
    y=y_tPlusDelta;
}
