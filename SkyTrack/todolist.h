#ifndef TODOLIST_H
#define TODOLIST_H
#include "QtWidgets/qdialog.h"
#include "database.h"
#include "login.h"
#include <QListWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class ToDoList;
}
QT_END_NAMESPACE

class ToDoList : public QDialog
{
    Q_OBJECT

public:
    explicit ToDoList(QWidget *parent = nullptr, Login *details = nullptr);
    void restoreTasks();
    ~ToDoList();
signals:
    void addTask(QString& );
private slots:
    void on_btnAdd_clicked();

    void on_btnRemove_clicked();

    void on_btnClear_clicked();

    void on_backButton_clicked();

    void on_txtTask_2_returnPressed();

private:
    Ui::ToDoList *ui;
    DataBase* db;
};
#endif // TODOLIST_H
