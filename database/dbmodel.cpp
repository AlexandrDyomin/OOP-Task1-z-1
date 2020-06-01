#include "dbmodel.h"

DBModel::DBModel(QObject *parent) : QObject(parent){

}

void DBModel::save(){
  // TODO:
  // можно не писать весь код самостоятельно,
  // а использовать классы для упрощения записи\чтения файлов
}

void DBModel::load(){
    // TODO:
}

void DBModel::add(const MyItem &row){

    QList<QStandardItem*> *row1 = new QList<QStandardItem*>();
    row1->append( new QStandardItem( row.x ));
    data.appendRow(*row1);

    // TODO: добавление ваших данных
}
