#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "truncatedcone.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    TruncatedCone first;
    TruncatedCone second;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initialize_objects();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void display_objects();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
