#include "window.h"
#include "popup.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(100, 50);
    m_button = new QPushButton("Hello", this);
    m_button->setGeometry(10, 10, 80, 30);
    QFont font("Courier");
    m_button->setFont(font);
    m_button->setIcon(QIcon::fromTheme("face-smile"));
    //connect(m_button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    PopUp *popup = new PopUp();
    connect(m_button, SIGNAL(clicked()), popup, SLOT(show()));
}
