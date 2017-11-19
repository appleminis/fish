#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <glwidget.h>
#include <banc.h>


class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Glwidget *glw;
private slots:
    void on_pushButton_clicked();
    void on_verticalSlider_2_valueChanged(int value);
    void on_verticalSlider_3_valueChanged(int value);
    void on_verticalSlider_valueChanged(int value);
    void on_horizontalSlider_valueChanged(int value);
};

#endif // MAINWINDOW_H
