#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_weightLineEdit_textChanged(const QString &weight);

    void on_heightLineEdit_textChanged(const QString &height);
    void calculate_bmi();

private:
    Ui::MainWindow *ui;

    QString weight_="<weight>";
    QString height_="<height>";
    double bmi_;

};
#endif // MAINWINDOW_HH
