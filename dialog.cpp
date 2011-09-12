#include "dialog.h"
#include "ui_dialog.h"
#include <QSettings>

#define REG_KEY "HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment"
#define REG_VAR "Path"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);    

    QSettings settings(REG_KEY, QSettings::NativeFormat);
    QString S = settings.value(REG_VAR).toString();
    ui->plainTextEdit->document()->setPlainText(S.replace(";","\n"));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnSave_clicked()
{

}

void Dialog::on_pushButton_2_clicked()
{

}
