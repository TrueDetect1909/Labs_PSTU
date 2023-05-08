#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Refueling {
    int check_number;
    QDateTime time;
    QString fuel_type;
    float fuel_amount;
    float fuel_price;
    float payment_amount;
    QString payment_type;
    QString workstation_number;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_refuelButton_clicked();

    void on_pricesButton_clicked();

    void on_historyButton_clicked();

private:
    Ui::MainWindow *ui;
    double fuel_prices[4] = { 45.5, 48.5, 52.0, 47.0 };
    int check_number = 1;
    QStandardItemModel *history_model;

    void saveRefuelingToFile(Refueling refueling);
    void readRefuelingsFromFile();
};

#endif // MAINWINDOW_H
