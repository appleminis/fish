#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QVector3D>
#include <QTimer>
#include <banc.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Glwidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    QWidget *prt;
    explicit Glwidget(QWidget *parent = 0);
    ~Glwidget();

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void button1click();

    QTimer timer;
    float _t;

    banc *b;

signals:

public slots:
};

#endif // GLWIDGET_H
