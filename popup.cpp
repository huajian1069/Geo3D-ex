#include "popup.h"
#include <QProgressBar>
#include <QSlider>
#include <QLabel>

PopUp::PopUp(QWidget *parent) : QWidget(parent)
{
    setFixedSize(230, 90);
    // create a progressor bar
    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setGeometry(10, 10, 210, 30);

    // create a slider
    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(0);
    slider->setGeometry(10, 40, 210, 30);
    QObject::connect(slider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));

    //create a label
    QLabel *label = new QLabel(this);
    label->setText("Have fun play around with this GUI");
    label->setGeometry(10, 70, 210, 20);
    label->show();
}
