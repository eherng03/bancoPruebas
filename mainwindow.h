#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void algoritmoSencillo(std::string palabras);
    void algoritmoFoto();

private slots:
    void on_runButton_clicked();

    void on_pushButton_2_clicked();

    void on_selectImage_clicked();

private:
    Ui::MainWindow *ui;
    std::string timesSencillo;
    std::string timesFoto;

};

#endif // MAINWINDOW_H
