#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "defaultweapondamage.h"
#include <QIcon>
#include "weaponurls.h"
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setWindowIcon(QIcon(":/taskbar/arkdc.ico"));
    ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/default.png"));
    ui->pushButton_webLink->setIconSize(QSize(248,248));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    //reset lcds
    ui->lcdNumber_rawdamage->display(0);
    ui->lcdNumber_InstantTorpor->display(0);
    ui->lcdNumber_TorporOverTime->display(0);
    ui->lcdNumber_TotalTorpor->display(0);

    //tmp variables for calculating certain cases
    float tmp(0.f), tmp2(0.f), tmp3(0.f);

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
        ui->lcdNumber_InstantTorpor->display((BaseTorpor_WOODEN_CLUB) * (ui->doubleSpinBox_damagepercent->value() / 100));
        ui->lcdNumber_TotalTorpor->display((BaseTorpor_WOODEN_CLUB) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 8:
        ui->lcdNumber_rawdamage->display((BaseDamage_METAL_SWORD) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 9:
        ui->lcdNumber_rawdamage->display(1);  //electric prod
        tmp = (BaseTorpor_ELECTRIC_PROD) * (ui->doubleSpinBox_damagepercent->value() / 100);
        ui->lcdNumber_InstantTorpor->display(tmp);
        ui->lcdNumber_TotalTorpor->display(tmp);
        break;
    case 10:
        ui->lcdNumber_rawdamage->display((BaseDamage_SLINGSHOT) * (ui->doubleSpinBox_damagepercent->value() / 100));
        tmp = (BaseTorpor_SLINGSHOT) * (ui->doubleSpinBox_damagepercent->value() / 100);
        ui->lcdNumber_InstantTorpor->display(tmp);
        ui->lcdNumber_TotalTorpor->display(tmp);
        break;
    case 11:
        if (ui->radioButton_ammo1->isChecked()) {  //normal arrow
            ui->lcdNumber_rawdamage->display((BaseDamage_WOODEN_BOW_STONE_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100));
        } else {  //tranq arrow
            ui->lcdNumber_rawdamage->display((BaseDamage_WOODEN_BOW_TRANQ_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100));
            tmp = (BaseTorpor_WOODEN_BOW_TRANQ_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100);
            ui->lcdNumber_InstantTorpor->display(tmp);
            tmp2 = (DotTorpor_WOODEN_BOW_TRANQ_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100);
            ui->lcdNumber_TorporOverTime->display(tmp2);
            ui->lcdNumber_TotalTorpor->display(tmp + tmp2);
        }
        break;
    case 12:
        if (ui->radioButton_ammo1->isChecked()) {  //normal arrow
            ui->lcdNumber_rawdamage->display((BaseDamage_CROSSBOW_STONE_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100));
        } else {  //tranq arrow
            ui->lcdNumber_rawdamage->display((BaseDamage_CROSSBOW_TRANQ_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100));
            tmp = (BaseTorpor_CROSSBOW_TRANQ_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100);
            ui->lcdNumber_InstantTorpor->display(tmp);
            tmp2 = (DotTorpor_CROSSBOW_TRANQ_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100);
            ui->lcdNumber_TorporOverTime->display(tmp2);
            ui->lcdNumber_TotalTorpor->display(tmp + tmp2);
        }
        break;
    case 13:
        if (ui->radioButton_ammo1->isChecked()) {  //metal arrow
            ui->lcdNumber_rawdamage->display((BaseDamage_COMPOUND_BOW_METAL_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100));
        } else if (ui->radioButton_ammo2->isChecked()) {  //normal arrow
            ui->lcdNumber_rawdamage->display((BaseDamage_COMPOUND_BOW_STONE_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100));
        } else { //tranq arrow
            ui->lcdNumber_rawdamage->display((BaseDamage_COMPOUND_BOW_TRANQ_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100));
            tmp = (BaseTorpor_COMPOUND_BOW_TRANQ_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100);
            ui->lcdNumber_InstantTorpor->display(tmp);
            tmp2 = (DotTorpor_COMPOUND_BOW_TRANQ_ARROW) * (ui->doubleSpinBox_damagepercent->value() / 100);
            ui->lcdNumber_TorporOverTime->display(tmp2);
            ui->lcdNumber_TotalTorpor->display(tmp + tmp2);
        }
        break;
    case 14:
        ui->lcdNumber_rawdamage->display((BaseDamage_SIMPLE_PISTOL) * (ui->doubleSpinBox_damagepercent->value() / 100));
        break;
    case 15:
        if (ui->radioButton_ammo1->isChecked()) { //simple rifle ammo
            ui->lcdNumber_rawdamage->display((BaseDamage_LONGNECK_RIFLE) * (ui->doubleSpinBox_damagepercent->value() / 100));
        } else { //dart
            tmp = (BaseDamage_LONGNECK_RIFLE_DART) * (ui->doubleSpinBox_damagepercent->value() / 100);
            ui->lcdNumber_rawdamage->display(tmp);
            tmp2 = (tmp * 6);
            ui->lcdNumber_InstantTorpor->display(tmp2);
            tmp3 = (tmp * 2.5);
            ui->lcdNumber_TorporOverTime->display(tmp3);
            ui->lcdNumber_TotalTorpor->display(tmp2 + tmp3);

        }
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
    if (ui->doubleSpinBox_damagepercent->value() != 100) {
        ui->doubleSpinBox_damagepercent->setValue(100.00);
    }
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
        ui->radioButton_ammo1->setText("Stone");
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

    switch (index) {
    case 0:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Stone_Pick.png"));
        wikilink = arkWiki_Stone_Pick;
        break;
    case 1:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Stone_Hatchet.png"));
        wikilink = arkWiki_Stone_Hatchet;
        break;
    case 2:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Torch.png"));
        wikilink = arkWiki_Torch;
        break;
    case 3:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Metal_Pick.png"));
        wikilink = arkWiki_Metal_Pick;
        break;
    case 4:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Metal_Hatchet.png"));
        wikilink = arkWiki_Metal_Hatchet;
        break;
    case 5:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Metal_Sickle.png"));
        wikilink = arkWiki_Metal_Sickle;
        break;
    case 6:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Pike.png"));
        wikilink = arkWiki_Pike;
        break;
    case 7:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Wooden_Club.png"));
        wikilink = arkWiki_Wooden_Club;
        break;
    case 8:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Metal_Sword.png"));
        wikilink = arkWiki_Metal_Sword;
        break;
    case 9:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Electric_Prod.png"));
        wikilink = arkWiki_Electric_Prod;
        break;
    case 10:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Slingshot.png"));
        wikilink = arkWiki_Slingshot;
        break;
    case 11:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Bow.png"));
        wikilink = arkWiki_Bow;
        break;
    case 12:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Crossbow.png"));
        wikilink = arkWiki_Crossbow;
        break;
    case 13:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Compound_Bow.png"));
        wikilink = arkWiki_Compound_Bow;
        break;
    case 14:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Simple_Pistol.png"));
        wikilink = arkWiki_Simple_Pistol;
        break;
    case 15:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Longneck_Rifle.png"));
        wikilink = arkWiki_Longneck_Rifle;
        break;
    case 16:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Shotgun.png"));
        wikilink = arkWiki_Shotgun;
        break;
    case 17:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Fabricated_Pistol.png"));
        wikilink = arkWiki_Fabricated_Pistol;
        break;
    case 18:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Pump-Action_Shotgun.png"));
        wikilink = arkWiki_Pump_Action_Shotgun;
        break;
    case 19:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Assault_Rifle.png"));
        wikilink = arkWiki_Assault_Rifle;
        break;
    case 20:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Fabricated_Sniper_Rifle.png"));
        wikilink = arkWiki_Fabricated_Sniper_Rifle;
        break;
    case 21:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Rocket_Launcher.png"));
        wikilink = arkWiki_Rocket_Launcher;
        break;
    default:
        ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/default.png"));
        wikilink = arkWiki_Default;
        break;
    }
}

void MainWindow::on_pushButton_webLink_released()
{
    QDesktopServices::openUrl(wikilink);
}
