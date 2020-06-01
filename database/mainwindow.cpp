#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel( &model.data );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_clicked(){
    MyItem it;
    //    TODO: Проверка входных данных
    it.x = ui->lineEdit_field1->text();

    model.add( it );
}

// TODO: удаление выделенной или нескольких выделенных строк
// Не забудьте, что программа должна беречь данные пользователя
// Поэтому сделайте защиту от случайного удаления
// см. документацию по tableView->selectionModel()


// TODO: Изменение данных в выбранной строке

// TODO: Поиск

// TODO: Сортировка

// TODO: Сохранение

// TODO: Загрузка

// TODO: Информация о разработчике




