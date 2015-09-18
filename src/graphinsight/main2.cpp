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

#include "PythonQt.h"
#include "gui/PythonQtScriptingConsole.h"
#include "MainWindowDecorator.h"

int main(int argc, char *argv[])
{

   QApplication a(argc, argv);
   QDate date = QDate::currentDate ();
   // Set the application dependent parameters, these parameters will influence the .ini file of QSettings
   QCoreApplication::setOrganizationName("GraphInsight");
   QCoreApplication::setOrganizationDomain("graphinsight.com");
   QCoreApplication::setApplicationName("x-projects");

   QSettings settings;
   QString initialFile;
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
   // Now set the expiration times of the software based on the current license
   QDialog w2;

   switch ( LicenseType )
   {  case TrialLicense: //Trial
      {  if(date.year() >= 2013 && date.month() > 3 && date.day() >= 1 )
         {  QMessageBox::warning( &w2,  "Error",  "This product license has expired, contact us to obtain a new license\ninfo@graphinsight.com" );
            return 0;
         }
      }
      break;
      case AcademicLicense: //Academic
      {  if(date.year() >= 2013 && date.month() > 3 && date.day() >= 1 )
         {  QMessageBox::warning( &w2,  "Error",  "This product license has expired, contact us to obtain a new license\ninfo@graphinsight.com" );
            return 0;
         }
      }
      break;
      case ProfessionalLicense: //Professional
         break;
   }

   MainWindow w(NULL, initialFile);
   w.show();

   // PythonQT shell
   PythonQt::init(PythonQt::IgnoreSiteModule | PythonQt::RedirectStdOut );
   PythonQtObjectPtr  mainContext = PythonQt::self()->getMainModule();
   PythonQtScriptingConsole console(&w, mainContext);

   //w.getSplitterUI()->addWidget(&console);
   console.consoleMessage("\"Welcome to GraphInsight 1.3\"");
   console.appendCommandPrompt(false);
   console.setMinimumSize(250,250);
   QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
   console.setSizePolicy(sizePolicy1);
   console.setContextMenuPolicy(Qt::CustomContextMenu);

   console.setWindowTitle("GraphInsight console");
   console.setShown(true);

   QPalette p = console.palette();
   p.setColor(QPalette::Base, QColor(0, 0,0) );
   p.setColor(QPalette::Text, QColor(0, 255,0) );
   console.setPalette(p);
   MainWindowDecorator *decorator = new MainWindowDecorator(&w);
   // add a QObject to the namespace of the main python context
   mainContext.addObject("currentGraph", decorator);
   console.show();
   w.addConsoleWidget(&console);
   return a.exec();

}
