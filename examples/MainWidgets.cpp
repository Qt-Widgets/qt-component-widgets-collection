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
}
