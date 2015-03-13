#include "main.h"

namespace data {
fileHandler * handler = 0;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setApplicationName("1504Scouting");
	//fileHandler handler((QString)QStandardPaths::AppDataLocation);

	fileHandler realHandler(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
	data::handler = &realHandler;
	data::handler->consoleLog("Appdata:"+QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
	MainWindow w;
	//MainWindow w(0,&handler);
	w.show();

	return a.exec();
}
//There are some deaths worse than death.
