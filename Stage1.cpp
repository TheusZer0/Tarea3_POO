#include "Comuna.h"
#include "Simulator.h"
#include "Pedestrian.h"
#include <QCoreApplication>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc != 2){
        cout << "Usage: stage1 <configurationFile.txt>" << endl;
        exit(-1);
    }
    ifstream fin(argv[1]);
    double N, I, I_time, comunaWidth,comunaLength,speed, delta_t,deltaAngle;
    // this is not really needed, just to check data read.
    cout << "File: " << argv[1] << endl;

    /*
    fin >> N >> I >> I_time;
    fin >> comunaWidth >> comunaLength;
    fin >> speed >> delta_t >> deltaAngle;
    cout << N << "," << I << "," << I_time << endl;
    cout << comunaWidth <<"," << comunaLength << endl;
    cout << speed <<","<< delta_t <<"," << deltaAngle<< endl;
    */
    double samplingTime = 1.0;
    Comuna comuna(comunaWidth, comunaLength);
    cout << "comuna:" << comuna.getWidth()<< "\n" ;
    Pedestrian person(comuna, speed, deltaAngle);
    comuna.setPerson(person);
    Simulator sim(cout, comuna, delta_t, samplingTime);
    sim.startSimulation();
    return a.exec();
}
