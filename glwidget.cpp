#include "glwidget.h"

Glwidget::Glwidget(QWidget *parent) : QOpenGLWidget(parent)
{
    prt=parent;
    b =new banc(750);

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.setInterval(1);
    timer.start();

    _t=0;
}

Glwidget::~Glwidget()
{

}

void Glwidget::initializeGL()
{
   glClearColor(0.05,0.05,0.05, 0.0f);
   //glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   //glDepthFunc(GL_LEQUAL);
}

void Glwidget::resizeGL(int width, int height)
{
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    gluPerspective(60,aspect,.1,100000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Glwidget::paintGL()
{
   //_t+=0.01;

   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   gluLookAt ( sin(_t)*30,0,cos(_t)*30,0,0,0,0,1,0);

   b->anime();
   b->aff();

   prt->setWindowTitle(QString("%1 %2").arg(b->t1).arg(b->t2));
   //*setWindowIconText();
}

void Glwidget::button1click()
{
    update ();
}

