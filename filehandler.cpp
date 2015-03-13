#include "filehandler.h"

QFile dataFile;
QFile rootFile;
QFile numberFile;

QTextStream stdoutlog(stdout);
QTextStream dataStream(&dataFile);
QTextStream rootStream(&rootFile);
QTextStream numberStream(&numberFile);

QString appDataPath = "";

fileHandler::fileHandler(QString appData){

	appDataPath = appData;
	QDir dir(appDataPath);
	dir.mkpath(dir.absolutePath());
	rootFile.setFileName(appDataPath+"/root.cfg");
	if(!rootFile.exists()){
		rootFile.open(QIODevice::WriteOnly|QIODevice::Text);
		rootStream << "";
		rootStream.flush();
		rootFile.close();
	}

	numberFile.setFileName(appDataPath+"/number.cfg");
	if(!numberFile.exists()){
		numberFile.open(QIODevice::WriteOnly|QIODevice::Text);
		numberStream << "0";
		numberStream.flush();
		numberFile.close();
	}


}

fileHandler::~fileHandler(){

}
void fileHandler::writeData(std::vector<QString> data){
	if(!dataFile.isOpen()){
		dataFile.setFileName(getRoot()+"/"+getUUID()+".csv");
		dataFile.open(QIODevice::Append|QIODevice::Text);
	}

	for (QString s : data){
		dataStream << s+",";
	}

	dataStream << "\n";
	dataStream.flush();
}

QString fileHandler::getUUID(){
	numberFile.open(QIODevice::ReadOnly|QIODevice::Text);
	QString uuid = numberStream.readAll();
	numberFile.close();
	return uuid;
}

QString fileHandler::getRoot(){
	rootFile.open(QIODevice::ReadOnly|QIODevice::Text);
	QString rootPath = rootStream.readAll();
	rootFile.close();
	return rootPath;
}

void fileHandler::writeUUID(QString UUID){
	dataFile.close();
	numberFile.open(QIODevice::WriteOnly|QIODevice::Text);
	numberStream<<UUID;
	numberStream.flush();
	numberFile.close();
}

void fileHandler::writeRoot(QString rootPath){
	rootFile.open(QIODevice::WriteOnly|QIODevice::Text);
	rootStream<<rootPath;
	rootStream.flush();
	rootFile.close();
}

void fileHandler::consoleLog(QString text){
	stdoutlog << "\n"+text;
	stdoutlog.flush();
}
