#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile check_file("check_number.txt");
    if (check_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&check_file);
        in >> check_number;
    }
    check_file.close();

    history_model = new QStandardItemModel(this);
    history_model->setColumnCount(8);
    history_model->setHeaderData(0, Qt::Horizontal, "Номер чека");
    history_model->setHeaderData(1, Qt::Horizontal, "Время");
    history_model->setHeaderData(2, Qt::Horizontal, "Тип топлива");
    history_model->setHeaderData(3, Qt::Horizontal, "Кол-во литров");
    history_model->setHeaderData(4, Qt::Horizontal, "Цена за литр");
    history_model->setHeaderData(5, Qt::Horizontal, "Стоимость заправки");
    history_model->setHeaderData(6, Qt::Horizontal, "Тип оплаты");
    history_model->setHeaderData(7, Qt::Horizontal, "Номер рабочего места");
    ui->historyTableView->setModel(history_model);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_refuelButton_clicked()
{
    
    QString fuel_type = ui->fuelTypeComboBox->currentText();
    float fuel_amount = ui->fuelAmountSpinBox->value();
    QString payment_type = ui->paymentTypeComboBox->currentText();
    QString workstation_number = ui->workstationComboBox->currentText();

    float fuel_price;
    if (fuel_type == "92") {
        fuel_price = fuel_prices[0];
    } else if (fuel_type == "95") {
        fuel_price = fuel_prices[1];
    } else if (fuel_type == "100") {
        fuel_price = fuel_prices[2];
    } else if (fuel_type == "DT") {
        fuel_price = fuel_prices[3];
    } else {
        QMessageBox::critical(this, "Ошибка", "Неверный тип оплаты");
        return;
    }

    
    float payment_amount = fuel_amount * fuel_price;

    
    Refueling refueling;
    refueling.check_number = check_number;
    refueling.time = QDateTime::currentDateTime();
    refueling.fuel_type = fuel_type;
    refueling.fuel_amount = fuel_amount;
    refueling.fuel_price = fuel_price;
    refueling.payment_amount = payment_amount;
    refueling.payment_type = payment_type;
    refueling.workstation_number = workstation_number; 

    
    saveRefuelingToFile(refueling);

    
    check_number++;

    
    QFile check_file("check_number.txt");
    if (check_file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&check_file);
        out << check_number;
    }
    check_file.close();

    
    QList<QStandardItem*> row_items;
    row_items.append(new QStandardItem(QString::number(refueling.check_number)));
    row_items.append(new QStandardItem(refueling.time.toString()));
    row_items.append(new QStandardItem(refueling.fuel_type));
    row_items.append(new QStandardItem(QString::number(refueling.fuel_amount)));
    row_items.append(new QStandardItem(QString::number(refueling.fuel_price)));
    row_items.append(new QStandardItem(QString::number(refueling.payment_amount)));
    row_items.append(new QStandardItem(refueling.payment_type));
    row_items.append(new QStandardItem(refueling.workstation_number));
    history_model->appendRow(row_items);

    QMessageBox::information(this, "Успешно", "Заправка завершена");
}

void MainWindow::on_pricesButton_clicked()
{
    
    fuel_prices[0] = ui->price92SpinBox->value();
    fuel_prices[1] = ui->price95SpinBox->value();
    fuel_prices[2] = ui->price100SpinBox->value();
    fuel_prices[3] = ui->priceDTSpinBox->value();

    QMessageBox::information(this, "Успешно", "Цены на топливо обновлены");
}

void MainWindow::on_historyButton_clicked()
{
    
    readRefuelingsFromFile();
}

void MainWindow::saveRefuelingToFile(Refueling refueling)
{
    QFile file("history.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << refueling.check_number << ",";
        out << refueling.time.toString("yyyy-MM-dd hh:mm:ss") << ",";
        out << refueling.fuel_type << ",";
        out << refueling.fuel_amount << ",";
        out << refueling.fuel_price << ",";
        out << refueling.payment_amount << ",";
        out << refueling.payment_type << ",";
        out << refueling.workstation_number << "\n";
    }
    file.close();
}

void MainWindow::readRefuelingsFromFile()
{
    QFile file("history.csv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        history_model->removeRows(0, history_model->rowCount());
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            QList<QStandardItem*> row_items;
            for (int i = 0; i < fields.size(); i++) {
                row_items.append(new QStandardItem(fields.at(i)));
            }
            history_model->appendRow(row_items);
        }
    }
    file.close();
}
