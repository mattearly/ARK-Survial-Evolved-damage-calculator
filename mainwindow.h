#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    //weapon stuff
    void on_pushButton_released();

    void on_comboBox_Weapon_currentIndexChanged(int index);

    void on_pushButton_webLink_released();

    //dino stuff
    void on_pushButton_2_released();

    void on_comboBox_Dinosaur_currentIndexChanged(int index);

    void on_pushButton_webLink_2_released();

    void on_pushButton_forgecalc_released();

    void on_pushButton_TAMING_released();

    void on_comboBox_Dinosaur_taming_currentIndexChanged(int index);

    void on_pushButton_webLink_taming_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
