#include "MainWidgets.h"
#include "ui_MainWidgets.h"

#include <QLayout>

MainWidgets::MainWidgets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidgets)
{
    ui->setupUi(this);
}

MainWidgets::~MainWidgets()
{
    delete ui;
}

void MainWidgets::on_horizontalSlider_valueChanged(int value)
{
    ui->progressBar->setValue(value);
    ui->progressBar_2->setValue(value);
}

void MainWidgets::on_pushButton_clicked()
{
    ui->progressBar->setMaximum(0);
    ui->progressBar_2->setMaximum(0);
}
