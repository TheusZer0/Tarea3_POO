#include <QtMath> // for M_PI and functions, see https://doc.qt.io/qt-5/qtmath.html
#include <string>
#include <iostream>
#include "Comuna.h"
#include "Pedestrian.h"

Pedestrian::Pedestrian(Comuna &com, double speed, double deltaAngle) : comuna(com){
    // falta inicializar variables, recordar que esto es un constructor
    // x_tPlusDelta,y_tPlusDelta

    myRand = QRandomGenerator::securelySeeded();
    this->deltaAngle=deltaAngle;
    this->speed = speed*(0.9+0.2*myRand.generateDouble());
    this-> x = myRand.generateDouble() * comuna.getWidth();
    this-> y = myRand.generateDouble() * comuna.getWidth();
    this->angle = myRand.generateDouble() * 2 * M_PI;

    //opcional, no estoy seguro, solo es para inicializar las variables
    this->x_tPlusDelta=x+speed*qCos(angle);
    this->y_tPlusDelta=y+speed*qCos(angle);
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

    if (x_tPlusDelta < 0){
        x_tPlusDelta -= x_tPlusDelta;
        angle = M_PI-angle;
    }
    if (y_tPlusDelta < 0){
        y_tPlusDelta -= y_tPlusDelta;
        angle = 2 * M_PI - angle;
    }
    if (x_tPlusDelta > comuna.getWidth()){
        x_tPlusDelta = 2 * comuna.getWidth() - x_tPlusDelta;
        angle = M_PI - angle;
    }
    if (y_tPlusDelta > comuna.getHeight()){
        y_tPlusDelta = 2 * comuna.getHeight() - y_tPlusDelta;
        angle = 2 * M_PI - angle;
    }
}

void Pedestrian::updateState(){
    x=x_tPlusDelta;
    y=y_tPlusDelta;
}
