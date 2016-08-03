#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "defaultweapondamage.h"
#include <QIcon>
#include "weaponurls.h"
#include <QDesktopServices>
#include "defaultdinodamage.h"
#include "dinourls.h"
#include <QtMath>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setWindowIcon(QIcon(":/taskbar/arkdc.ico"));
    ui->pushButton_webLink->setIcon(QIcon(":/weapons/weapons-icons/Stone_Pick.png"));
    ui->pushButton_webLink->setIconSize(QSize(248,248));
    ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Allosaurus.png"));
    ui->pushButton_webLink_2->setIconSize(QSize(248,248));
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*SECTION 1 DAMAGES */

//WEAPON DAMAGE

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
    switch (index) {  //switches ammo radio buttons
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

    switch (index) {  //updates web link to currently selected weapon
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

//DINOSAUR DAMAGE

void MainWindow::on_pushButton_2_released()
{
    //reset lcds
    ui->lcdNumber_rawdamage_2->display(0);
    ui->lcdNumber_InstantTorpor_2->display(0);
    ui->lcdNumber_TorporOverTime_2->display(0);
    ui->lcdNumber_TotalTorpor_2->display(0);

    switch (ui->comboBox_Dinosaur->currentIndex()) {
    case 0:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_ALLOSAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 1:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_ANGLER) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 2:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_ANKYLOSAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 3:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_ARANEO) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 4:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_ARGENTAVIS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 5:
        (ui->radioButton_ammo1_2->isChecked()) ? ui->lcdNumber_rawdamage_2->display((BaseDamage_ARTHROPLUERA) * (ui->doubleSpinBox_damagepercent_2->value() / 100))
                                               :  ui->lcdNumber_rawdamage_2->display((BaseDamage_ARTHROPLUERA_altFire) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 6:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_BEELZEBUFO) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        ui->lcdNumber_TorporOverTime_2->display(((BaseDamage_BEELZEBUFO) * (ui->doubleSpinBox_damagepercent_2->value() / 100))*3);
        ui->lcdNumber_TotalTorpor_2->display(((BaseDamage_BEELZEBUFO) * (ui->doubleSpinBox_damagepercent_2->value() / 100))*3);
        break;
    case 7:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_BRONTOSAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 8:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_CARBONEMYS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 9:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_CARNOTAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 10:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_CASTOROIDES) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 11:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_COMPY) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 12:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_DILOPHOSAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 13:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_DIMETRODON) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 14:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_DIMORPHODON) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 15:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_DIPLODOCUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 16:
        (ui->radioButton_ammo1_2->isChecked()) ? ui->lcdNumber_rawdamage_2->display((BaseDamage_DIREBEAR) * (ui->doubleSpinBox_damagepercent_2->value() / 100))
                                               : ui->lcdNumber_rawdamage_2->display((BaseDamage_DIREBEAR_altFire) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 17:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_DIREWOLF) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 18:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_DODO) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 19:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_DOEDICURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 20:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_DUNGBEETLE) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 21:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_DUNKLEOSTEUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 22:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_GALLIMIMUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 23:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_GIGANTOPITHECUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 24:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_GIGANTOSAURUS_tamed) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 25:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_ICHTHYOSAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 26:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_KAIRUKU) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 27:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_LYSTROSAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 28:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_MAMMOTH) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 29:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_MANTA) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 30:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_MEGALOCEROS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 31:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_MEGALODON) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 32:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_MESOPITHECUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 33:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_MOSASAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 34:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_ONYC) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 35:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_OVIRAPTOR) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 36:
        if (ui->radioButton_ammo1_2->isChecked()) {
            ui->lcdNumber_rawdamage_2->display((BaseDamage_PACHY) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
            ui->lcdNumber_TorporOverTime_2->display(((BaseDamage_PACHY) * (ui->doubleSpinBox_damagepercent_2->value() / 100)));
            ui->lcdNumber_TotalTorpor_2->display(((BaseDamage_PACHY) * (ui->doubleSpinBox_damagepercent_2->value() / 100)));
       } else {
            ui->lcdNumber_rawdamage_2->display((BaseDamage_PACHY_charge) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
            ui->lcdNumber_TorporOverTime_2->display(((BaseDamage_PACHY_charge) * (ui->doubleSpinBox_damagepercent_2->value() / 100))*3.5);
            ui->lcdNumber_TotalTorpor_2->display(((BaseDamage_PACHY_charge) * (ui->doubleSpinBox_damagepercent_2->value() / 100))*3.5);
        }
        break;
    case 37:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_PARACERATHERIUM) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 38:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_PARASAUR) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 39:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_PELAGORNIS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 40:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_PHIOMIA) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 41:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_PLESIOSAUR) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 42:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_PROCOPTODON) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 43:
        (ui->radioButton_ammo1_2->isChecked()) ? ui->lcdNumber_rawdamage_2->display((BaseDamage_PTERANODON) * (ui->doubleSpinBox_damagepercent_2->value() / 100))
                                               : ui->lcdNumber_rawdamage_2->display((BaseDamage_PTERANODON_rollAttack) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 44:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_PULMONOSCORPIUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        ui->lcdNumber_TorporOverTime_2->display(((BaseDamage_PULMONOSCORPIUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100))*3);
        ui->lcdNumber_TotalTorpor_2->display(((BaseDamage_PULMONOSCORPIUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100))*3);
        break;
    case 45:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_QUETZAL) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 46:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_RAPTOR) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 47:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_SABERTOOTH) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 48:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_SARCO) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 49:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_SPINOSAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 50:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_STEGOSAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 51:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_TERRORBIRD) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 52:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_TITANOSAUR) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 53:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_TRICERATOPS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 54:
        ui->lcdNumber_rawdamage_2->display((BaseDamage_TYRANNOSAURUS) * (ui->doubleSpinBox_damagepercent_2->value() / 100));
        break;
    case 55:
        (ui->radioButton_ammo1_2->isChecked()) ? ui->lcdNumber_rawdamage_2->display((BaseDamage_WOOLLYRHINO) * (ui->doubleSpinBox_damagepercent_2->value() / 100))
            : ui->lcdNumber_rawdamage_2->display(((BaseDamage_WOOLLYRHINO) * (ui->doubleSpinBox_damagepercent_2->value() / 100))*12.5);
        break;
    default:
        break;
    }
}

