#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QFile>
#include <QStandardPaths>
#include <QTextStream>
#include "chooselocation.h"
#include "namespaces.h"
//#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

	Q_OBJECT

public:
		//chooseLocation c;
		QString teamNum;
		QString matchNum;
		QString teamAlliance;
		QString driveType;
		QString liftType;
		QString toteStacking;
		QString lvlTotes;
		QString binGrab;
		QString fromStep;
		QString binLvl;
		QFile myFile;
		QString noodleGrab;
		QString landRekt;


	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void set();

private slots:
	void on_teamForm_textChanged(const QString &arg1);

	void on_matchForm_textChanged(const QString &arg1);

	void on_commentsBox_textChanged();

	void on_blue_clicked();

	void on_red_clicked();

	void on_forklift_clicked();

	void on_conveyor_clicked();

	void on_binGrabYes_clicked();

	void on_binGrabNo_clicked();

	void on_binLevel_textChanged(const QString &arg1);

	void on_stepYes_clicked();

	void on_stepNo_clicked();

	void on_Mecanum_clicked();

	void on_Tank_clicked();

	void on_tankWheels_currentTextChanged(const QString &arg1);

	void on_toteStackYes_clicked();

	void on_toteStackNo_clicked();

	void on_landfillYes_clicked();

	void on_landfillNo_clicked();

	void on_noodleGrabYes_clicked();

	void on_noodleGrabNo_clicked();

	void on_scoutNumber_valueChanged(const QString arg1);

	void on_save_clicked();

	void on_toteLevel_valueChanged(const QString &arg1);

	void on_liftText_textChanged(const QString arg1);

private:
	Ui::MainWindow *ui;
	//fileHandler * handler;
};

#endif // MAINWINDOW_H
