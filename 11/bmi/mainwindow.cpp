#include "mainwindow.hh"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::calculate_bmi);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_weightLineEdit_textChanged(const QString &weight)
{
    weight_=weight;
}


void MainWindow::on_heightLineEdit_textChanged(const QString &height)
{
    height_=height;
}

void MainWindow::calculate_bmi()
{   bool ok;
    double weight = weight_.toDouble(&ok);
    double height = height_.toDouble(&ok);
    if (!ok) {
        qDebug() << "Invalid weight input!";
        return;
    }


    if (!ok || height == 0) {
        qDebug() << "Invalid height input or height is zero!";
        ui->resultLabel->setText("Cannot count");
        return;
    }

    bmi_= weight/(height*height/10000);
    ui->resultLabel->setText(QString::number(bmi_));

    if (bmi_ < 18.5)
        ui->infoTextBrowser->setText("Underweight");
    else if (bmi_ >= 18.5 && bmi_ <= 25)
        ui->infoTextBrowser->setText("Normal range");
    else
        ui->infoTextBrowser->setText("Overweight");

}




