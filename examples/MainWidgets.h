#ifndef MAINWIDGETS_H
#define MAINWIDGETS_H

#include <QWidget>

namespace Ui {
class MainWidgets;
}

class MainWidgets : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidgets(QWidget *parent = nullptr);
    ~MainWidgets();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::MainWidgets *ui;
};

#endif // MAINWIDGETS_H
