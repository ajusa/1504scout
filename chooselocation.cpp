#include "chooselocation.h"
#include "ui_chooselocation.h"
#include <QFileDialog>
QString UUID,root;

chooseLocation::chooseLocation(QWidget *parent) : QDialog(parent), ui(new Ui::chooseLocation)

{
	ui->setupUi(this);
	UUID=data::handler->getUUID();
	root=data::handler->getRoot();
	ui->numberBox->setValue(UUID.toInt());
	check();
}

chooseLocation::~chooseLocation(){
	delete ui;
}

void chooseLocation::check(){
	if(root==""){
		ui->OKButton->setEnabled(false);
		ui->rootButton->setText("Set Data Location");
		ui->readyLabel->setVisible(false);
	}
	else {
		ui->OKButton->setEnabled(true);
		ui->rootButton->setText("Data: "+root);
		ui->readyLabel->setVisible(true);
	}
	if(UUID=="0"){
		ui->OKButton->setEnabled(false);
		ui->readyLabel->setVisible(false);
	}else{

	}
}
void chooseLocation::on_rootButton_clicked()
{
	root = QFileDialog::getExistingDirectory(this,"Choose folder","/",QFileDialog::ShowDirsOnly);
	check();
}


void chooseLocation::on_numberBox_valueChanged(const QString arg1)
{
	if(arg1=="Unset")
	UUID="0";
	else UUID = arg1;
	check();
}

void chooseLocation::on_OKButton_clicked()
{
	data::handler->writeRoot(root);
	data::handler->writeUUID(UUID);
	close();
}

void chooseLocation::on_resetButton_clicked()
{
	root="";
	ui->numberBox->setValue(0);
	check();
}
