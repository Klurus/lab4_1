// mainwindow.cpp
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QSlider>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    progressIndicator = new ProgressIndicator(this);
    setWindowTitle("Лабораторная  работа №4");
    QSlider *slider = new QSlider(Qt::Horizontal);
    //QSlider *sliderSecond = new QSlider(Qt::Horizontal);
    slider->setRange(progressIndicator->minimumValue(), progressIndicator->maximumValue());
    //sliderSecond->setRange(progressIndicator->minimumValue(), progressIndicator->maximumValue());
    connect(slider, &QSlider::valueChanged, progressIndicator, &ProgressIndicator::setProgressValue);
    //moveButton = new QPushButton("Изменить значение");
    //connect(moveButton, &QPushButton::clicked, this, &MainWindow::moveProgressBar);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(progressIndicator);
    layout->addWidget(slider);
    //layout->addWidget(sliderSecond);
    //layout->addWidget(moveButton);


    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

}


void MainWindow::moveProgressBar()
{
    static int currentValue = progressIndicator->minimumValue();

    // Увеличиваем значение прогресс-бара на каждом нажатии
    progressIndicator->setProgressValue(currentValue);

    // Увеличиваем значение прогресса
    currentValue += 5;

    // Перемещаем значение в начало, если достигнуто максимальное значение
    if (currentValue > progressIndicator->maximumValue())
        currentValue = progressIndicator->minimumValue();
}

