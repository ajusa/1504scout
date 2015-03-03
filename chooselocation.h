#ifndef CHOOSELOCATION_H
#define CHOOSELOCATION_H

#include <QDialog>

namespace Ui {
class chooseLocation;
}

class chooseLocation : public QDialog
{
	Q_OBJECT

public:
	explicit chooseLocation(QWidget *parent = 0);
	~chooseLocation();

private:
	Ui::chooseLocation *ui;
};

#endif // CHOOSELOCATION_H
