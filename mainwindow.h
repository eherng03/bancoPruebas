#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QImage>
#include <QFile>
#include <vector>
#include <fstream>
#include <iostream>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void algoritmoSencillo();
    void algoritmoFoto();
    std::ifstream ficheroEntrada;
    std::vector<std::string> listaPalabras;


private slots:
    void on_runButton_clicked();

    void on_selectImage_clicked();

    void on_selectFileButton_clicked();

    void on_runButton2_clicked();

private:
    Ui::MainWindow *ui;
    std::string timesSencillo;
    std::string timesFoto;
    QImage imagenAntes;
    QImage imagenDespues;
    QString text;
    bool hayImagenCargada;
    int contadorFicheros;
    int contadorImagenes;
    double tiemposPasadosSencillo;
    double tiemposPasadosComplejo;
    double mediaSencillo;
    double mediaComplejo;

};

#endif // MAINWINDOW_H
