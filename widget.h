#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTableView>
#include<QStandardItem>

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

private:
    Ui::Widget *ui;
    QTableView *tableView_sql;
    QStandardItemModel *model;
};
#endif // WIDGET_H
