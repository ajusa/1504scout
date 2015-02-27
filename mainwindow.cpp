#include "mainwindow.h"
#include "ui_mainwindow.h"
QString root = "C:/Users/Arham/Documents/fakeRoot/";
QFile file;
QFile config("number.cfg");
QString UUID;
QString comments;
QTextStream configStream(&config);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    if (!config.open(QIODevice::ReadOnly | QIODevice::Text))
             return;
    UUID = configStream.readAll();
    int UUIDInt = UUID.toInt();
    file.setFileName(root + UUID + ".csv");
    config.close();
    ui->setupUi(this);
    ui->scoutNumber->setValue(UUIDInt);
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_teamForm_textChanged(const QString &arg1)
{
teamNum = arg1;
}

void MainWindow::on_matchForm_textChanged(const QString &arg1)
{
   matchNum = arg1;
}

void MainWindow::on_commentsBox_textChanged()
{
comments = "\""+ui->commentsBox->toPlainText()+"\"";
}

void MainWindow::on_blue_clicked()
{
teamAlliance = "Blue Alliance";
}


void MainWindow::on_red_clicked()
{
    teamAlliance = "Red Alliance";
}

void MainWindow::on_forklift_clicked()
{
liftType = "Forklift";
}

void MainWindow::on_conveyor_clicked()
{
    liftType = "Conveyor";
}

void MainWindow::on_binGrabYes_clicked()
{
    binGrab = "Yes";
    ui->label_7->setEnabled(true);
    ui->binLevel->setEnabled(true);
    ui->label_8->setEnabled(true);
    ui->stepYes->setEnabled(true);\
    ui->stepNo->setEnabled(true);
}


void MainWindow::on_binGrabNo_clicked()
{
    binGrab = "No";
    ui->label_7->setEnabled(false);
    ui->binLevel->setEnabled(false);
    ui->binLevel->clear();
    ui->label_8->setEnabled(false);
    ui->stepYes->setEnabled(false);\
    ui->stepNo->setEnabled(false);
}


void MainWindow::on_binLevel_textChanged(const QString &arg1)
{
binLvl=arg1;
}

void MainWindow::on_stepYes_clicked()
{
    fromStep = "Yes";
}

void MainWindow::on_stepNo_clicked()
{

    fromStep = "No";
}


void MainWindow::on_Mecanum_clicked()
{
    ui->tankWheels->setEnabled(false);
    ui->tankWheels->setCurrentIndex(0);
    driveType = "Mecanum";
}


void MainWindow::on_Tank_clicked()
{
    ui->tankWheels->setEnabled(true);
    driveType = "Tank";
}


void MainWindow::on_tankWheels_currentTextChanged(const QString &arg1)
{
driveType = arg1;
}

void MainWindow::on_toteStackYes_clicked()
{
    ui->toteLevel->setEnabled(true);
    ui->label_6->setEnabled(true);
    toteStacking = "Yes";
}


void MainWindow::on_toteStackNo_clicked()
{
    ui->toteLevel->setEnabled(false);
    ui->label_6->setEnabled(false);
    ui->toteLevel->clear();
    toteStacking = "No";
}

void MainWindow::on_landfillYes_clicked()
{
landRekt = "Yes";
}


void MainWindow::on_landfillNo_clicked()
{
    landRekt = "No";
}


void MainWindow::on_noodleGrabYes_clicked()
{
noodleGrab = "Yes";
}

void MainWindow::on_noodleGrabNo_clicked()
{
    noodleGrab = "No";
}

void MainWindow::on_scoutNumber_valueChanged(const QString &arg1)
{
    if (!config.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    configStream << arg1;
    config.close();
}

void MainWindow::on_save_clicked()
{
    QTextStream out(&file);
    /*if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;
    QString line = out.readAll();
    file.close();*/
        if (!file.open(QIODevice::Append | QIODevice::Text))
            return;


        out << /*line <<*/ teamNum << "," << matchNum << ","
        << teamAlliance << ","
        << driveType << ","
        << liftType << ","
        << toteStacking << ","
        << lvlTotes << ","
        << binGrab << ","
        << fromStep << ","
        << binLvl << ","
        << noodleGrab << ","
        << landRekt << ","
        << comments <<  "\n";
        file.close();
        ui->saveFeedback->setHtml("<html><body><b>Data for team "+teamNum+" saved.</b></body></html>");

        /*QRadioButton* radios[3];
        radios[0]=ui->binGrabNo;
        radios[1]=ui->binGrabYes;
        radios[2]=ui->toteStackNo;*/
        QRadioButton* radios[] =
        {ui->binGrabNo,
         ui->binGrabYes,
         ui->landfillNo,
         ui->landfillYes,
         ui->conveyor,
         ui->forklift,
         ui->Mecanum,
         ui->noodleGrabNo,
         ui->noodleGrabYes,
         ui->stepNo,
         ui->stepYes,
         ui->Tank,
         ui->toteStackNo,
         ui->toteStackYes,
         ui->red,
         ui->blue};
        for (int i=0; i < 16 ; i++){
            radios[i]->setAutoExclusive(false);
            radios[i]->setChecked(false);
            radios[i]->setAutoExclusive(true);
        }
        this->on_toteStackNo_clicked();
        this->on_binGrabNo_clicked();
        this->on_Mecanum_clicked();

        QString vars[] =
        {teamNum,
         matchNum,
         teamAlliance,
         driveType,
         liftType,
         toteStacking,
         lvlTotes,
         binGrab,
         fromStep,
         binLvl,
         noodleGrab,
         landRekt};

        for(int i=0; i < 12; i++)
        {
            vars[i] = "";
        }

        /*this->close();
        this->show();*/
}

void MainWindow::on_toteLevel_valueChanged(const QString &arg1)
{
    lvlTotes = arg1;
    ui->toteStackYes->click();
}
