#include "addrepairdialog.h"
#include "ui_addrepairdialog.h"

AddRepairDialog::AddRepairDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRepairDialog)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());//Автоматически устанавливает время


}
QDate AddRepairDialog::date() const
{
    return ui->dateEdit->date();
}
AddRepairDialog::~AddRepairDialog()
{
    delete ui;
}
