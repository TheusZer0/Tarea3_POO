#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Comuna.h"
#include "Simulator.h"
#include "Pedestrian.h"
#include <iostream>
#include <fstream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>

using namespace std;

MainWindow::MainWindow(QChart * chart,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);
}

MainWindow::~MainWindow()
{
    delete ui;
}
