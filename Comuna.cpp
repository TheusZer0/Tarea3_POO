#include "Comuna.h"

Comuna::Comuna(double width, double length): territory(0,0,width,length){
    pPerson=NULL;
}

double Comuna::getWidth() const {
    return 0;
}

double Comuna::getHeight() const {
    return 0;
}

void Comuna::setPerson(Pedestrian & person){
   //
}

void Comuna::computeNextState (double delta_t) {
   //
}

void Comuna::updateState () {
   //
}

string Comuna::getStateDescription(){
    string a = "final";
    return a;//
}

string Comuna::getState() const{
    string a = "final";
    return a;//
}
