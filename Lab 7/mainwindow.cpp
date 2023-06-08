#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    first = TruncatedCone();
    second = TruncatedCone();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    this->initialize_objects();
}
void MainWindow :: on_pushButton_2_clicked()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();

    ui->label_5->setText(QString(""));
    ui->label_6->setText(QString(""));
    ui->label_7->setText(QString(""));
    ui->label_8->setText(QString(""));
    ui->label_16->setText(QString(""));
    ui->label_17->setText(QString(""));
    ui->label_18->setText(QString(""));
    ui->label_19->setText(QString(""));
}
void MainWindow::display_objects()
{
    ui->label_5->setText(QString("Результат"));
    ui->label_6->setText(QString("V1 ="));
    ui->label_7->setText(QString::number(first.volume()));
    ui->label_8->setText(QString("V2 ="));
    ui->label_16->setText(QString::number(second.volume()));
    ui->label_17->setText(QString("V1"));
    ui->label_18->setText(QString("V2"));
    ui->label_19->setText(QString(first.compare(second)));
}
void MainWindow::initialize_objects()
{
    double height_1, height_2;
    double low_r1, low_r2;
    double up_r1, up_r2;
    try{
        height_1 = stod(ui->lineEdit_1->text().toStdString());
        up_r1 = stod(ui->lineEdit_2->text().toStdString());
        low_r1 = stod(ui->lineEdit_3->text().toStdString());

        height_2 = stod(ui->lineEdit_4->text().toStdString());
        up_r2 = stod(ui->lineEdit_5->text().toStdString());
        low_r2 = stod(ui->lineEdit_6->text().toStdString());

        first.set_height(height_1);
        first.set_lowerRadius(low_r1);
        first.set_upperRadius(up_r1);

        check_height(first.get_height());
        check_radiuses(first.get_lowerRadius(), first.get_upperRadius());
        second.set_height(height_2);
        second.set_lowerRadius(low_r2);
        second.set_upperRadius(up_r2);
        check_height(second.get_height());
        check_radiuses(second.get_lowerRadius(), second.get_upperRadius());

        this->display_objects();
    }
//    catch(invalid_argument)
//    {
//        QMessageBox::warning(this, "Помилка", "Введіть коректні значення!");
//    }
//    catch(incorrect_radiuses)
//    {
//        QMessageBox::warning(this, "Помилка", "Радіуси введені некоректно.Пам'ятайте, що радіус нижньої основи не можу бути меншим за радіус верхньої основи");
//    }
//    catch(incorrect_height)
//    {
//        QMessageBox::warning(this, "Помилка", "Некоректна висота конуса.Пам'ятайте, що висота має бути більшою за 0");
//    }
    catch (const incorrect_radiuses& ex) {
        QMessageBox::warning(this, "Помилка", QString::fromUtf8(ex.what()));
    }
    catch (const incorrect_height& ex) {
        QMessageBox::warning(this, "Помилка", QString::fromUtf8(ex.what()));
    }
    catch (...) {
        QMessageBox::warning(this, "Помилка", "Введіть коректні значення!");
    }

}
