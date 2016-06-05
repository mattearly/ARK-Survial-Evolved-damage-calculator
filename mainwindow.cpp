#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "defaultweapondamage.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_released()
{
    switch (ui->comboBox_Weapon->currentIndex()) {
    case 0:
        ui->lcdNumber_rawdamage->display((BaseDamage_STONE_PICK) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 1:
        ui->lcdNumber_rawdamage->display((BaseDamage_STONE_HATCHET) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 2:
        ui->lcdNumber_rawdamage->display((BaseDamage_TORCH) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 3:
        ui->lcdNumber_rawdamage->display((BaseDamage_METAL_PICK) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 4:
        ui->lcdNumber_rawdamage->display((BaseDamage_METAL_HATCHET) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 5:
        ui->lcdNumber_rawdamage->display((BaseDamage_METAL_SICKLE) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 6:
        ui->lcdNumber_rawdamage->display((BaseDamage_PIKE) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 7:
        ui->lcdNumber_rawdamage->display((BaseDamage_WOODEN_CLUB) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 8:
        ui->lcdNumber_rawdamage->display((BaseDamage_METAL_SWORD) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 9:
        ui->lcdNumber_rawdamage->display(1);  //electric prod
        break;
    case 10:
        ui->lcdNumber_rawdamage->display((BaseDamage_SLINGSHOT) * (ui->doubleSpinBox_damagepercent->value() / 100));
        //+torpor
        break;
    case 11:
        ui->lcdNumber_rawdamage->display((BaseDamage_WOODEN_BOW_STONE_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100));
        //+tranq arrow version
        break;
    case 12:
        ui->lcdNumber_rawdamage->display((BaseDamage_CROSSBOW_STONE_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100));
        //+tranq arrow version
        break;
    case 13:
        ui->lcdNumber_rawdamage->display((BaseDamage_COMPOUND_BOW_METAL_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100));
        //+stone arrow version
        //+tranq arrow version
        break;
    case 14:
        ui->lcdNumber_rawdamage->display((BaseDamage_SIMPLE_PISTOL) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 15:
        ui->lcdNumber_rawdamage->display((BaseDamage_LONGNECK_RIFLE) * (ui->doubleSpinBox_damagepercent->value() / 100));
        //+dart version
        break;
    case 16:
        ui->lcdNumber_rawdamage->display((BaseDamage_SHOTGUN) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 17:
        ui->lcdNumber_rawdamage->display((BaseDamage_FABRICATED_PISTOL) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 18:
        ui->lcdNumber_rawdamage->display((BaseDamage_PUMP_ACTION_SHOTGUN) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 19:
        ui->lcdNumber_rawdamage->display((BaseDamage_ASSAULT_RIFLE) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 20:
        ui->lcdNumber_rawdamage->display((BaseDamage_FABRICATED_SNIPER_RIFLE) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 21:
        ui->lcdNumber_rawdamage->display((BaseDamage_ROCKET_LAUNCHER) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    default:
        ui->lcdNumber_rawdamage->display(0);
        break;
    }
}
