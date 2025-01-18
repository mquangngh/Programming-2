#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000); // 1000 milisecond, timer timeout after everysecond
    connect(ui->startButton,&QPushButton::clicked,this,&MainWindow::on_startButton_clicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::on_stopButton_clicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::on_resetButton_clicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::on_closeButton_clicked);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);
    ui->lcdNumberSec->setStyleSheet("background-color: orange");
    ui->lcdNumberMin->setStyleSheet("background-color: green");
    // Initialize seconds
    seconds_ = 0;

    // Display initial seconds
    ui->lcdNumberSec->display(seconds_ % 60);
    ui->lcdNumberMin->display(seconds_ / 60);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_startButton_clicked()
{
    timer->start(1000);

}


void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}


void MainWindow::on_resetButton_clicked()
{
    seconds_ = 0;
    ui->lcdNumberSec->display(seconds_%60);
    ui->lcdNumberMin->display(seconds_/60);
    timer->stop();

}


void MainWindow::on_closeButton_clicked()
{
    this->close();
}

void MainWindow::onTimeout()
{
    ++seconds_;
    ui->lcdNumberSec->display(seconds_%60);
    ui->lcdNumberMin->display(seconds_/60);

}

