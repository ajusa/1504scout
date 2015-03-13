#include "mainwindow.h"
#include "ui_mainwindow.h"

//QString rootCopy = "C:/Users/vargascalderonn15/Documents/fakerootCopy/";
//QString rootCopy;
//QString UUIDCopy;
QString comments;
//fileHandler * handler;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

	ui->setupUi(this);
	chooseLocation c(this);
	data::handler->consoleLog(data::handler->getUUID()+","+data::handler->getRoot());
	if(data::handler->getUUID()=="0"||data::handler->getRoot() == ""){
		c.show();

		if(c.exec()==1){
			close();
		}
	}
	if(data::handler->getUUID()=="0"||data::handler->getRoot() == ""){
		close();
	}
	ui->scoutNumber->setValue(data::handler->getUUID().toInt());
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

	ui->binHeightLabel->setEnabled(true);
	ui->binLevel->setEnabled(true);
	ui->binStepLabel->setEnabled(true);
	ui->binHeightLabel->setEnabled(true);
	ui->stepYes->setEnabled(true);\
	ui->stepNo->setEnabled(true);
}


void MainWindow::on_binGrabNo_clicked()
{
	binGrab = "No";

	ui->binHeightLabel->setEnabled(false);
	ui->binLevel->setEnabled(false);
	ui->binLevel->clear();
	ui->binHeightLabel->setEnabled(false);
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
	ui->toteLevelLabel->setEnabled(true);
	toteStacking = "Yes";
}


void MainWindow::on_toteStackNo_clicked()
{
	ui->toteLevel->setEnabled(false);
	ui->toteLevelLabel->setEnabled(false);
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

void MainWindow::on_scoutNumber_valueChanged(const QString arg1)
{
	data::handler->writeUUID(arg1);
}

void MainWindow::on_save_clicked()
{
	std::vector<QString> info({
				teamNum,
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
				landRekt,
				comments});

	data::handler->writeData(info);
	ui->saveFeedback->setHtml("<html><body><b>Data for team "+teamNum+" saved.</b></body></html>");

	std::vector<QRadioButton*> radios(
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
	 ui->customLift,
	 ui->toteStackNo,
	 ui->toteStackYes,
	 ui->red,
	 ui->blue});
	for (QRadioButton* radio : radios){
		radio->setAutoExclusive(false);
		radio->setChecked(false);
		radio->setAutoExclusive(true);
	}
	this->on_toteStackNo_clicked();
	this->on_binGrabNo_clicked();
	this->on_Mecanum_clicked();

	std::vector<QString*> vars({
								  &teamNum,
								  &matchNum,
								  &teamAlliance,
								  &driveType,
								  &liftType,
								  &toteStacking,
								  &lvlTotes,
								  &binGrab,
								  &fromStep,
								  &binLvl,
								  &noodleGrab,
								  &landRekt});

		for(QString * var : vars)
		{
			*var = "";
		}
}

void MainWindow::on_toteLevel_valueChanged(const QString &arg1)
{
	lvlTotes = arg1;
	ui->toteStackYes->click();
}


void MainWindow::on_liftText_textChanged(const QString arg1)
{
	ui->customLift->click();
	driveType = arg1;
}

void MainWindow::set()
{
	return;
}
