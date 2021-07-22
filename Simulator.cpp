#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
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
QChart * Simulator::startSimulation(){
    printStateDescription();
    t=0;
    printState(t);
    timer->start(1000);
    QLineSeries *series = new QLineSeries();
    QChart *chart = simulateSlot(series);
    return chart;
}

QChart * Simulator::simulateSlot(QLineSeries *series){
    while(t<endTime) {
        for (double nextStop=t+samplingTime; t < nextStop; t+= delta_t) {
            comuna.computeNextState(delta_t); // compute its next state based on current global state
            comuna.updateState();  // update its state
        }        
        series->append(comuna.getX(),comuna.getY());
        printState(t);
    }
    QChart *chart = new QChart();
    //chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Line Chart Example");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    return chart;
}
