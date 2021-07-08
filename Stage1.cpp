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

    double N, I, I_time, comunaWidth,comunaLength,speed, delta_t,deltaAngle;

    //Falta Lectura del archivo
    ifstream fin(argv[1]);

    cout << "File: " << argv[1] << endl;

    /* Lectura del archivo, errores con el flujo al parecer, da exponenciales de -28 XD
    fin >> N >> I >> I_time;
    cout << N << "," << I << "," << I_time << endl;
    fin >> comunaWidth >> comunaLength;
    fin >> speed >> delta_t >> deltaAngle;

    cout << N << "," << I << "," << I_time << endl;
    cout << comunaWidth <<"," << comunaLength << endl;
    cout << speed <<","<< delta_t <<"," << deltaAngle<< endl;
    */

    double samplingTime = 1.0;
    Comuna comuna(1000, 100);

    //
    cout << "comuna Width:" << comuna.getWidth()<< "\n" ;
    cout << "comuna Height:" << comuna.getHeight()<< "\n" ;

    Pedestrian person(comuna, 1.4, 0.4);
    comuna.setPerson(person);
    Simulator sim(cout, comuna, 0.2, samplingTime);
    sim.startSimulation();

    //return a.exec();
}
