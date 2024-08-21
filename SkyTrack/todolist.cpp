#include "todolist.h"
#include "ui_todolist.h"
#include "login.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QDialog>
#include <QStringList>
#include <QPixmap>

// Work done by Nicholas

ToDoList::ToDoList(QWidget *parent, Login *details)
    : QDialog(parent)
    , ui(new Ui::ToDoList)
{
    ui->setupUi(this);
      
    db = new DataBase(this);
    db->callDataBase(details->getEmail(), details->getPassword(), details->getToken(), false);
    connect(db, &DataBase::accessTasks, this, &ToDoList::restoreTasks);
      
    QPixmap pixMap(":/Weather.png");
    ui->pic->setPixmap(pixMap);
    ui->pic->setScaledContents(true);
    ui->pic->setFixedSize(ui->pic->pixmap().size());
   
}
ToDoList::~ToDoList()
{
    delete ui;
    delete db;
}

void ToDoList::restoreTasks()
{
    QJsonArray tasks = db->getTasks();
    QString list = "";

        for(int i = 0; i < tasks.size(); i++)
        {
            list = tasks[i].toString();
            ui->listWidget_2->addItem(new QListWidgetItem(list,ui ->listWidget_2));
        }
}

void ToDoList::on_btnAdd_clicked()
{
    QString list = ui->txtTask_2->text();
    db->addList(list);
    QListWidgetItem* item = new QListWidgetItem(ui->txtTask_2->text(),ui ->listWidget_2);
    ui -> listWidget_2->addItem(item);
    ui -> txtTask_2->clear();
    ui -> txtTask_2->setFocus();
}


void ToDoList::on_btnRemove_clicked()
{
    QListWidgetItem* item = ui->listWidget_2->takeItem(ui->listWidget_2->currentRow());
    QJsonArray tasks = db->getTasks();
    if(!tasks.empty())
    {
        db->removeTask(item->text());
    }

    delete item;
}


void ToDoList::on_btnClear_clicked()
{
    ui->listWidget_2->clear();
    db->clearTasks();
}


void ToDoList::on_backButton_clicked()
{
    hide();
    QWidget *parent = this->parentWidget();
    parent->show();

}


void ToDoList::on_txtTask_2_returnPressed()
{
    QListWidgetItem* item = new QListWidgetItem(ui->txtTask_2->text(),ui ->listWidget_2);
    ui -> listWidget_2->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui -> txtTask_2->clear();
    ui -> txtTask_2->setFocus();
    for(int i =0; i < ui->listWidget_2->count();i++){
        ui->listWidget_2->item(i)->text();
    }
}

