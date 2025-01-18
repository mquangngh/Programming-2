#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gradecalculator.hh"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBoxN->setMaximum(MAX_N_POINTS);
    ui->spinBoxG->setMaximum(MAX_G_POINTS);
    ui->spinBoxP->setMaximum(MAX_P_POINTS);

    connect(ui->calculatePushButton, &QPushButton::clicked, this, &MainWindow::on_calculatePushButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calculatePushButton_clicked()
{
    int N = ui->spinBoxN->value();
    int G = ui->spinBoxG->value();
    int P = ui->spinBoxP->value();
    int E = ui->spinBoxE->value();
    int W_Score = score_from_weekly_exercises(N,G);
    int P_Score = score_from_projects(P);
    int Total_Grade = calculate_total_grade(N,G,P,E);


    // Display the results in the text browser
    QString resultText = "W-Score: " + QString::number(W_Score) + "\n"
                         "P-Score: " + QString::number(P_Score) + "\n"
                         "Total grade: " + QString::number(Total_Grade);

    ui->textBrowser->setText(resultText);
}

