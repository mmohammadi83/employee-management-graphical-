#include "removeemployee.h"
#include "ui_removeemployee.h"
#include "showdetailsbysearch.h"
#include <QString>
#include <string>
#include <QMessageBox>
using namespace std;

removeEmployee::removeEmployee(Back::LinkList* list ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeEmployee),
    list(list)
{
    ui->setupUi(this);
}

removeEmployee::~removeEmployee()
{
    delete ui;
}

void removeEmployee::on_pushButton_2_clicked()
{
    this->close();
}

void removeEmployee::on_pushButton_clicked()
{
    QString RemoveID = ui->lineEdit->text();
    string removeID = RemoveID.toStdString();

    Back::LinkList list2 = *list;
    Back::Employee* emp = list2[removeID];


    if (emp) {
        showdetailsbysearch *detailDialog = new showdetailsbysearch(emp ,this);
        detailDialog->show();
        detailDialog = nullptr;
        delete detailDialog;

        list->popNode(*emp);
        QMessageBox::information(this, "Success", "Successfully deleted, this person was removed");
    } else {
        QMessageBox::warning(this, "Error", "Not found");
    }

    emp = nullptr;
    delete emp;
}
