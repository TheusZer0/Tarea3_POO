#ifndef COMUNA_H
#define COMUNA_H

#include "Pedestrian.h"
#include <QRect>
#include <string>
using namespace std;

class Comuna {
private:
    Pedestrian * pPerson;
    QRect territory; // Alternatively: double width, length;
    // but more methods would be needed.

public:
    Comuna(double width, double length);
    double getWidth() const;
    double getHeight() const;
    void setPerson(Pedestrian &person);
    void computeNextState (double delta_t);
    void updateState ();
    static string getStateDescription();
    string getState() const;
};

#endif // COMUNA_H

