#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createModelView(int rows=1);

private slots:
    void on_action_SaveAll_triggered();
    void on_pushButtonAddRow_clicked();
    void on_action_Open_triggered();
    void on_action_Save_as_triggered();
    void on_pushButtonDelRow_clicked();
    void on_pushButtonSort_clicked();

    void on_pushButtonSearch_clicked();

    void on_action_Create_triggered();

    void on_action_AboutProgram_triggered();

    void on_action_Guide_triggered();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* pModel;
    int rowCount;
    int columnCount;
    QString nameFile = "Base_data.txt";
};
#endif // MAINWINDOW_H
