#ifndef FILEHANDLER
#define FILEHANDLER

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>

class fileHandler{
public:
	fileHandler(QString appData);
	~fileHandler();
	QString getUUID();
	QString getRoot();
	void writeUUID(QString UUID);
	void writeRoot(QString root);
	void consoleLog(QString text);
	void writeData(std::vector<QString> data);
};
#endif // FILEHANDLER

