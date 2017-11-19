#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    glw = new Glwidget(this);
    this->gridLayout->addWidget(glw,0,0,1,1);

    glw->button1click();

    verticalSlider_3->setMaximum(1000);

    verticalSlider->setValue(20);   //separate
    verticalSlider_2->setValue(40); //cohesion
    verticalSlider_3->setValue(20);  //velocity cohesion
    horizontalSlider->setValue(50);


}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    glw->button1click();
}

void MainWindow::on_verticalSlider_2_valueChanged(int value)
{
    glw->b->cohe=value/100.0;
}

void MainWindow::on_verticalSlider_3_valueChanged(int value)
{
    glw->b->alig=value/1000.0;
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    glw->b->sepa=value/100.0;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    glw->b->il=value/100.0;
}
