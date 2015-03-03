#include "chooselocation.h"
#include "ui_chooselocation.h"

chooseLocation::chooseLocation(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::chooseLocation)
{
	ui->setupUi(this);
}

chooseLocation::~chooseLocation()
{
	delete ui;
}
