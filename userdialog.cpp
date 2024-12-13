#include "userdialog.h"
#include "ui_userdialog.h"

 // Include the header for the new dialog
static QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
static QString desktopPath2 = desktopPath.replace("/", "\\");
static string filePath = desktopPath2.toStdString()+"\\Employees.txt";

UserDialog::UserDialog(Back::LinkList* list ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog),
    addManager(nullptr),
    addDeveloper(nullptr),
    searchEmployeeDialog(nullptr)
    ,removeEmployeeDialog(nullptr)
    ,list(list)

{
    ui->setupUi(this);
    try {
        loadEmployees(filePath , *list);
    } catch (...) {
        QMessageBox::warning(this ,"warning" ,"Unable to open file Employees.txt. Please check the file path and permissions.");
    }

}

UserDialog::~UserDialog()
{
    delete ui;
    if (addManager != nullptr)
        delete addManager;
    if (addDeveloper != nullptr)
        delete addDeveloper;
    if (searchEmployeeDialog != nullptr)
        delete searchEmployeeDialog;
    if (removeEmployeeDialog != nullptr)
        delete removeEmployeeDialog;  // Delete removeEmployeeDialog if it's not nullptr
}

void UserDialog::on_pushButton_4_clicked()
{
    if (addManager == nullptr)
        addManager = new AddManager(list ,this);
    addManager->show();
    addManager = nullptr;
    delete addManager;
}

void UserDialog::on_pushButton_5_clicked()
{
    if (addDeveloper == nullptr)
        addDeveloper = new AddDeveloper(list ,this);
    addDeveloper->show();
    addDeveloper = nullptr;
    delete addDeveloper;
}

void UserDialog::on_pushButton_6_clicked()
{
    if (searchEmployeeDialog == nullptr)
        searchEmployeeDialog = new searchEmployee(list , this);
    searchEmployeeDialog->show();
    searchEmployeeDialog = nullptr;
    delete searchEmployeeDialog;
}

void UserDialog::on_pushButton_10_clicked()
{
    if (removeEmployeeDialog == nullptr)
        removeEmployeeDialog = new removeEmployee(list , this);
    removeEmployeeDialog->show();
    removeEmployeeDialog = nullptr;
    delete removeEmployeeDialog;
}

void UserDialog::on_pushButton_7_clicked()
{
    listemployee *listDialog = new listemployee(list , this);
    listDialog->setModal(true);
    listDialog->show();
    listDialog = nullptr;
    delete listDialog;
}

void UserDialog::on_pushButton_clicked()
{
    this->close();
}

void UserDialog::on_pushButton_9_clicked()
{
    saveEmployees(filePath , *list);
    QMessageBox::information(this , "info" , "saved changes" , QMessageBox::Ok);

}
