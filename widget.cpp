#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tableView_sql = ui->tableView_sql;
    //Создание таблицы на 6 ячеик
    model = new QStandardItemModel(0 ,6 ,this);
    model->setHorizontalHeaderLabels({"Дата","Клиент|Организация","Название модели"
                                    ,"Диагностика","Запчасти","Сумма ремонта"});
    //Применяет модель к таблицам из UI
    ui->tableView_sql->setModel(model);
    tableView_sql->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView_sql->verticalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    QList<QStandardItem*> row;
    row << new QStandardItem("2023-10-01")
        << new QStandardItem("ООО Ромашка")
        << new QStandardItem("HP LaserJet")
        << new QStandardItem("Чистка")
        << new QStandardItem("Картридж")
        << new QStandardItem("1500");
    model->appendRow(row);  // Добавляем строку

    tableView_sql->setModel(model);  // Связываем
}

Widget::~Widget()
{
    delete ui;
}

