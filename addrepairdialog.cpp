#include "addrepairdialog.h"
#include "ui_addrepairdialog.h"

AddRepairDialog::AddRepairDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRepairDialog)
{
    ui->setupUi(this);
    ui->DateEdit->setDate(QDate::currentDate());//Автоматически устанавливает время
}
//Настройка окон для вывода и заполнения
QDate AddRepairDialog::date() const
{
    return ui->DateEdit->date();
}

QString AddRepairDialog::client()const
{
    return ui ->ClientLineEdit ->text();
}
QString AddRepairDialog::model() const
{
    return ui ->ModelLineEdit ->text();
}
QString AddRepairDialog::diagnostic() const
{
    return ui ->DiagnosticTextEdit ->toPlainText();
}
QString AddRepairDialog::zip() const
{
    return ui ->ZipTextEdit ->toPlainText();
}
double AddRepairDialog::sum() const
{
    return ui ->SumSpinBox ->value();
}


AddRepairDialog::~AddRepairDialog()
{
    delete ui;
}
