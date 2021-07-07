#include "Simulator.h"
Simulator::Simulator(ostream &output, Comuna &com, double delta, double st) : comuna(com), out(output) /*.....*/{
    t=0;
    delta_t=delta;
    samplingTime=st;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(simulateSlot()));
}

void Simulator::printStateDescription() const {
    string s= "a";  //....
    out << s << endl;
}
void Simulator::printState(double t) const{
    string s = to_string(t) + ",\t";
    //...
    out << s << endl;
}
void Simulator::startSimulation(){
    printStateDescription();
    t=0;
    printState(t);
    timer->start(/*.....*/);
}
void Simulator::simulateSlot(){
    double nextStop=t+samplingTime;
    while(t<nextStop) {
       comuna.computeNextState(delta_t); // compute its next state based on current global state
       comuna.updateState();  // update its state
       t+=delta_t;
    }
    printState(t);
}
