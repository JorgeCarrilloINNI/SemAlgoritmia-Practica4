#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <list>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->agregarInicio, &QPushButton::clicked, this, &MainWindow::crearNeuronaInicio);
    connect(ui->agregarFinal, &QPushButton::clicked, this, &MainWindow::crearNeuronaFinal);
    connect(ui->mostrar, &QPushButton::clicked, this, &MainWindow::mostrar);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::crearNeuronaInicio(){
    QString idValue = ui->id->toPlainText();
    QString voltajeValue = ui->voltaje->toPlainText();
    QString posXValue = ui->posicionx->toPlainText();
    QString posYValue = ui->posiciony->toPlainText();
    int redValue = ui->red->value();
    int greenValue = ui->green->value();
    int blueValue = ui->blue->value();

    int id = idValue.toInt();
    float voltaje = voltajeValue.toFloat();
    int posX = posXValue.toInt();
    int posY = posYValue.toInt();

    Neurona nuevaNeurona(id, voltaje, posX, posY, redValue, greenValue, blueValue);
    listaNeuronas.agregar_inicio(nuevaNeurona);

    ui->id->clear();
    ui->voltaje->clear();
    ui->posicionx->clear();
    ui->posiciony->clear();
    ui->red->setValue(0);
    ui->green->setValue(0);
    ui->blue->setValue(0);
}


void MainWindow::crearNeuronaFinal(){
    QString idValue = ui->id->toPlainText();
    QString voltajeValue = ui->voltaje->toPlainText();
    QString posXValue = ui->posicionx->toPlainText();
    QString posYValue = ui->posiciony->toPlainText();
    int redValue = ui->red->value();
    int greenValue = ui->green->value();
    int blueValue = ui->blue->value();

    int id = idValue.toInt();
    float voltaje = voltajeValue.toFloat();
    int posX = posXValue.toInt();
    int posY = posYValue.toInt();

    Neurona nuevaNeurona(id, voltaje, posX, posY, redValue, greenValue, blueValue);
    listaNeuronas.agregar_final(nuevaNeurona);

    ui->id->clear();
    ui->voltaje->clear();
    ui->posicionx->clear();
    ui->posiciony->clear();
    ui->red->setValue(0);
    ui->green->setValue(0);
    ui->blue->setValue(0);
}

void MainWindow::mostrar(){
    list<Neurona>& lista = listaNeuronas.listaNeurona();
    ui->listaNeuronas->clear();

    for(Neurona &neurona : lista) {
        QString info = "Neurona: " + QString::number(neurona.getId()) + "\n"+
        "Voltaje: " + QString::number(neurona.getVoltaje()) + "\n"+
        "Posición X: " + QString::number(neurona.getPosX()) + "\n"+
        "Posición Y: " + QString::number(neurona.getPosY()) + "\n"+
        "Red: " + QString::number(neurona.getRed()) + "\n"+
        "Green: " + QString::number(neurona.getGreen()) + "\n"+
        "Blue: " + QString::number(neurona.getBlue()) + "\n"+
        "-----------------\n";

        ui->listaNeuronas->insertPlainText(info);
    }
}
