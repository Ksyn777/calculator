#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLCDNumber lcd;
    double firstNumber;
    double secondNumber;
    QString operation = "";
    bool decimalPoint = false;
    double decimalFactor = 0.1;
    QString text = QString::number(currentNumber, 'g', 10);




private:
    int currentNumber; // przechowuje wpisane cyfry
    QString type = "type";
    double result;
    void wprowadzenie_przycisku(int liczba);







private slots:
    void on_one_button_clicked();

    void on_two_button_clicked();

    void on_three_button_clicked();

    void on_four_button_clicked();

    void on_five_button_clicked();

    void on_six_button_clicked();

    void on_seven_button_clicked();

    void on_eight_button_clicked();

    void on_nine_button_clicked();

    void on_zero_button_clicked();

    void on_dodawanie_button_clicked();

    void on_suma_button_clicked();

    void on_pushButton_clicked();

    void on_odejmowanie_button_clicked();



    void on_mnozenie_button_clicked();

    void on_dzielenie_button_clicked();

    void on_potegowanie_button_clicked();

    void on_pierwiastki_button_clicked();



    void on_przecinek_button_clicked();



    void on_koniec_button_clicked();

    void on_procent_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
