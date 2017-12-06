#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_senha_inv->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bool chave= false;


    string str1 = "teste";
    int num2 = str1.compare( ui->line_login->text().toUtf8().constData() );
    num2 += str1.compare( ui->line_senha->text().toUtf8().constData() );

    cout << "n: " << num2 << endl;
    cout << "l: " << ui->line_login->text().toUtf8().constData() << endl;
    if ( num2 == 0){
        ui->label_senha_inv->setVisible(false);
        chave = true;
    }else {
        ui->label_senha_inv->setVisible(true);
    }
    if( chave == true){
        ui->label_titulo->setText("Login efetuado!");

    } else {
        ui->label_titulo->setText("Digite suas credenciais");

    }
}

