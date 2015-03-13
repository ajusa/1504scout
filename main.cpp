#include "main.h"

namespace data {
fileHandler * handler = 0;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setApplicationName("1504Scouting");

	fileHandler realHandler(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
	data::handler = &realHandler;

	MainWindow w;
	w.show();

	return a.exec();
}
//There are some deaths worse than death.
