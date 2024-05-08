// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "progressindicator.h"

class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void moveProgressBar();

private:
    ProgressIndicator *progressIndicator;
    QPushButton *moveButton;
};

#endif // MAINWINDOW_H
