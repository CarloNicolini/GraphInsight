/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#include <QtGui/QApplication>
#include "MainWindow.h"
#include "Common.h"
#include "QUtils.h"
#include "LicenseType.h"
#include "SplashDialog.h"

#ifdef USE_PYTHONQT
#include "PythonQt.h"
#include "gui/PythonQtScriptingConsole.h"
#include "MainWindowDecorator.h"
#include "PythonQtObjectPtr.h"
#include "ConnectionHelper.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate date = QDate::currentDate();
    QSettings settings;

        /*
   SplashDialog splash;
   splash.setWindowFlags(Qt::WindowStaysOnTopHint);
   // Only for professional license, is possible to avoid the splash screen, by clicking
   if ( LicenseType!=ProfessionalLicense )
   {  // For licenses other than professional, the SkipOnStartup checkbox is not enabled
      splash.setSkipOnStartupVisible(false);
      splash.exec();
      splash.setWindowFlags(Qt::WindowStaysOnTopHint);
      initialFile = splash.getSelectedExample();
   }
   else    // for professional license...
   {  splash.setSkipOnStartupVisible(true);
      if ( !settings.value("SkipOnStartup").toBool())
      {  splash.exec();
         initialFile = splash.getSelectedExample();
      }
      else
      {  settings.setValue("SkipOnStartup",splash.getIfSkipOnStartup());
      }
   }

   // Exit if the user made some stupid action, like quitting the splash
   if (splash.getSelectedExample()==QString("quit"))   // the string "quit" is the default one in SplashDialog
   {  exit(0);
   }
   */
        // Now set the expiration times of the software based on the current license
        QDialog licenseExpirationDialog;

    switch ( LicenseType )
    {  case TrialLicense: //Trial
    {  if(date.year() >= 2014 && date.month() >= 11 && date.day() >= 10 )
        {
            QMessageBox::warning( &licenseExpirationDialog,  "Error",  "This product license has expired, contact us to obtain a new license\ninfo@graphinsight.com" );
            QDesktopServices::openUrl(QUrl("http://www.graphinsight.com/download"));
            return 0;
        }
    }
        break;
    case AcademicLicense: //Academic
    {  if(date.year() >= 2014 && date.month() >= 11 && date.day() >= 10 )
        {
            QMessageBox::warning( &licenseExpirationDialog,  "Error",  "This product license has expired, contact us to obtain a new license\ninfo@graphinsight.com" );
            QDesktopServices::openUrl(QUrl("http://www.graphinsight.com/download"));
            return 0;
        }
    }
        break;
    case ProfessionalLicense: //Professional
        break;
    }

    QString initialFileString(":/samples/NetScience.net");
    if (argc>1)
    {
        QFile initialFile(argv[1]);
        if (initialFile.exists())
        initialFileString = QString::fromAscii(argv[1]);
        else
            qDebug() << "No such file" << initialFileString;
    }
    MainWindow mainWindow(NULL,initialFileString);
    //MainWindow mainWindow(NULL,"empty.net");
    mainWindow.show();

#ifdef USE_PYTHONQT
    // now hide the console widget, this method MUST be called outside the constructor otherwise we have the
    // InvalidDrawable problem http://qt-project.org/forums/viewthread/22793
    // Set the python console as non visible
    // questo provoca un problema di Invalid Drawable su OSX e forse anche il problema del glitch su windows
    mainWindow.getConsoleWidget()->hide();
    MainWindowDecorator *decorator = new MainWindowDecorator(&mainWindow);
    mainWindow.getCurrentPythonContext().addObject("G",decorator);
    //QString initfilename("init.py");
    //QFile initFile(initfilename);
    //if (initFile.exists())
    //mainWindow.getCurrentPythonContext().evalFile(initfilename);
#endif

    return a.exec();
}
