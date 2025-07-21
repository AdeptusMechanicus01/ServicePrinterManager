#ifndef ADDREPAIRDIALOG_H
#define ADDREPAIRDIALOG_H

#include <QDialog>
#include <QDate>
#include <QPushButton>
#include <QMessageBox>


namespace Ui {
class AddRepairDialog;
}

class AddRepairDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRepairDialog(QWidget *parent = nullptr);
    ~AddRepairDialog();
    QDate date() const;
    QString client()const;
    QString model()const;
    QString diagnostic()const;
    QString zip()const;
    double sum() const;
private slots:
    void SaveARowToATable();

private:
    Ui::AddRepairDialog *ui;
};

#endif // ADDREPAIRDIALOG_H
