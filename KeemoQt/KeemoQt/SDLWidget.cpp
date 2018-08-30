#include "SDLWidget.h"

SDLWidget::SDLWidget(QWidget* parent, Qt::WindowFlags f):
    QOpenGLWidget(parent, f)
{
    this->setMinimumWidth(160);
    this->setMaximumWidth(160);

    this->setMinimumHeight(144);
    this->setMaximumHeight(144);
}

SDLWidget::~SDLWidget(){
    QOpenGLWidget::~QOpenGLWidget();
}
