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
        ui->lcdNumber_rawdamage->display((BaseDamage_WOODEN_CLUB) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 8:
        ui->lcdNumber_rawdamage->display((BaseDamage_METAL_SWORD) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 9:
        ui->lcdNumber_rawdamage->display(1);  //electric prod
       // ui->lcdNu
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

void MainWindow::on_comboBox_Weapon_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        ui->radioButton_ammo1->setText("Ammo1");
        ui->radioButton_ammo2->setText("Ammo2");
        ui->radioButton_ammo3->setText("Ammo3");
        ui->radioButton_ammo1->setEnabled(false);
        ui->radioButton_ammo2->setEnabled(false);
        ui->radioButton_ammo3->setEnabled(false);
        break;
    case 10:  //sling
        ui->radioButton_ammo1->setText("ROCK");
        ui->radioButton_ammo2->setText("Am2");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(false);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 11:   //wood bow
        ui->radioButton_ammo1->setText("Stone Arrow");
        ui->radioButton_ammo2->setText("Tranq Arrow");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(true);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 12:   //crossbow
        ui->radioButton_ammo1->setText("Stone Arrow");
        ui->radioButton_ammo2->setText("Tranq Arrow");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(true);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 13:  //compound bow
        ui->radioButton_ammo1->setText("Metal Arr");
        ui->radioButton_ammo2->setText("Stone Arr");
        ui->radioButton_ammo3->setText("Tranq Arr");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(true);
        ui->radioButton_ammo3->setEnabled(true);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 14:  //simple pistol
        ui->radioButton_ammo1->setText("Simple Bullet");
        ui->radioButton_ammo2->setText("Am2");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(false);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 15:  //longneck rifle
        ui->radioButton_ammo1->setText("Simple Rifle Ammo");
        ui->radioButton_ammo2->setText("Dart");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(true);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 16:  //double barrel shotgun
        ui->radioButton_ammo1->setText("Simple Shotgun Ammo");
        ui->radioButton_ammo2->setText("Am2");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(false);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 17:   //fabricated pistol
        ui->radioButton_ammo1->setText("Advanced Bullet");
        ui->radioButton_ammo2->setText("Am2");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(false);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 18:  //pump-action shotgun
        ui->radioButton_ammo1->setText("Simple Shotgun Ammo");
        ui->radioButton_ammo2->setText("Am2");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(false);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 19: //assault rifle
        ui->radioButton_ammo1->setText("Advanced Rifle Bullet");
        ui->radioButton_ammo2->setText("Am2");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(false);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 20:  //fabricated sniper rifle
        ui->radioButton_ammo1->setText("Advanced Sniper Bullet");
        ui->radioButton_ammo2->setText("Am2");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(false);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    case 21:  //rocket launcher
        ui->radioButton_ammo1->setText("Rocket");
        ui->radioButton_ammo2->setText("Am2");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(true);
        ui->radioButton_ammo2->setEnabled(false);
        ui->radioButton_ammo3->setEnabled(false);
        ui->radioButton_ammo1->setChecked(true);
        break;
    default:
        ui->radioButton_ammo1->setText("Am1");
        ui->radioButton_ammo2->setText("Am2");
        ui->radioButton_ammo3->setText("Am3");
        ui->radioButton_ammo1->setEnabled(false);
        ui->radioButton_ammo2->setEnabled(false);
        ui->radioButton_ammo3->setEnabled(false);
        break;
    }
}