void MainWindow::on_comboBox_Dinosaur_currentIndexChanged(int index)
{
    if (ui->doubleSpinBox_damagepercent_2->value() != 100) {
        ui->doubleSpinBox_damagepercent_2->setValue(100.00);
    }
    switch (index) {
    case 5:
    case 16:
        ui->radioButton_ammo1_2->setText("Attack1");
        ui->radioButton_ammo2_2->setText("Attack2");
        ui->radioButton_ammo1_2->setEnabled(true);
        ui->radioButton_ammo2_2->setEnabled(true);
        ui->radioButton_ammo1_2->setChecked(true);
        break;
    case 36:
    case 55:
        ui->radioButton_ammo1_2->setText("Attack1");
        ui->radioButton_ammo2_2->setText("Charge");
        ui->radioButton_ammo1_2->setEnabled(true);
        ui->radioButton_ammo2_2->setEnabled(true);
        ui->radioButton_ammo1_2->setChecked(true);
        break;
    case 43:
        ui->radioButton_ammo1_2->setText("Attack1");
        ui->radioButton_ammo2_2->setText("Roll");
        ui->radioButton_ammo1_2->setEnabled(true);
        ui->radioButton_ammo2_2->setEnabled(true);
        ui->radioButton_ammo1_2->setChecked(true);
        break;
    default:
        ui->radioButton_ammo1_2->setText("Attack1");
        ui->radioButton_ammo2_2->setText("Attack2");
        ui->radioButton_ammo1_2->setEnabled(true);
        ui->radioButton_ammo2_2->setEnabled(false);
        ui->radioButton_ammo1_2->setChecked(true);
        break;
    }

    switch (index) {
    case 0:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Allosaurus.png"));
        wikilink_2 = arkWiki_ALLOSAURUS;
        break;
    case 1:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Angler.png"));
        wikilink_2 = arkWiki_ANGLER;
        break;
    case 2:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Ankylosaurus.png"));
        wikilink_2 = arkWiki_ANKYLOSAURUS;
        break;
    case 3:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Araneo.png"));
        wikilink_2 = arkWiki_ARANEO;
        break;
    case 4:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Argentavis.png"));
        wikilink_2 = arkWiki_ARGENTAVIS;
        break;
    case 5:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Arthropluera.png"));
        wikilink_2 = arkWiki_ARTHROPLUERA;
        break;
    case 6:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Beelzebufo.png"));
        wikilink_2 = arkWiki_BEELZEBUFO;
        break;
    case 7:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Brontosaurus.png"));
        wikilink_2 = arkWiki_BRONTOSAURUS;
        break;
    case 8:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Carbonemys.png"));
        wikilink_2 = arkWiki_CARBONEMYS;
        break;
    case 9:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Carnotaurus.png"));
        wikilink_2 = arkWiki_CARNOTAURUS;
        break;
    case 10:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Castoroides.png"));
        wikilink_2 = arkWiki_CASTOROIDES;
        break;
    case 11:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Compy.png"));
        wikilink_2 = arkWiki_COMPY;
        break;
    case 12:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Dilophosaurus.png"));
        wikilink_2 = arkWiki_DILOPHOSAURUS;
        break;
    case 13:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Dimetrodon.png"));
        wikilink_2 = arkWiki_DIMETRODON;
        break;
    case 14:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Dimorphodon.png"));
        wikilink_2 = arkWiki_DIMORPHODON;
        break;
    case 15:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Diplodocus.png"));
        wikilink_2 = arkWiki_DIPLODOCUS;
        break;
    case 16:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Direbear.png"));
        wikilink_2 = arkWiki_DIREBEAR;
        break;
    case 17:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Direwolf.png"));
        wikilink_2 = arkWiki_DIREWOLF;
        break;
    case 18:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Dodo.png"));
        wikilink_2 = arkWiki_DODO;
        break;
    case 19:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Doedicurus.png"));
        wikilink_2 = arkWiki_DOEDICURUS;
        break;
    case 20:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/DungBeetle.png"));
        wikilink_2 = arkWiki_DUNGBEETLE;
        break;
    case 21:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Dunkleosteus.png"));
        wikilink_2 = arkWiki_DUNKLEOSTEUS;
        break;
    case 22:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Gallimimus.png"));
        wikilink_2 = arkWiki_GALLIMIMUS;
        break;
    case 23:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Gigantopithecus.png"));
        wikilink_2 = arkWiki_GIGANTOPITHECUS;
        break;
    case 24:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Gigantosaurus.png"));
        wikilink_2 = arkWiki_GIGANTOSAURUS;
        break;
    case 25:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Ichthy.png"));
        wikilink_2 = arkWiki_ICHTHYOSAURUS;
        break;
    case 26:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Kairuku.png"));
        wikilink_2 = arkWiki_KAIRUKU;
        break;
    case 27:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Lystrosaurus.png"));
        wikilink_2 = arkWiki_LYSTROSAURUS;
        break;
    case 28:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Mammoth.png"));
        wikilink_2 = arkWiki_MAMMOTH;
        break;
    case 29:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Manta.png"));
        wikilink_2 = arkWiki_MANTA;
        break;
    case 30:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Megaloceros.png"));
        wikilink_2 = arkWiki_MEGALOCEROS;
        break;
    case 31:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Megalodon.png"));
        wikilink_2 = arkWiki_MEGALODON;
        break;
    case 32:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Mesopithecus.png"));
        wikilink_2 = arkWiki_MESOPITHECUS;
        break;
    case 33:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Mosasaurus.png"));
        wikilink_2 = arkWiki_MOSASAURUS;
        break;
    case 34:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Onyc.png"));
        wikilink_2 = arkWiki_ONYC;
        break;
    case 35:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Oviraptor.png"));
        wikilink_2 = arkWiki_OVIRAPTOR;
        break;
    case 36:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Pachy.png"));
        wikilink_2 = arkWiki_PACHY;
        break;
    case 37:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Paraceratherium.png"));
        wikilink_2 = arkWiki_PARACERATHERIUM;
        break;
    case 38:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Parasaur.png"));
        wikilink_2 = arkWiki_PARASAUR;
        break;
    case 39:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Pelagornis.png"));
        wikilink_2 = arkWiki_PELAGORNIS;
        break;
    case 40:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Phiomia.png"));
        wikilink_2 = arkWiki_PHIOMIA;
        break;
    case 41:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Plesiosaur.png"));
        wikilink_2 = arkWiki_PLESIOSAUR;
        break;
    case 42:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Procoptodon.png"));
        wikilink_2 = arkWiki_PROCOPTODON;
        break;
    case 43:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Pterosaur.png"));
        wikilink_2 = arkWiki_PTERANODON;
        break;
    case 44:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Pulmonoscorpius.png"));
        wikilink_2 = arkWiki_PULMONOSCORPIUS;
        break;
    case 45:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Quetzal.png"));
        wikilink_2 = arkWiki_QUETZAL;
        break;
    case 46:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Raptor.png"));
        wikilink_2 = arkWiki_RAPTOR;
        break;
    case 47:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Sabertooth.png"));
        wikilink_2 = arkWiki_SABERTOOTH;
        break;
    case 48:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Sarcosaurus.png"));
        wikilink_2 = arkWiki_SARCO;
        break;
    case 49:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Spino.png"));
        wikilink_2 = arkWiki_SPINOSAURUS;
        break;
    case 50:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Stegosaurus.png"));
        wikilink_2 = arkWiki_STEGOSAURUS;
        break;
    case 51:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/TerrorBird.png"));
        wikilink_2 = arkWiki_TERRORBIRD;
        break;
    case 52:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Titanosaur.png"));
        wikilink_2 = arkWiki_TITANOSAUR;
        break;
    case 53:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Triceratops.png"));
        wikilink_2 = arkWiki_TRICERATOPS;
        break;
    case 54:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/Trex.png"));
        wikilink_2 = arkWiki_TYRANNOSAURUS;
        break;
    case 55:
        ui->pushButton_webLink_2->setIcon(QIcon(":/dinos/dinos-icons/WoollyRhino.png"));
        wikilink_2 = arkWiki_WOOLLYRHINO;
        break;
    default:

        break;
    }
}

