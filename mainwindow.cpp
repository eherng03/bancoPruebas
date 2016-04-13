#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <string>
#include <sstream>
#include <qfiledialog.h>
#include <QImage>
#include <qimage.h>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;



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

    algoritmoSencillo();
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
void MainWindow::algoritmoSencillo(){
    //trabajar con listaPalabras

}


void MainWindow::algoritmoFoto(){

        QImage fotoOriginal = imagenAntes;
        QImage fotoBW = fotoOriginal.copy();
        QSize sizeImage = fotoBW.size();
        int width = sizeImage.width();
        int height = sizeImage.height();

        QRgb color;

        for (int f1 = 0; f1 < width; f1++) {
            for (int f2 = 0; f2 < height; f2++) {
                color = fotoBW.pixel(f1, f2);
                int gray = (qRed(color) + qGreen(color) + qBlue(color))/3;
                fotoBW.setPixel(f1, f2, qRgb(gray, gray, gray));
            }
        }

}

void MainWindow::on_selectImage_clicked()
{

    QString fileName = QFileDialog::getOpenFileName();
    QImage aux;
    aux.load(fileName);
    setImagen(aux);


    //abrir ventana de seleccionar imagen
}

void MainWindow::on_selectFileButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName();
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");

        for(int  i = 0; i < fields.size(); i++){
            QString cadena = fields.at(i);
            string normal = cadena.toStdString();
            listaPalabras.push_back(normal);
        }


    }

    file.close();
}

void MainWindow::on_chargutton_clicked()
{
    ifstream ficheroEntrada;
    string frase;

    ficheroEntrada.open("bbdd.txt");
    if(ficheroEntrada != NULL){
        //leer los numeros y cargarlos en el espacio de texto reservado para ello
    }

    ficheroEntrada.close();

}

QImage MainWindow::getImagen(){
    return imagenAntes;
}

void MainWindow::setImagen(QImage foto){
    imagenAntes = foto;
}
