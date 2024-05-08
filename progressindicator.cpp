// progressindicator.cpp
#include "progressindicator.h"
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QProgressBar>



ProgressIndicator::ProgressIndicator(QWidget *parent)
    : QWidget(parent),
    m_progressValue(0),
    m_maximumValue(100),
    m_minimumValue(0)
{

}


int ProgressIndicator::progressValue() const
{
    return m_progressValue;
}

int ProgressIndicator::maximumValue() const
{
    return m_maximumValue;
}

int ProgressIndicator::minimumValue() const
{
    return m_minimumValue;
}

void ProgressIndicator::setProgressValue(int value)
{
    m_progressValue = qBound(m_minimumValue, value, m_maximumValue);
    update(); // Обновляем виджет при изменении значения
}

void ProgressIndicator::setMaximumValue(int value)
{
    m_maximumValue = value;
    setProgressValue(m_progressValue); // Обновляем значение, чтобы оно соответствовало новому максимальному значению
}

void ProgressIndicator::setMinimumValue(int value)
{
    m_minimumValue = value;
    setProgressValue(m_progressValue); // Обновляем значение, чтобы оно соответствовало новому минимальному значению
}

void ProgressIndicator::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Рисование индикатора выполнения
    int width = this->width();
    int height = this->height();
    int progressWidth = (m_progressValue - m_minimumValue) * width / (m_maximumValue - m_minimumValue);
    // Создание индикатора выполнения
    QProgressBar *progressBar = new QProgressBar(this);

    // Установка минимального и максимального значения
    progressBar->setMinimum(m_minimumValue);
    progressBar->setMaximum(m_maximumValue);

    // Установка текущего значения
    progressBar->setValue(m_progressValue);

    // Изменение цвета

    QLinearGradient gradient(0, 0, width, 0);
    gradient.setColorAt(0, Qt::blue);  // Start color (left side)
    gradient.setColorAt(1, Qt::green); // End color (right side)

    painter.fillRect(0, 0, progressWidth, height, gradient);
}






