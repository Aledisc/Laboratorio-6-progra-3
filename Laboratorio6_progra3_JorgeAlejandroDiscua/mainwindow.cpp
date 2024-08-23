#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "gestormatrices.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

GestorMatrices matriz;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    exit(0);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_5_clicked()
{
    matriz.crearMatrices(ui->sbF1->value(),ui->sbC1->value(),ui->sbF2->value(),ui->sbC2->value(),ui->matriz1,ui->matriz2);
    ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_pushButton_7_clicked()
{
    matriz.sumarMatrices(ui->matriz1,ui->matriz2,ui->matriz3);
}


void MainWindow::on_pushButton_8_clicked()
{
    matriz.restarMatrices(ui->matriz1,ui->matriz2,ui->matriz3);
}


void MainWindow::on_pushButton_9_clicked()
{
    matriz.multiplicarMatrices(ui->matriz1,ui->matriz2,ui->matriz3);
}


void MainWindow::on_pushButton_10_clicked()
{
    matriz.crearMatriz(ui->sbF->value(),ui->sbC->value(),ui->matrizElemento);
    ui->stackedWidget_3->setCurrentIndex(1);
}


void MainWindow::on_pushButton_11_clicked()
{
    matriz.buscarElemento(ui->sbEl->value(),ui->matrizElemento,ui->elementoLabel);
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_pushButton_14_clicked()
{
    matriz.crearMatriz(ui->sbFT->value(),ui->sbCT->value(),ui->tablaTransp);
    ui->stackedWidget_4->setCurrentIndex(1);
}


void MainWindow::on_pushButton_15_clicked()
{
    matriz.calcularTranspuesta(ui->tablaTransp,ui->Transp);
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_5->setCurrentIndex(0);
}


void MainWindow::on_pushButton_20_clicked()
{
    matriz.crearMatriz(ui->sbFR->value(),ui->sbCR->value(),ui->matrizR);
    ui->stackedWidget_5->setCurrentIndex(1);
}


void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);
}


void MainWindow::on_pushButton_21_clicked()
{
    matriz.rotarMatriz(ui->rotada);
}


void MainWindow::on_pushButton_23_clicked()
{
    matriz.copiarTabla(ui->matrizR,ui->rotada);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_4->setCurrentIndex(0);
}

