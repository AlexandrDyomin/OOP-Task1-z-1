#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::createModelView(int rows){
    // Создание модели данных
    pModel = new QStandardItemModel(rows, 6, this);
    pModel->setHorizontalHeaderLabels(QStringList() << "Фамилия"
                                                    << "Имя"
                                                    << "Отчество"
                                                    << "Дата рождения"
                                                    << "Телефон"
                                                    << "Email");
    rowCount = pModel->rowCount();
    columnCount = pModel->columnCount();

    // Добавление объекта QDate в 4 колонку
    for (int i = 0; i < rowCount; i++){
        QModelIndex index;
        index = pModel->index(i, 3);
        pModel->setData(index, QDate());
    }

    // Установка модели представления
    ui->tableView->setModel(pModel);
}

void MainWindow::on_action_Open_triggered()
{
    nameFile = QFileDialog::getOpenFileName(0,
                                 "Открыть файл",
                                 "/home/alexandr",
                                 "*.txt");
    QFile file(nameFile);

    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        QString str;
        createModelView();
        int i = 0;
        while (!stream.atEnd()){
            str = stream.readLine();
            str.remove("");
            QStringList list;
            list.append(str.split(";"));
            for (; i < rowCount; i++){
                for (int j = 0; j < columnCount; j++){
                    QModelIndex index;
                    index = pModel->index(i, j);
                    pModel->setData(index, list.at(j), Qt::DisplayRole);
                }
            }
            on_pushButtonAddRow_clicked();
        }
        file.close();
    }
}

void MainWindow::on_action_Save_as_triggered()
{
    nameFile = QFileDialog::getSaveFileName(0,
                                            "Сохранить файл",
                                            "/home/alexandr",
                                            "*.txt");
    on_action_SaveAll_triggered();
}

void MainWindow::on_action_SaveAll_triggered()
{
    QFile file(nameFile);

    if (file.open(QIODevice::WriteOnly)){
        QTextStream stream;
        stream.setDevice(&file);

        for (int i = 0; i < rowCount; i++){
            for (int j = 0; j < columnCount; j++){
                QModelIndex index;
                index = pModel->index(i, j);
                QString data = index.data().toString();
                stream << data << ";";
            }
            stream << '\n';
        }
        file.close();
    }
}

void MainWindow::on_pushButtonAddRow_clicked()
{
    pModel->appendRow(new QStandardItem());
    rowCount = pModel->rowCount();
    QModelIndex index = pModel->index(rowCount-1, 3);
    pModel->setData(index, QDate());
}

void MainWindow::on_pushButtonSort_clicked()
{
    pModel->sort(0);
}

void MainWindow::on_pushButtonDelRow_clicked()
{
    QModelIndexList indexList = ui->tableView->selectionModel()->selectedRows();
    foreach(QModelIndex index, indexList){
        pModel->removeRow(index.row());
    }
}

void MainWindow::on_pushButtonSearch_clicked()
{
    QString keyWord = ui->lineEdit->text();
    QList<QStandardItem*> items;
    items = pModel->findItems(keyWord, Qt::MatchContains, 0);

    if (items.size()){
        ui->tableView->selectRow(items.at(0)->row());
    }
}

void MainWindow::on_action_Create_triggered()
{
    MainWindow* newWindow = new MainWindow();
    newWindow->setWindowTitle("База данных");
    newWindow->show();
}

void MainWindow::on_action_AboutProgram_triggered()
{
    QMessageBox::about(this, "О программе", "База данных Ver 1.0\nСобрано 11.03.2020 г.");
}

void MainWindow::on_action_Guide_triggered()
{
    QWidget* pWidget = new QWidget(0,Qt::Tool);
    QLabel* pLabel = new QLabel();
    QPixmap* pGuide = new QPixmap("/home/alexandr/Development/C++/BaseData/Icons/Руководство пользователя.png");
    QVBoxLayout* pVBoxLout = new QVBoxLayout();

    pWidget->setWindowTitle("Руководство пользователя");
    pLabel->setPixmap(*pGuide);
    pVBoxLout->addWidget(pLabel);
    pWidget->setLayout(pVBoxLout);
    pWidget->show();
}
