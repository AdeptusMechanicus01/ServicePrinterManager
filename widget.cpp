#include "widget.h"
#include "./ui_widget.h"
#include "addrepairdialog.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(AddARowToATable()));
    tableView_sql = ui->tableView_sql;
    //Создание таблицы на 6 ячеик
    model = new QStandardItemModel(0 ,6 ,this);
    model->setHorizontalHeaderLabels({"Дата","Клиент|Организация","Название модели"
                                    ,"Диагностика","Запчасти","Сумма ремонта"});
    //Применяет модель к таблицам из UI
    ui->tableView_sql->setModel(model);
    tableView_sql->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView_sql->verticalHeader()->setSectionResizeMode(QHeaderView::Interactive);



    tableView_sql->setModel(model);  // Связываем

}


Widget::~Widget()
{
    delete ui;
}


void Widget::AddARowToATable()
{
    // Создание и открытие диалога
    AddRepairDialog dialog(this);

    // Если пользователь нажал "Добавить" (Accepted)
    if(dialog.exec() == QDialog::Accepted)
    {
        // Создаем список элементов для новой строки
        QList<QStandardItem*> rowItems;

        // Преобразуем данные в элементы таблицы
        rowItems << new QStandardItem(dialog.date().toString("dd.MM.yyyy"))
                 << new QStandardItem(dialog.client())
                 << new QStandardItem(dialog.model())       //
                 << new QStandardItem(dialog.diagnostic())
                 << new QStandardItem(dialog.zip());
        int totalSum = static_cast<int>(dialog.sum());
        QString sumText = QString::number(totalSum) + " ₽";
        rowItems <<new QStandardItem(sumText);


        // Добавляем строку в модель
        model->appendRow(rowItems);
    }
}

void Widget::initDatabase()
{
    // Подключение SQL base
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("repairs.db");

    if(!db.open())
    {
        qDebug() << "Ошибка открытия БД: "<<db.lastError().text();
    }
    //2.ЗАгрузить SQL из ресурсов

    QFile sqlFile(":/base/init.sql");
    if(!sqlFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Не могу открыть init.sql";
        return;
    }
    //Чтение всего файла
    QTextStream stream (&sqlFile);
    QString sql = stream.readAll();
    sqlFile.close();
    // Выполнение SQ:
    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug() <<"Ошибка SQL :" << query.lastError().text();
    }
}
