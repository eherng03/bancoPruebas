#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QDialog>

namespace Ui {
class ImageViewer;
}

class ImageViewer : public QDialog
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = 0);
    ~ImageViewer();
    void setImages(QImage imagen1, QImage imagen2);

private:
    Ui::ImageViewer *ui;
};

#endif // IMAGEVIEWER_H
