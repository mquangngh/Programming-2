#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <string>
#include <fstream>
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->closePushButton,&QPushButton::clicked,this,&MainWindow::on_closePushButton_clicked);
    connect(ui->findPushButton,&QPushButton::clicked,this,&MainWindow::on_findPushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_filelineEdit_editingFinished()
{
    file_ = ui->fileLineEdit->text();
}


void MainWindow::on_keylineEdit_editingFinished()
{
    key_ = ui->keyLineEdit->text();
}


void MainWindow::on_closePushButton_clicked()
{
    this->close();
}


void MainWindow::on_findPushButton_clicked()
{

    QString filePath = file_;
    QString searchWord = key_;

    std::ifstream input_file(filePath.toStdString());


    if (!input_file) {


      ui->textBrowser->setText("File not found");
      return;
    }

    // Read file content into a string
    std::string fileContent;
    std::getline(input_file, fileContent);



    size_t foundIndex;
    if (ui->matchCheckBox->isChecked()) {
      foundIndex = fileContent.find(searchWord.toStdString());
    } else {
      // Convert search word to lowercase for case-insensitive search
      std::string lowerSearchWord = searchWord.toLower().toStdString();
      foundIndex = fileContent.find(lowerSearchWord);
    }

    if (searchWord.isEmpty()) {
      ui->textBrowser->setText("File found");
    } else if (foundIndex != std::string::npos) {
      ui->textBrowser->setText("Word found");
    } else {
      ui->textBrowser->setText("Word not found");
    }
}
