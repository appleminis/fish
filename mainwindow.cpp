#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    glw = new Glwidget(this);
    this->gridLayout->addWidget(glw,0,0,1,1);

    glw->button1click();

    on_verticalSlider_valueChanged(50);
    on_verticalSlider_2_valueChanged(10);
    on_verticalSlider_3_valueChanged(50);
    on_horizontalSlider_valueChanged(30);
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
    glw->b->alig=value/100.0;
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    glw->b->sepa=value/500.0;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    glw->b->il=value/100.0;
}
