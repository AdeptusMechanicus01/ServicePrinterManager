#include "addrepairdialog.h"
#include "ui_addrepairdialog.h"

AddRepairDialog::AddRepairDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRepairDialog)
{
    ui ->setupUi(this);
    connect(ui->SavePushButton,SIGNAL(clicked()),this,SLOT(SaveARowToATable()));//Подключение кнопки
    ui ->DateEdit->setDate(QDate::currentDate());//Автоматически устанавливает время
    ui->SumSpinBox->setMaximum(99999);
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

void AddRepairDialog::SaveARowToATable()
{
    //Проверка на ввод всех полей
    if(ui ->ClientLineEdit ->text().isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить данные");
        return;
    }
   //Проверка на сумму
    if(ui->SumSpinBox->value() > 99999){
        QMessageBox::warning(this, "Ошибка","Сумма превысела допустимое значение");    }
        accept();
}

