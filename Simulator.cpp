#include <iostream>
#include "Simulator.h"

Simulator::Simulator(ostream &output, Comuna &com, double delta, double st ,double endT) : comuna(com), out(output) {
    t=0;
    delta_t=delta;
    samplingTime=st;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(simulateSlot()));
    endTime=endT;
}

void Simulator::printStateDescription() const {
    string s="time,\t"+ Comuna::getStateDescription();
    out << s << endl;
}
void Simulator::printState(double t) const{
    string s = to_string(t) + ",\t";
    s += comuna.getState();
    out << s << endl;
}
void Simulator::startSimulation(){
    printStateDescription();
    t=0;
    printState(t);
    timer->start(1000);
    simulateSlot();
    //esta linea hay que cambiar, necesito hacer k se alargue los X segundos
}
void Simulator::simulateSlot(){
    while(t<endTime) {
        for (double nextStop=t+samplingTime; t < nextStop; t+= delta_t) {
            comuna.computeNextState(delta_t); // compute its next state based on current global state
            comuna.updateState();  // update its state
        }
        printState(t);
    }
}
