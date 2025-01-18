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
    void on_filelineEdit_editingFinished();

    void on_keylineEdit_editingFinished();

    void on_closePushButton_clicked();

    void on_findPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString file_;
    QString key_;
};
#endif // MAINWINDOW_HH
