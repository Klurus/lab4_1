// progressindicator.h
#ifndef PROGRESSINDICATOR_H
#define PROGRESSINDICATOR_H

#include <QWidget>
#include <QLineEdit>

class ProgressIndicator : public QWidget
{
    Q_OBJECT
public:
    explicit ProgressIndicator(QWidget *parent = nullptr);

    int progressValue() const;
    int maximumValue() const;
    int minimumValue() const;

public slots:
    void setProgressValue(int value);
    void setMaximumValue(int value);
    void setMinimumValue(int value);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_progressValue;
    int m_maximumValue;
    int m_minimumValue;

};

#endif // PROGRESSINDICATOR_H
