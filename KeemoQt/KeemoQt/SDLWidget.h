#ifndef SDLWIDGET_H
#define SDLWIDGET_H

#include <QOpenGLWidget>
#include <QWindow>

class SDLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit SDLWidget(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~SDLWidget();

};

#endif // SDLWIDGET_H
