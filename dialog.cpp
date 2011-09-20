#include "dialog.h"
#include "ui_dialog.h"
#include <QSettings>

#define REG_KEY "HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment"
#define REG_VAR "Path"

QSettings qSettings(REG_KEY, QSettings::NativeFormat);

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);    

    QString S = qSettings.value(REG_VAR).toString();
    ui->plainTextEdit->document()->setPlainText(S.replace(";","\n"));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnSave_clicked()
{
    QString S = ui->plainTextEdit->document()->toPlainText();
    qSettings.setValue(REG_VAR,S.replace("\n",";"));
    this->close();
}

void Dialog::on_btnClose_clicked()
{
    this->close();
}
