#include "popup.h"
#include <QProgressBar>
#include <QSlider>

PopUp::PopUp(QWidget *parent) : QWidget(parent)
{
    setFixedSize(200, 80);
    // create a progressor bar
    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setGeometry(10, 10, 180, 30);

    // create a slider
    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(0);
    slider->setGeometry(10, 40, 180, 30);
    QObject::connect(slider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
}
