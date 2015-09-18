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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "GLWidget.h"
#include "LayoutThread.h"
#include "Licensing.h"

#ifdef USE_PYTHONQT
#include "PythonQt.h"
//#include "PythonQt_QtAll.h" this is needed to create Qt interfaces via console! It actually has some problems in compilation
#include "gui/PythonQtScriptingConsole.h"
#endif

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{  Q_OBJECT
public:
   MainWindow(QWidget *parent = 0, QString initialFile = "");
   ~MainWindow();
   void setLicensing(Licensing *l);
   GLWidget *getGLWidget();
   Ui::MainWindow* getUi();
#ifdef USE_PYTHONQT
   PythonQtScriptingConsole* getConsoleWidget();
   PythonQtObjectPtr getCurrentPythonContext();
#endif
private:
   Ui::MainWindow *ui;
   GLWidget *glWidget;
   Licensing *licensing;
   QPointer<QSettings> settings;
   bool isLayoutRunning;
   QString lastFile;
   QString lastDir;
   QString lastExtension;
   QPointer<QSplitter> splitterHorizontalMain;

#ifdef USE_PYTHONQT
   PythonQtScriptingConsole *consoleWidget;
   PythonQtObjectPtr pythonContextPtr;
#endif
   QSplitter *vertSplitterConsoleGlWidget;
protected:
   void changeEvent(QEvent *e);
   //bool eventFilter(QObject *o, QEvent *e);


signals:
   void fileOpenRequested();
   void selectedNodeChanged(int id);
   void fileOpened(QString filename);


public slots:
   void updateStats(int nodes, int edges, int stepsCount, unsigned long elapsedTime, QString layoutStatus);
   void updateStatsOpenGL(double fps);
   void updateNodeStats(LNode *lnode);
   void updateAttributes();
   void updateDataSet();
   void updateDataSetRegexpFiltering();
   void updateDataSetElement(int row, int col, const QString val);
   void updateLayoutMethodsAndFilters();
   void updateColoringMethodsComboBoxes();
   void openFile(QString pathname = "");
   void printStatusBarStart();
   void printStatusBarStop();

   void aboutDialog();
   void autoStartLayout(int index);
   void buy();
   void disableFastMode();
   void disableFastMode(bool b);
   void disableFastMode(int v);
   void emailUsPRO();
   void emailUsSupport();
   void fullScreenDisable();
   void openUrlBlog();
   void openUrlConsulting();
   void openUrlFeedback();
   void openUrlLicensing();
   void openUrlNews();
   void openUrlSupport();
   void overlapCheckBoxClicked(bool clicked);
   void quit();
   void radiusEdgeNodeChanged(int);
   void reloadFile();
   void resetVisualization();
   void saveCurrentFile();
   void saveFile(const QString& pathame="");
   void saveImage(const QString& pathame="");
   void setLabelFontSize(int v);
   void setLabelMinNodeDegree(int v);
   void setSelectedNode(int tableRow=-1, int tableColumn=-1);
   void setSelectionLabel(int v);
   void startLayout();
   void stopLayout();
   void tableSetSelectedNode(LNode *lnode);
   void toggleFullScreen(bool b);
   void toggleLayout();
   void onActionEnableConsoleTriggered();
   //void toggleLayoutNothing();

private slots:
   void on_actionPreferences_triggered();
   void on_comboBoxLabelColumn_currentIndexChanged(int index);
};

#endif // MAINWINDOW_H
