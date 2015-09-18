#include <QApplication>
#include <QFileDialog>
#include <QDebug>

int main( int argc, char *argv[] )
{
	QApplication appMain(argc, argv);

	QString filtersList;
	filtersList += "My File Type(*.mft);;";
	filtersList += "All Files (*.*);;";
	QString defaultFile( "mypath/new_file.mft");
	QString selectedFilter; 
	// selectedFilter = "My File Type(*.mft);;";	// no segmentation fault
#ifdef __APPLE__
    qDebug() << "apple" ;
#endif
	QString selectedFile =	QFileDialog::getSaveFileName(
							NULL,
							"Save File Dialog",
							defaultFile,
                            filtersList,new QString("My File Type(*.mft);;"));

    qDebug() << selectedFile;

	return appMain.exec();
}
