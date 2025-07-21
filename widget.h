#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTableView>
#include<QStandardItem>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void AddARowToATable();

private:
    Ui::Widget *ui;
    QTableView *tableView_sql;
    QStandardItemModel *model;
    QSqlDatabase db;
    void initDatabase();
};
#endif // WIDGET_H