void MainWindow::on_pushButton_webLink_2_released()
{
    QDesktopServices::openUrl(wikilink_2);
}

/*SECTION 2 OTHER TOOLS */


void MainWindow::on_pushButton_forgecalc_released()
{
    int thatch(0), wood(0), sparkpowder(0), angler_gel(0);
    int cooktime(0);  //in seconds
    int metalingots(0);

    //figure out number of metal ingots will be made and even it out so the calculation runs correctly.
    ((ui->spinBox_metal->value() % 2) == 1) ? metalingots = (ui->spinBox_metal->value()-1) : metalingots = ui->spinBox_metal->value();

    cooktime = metalingots * 20;  //20 seconds per ingot

    //figure out how much thatch would be needed
    thatch = qCeil(cooktime / 7);

    //figure out how much wood would be needed
    wood = qCeil(cooktime / 30);

    //figure out how much sparkpowder would be needed
    sparkpowder = qCeil(cooktime / 60);

    //figure out how much angler gel would be needed
    angler_gel = qCeil(cooktime / 240);

    //display the results
    int tempHours = qFloor(cooktime / 3600);
    if (tempHours > 0) {cooktime = cooktime - (tempHours*3600);}
    (tempHours > 0) ? ui->textBrowser_forgeResults->setText("Time to Cook: " + QString::number(tempHours) + "h" +
                                                            QString::number(cooktime / 60) + "m" + QString::number(cooktime%60) + "s\n")
                    : ui->textBrowser_forgeResults->setText("Time to Cook: " + QString::number(cooktime / 60) + "m" + QString::number(cooktime%60) + "s\n");
     ui->textBrowser_forgeResults->append("This Will Require: \n  ->" + QString::number(thatch) + "  Thatch  -or-");
     ui->textBrowser_forgeResults->append("  ->" + QString::number(wood) + "  Wood  -or-");
     ui->textBrowser_forgeResults->append("  ->" + QString::number(sparkpowder) + "  Sparkpowder  -or-");
     ui->textBrowser_forgeResults->append("  ->" + QString::number(angler_gel) + "  Angler Gel");




}
