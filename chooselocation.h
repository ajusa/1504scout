#ifndef CHOOSELOCATION_H
#define CHOOSELOCATION_H

#include "namespaces.h"
#include <QAbstractButton>
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

protected:
	void check();
private slots:
	void on_rootButton_clicked();

	void on_numberBox_valueChanged(const QString arg1);

	void on_OKButton_clicked();

	void on_resetButton_clicked();

private:
	Ui::chooseLocation *ui;
};

#endif // CHOOSELOCATION_H
