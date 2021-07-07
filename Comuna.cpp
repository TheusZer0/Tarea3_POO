#include "Comuna.h"

Comuna::Comuna(double width, double length): territory(0,0,width,length){
    //constructor
    pPerson=NULL;
}

double Comuna::getWidth() const {
    double width = territory.width();
    return width;
}

double Comuna::getHeight() const {
    double Height = territory.height();
    return Height;
}

void Comuna::setPerson(Pedestrian &person) {
    Comuna::pPerson = &person;
}

void Comuna::computeNextState (double delta_t) {
   pPerson->computeNextState(delta_t);
}

void Comuna::updateState () {
   pPerson->updateState();
}

string Comuna::getStateDescription(){
    string x = "x ";
    string y = " y ";
    string a = x+","+y;
    return a;
}

string Comuna::getState() const{
    string a = pPerson->getState();
    return a;
}
