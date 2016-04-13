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
    void setImagen(QImage foto);
    QImage getImagen();
    void setImagenDespues(QImage foto);
    QImage getImagenDespues();
    std::ifstream ficheroEntrada;
    std::vector<std::string> listaPalabras;


private slots:
    void on_runButton_clicked();

    void on_pushButton_2_clicked();

    void on_selectImage_clicked();

    void on_selectFileButton_clicked();

    void on_chargutton_clicked();

private:
    Ui::MainWindow *ui;
    std::string timesSencillo;
    std::string timesFoto;
    QImage imagenAntes;
    QImage imagenDespues;
    QFile file;

};

#endif // MAINWINDOW_H
