#include "imageviewer.h"
#include "ui_imageviewer.h"
#include <QImage>
#include <QPixmap>

ImageViewer::ImageViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageViewer)
{
    ui->setupUi(this);
    ui->labelImagenOriginal->setScaledContents(true);
    ui->labelImagenModificada->setScaledContents(true);
}

ImageViewer::~ImageViewer()
{
    delete ui;

}

void ImageViewer::setImages(QImage imagen1, QImage imagen2){
    ui->labelImagenOriginal->setPixmap(QPixmap::fromImage(imagen1));
    ui->labelImagenModificada->setPixmap(QPixmap::fromImage(imagen2));
}
