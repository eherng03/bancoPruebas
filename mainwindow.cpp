#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <string>
#include <sstream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runButton_clicked()
{

    clock_t tStart = clock();
    algoritmoSencillo(ui->consolaText->toPlainText().toStdString());
    double tFin = (double) (clock() - tStart);
    std::ostringstream strs;
    strs << tFin;
    std::string str = strs.str();
    timesSencillo = timesSencillo + str + "\n";         //Para concatenarlo con el tiempo de ejecuciones anteriores
    QString tFinString = QString::fromStdString(timesSencillo);
    ui->timesText->setText(tFinString);
}


void MainWindow::on_pushButton_2_clicked()
{
    clock_t tStart = clock();
    algoritmoFoto();
    double tFin = (double) (clock() - tStart);
    std::ostringstream strs;
    strs << tFin;
    std::string str = strs.str();
    timesFoto = timesFoto + str + "\n";         //Para concatenarlo con el tiempo de ejecuciones anteriores
    QString tFinString = QString::fromStdString(timesFoto);
    ui->timesText->setText(tFinString);
}

/*
 *Metodo que tiene que ordenar las letras de cada palabra individualmente,
 * y luego el conjunto de todas las palabras, alfabeticamente
 */
void MainWindow::algoritmoSencillo(std::string palabras){


}


void MainWindow::algoritmoFoto(){


}

void MainWindow::on_selectImage_clicked()
{
    //abrir ventana de seleccionar imagen
}
