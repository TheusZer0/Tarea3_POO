#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Comuna.h"
#include <ostream>
#include <QTimer>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
using namespace QtCharts;

class Simulator: public QObject { // By inheriting from QObject,
    //our class can use signal and slot mechanism Qt provides.
    Q_OBJECT
private:
    Comuna &comuna;
    ostream &out;
    double t;
    double delta_t, samplingTime, endTime;
public:
    Simulator (ostream &output, Comuna &comuna, double delta_t, double samplingTime,double endTime);
    void printStateDescription() const;
    void printState(double t) const;
    QChart * startSimulation();
    QTimer * timer;  // see https://doc.qt.io/qt-5.12/qtimer.html
public slots:
    QChart * simulateSlot(QLineSeries *series);
};

#endif // SIMULATOR_H
