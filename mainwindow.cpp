#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <string>
#include <string.h>
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
#include <QLabel>
#include <qlabel.h>

using namespace std;

struct MyLessThan {
    bool operator()(const QString &s1, const QString &s2) const {
        QString st1 = s1.left(s1.indexOf('_'));
        int it1 = s1.right(s1.size() - s1.indexOf('_') - 1).toInt();
        QString st2 = s2.left(s2.indexOf('_'));
        int it2 = s2.right(s2.size() - s2.indexOf('_') - 1).toInt();
        if (st1 < st2)
            return true;
        if (st1 > st2)
            return false;
        if (it1 < it2)
            return true;
        return false;
    }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    contadorFicheros = 0;
    contadorImagenes = 0;
    mediaComplejo = 0;
    mediaSencillo = 0;
    tiemposPasadosSencillo = 0;
    tiemposPasadosComplejo = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runButton_clicked()
{
    clock_t tStart = clock();

    algoritmoSencillo();

    double tFin = (double) (clock() - tStart)/CLOCKS_PER_SEC;
    tiemposPasadosSencillo = tiemposPasadosSencillo + tFin;
    mediaSencillo = tiemposPasadosSencillo / contadorFicheros;

    std::ostringstream strs;
    strs << tFin;
    std::string str = strs.str();
    timesSencillo = timesSencillo + str + "\n";         //Para concatenarlo con el tiempo de ejecuciones anteriores
    QString tFinString = QString::fromStdString(timesSencillo);
    ui->timesText->setText(tFinString);
    ui->labelMediaS->setText(QString::number(mediaSencillo));
}


void MainWindow::on_runButton2_clicked()
{
    QMessageBox msgBox;

    if(hayImagenCargada){

        clock_t tStart = clock();
        algoritmoFoto();
        double tFin = (double) (clock() - tStart)/CLOCKS_PER_SEC;
        tiemposPasadosComplejo = tiemposPasadosComplejo + tFin;
        mediaComplejo = tiemposPasadosComplejo / contadorImagenes;

        std::ostringstream strs;
        strs << tFin;
        std::string str = strs.str();
        timesFoto = timesFoto + str + "\n";         //Para concatenarlo con el tiempo de ejecuciones anteriores
        QString tFinString = QString::fromStdString(timesFoto);

        ui->timesText_2->setText(tFinString);
        ui->labelMediaC->setText(QString::number(mediaComplejo));

    }else{
        msgBox.setWindowTitle("Error");
        msgBox.setText("Debes seleccionar una imagen antes de ejecutar el algoritmo.");
        msgBox.exec();
    }

}

/*
 *Metodo que tiene que ordenar las letras de cada palabra individualmente,
 * y luego el conjunto de todas las palabras, alfabeticamente
 */
void MainWindow::algoritmoSencillo(){
    contadorFicheros++;

    QString text1 = "fichero";
    QString text2 = ".txt";
    QString nombreFichero = text1 + QString::number(contadorFicheros) + text2;

    QFile file_for_writing(nombreFichero);
    file_for_writing.open(QIODevice::WriteOnly | QIODevice::Truncate); //
    QTextStream text_stream_for_writing(&file_for_writing);

    QStringList vectorPalabras = text.split(" ");
    QStringList vectorLetras;
    MyLessThan le;

    for(int i=0;i<vectorPalabras.length();i++){
        vectorLetras = vectorPalabras[i].split("");
        qSort(vectorLetras.begin(), vectorLetras.end(), le);
        vectorPalabras[i]="";
        for(int j=0;j<vectorLetras.length();j++){
            vectorPalabras[i]=vectorPalabras[i]+vectorLetras[j];
        }
    }
    qSort(vectorPalabras.begin(), vectorPalabras.end(), le);
    foreach (const QString &str, vectorPalabras) {
        text_stream_for_writing << str;
        text_stream_for_writing << " ";
    }
    file_for_writing.close();

}


void MainWindow::algoritmoFoto(){

    contadorImagenes++;

    QImage fotoOriginal = imagenAntes;
    imagenDespues = fotoOriginal.copy();
    QSize sizeImage = imagenDespues.size();
    int width = sizeImage.width();
    int height = sizeImage.height();

    QRgb color;

    for (int f1 = 0; f1 < width; f1++) {
        for (int f2 = 0; f2 < height; f2++) {
            color = imagenDespues.pixel(f1, f2);
            int gray = (qRed(color) + qGreen(color) + qBlue(color))/3;
            imagenDespues.setPixel(f1, f2, qRgb(gray, gray, gray));
        }
    }
    int w = ui->labelImagenOriginal->width();
    int h = ui->labelImagenOriginal->height();
    ui->labelImagenOriginal->setPixmap(QPixmap::fromImage(imagenAntes).scaled(w, h, Qt::KeepAspectRatio));
    ui->labelImagenBW->setPixmap(QPixmap::fromImage(imagenDespues).scaled(w, h, Qt::KeepAspectRatio));

}

void MainWindow::on_selectImage_clicked()
{

    QString fileName = QFileDialog::getOpenFileName();
    imagenAntes.load(fileName);
    hayImagenCargada = true;

}

void MainWindow::on_selectFileButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName();
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }else{

        QTextStream in(&file);
        text = in.readAll();
        file.close();
    }
}

