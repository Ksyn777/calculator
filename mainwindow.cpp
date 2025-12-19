#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLCDNumber>
#include <QString>
#include <string>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentNumber = 0;
    ui->lcdNumber->display(currentNumber);
    ui->lcdNumber->setDigitCount(9);
    result = 0;
    decimalPoint = false;
    decimalFactor = 0.1;
    QString text = QString::number(currentNumber, 'g', 10);

    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wprowadzenie_przycisku(int liczba)
{
    if(decimalPoint == false)
    {
        currentNumber = currentNumber * 10 + liczba;
    }
    else
    {
        currentNumber += liczba * decimalFactor;
        decimalFactor /= 10;
    }

    // Tworzymy tekst do wyświetlenia
    QString text = QString::number(currentNumber, 'g', 10);

    // Dodajemy kropkę, jeśli wciśnięto przecinek, a jej nie ma
    if(decimalPoint && !text.contains('.'))
        text += '.';

    ui->lcdNumber->display(text);
}


void MainWindow::on_one_button_clicked() { wprowadzenie_przycisku(1);}

void MainWindow::on_two_button_clicked() { wprowadzenie_przycisku(2);}

void MainWindow::on_three_button_clicked() { wprowadzenie_przycisku(3); }

void MainWindow::on_four_button_clicked() { wprowadzenie_przycisku(4);}

void MainWindow::on_five_button_clicked() { wprowadzenie_przycisku(5);}

void MainWindow::on_six_button_clicked() { wprowadzenie_przycisku(6);}

void MainWindow::on_seven_button_clicked() { wprowadzenie_przycisku(7);}

void MainWindow::on_eight_button_clicked() { wprowadzenie_przycisku(8);}

void MainWindow::on_nine_button_clicked() { wprowadzenie_przycisku(9);}

void MainWindow::on_zero_button_clicked() { wprowadzenie_przycisku(0);}


void MainWindow::on_dodawanie_button_clicked()
{
    result += currentNumber;   // dodaj bieżącą liczbę do sumy
    currentNumber = 0;         // zeruj bieżącą liczbę
    operation = "+";           // zapisz operację
    ui->lcdNumber->display(result); // opcjonalnie pokaz bieżący wynik
}

void MainWindow::on_suma_button_clicked()
{
    if(operation == "+") {result += currentNumber; ui->lcdNumber->display(result);}
    else if(operation == "-") {result -= currentNumber; ui->lcdNumber->display(result);}
    else if(operation == "*") {result *= currentNumber; ui->lcdNumber->display(result); }
    else if(operation == "/") {result /= currentNumber; ui->lcdNumber->display(result);}
    else if(operation == "Pot") { result = pow(result, currentNumber); ui->lcdNumber->display(result);}
    else if(operation == "Pier") { result = sqrt(result);  ui->lcdNumber->display(result);}

    ui->lcdNumber->display(QString::number(result, 'g', 10));
    currentNumber = 0;
    decimalPoint = false;
    decimalFactor = 0.1;
}



void MainWindow::on_pushButton_clicked()
{
    currentNumber = 0;
    ui->lcdNumber->display(0);
    result = 0;
}


void MainWindow::on_odejmowanie_button_clicked()
{
    if(result == 0 && currentNumber != 0)
        result = currentNumber; // dla pierwszej liczby
    else
        result -= currentNumber; // dla kolejnych liczb

    currentNumber = 0;         // zeruj bieżącą liczbę
    operation = "-";           // zapisz operację
    ui->lcdNumber->display(result); // opcjonalnie pokaz bieżący wynik
}







void MainWindow::on_mnozenie_button_clicked()
{
    if(result == 0)
    {
        result = currentNumber;
    }
    else
    {
        result *= currentNumber;
    }
    currentNumber = 0;
    operation = "*";           // zapisz operację
    ui->lcdNumber->display(result); // opcjonalnie pokaz bieżący wynik
}



void MainWindow::on_dzielenie_button_clicked()
{
    if(result == 0)
    {
        result = currentNumber;
    }
    else
    {
        result /= currentNumber;
    }
    currentNumber = 0;
    operation = "/";           // zapisz operację
    ui->lcdNumber->display(result); // opcjonalnie pokaz bieżący wynik
}


void MainWindow::on_potegowanie_button_clicked()
{
    if(result == 0)
    {
        result = currentNumber;
    }
    else
    {
        result = pow(result, currentNumber);
    }
    currentNumber = 0;
    operation = "Pot";           // zapisz operacj
    ui->lcdNumber->display(result); // opcjonalnie pokaz bieżący wynik
}


void MainWindow::on_pierwiastki_button_clicked()
{
    if(currentNumber != 0)
        result = sqrt(currentNumber);
    else if(result != 0)
        result = sqrt(result);
    else
        result = 0;

    currentNumber = 0;
    decimalPoint = false;
    decimalFactor = 0.1;
    operation = "Pier";
    ui->lcdNumber->display(QString::number(result, 'g', 10));
}


void MainWindow::on_przecinek_button_clicked()
{
    if(!decimalPoint) {
        decimalPoint = true;
        decimalFactor = 0.1; // reset czynnika dziesiętnego

        QString text = QString::number(currentNumber, 'g', 10);
        if(!text.contains('.')) text += '.';
        ui->lcdNumber->display(text);
    }
}


void MainWindow::on_koniec_button_clicked()
{
    close();
}


void MainWindow::on_procent_button_clicked()
{
    if (operation == "+" || operation == "-") {
        currentNumber = (result * currentNumber) / 100.0;
    } else if (operation == "*" || operation == "/") {
        currentNumber = currentNumber / 100.0;
    }
    ui->lcdNumber->display(currentNumber);
}

