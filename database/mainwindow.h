#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dbmodel.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_add_clicked();   // Добавление данных из поля ввода в таблицу


private:
    Ui::MainWindow *ui;

    DBModel model;                      // Модель
};

#endif // MAINWINDOW_H
