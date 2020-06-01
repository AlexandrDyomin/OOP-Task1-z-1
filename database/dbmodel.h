#ifndef DDMODEL_H
#define DDMODEL_H
#include <QStandardItemModel>
#include <QObject>

// Не используйте здесь ничего из главного окна напрямую
// Этот модуль только хранит и обрабатывает данные, но не взаимодействует с пользователем

// TODO: реализуйте в отдельном модуле класс для хранения одной строки данных
// Это должны быть конкретные данные (например как в курсовой по программированию),
// которые требуют проверки целостности

// PS. не пишите код этого класса прямо здесь, чтобы потом было интереснее всё это переносить в отдельный модуль
class MyItem{
public:
    QString x;
};


// Класс представляющий Модель  (в дополнение к Представлению, tableView)
// Он хранит и обрабатывает данные программы.

// TODO: дополнить конкретным описанием

class DBModel : public QObject
{
    Q_OBJECT
    QString filename;

public:
    explicit DBModel(QObject *parent = nullptr);

    QStandardItemModel data;   // таблица с данными.
    // Это очень простой вариант хранения данных,
    // в идеале нужно сделать класс DBModel на основе QAbstractItemModel

    // Хранить данные в QStandardItemModel или наследнике от QAbstractItemModel
    // удобно потому, что эти классы реализуют Модель в архитектуре Модель-Представление
    // и позволяют автоматически обновлять Представление (здесь это QTableView) при изменении модели
    // Подробнее про Модель-Представление:
    // http://www.doc.crossplatform.ru/qt/4.7.x/model-view-programming.html -- на русском для Qt4
    // https://doc.qt.io/qt-5/model-view-programming.html -- официальная документация


    void save(); // сохраняет данные в файл
    void load(); // загружает данные из файлы

    void add(const MyItem& row); // добавляет новую строку в таблицу

    // TODO: ...

signals:

};

#endif // DDMODEL_H
