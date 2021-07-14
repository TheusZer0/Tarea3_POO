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

    double N, I, I_time, comunaWidth,comunaLength,speed, deltaAngle,endTime,delta_t;

    ifstream fin(argv[1]);

    cout << "File: " << argv[1] << endl;

    /*
     * Se arreglo el tema del archivo, debes darle el path absoluto para que funcione
     * */
    fin >> N >> I >> I_time;
    fin >> comunaWidth >> comunaLength;
    fin >> speed >> delta_t >> deltaAngle;

    cout << N << "," << I << "," << I_time << endl;
    cout << comunaWidth <<"," << comunaLength << endl;
    cout << speed <<","<< delta_t <<"," << deltaAngle<< endl;


    double samplingTime = 1.0;
    endTime = 360;
    Comuna comuna(100, 100);

    //
    cout << "comuna Width:" << comuna.getWidth()<< "\n" ;
    cout << "comuna Height:" << comuna.getHeight()<< "\n" ;

    Pedestrian person(comuna, speed, deltaAngle);
    comuna.setPerson(person);
    Simulator sim(cout, comuna, delta_t,samplingTime,endTime);
    sim.startSimulation();

    //return a.exec();
}
