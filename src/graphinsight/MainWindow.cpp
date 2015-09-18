/****************************f************************************************
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
#include <errno.h>

#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QSplitter>
#include <QPalette>
#include <QSize>
#include <QSizePolicy>
#include <QTreeWidgetItem>
#include <QDebug>

#include "MainWindow.h"
#include "OptionsDialog.h"
#include "ui_MainWindow.h"
#include "ui_About.h"

#include "LicenseType.h"
#include "Common.h"
#include "DataSet.h"
#include "QUtils.h"
#include "GraphLayout.h"

#ifdef USE_PYTHONQT
#include "PythonQt.h"
#include "gui/PythonQtScriptingConsole.h"
#include "LNodeFactory.h"
#endif

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * @param initialFile
 */
MainWindow::MainWindow(QWidget *parent, QString initialFile) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);

    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    move(desktopRect.center() - frameGeometry().center());
    //QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    //move(desktopRect.center() - rect().center());

    ui->tabWidget->setCurrentIndex(0);

    this->setWindowTitle("GraphInsight " + QString(getVersionNumber().c_str()) );
    // INIZIALIZE GLWIDGET
    glWidget = new GLWidget(this);
    // We must set StrongFocus as focus policy in order to enable keyEvent on GLWidget
    this->glWidget->setFocusPolicy(Qt::StrongFocus);
    this->glWidget->setMinimumSize(640,480);

    glWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    // Create a vertical splitter to separate opengl and console
    QSplitter *splitVertical = new QSplitter;
    splitVertical->setOrientation(Qt::Vertical);
    // probabile cause del glitch http://qt-project.org/forums/viewthread/4150/
    //splitVertical->setOpaqueResize(false); // avoid to call resizeGL event online and create wrong glitches
    splitVertical->addWidget(glWidget);

    this->vertSplitterConsoleGlWidget=splitVertical;
#ifdef USE_PYTHONQT
    // ... then add the PythonQtScriptingConsole widget as second row of the vertical splitter
    // 1) Inizialize Python context, if DEBUG mode then print to stdout
    PythonQt::init(PythonQt::IgnoreSiteModule | PythonQt::RedirectStdOut );
    //PythonQt_QtAll::init();
    pythonContextPtr = PythonQt::self()->getMainModule();
    PythonQt::self()->addWrapperFactory(new LNodeFactory(this));

    // the following is optional and only needed if you want a constructor:
    // register the new object as a known classname
    //PythonQt::self()->registerCPPClass("LNodeWrapper", "LNode", "example");

    // 2) Create the PythonQtScriptingConsole widget
    PythonQtScriptingConsole *console = new PythonQtScriptingConsole(NULL, pythonContextPtr);
    QString welcomeMessage = "Welcome to GraphInsight " + QString(GRAPHINSIGHT_VERSION) +"\n";
    welcomeMessage += "Type \"G.\" and let autocompletion help you\n";
    console->appendWelcomeMessage(welcomeMessage);
    // Important, this helps to hide specific methods to the user
    QStringList invisibleMethods;
    // Avoid inserting dangerous methods
    invisibleMethods << "delete" << "connect" << "disconnect" << "deleteLater" << "destroyed" << "children" << "findChildren" << "findChild" << "inherits" << "metaObject" << "tr";
    invisibleMethods << "setParent" << "objectName" << "property" << "setProperty" << "className" << "parent";
    invisibleMethods << "help" << "nodeAttributeChanged" ;
    // Avoid inserting signals, the signals have a signature that begins with __ and in PythonQtScriptingConsole the slots/signals starting with __ are filtered :P
    console->setInvisibleCompletitionMethods(invisibleMethods);

    consoleWidget = console;
    splitVertical->addWidget(console);
    // 3) Set console color properties
    QPalette p = console->palette();
    p.setColor(QPalette::Base, QColor(0, 0,0) );
    p.setColor(QPalette::Text, QColor(0, 255,0) );
    console->setPalette(p);
    console->showMaximized();
    // This connection keeps updated the status of glWidget when commands are executed
    QObject::connect(console,SIGNAL(commandExecuted()),this->glWidget,SLOT(repaint()));
    QObject::connect(console,SIGNAL(commandExecuted()),this->glWidget,SLOT(updateColors()));
    QObject::connect(console,SIGNAL(commandExecuted()),this->glWidget,SLOT(updateGL()));

    // This command keeps updated the status of possible layout methods
    QObject::connect(console,SIGNAL(commandExecuted()),this,SLOT(updateLayoutMethodsAndFilters()));
    QObject::connect(console,SIGNAL(commandExecuted()),this->glWidget,SLOT(update()));
#endif
    splitterHorizontalMain = new QSplitter(Qt::Horizontal,this);
    splitterHorizontalMain->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Preferred);
    splitterHorizontalMain->addWidget(ui->tabWidget);
    splitterHorizontalMain->addWidget(splitVertical);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(splitterHorizontalMain);
    this->centralWidget()->setLayout(layout);
    this->centralWidget()->show();

    // load layout and coloring methods:
    for(int i = 0; GraphLayout::layoutMethods[i]; i++)
    {  ui->comboBoxAlgorithm->insertItem(i,GraphLayout::layoutMethods[i]);
    }

    updateColoringMethodsComboBoxes();

    ui->treeWidgetStatistic->expandAll(); // expand tree in stats tab
    //ui->actionOpen_graph->setEnabled(false); // per disabilitare l'apertura di files

    QObject::connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(quit()) );
    QObject::connect(this, SIGNAL(selectedNodeChanged(int)), this->glWidget, SLOT(setSelectedNode(int)));
    QObject::connect(this->glWidget, SIGNAL(customContextMenuRequested(const QPoint &)), glWidget, SLOT(contextMenu(const QPoint &)));
    QObject::connect(this->glWidget, SIGNAL(layoutCompleted()), this, SLOT(stopLayout()));
    QObject::connect(this->glWidget, SIGNAL(hasAborted()), this, SLOT(resetVisualization()));
    QObject::connect(this->glWidget, SIGNAL( graphStatsChanged(int,int,int,ulong,QString)), this, SLOT(updateStats(int,int,int, ulong,QString)));
    QObject::connect(this->glWidget, SIGNAL(dataSetLoaded()), this, SLOT(updateDataSet()));
    QObject::connect(this->glWidget, SIGNAL(selectedNodeChanged(LNode*)), this, SLOT(tableSetSelectedNode(LNode*)));
    QObject::connect(this->glWidget, SIGNAL(selectedNodeChanged(LNode*)), this, SLOT(updateNodeStats(LNode*)));
    // Connect actions
    QObject::connect(ui->actionOpen_graph, SIGNAL(triggered()), this, SLOT(openFile()));
    QObject::connect(ui->actionSaveGraphLayout, SIGNAL(triggered()), this, SLOT(saveFile()));
    QObject::connect(ui->actionReload_this_File, SIGNAL(triggered()), this, SLOT(reloadFile()));
    QObject::connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveCurrentFile()));
    QObject::connect(ui->actionEnablePythonConsole,SIGNAL(triggered()),this,SLOT(onActionEnableConsoleTriggered()));
    //
    //  QObject::connect(ui->checkBox_3, SIGNAL(toggled(bool)), glWidget, SLOT(setAutoRotation(bool)));
    QObject::connect(ui->checkBoxShowGrid, SIGNAL(toggled(bool)), glWidget, SLOT(setShowGrid(bool)));

    // ::: Filter minimum node degree connection :::
    // [0] slider + spinbox
    QObject::connect(ui->horizontalSliderFilterMinNodeDegree, SIGNAL(valueChanged(int)), ui->spinBoxFilterMinNodeDegree, SLOT(setValue(int)));
    QObject::connect(ui->spinBoxFilterMinNodeDegree, SIGNAL(valueChanged(int)), ui->horizontalSliderFilterMinNodeDegree, SLOT(setValue(int)));
    QObject::connect(ui->horizontalSliderFilterMinNodeDegree, SIGNAL(valueChanged(int)), this->glWidget, SLOT(visualizationFilterNodeDegree(int)));
    //QObject::connect(ui->horizontalSliderFilterMinNodeDegree,SIGNAL(rangeChanged(int,int)),ui->spinBoxFilterMinNodeDegree,SLOT(setRange(int,int)));

    // ::: Filter label degree
    // [0] slider + spinbox
    QObject::connect(ui->spinBoxLabelMinDegree, SIGNAL(valueChanged(int)), ui->horizontalSliderLabelMinDegree, SLOT(setValue(int)));
    QObject::connect(ui->horizontalSliderLabelMinDegree, SIGNAL(valueChanged(int)), ui->spinBoxLabelMinDegree, SLOT(setValue(int)));
    QObject::connect(ui->horizontalSliderLabelMinDegree, SIGNAL(valueChanged(int)), ui->spinBoxLabelMinDegree, SLOT(update()));
    QObject::connect(ui->horizontalSliderLabelMinDegree, SIGNAL(valueChanged(int)), this, SLOT(setLabelMinNodeDegree(int)));
    //QObject::connect(ui->horizontalSliderLabelMinDegree,SIGNAL(rangeChanged(int,int)),ui->spinBoxFilterMinNodeDegree,SLOT(setRange(int,int)));

    // ::: Label font size slider + spin box connections
    QObject::connect(ui->spinBoxLabelFontSize, SIGNAL(valueChanged(int)), ui->horizontalSliderLabelFontSize, SLOT(setValue(int)));
    QObject::connect(ui->horizontalSliderLabelFontSize, SIGNAL(valueChanged(int)), ui->spinBoxLabelFontSize, SLOT(setValue(int)));
    QObject::connect(ui->horizontalSliderLabelFontSize, SIGNAL(valueChanged(int)), this, SLOT(setLabelFontSize(int)));

    // ::: Node radius connections (they change node radius and edges radius, also act on fastgraph mode
    QObject::connect(ui->horizontalSliderNodeRadius, SIGNAL(valueChanged(int)), ui->spinBoxNodeRadius, SLOT(setValue(int)));
    QObject::connect(ui->horizontalSliderNodeRadius, SIGNAL(valueChanged(int)), this, SLOT(disableFastMode(int)));
    QObject::connect(ui->horizontalSliderNodeRadius, SIGNAL(valueChanged(int)), this, SLOT(radiusEdgeNodeChanged(int)));
    QObject::connect(ui->spinBoxNodeRadius, SIGNAL(valueChanged(int)), ui->horizontalSliderNodeRadius, SLOT(setValue(int)));

    // ::: Edge radius connections
    QObject::connect(ui->horizontalSliderEdgeRadius, SIGNAL(valueChanged(int)), ui->spinBoxEdgeRadius, SLOT(setValue(int)));
    QObject::connect(ui->horizontalSliderEdgeRadius, SIGNAL(valueChanged(int)), this, SLOT(disableFastMode(int)));
    QObject::connect(ui->horizontalSliderEdgeRadius, SIGNAL(valueChanged(int)), this, SLOT(radiusEdgeNodeChanged(int)));
    QObject::connect(ui->spinBoxEdgeRadius, SIGNAL(valueChanged(int)), ui->horizontalSliderEdgeRadius, SLOT(setValue(int)));

    // ::: Night mode activation
    QObject::connect(ui->checkBoxSetNight, SIGNAL(toggled(bool)), glWidget, SLOT(setNightMode(bool)));

    // :: Actions connections:
    // [0] Open Graph
    QObject::connect(ui->actionOpen_graph, SIGNAL(triggered()), this, SLOT(disableFastMode()));

    // [1] Open About dialog
    QObject::connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(aboutDialog()));

    // [2] Action Save image
    QObject::connect(ui->actionSaveAsImage, SIGNAL(triggered(bool)), this, SLOT(saveImage()));

    // [3] Action go to fullscreen Enter / Exit
    QObject::connect(ui->actionFullscreen, SIGNAL(toggled(bool)), this, SLOT(toggleFullScreen(bool)));
    QObject::connect(ui->actionFullScreenEsc, SIGNAL(triggered()), this, SLOT(fullScreenDisable()));
    QObject::connect(ui->actionFullscreen, SIGNAL(hovered()), this, SLOT(buy()));

    // [4] Action Get latest news
    QObject::connect(ui->actionLatest_news, SIGNAL(triggered()), this, SLOT(openUrlNews()));
    // [5] Action send us feedback
    QObject::connect(ui->actionSend_feedback, SIGNAL(triggered()), this, SLOT(openUrlFeedback()));
    // [6] Action Get PRO license
    QObject::connect(ui->actionPROLicensing, SIGNAL(triggered()), this, SLOT(openUrlLicensing()));
    // [7] Action get PRO consulting
    QObject::connect(ui->actionPROConsulting, SIGNAL(triggered()), this, SLOT(openUrlConsulting()));
    // [8] Action Get Online documentation
    QObject::connect(ui->actionOnline_documentation, SIGNAL(triggered()), this, SLOT(openUrlSupport()));
    // [9] Action Go to www.visual-analytics.org
    QObject::connect(ui->actionVisual_analytics_org_blog, SIGNAL(triggered()), this, SLOT(openUrlBlog()));
    // [10] Action Email for support
    QObject::connect(ui->actionEmailUsSupport, SIGNAL(triggered()), this, SLOT(emailUsSupport()));
    // [11] Action Email us for Pro license
    QObject::connect(ui->actionEmailUsPro, SIGNAL(triggered()), this, SLOT(emailUsPRO()));

    QObject::connect(ui->comboBoxNodeColor, SIGNAL( currentIndexChanged(int) ), glWidget, SLOT( setNodeColorMethod(int)));
    QObject::connect(ui->comboBoxEdgeColor, SIGNAL( currentIndexChanged(int) ), glWidget, SLOT( setEdgeColorMethod(int)));
    QObject::connect(ui->comboBoxGlobalQuality, SIGNAL( currentIndexChanged(int) ), glWidget, SLOT( setQuality(int)));
    QObject::connect(ui->comboBoxSelectLabel, SIGNAL( currentIndexChanged(int) ), this, SLOT( setSelectionLabel(int)));
    QObject::connect(ui->comboBoxEdgeType, SIGNAL( currentIndexChanged(int) ), glWidget, SLOT( setEdgeType(int)));
    QObject::connect(ui->tableWidgetDatabase, SIGNAL(cellClicked(int,int)), this, SLOT(setSelectedNode(int,int)));
    QObject::connect(ui->pushButtonStartStop, SIGNAL(clicked()),this,SLOT(toggleLayout()));

    // ::: Select algorithm connection, change combobox for layout method or layout dimension => autostartlayout :::
    QObject::connect(ui->comboBoxAlgorithm, SIGNAL(currentIndexChanged(int)), this, SLOT(autoStartLayout(int)));
    QObject::connect(ui->comboBoxDimension, SIGNAL(currentIndexChanged(int)), this, SLOT(autoStartLayout(int)));

    QObject::connect(ui->comboBoxAlgorithm, SIGNAL(currentIndexChanged(int)), this->glWidget, SLOT(repaint()));
    QObject::connect(ui->comboBoxDimension, SIGNAL(currentIndexChanged(int)), this->glWidget, SLOT(repaint()));

    // ::: When the tabwidget is changed activate slot MainWindow::tabChanged
    //QObject::connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));
    // For now hide the checkbox case sensitivity
    this->ui->checkBoxRegExpCaseSensitive->hide();
    QObject::connect(this->glWidget,SIGNAL(nodeUnselected()),this->ui->tableWidgetDatabase,SLOT(clearSelection()));

    QObject::connect(ui->lineEditRegExpFilter, SIGNAL(textChanged(QString)), this, SLOT(updateDataSetRegexpFiltering()));
    QObject::connect(ui->checkBoxRegExpCaseSensitive,SIGNAL(clicked()),this,SLOT(updateDataSetRegexpFiltering()));
    QObject::connect(ui->lineEditRegExpFilter, SIGNAL(returnPressed()), this, SLOT(updateDataSetRegexpFiltering()));
    // ::: When the user press Enter the dataset is updated
    QObject::connect(ui->lineEditRegExpFilter, SIGNAL(editingFinished()), this, SLOT(updateDataSetRegexpFiltering()));

    // Labels Overlap remotion signal-slot
    QObject::connect(ui->checkBoxRemoveLabelOverlaps,SIGNAL(clicked(bool)),this,SLOT(overlapCheckBoxClicked(bool)));

    // Set default value for spinboxes
    //this->ui->spinBoxEdgeRadius->setValue(0);
    this->ui->spinBoxFilterMinNodeDegree->setValue(0);
    this->ui->spinBoxLabelMinDegree->setValue(0);
    this->ui->spinBoxNodeRadius->setValue(0);
    this->ui->spinBoxLabelFontSize->setValue(1);

    // Connect the FPS signals from glWidget to the FPS show
    QObject::connect(glWidget, SIGNAL(paintFinished(double)), this, SLOT(updateStatsOpenGL(double)));

    // questi vanno messi qui perchè cosi' ci sono gi  signals/slots caricati.
    ui->comboBoxAlgorithm->setCurrentIndex(0); // metodi layout
    ui->comboBoxNodeColor->setCurrentIndex(4); // metodi colore nodi
    ui->comboBoxEdgeColor->setCurrentIndex(4); // metodi colore archi

    // Set the application dependent parameters, these parameters will influence the .ini file of QSettings
    QCoreApplication::setOrganizationName("GraphInsightTeam");
    QCoreApplication::setOrganizationDomain("www.graphinsight.com");
    QCoreApplication::setApplicationName("GraphInsight");

    settings = new QSettings("GraphInsightTeam", "GraphInsight " + QString(getVersionNumber().c_str()));

    // Settings files will be save under LINUX in
    // $HOME/.config/GraphInsightTeam/GraphInsightVERSION
    if(settings->contains("paths/lastDir"))
    {
        lastDir = settings->value("paths/lastDir").toString();
    }
    else
    {
#ifdef Q_WS_MAC
        QString appPath = QApplication::applicationDirPath();
        lastDir = appPath.append("/../Resources/Samples/");
#else
        lastDir = QDir::homePath();
#endif
    }

    if ( settings->contains("splitterSize") )
    {
        QList<int> s ;
        s.push_back(settings->value("tabwidgetSize").toInt());
        s.push_back(settings->value("glWidgetSize").toInt());
        splitterHorizontalMain->setSizes(s);
    }

    if ( settings->contains("mainWindowSize") )
    {
        this->resize(settings->value("mainWindowSize").toSize() );
    }

    if(qApp->argc() > 1)
    {  lastFile = QString(qApp->argv()[1]);
    }
    else
    {  if(!initialFile.isEmpty())
        {  lastFile = initialFile;
        }
        else
        {  lastFile = "empty";
        }
    }

    isLayoutRunning = false; // initially, the layout is not running.
    openFile(lastFile);
    glWidget->setNonIntersectingLabels(false);
    this->setFocus();
}

Ui::MainWindow* MainWindow::getUi()
{  return this->ui;
}

#ifdef USE_PYTHONQT
PythonQtScriptingConsole* MainWindow::getConsoleWidget()
{
    return consoleWidget;
}

PythonQtObjectPtr MainWindow::getCurrentPythonContext()
{  return this->pythonContextPtr;
}
#endif
/**
 * @brief MainWindow::getGLWidget
 * @return
 */
GLWidget* MainWindow::getGLWidget()
{  return this->glWidget;
}

/**
 * @brief MainWindow::toggleLayout
 */
void MainWindow::toggleLayout()
{  if(isLayoutRunning)
    {  glWidget->stop();

        if(glWidget->layoutThread.dataSet.graphGL->g != glWidget->layoutThread.dataSet.graphGL)
        {  // se tecnica multilivello non'ha terminato,
            // allora forza layout random.
            glWidget->reload(GraphLayout::MethodRandom, ui->comboBoxDimension->currentIndex()+2);
        }

        ui->pushButtonStartStop->setIcon(QIcon(":/icons/start.png"));
        ui->pushButtonStartStop->setText("Start");
    }
    else
    {  glWidget->reload(ui->comboBoxAlgorithm->currentIndex(), ui->comboBoxDimension->currentIndex()+2);
        ui->pushButtonStartStop->setIcon(QIcon(":/icons/stop.png"));
        ui->pushButtonStartStop->setText("Stop");
    }
    isLayoutRunning = !isLayoutRunning;
    //qApp->installEventFilter(this);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete this->settings;
    delete ui;
}

/**
 * @brief MainWindow::eventFilter
 * @param o
 * @param e
 * @return
 */
/*
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    // Handle the mouse click event
    if (event->type() == QEvent::CursorChange )
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        qDebug() << "cursor move" << mouseEvent->pos().x() << "," << mouseEvent->pos().y();
        //statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));
    }

    if (event->type() == QEvent::HoverEnter )
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        qDebug() << "hover enter" << mouseEvent->pos().x() << "," << mouseEvent->pos().y();
        //statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));
    }
    return  false;
}
*/

/**
 * @brief MainWindow::changeEvent
 * @param e
 */
void MainWindow::changeEvent(QEvent *e)
{  QMainWindow::changeEvent(e);
    switch (e->type())
    {  case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/**
 * @brief MainWindow::openFile
 * @param pathname
 */
void MainWindow::openFile(QString pathname)
{
    glWidget->setGLEnabled(false);
    // For security let's set the maximum possible degree for node label filter, this avoids show of labels for a short period of time during loading
    ui->horizontalSliderLabelMinDegree->setMaximum(1E6);
    ui->horizontalSliderLabelMinDegree->setValue(1E6);
    ui->lineEditRegExpFilter->clear(); // textline in tab dataset
    stopLayout();
    emit fileOpenRequested(); // this will connect to MainWindowDecorator to stop current running layout

    QString graphFileName = pathname;
    if( graphFileName.isEmpty())
    {
        graphFileName = QFileDialog::getOpenFileName(this,"Open file...",lastDir,
                                                     "Pajek network (*.net);;Dimacs (*.dimacs);;CNF Variable Interaction Graph (*.cnf);;CNF Variable Resolution Graph (*.cnf2)");
        if(graphFileName.isEmpty())
        {
            if(lastFile.compare("empty") != 0 && !lastFile.isEmpty())
                return;
        }
    }

    QFileInfo fi(graphFileName);

    if(graphFileName.compare("empty") != 0)
    {  lastDir = fi.absolutePath();
        lastFile = fi.absoluteFilePath();
        lastExtension = fi.suffix();
        settings->beginGroup("paths");
        settings->setValue("lastDir", lastDir);
        settings->setValue("lastFile", lastFile);
        settings->setValue("lastOpenedFormat",fi.suffix());
        settings->endGroup();
    }

    statusBar()->showMessage(QString("Loading ").
                             append("\"").append(fi.fileName()).
                             append("\" ..."));

    if(glWidget->openFile(graphFileName,0, ui->comboBoxDimension->currentIndex()+2) == false)
    {
        this->openFile("empty");
        QUtils::criticalMessage(this,QString("Unable to load file:\n").append(glWidget->layoutThread.dataSet.errorMessage).append("\nPlease, check pathname, extension and content."));
        return;
    }
    else    // File is loaded successfully but there are warning message, probably bad parsed lines to check
    {
        if ( !glWidget->layoutThread.dataSet.warningMessage.isEmpty() )
        {  QMessageBox::warning( this,  "Errors reading input file", QString("Errors found parsing the input file\n" + glWidget->layoutThread.dataSet.warningMessage ) );
        }
    }

    // enable/disable layout techniques, depending on the number of edges of the loaded graph.
    ui->comboBoxAlgorithm->setCurrentIndex(0);

    // Update the possible layout methods, by explicity disallowing those not suited for multicomponent or too big graphs
    this->updateLayoutMethodsAndFilters();

    resetVisualization();
    glWidget->setNonIntersectingLabels(false);

    // Print file size information in the status bar
    QString fileSize;
    if(fi.size() > 1024)
    {
        if(fi.size() > 1024*1024)
        {  fileSize.append(QString::number(fi.size() / (1024*1024))).append( "Mb");
        }
        else
        {  fileSize.append(QString::number(fi.size() / (1024))).append( "Kb");
        }
    }
    else
    {  fileSize.append(QString::number(fi.size())).append( "b");
    }

    statusBar()->showMessage(QString("\"").append(fi.fileName()).
                             append("\"").
                             append( " loaded (").
                             append(fileSize).append("): ").
                             append(QString::number(glWidget->layoutThread.dataSet.graphGL->statsNodesCount)).
                             append(" nodes and ").
                             append(QString::number(glWidget->layoutThread.dataSet.graphGL->statsEdgesCount)).
                             append(" edges.")
                             );

    ui->comboBoxDimension->setCurrentIndex(glWidget->layoutThread.dataSet.graphGL->nDimensions-2);
    this->setWindowTitle( fi.fileName() + " - GraphInsight " + QString(getVersionNumber().c_str()) );

    emit this->fileOpened(pathname);
    this->updateAttributes();
    glWidget->setGLEnabled(true);
}

/**
 * @brief MainWindow::saveFile
 * @param pathname
 */
void MainWindow::saveFile(const QString &pathname)
{
    DEBUG_PRINT("savefile called!");
    if ( (this->glWidget->layoutThread.isRunning()) )
    {
        this->glWidget->layoutThread.stopMe();
        this->toggleLayout();
    }

    QString qpathname;

    if(!pathname.isEmpty())
    {  qpathname = QString(pathname);
        if(qpathname.compare("empty") == 0)
            return;
    }
    else
    {
        QString  *selectedFilter = new QString("Pajek network (*.net)");
        if (lastDir.isEmpty())
            lastDir = ":/samples/";
        qpathname = QFileDialog::getSaveFileName(
                    this,
                    "Save graph (with layout) as...",
                    lastDir,
                    "Pajek network (*.net);; DOT (*.dot);; GnuPlot B&W (*.gp);; GnuPlot Colors (*.gpc);; SVG (*.svg);; Dimacs (*.dimacs)",selectedFilter
            #ifdef __APPLE__    // workaround for a qt bug in Qt 4.7.4
                    ,QFileDialog::DontUseNativeDialog);
#else
                    );

#endif
        if (selectedFilter)
            delete selectedFilter;
    }

    if(qpathname.isEmpty() || qpathname.at(0) == ':') // i file in resources NON vengono salvati! cosi' le demo rimangono ok...
        return;

    QFileInfo fi(qpathname);
    lastDir = fi.absolutePath();
    if(glWidget->saveFile(qpathname) == false)
    {  QUtils::criticalMessage(this,QString("Unable to save file: ").append(glWidget->layoutThread.dataSet.errorMessage).append(". Please, check pathname and extension."));
    }
    DEBUG_PRINT("qpathname = " << qpathname.toAscii().data());
}

/**
 * @brief MainWindow::disableFastMode
 * @param v
 */
void MainWindow::disableFastMode(int v)
{  disableFastMode(true);
}

/**
 * @brief MainWindow::disableFastMode
 */
void MainWindow::disableFastMode()
{  disableFastMode(true);
}

/**
 * @brief MainWindow::disableFastMode
 * @param b
 */
void MainWindow::disableFastMode(bool b)
{  //ui->checkBox_2->setChecked(false);
}

/**
 * @brief MainWindow::aboutDialog
 */
void MainWindow::aboutDialog()
{
    QDialog *w2 = new QDialog;
    Ui_Dialog d;
    d.setupUi(w2);

    // A complicate way to modify the text but now for every version we have the version number and revision printed inside the program
    QString text= d.textEdit->toHtml().replace("GRAPHINSIGHT_VERSION",QString(getVersionNumber().c_str()));
    text.replace("GRAPHINSIGHT_LICENSE",QString( getLicenseType().c_str()));
    //text.replace("GRAPHINSIGHT_REVISION","Rev " + QString::number(getRevisionNumber()));
    d.textEdit->setText(text);
    w2->setFixedSize(w2->width(), w2->height());

    w2->setWindowFlags(Qt::WindowStaysOnTopHint );//Qt::SplashScreen
    w2->move(this->geometry().center()- w2->geometry().center());
    w2->exec();
}

/**
 * @brief MainWindow::resetVisualization
 */
void MainWindow::resetVisualization()
{
    ui->checkBoxSetNight->setChecked(true);
    ui->comboBoxSelectLabel->setCurrentIndex(1);
    ui->horizontalSliderFilterMinNodeDegree->setValue(ui->horizontalSliderFilterMinNodeDegree->minimum());
    ui->horizontalSliderLabelFontSize->setValue(ui->horizontalSliderLabelFontSize->minimum()+2);
    ui->comboBoxEdgeType->setCurrentIndex(0);
    ui->horizontalSliderNodeRadius->setValue(std::max(0,50 - (int)log((double)glWidget->layoutThread.dataSet.graphGL->statsEdgesCount+1) *2));
    ui->horizontalSliderEdgeRadius->setValue(ui->horizontalSliderNodeRadius->value()/2);
    ui->spinBoxNodeRadius->setValue(ui->horizontalSliderNodeRadius->value());
    ui->spinBoxFilterMinNodeDegree->setValue(0);
    ui->spinBoxLabelFontSize->setValue(ui->horizontalSliderLabelFontSize->value());
    ui->spinBoxLabelMinDegree->setValue(ui->spinBoxLabelMinDegree->maximum());
    ui->comboBoxSelectLabel->setCurrentIndex(1);
    ui->checkBoxShowGrid->setChecked(true);
    ui->comboBoxNodeColor->setCurrentIndex(4);
    ui->comboBoxEdgeColor->setCurrentIndex(4);
    ui->checkBoxRemoveLabelOverlaps->setChecked(false);

    ui->comboBoxGlobalQuality->setCurrentIndex(0);
    // XXX commentato perchè sennò fissa sempre a 2 il raggio dei lati invece bisogna usare un'euristica
    // ui->horizontalSliderEdgeRadius->setValue(2);

    // XXX commented because in some situation may need to allocate much memory
    int edges = glWidget->layoutThread.dataSet.graphGL->statsEdgesCount;
    for(;;)
    {  if(edges < 2000)
        {  ui->comboBoxGlobalQuality->setCurrentIndex(5);
            break;
        }
        if(edges < 3000)
        {  ui->comboBoxGlobalQuality->setCurrentIndex(4);
            break;
        }
        if(edges < 8000)
        {  ui->comboBoxGlobalQuality->setCurrentIndex(3);
            break;
        }

        if(edges < 10000)
        {  ui->comboBoxGlobalQuality->setCurrentIndex(2);
            break;
        }

        if(edges < 20000)
        {  ui->comboBoxGlobalQuality->setCurrentIndex(1);
            break;
        }
        if(edges > 50000)
        {  ui->horizontalSliderEdgeRadius->setValue(0);
        }
        ui->comboBoxGlobalQuality->setCurrentIndex(0);
        break;
    }
    // for more than 20000 edges set radius always to zero
    if (edges>20000)
        ui->horizontalSliderEdgeRadius->setValue(0);
    ui->spinBoxEdgeRadius->setValue(ui->horizontalSliderEdgeRadius->value());
    glWidget->update();
    glWidget->resetScene();
}

/**
 * @brief MainWindow::updateNodeStats
 * @param lnode
 */
void MainWindow::updateNodeStats(LNode *lnode)
{
    //QString desc;
    if(lnode && glWidget->layoutThread.dataSet.graphGL->g == glWidget->layoutThread.dataSet.graphGL)
    {
        // SUBSTITUTE_INDEX_ID
        Entity *entity = lnode->ptrEntity;
        ui->treeWidgetSelectedItem->clear();
        //ui->treeWidget_2->addTopLevelItem(new QTreeWidgetItem());
        //ui->treeWidget_2->addTopLevelItem(new QTreeWidgetItem());
        //   ui->treeWidget_2->topLevelItem(0)->setText(0,QString("Id"));
        //   ui->treeWidget_2->topLevelItem(1)->setText(0,QString("Degree"));
        //         ui->treeWidget_2->topLevelItem(0)->setText(1,QString::number(lnode->id));
        //     ui->treeWidget_2->topLevelItem(1)->setText(1,QString::number(lnode->degree));

        // First row
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0,QString("Id"));
        item->setText(1,QString::number(lnode->id));
        ui->treeWidgetSelectedItem->addTopLevelItem(item);
        // Second row
        QTreeWidgetItem *item2 = new QTreeWidgetItem();
        item2->setText(0,QString("Degree"));
        item2->setText(1,QString::number(lnode->degree));

        ui->treeWidgetSelectedItem->addTopLevelItem(item2);

        // Third row
        QTreeWidgetItem *item3 = new QTreeWidgetItem();
        item3->setText(0,QString("Component"));
        item3->setText(1,QString::number(lnode->component));

        ui->treeWidgetSelectedItem->addTopLevelItem(item3);

        QTreeWidgetItem *item4 = new QTreeWidgetItem();
        item4->setText(0,QString("Neighbors count"));
        item4->setText(1,QString::number(lnode->neighborsRand.size()));
        ui->treeWidgetSelectedItem->addTopLevelItem(item4);

        for (unsigned int i=0; i<lnode->ptrEntity->attributes.size();++i)
        {
            QTreeWidgetItem *itemZ = new QTreeWidgetItem();
            itemZ->setText(0, QString::fromStdString( glWidget->layoutThread.dataSet.colNames.at(i) ));
            itemZ->setText(1, QString::fromStdString( lnode->ptrEntity->attributes.at(i)->valueString )  );
            ui->treeWidgetSelectedItem->addTopLevelItem(itemZ);
        }
    }
    else
    {
        ui->treeWidgetSelectedItem->clear();
    }

    if (lnode)
        statusBar()->showMessage("ID="+QString::number(lnode->id)+" Degree=" + QString::number(lnode->degree) + " Neighbors count=" + QString::number(lnode->neighborsRand.size()));
}

/**
 * @brief MainWindow::updateStatsOpenGL
 */
void MainWindow::updateStatsOpenGL(double fps)
{
    ui->treeWidgetStatistic->topLevelItem(2)->child(0)->setText(1,QString::number(fps));
    ui->treeWidgetStatistic->topLevelItem(2)->child(1)->setText(1,QString((char *)glGetString(GL_VENDOR)));
    ui->treeWidgetStatistic->topLevelItem(2)->child(2)->setText(1,QString((char *)glGetString(GL_RENDERER)));
    ui->treeWidgetStatistic->topLevelItem(2)->child(3)->setText(1,QString((char *)glGetString(GL_VERSION)));
}

/**
 * @brief MainWindow::updateStats
 * @param nodes
 * @param edges
 * @param stepsCount
 * @param elapsedTime
 * @param layoutStatus
 */
void MainWindow::updateStats(int nodes, int edges, int stepsCount, ulong elapsedTime, QString layoutStatus)
{  // XXX CARLO inserire qui i dati base statistici
    QString coarseGraphNodesCount =QString::number(glWidget->layoutThread.dataSet.graphGL->g->statsNodesCount);
    QString baseNodesCount = QString::number(nodes);
    QString nodestat = coarseGraphNodesCount+QString("/")+baseNodesCount + QString(" (");
    int levelNodes = glWidget->layoutThread.dataSet.graphGL->g->statsNodesCount;
    // Switch to 0 if the division with 0 gives Nan
    if (nodes==0)
        nodestat += QString("0");
    else
        nodestat += QString::number(100*(double)levelNodes/(double)nodes,'f',0);

    nodestat += QString("%)");

    double minDegree = glWidget->layoutThread.dataSet.graphGL->statsMinNodeDegree;
    double maxDegree = glWidget->layoutThread.dataSet.graphGL->statsMaxNodeDegree;
    double avgDegree = 2*(double)edges/(double)nodes;
    if (glWidget->layoutThread.dataSet.graphGL->nodesRand.empty())
    {
        minDegree=0.0;
        maxDegree=0.0;
        avgDegree=0.0;
    }

    QString coarseGraphEdgesCount =QString::number(glWidget->layoutThread.dataSet.graphGL->g->statsEdgesCount);
    QString baseEdgesCount = QString::number(edges);
    QString edgestat = coarseGraphEdgesCount+QString("/")+baseEdgesCount;

    ui->treeWidgetStatistic->topLevelItem(0)->setText(1,QString("(|V|,|E|)=").append( QString::number(nodes)).append(",").append(QString::number(edges)));
    ui->treeWidgetStatistic->topLevelItem(0)->child(0)->setText(1,nodestat);
    ui->treeWidgetStatistic->topLevelItem(0)->child(1)->setText(1,edgestat);
    ui->treeWidgetStatistic->topLevelItem(0)->child(2)->setText(1,QString::number(glWidget->layoutThread.dataSet.graphGL->countConnectedComponents()));
    ui->treeWidgetStatistic->topLevelItem(0)->child(3)->setText(1,QString::number(maxDegree));
    ui->treeWidgetStatistic->topLevelItem(0)->child(4)->setText(1,QString::number(minDegree));
    ui->treeWidgetStatistic->topLevelItem(0)->child(5)->setText(1,QString::number(avgDegree,'g',3));
    ui->treeWidgetStatistic->topLevelItem(0)->child(6)->setText(1,QString(glWidget->layoutThread.dataSet.graphGL->pathName.c_str()));

    ui->treeWidgetStatistic->topLevelItem(1)->setText(1,QString(layoutStatus).append(" (").append(QString::number(stepsCount)).append(" steps)"));
    ui->treeWidgetStatistic->topLevelItem(1)->child(0)->setText(1,QString::number(stepsCount));
    ui->treeWidgetStatistic->topLevelItem(1)->child(1)->setText(1,QString::number((unsigned long)(elapsedTime / 1000.0)));
    ui->treeWidgetStatistic->topLevelItem(1)->child(2)->setText(1,layoutStatus);

    ui->treeWidgetStatistic->topLevelItem(3)->child(0)->setText(1, QString::number(QThread::idealThreadCount()));
}

void MainWindow::updateLayoutMethodsAndFilters()
{
    // update the active layout methods in the combobox menu
    for(int i = 0; GraphLayout::layoutMethods[i]; i++)
    {  qobject_cast<QStandardItemModel *>(ui->comboBoxAlgorithm->model())->item( i )->setEnabled( glWidget->layoutThread.dataSet.graphGL->lmOk(i));
    }

    // Update the range of filters depending on current graph, first update the graph stats
    double oldMinDegree = this->glWidget->layoutThread.dataSet.graphGL->statsMinNodeDegree;
    double oldMaxDegree = this->glWidget->layoutThread.dataSet.graphGL->statsMaxNodeDegree;
    this->glWidget->layoutThread.dataSet.graphGL->updateStaticStats();

    int minDeg = std::floor(this->glWidget->layoutThread.dataSet.graphGL->statsMinNodeDegree);
    int maxDeg = std::ceil(this->glWidget->layoutThread.dataSet.graphGL->statsMaxNodeDegree);
    // Setting ranges of filter nodes spinbox and sliders
    if (this->glWidget->layoutThread.dataSet.graphGL->nodesRand.size()==0 )
    {
        // For nodes visualization
        ui->horizontalSliderFilterMinNodeDegree->setEnabled(false);
        ui->spinBoxFilterMinNodeDegree->setEnabled(false);
        ui->horizontalSliderFilterMinNodeDegree->setRange(0,0);
        ui->spinBoxFilterMinNodeDegree->setRange(0,0);
        // For labels visualization
        ui->horizontalSliderLabelMinDegree->setEnabled(false);
        ui->spinBoxLabelMinDegree->setEnabled(false);
        ui->horizontalSliderLabelMinDegree->setRange(0,0);
        ui->spinBoxLabelMinDegree->setRange(0,0);
    }
    else
    {
        // For nodes
        ui->horizontalSliderFilterMinNodeDegree->setEnabled(true);
        ui->spinBoxFilterMinNodeDegree->setEnabled(true);
        ui->horizontalSliderFilterMinNodeDegree->setRange(std::floor((float)minDeg),std::ceil((float)maxDeg)+1);
        ui->spinBoxFilterMinNodeDegree->setRange(std::floor((float)minDeg),std::ceil((float)maxDeg)+1);
        // For labels
        ui->horizontalSliderLabelMinDegree->setEnabled(true);
        ui->spinBoxLabelMinDegree->setEnabled(true);
        ui->horizontalSliderLabelMinDegree->setRange(std::floor((float)minDeg),std::ceil((float)maxDeg)+1);
        ui->spinBoxLabelMinDegree->setRange(std::floor((float)minDeg),std::ceil((float)maxDeg)+1);

        // Only if it changed
        if ( abs(oldMinDegree - this->glWidget->layoutThread.dataSet.graphGL->statsMinNodeDegree) > 1E-9 ||
              abs(oldMaxDegree - this->glWidget->layoutThread.dataSet.graphGL->statsMaxNodeDegree) > 1E-9 )
        {
            ui->horizontalSliderLabelMinDegree->setValue(std::ceil((float)maxDeg)+1);
            ui->spinBoxLabelMinDegree->setValue(std::ceil((float)maxDeg)+1);
        }
    }
    //qDebug() << "Node degrees MAX=" << maxDeg << " MIN=" << minDeg ;
}

/**
 * @brief MainWindow::stopLayout
 */
void MainWindow::stopLayout()
{  if(isLayoutRunning)
        toggleLayout();
}

/**
 * @brief MainWindow::startLayout
 */
void MainWindow::startLayout()
{  stopLayout();
    toggleLayout();
}

/**
 * @brief MainWindow::updateAttributes
 */
void MainWindow::updateAttributes()
{
    // Set the current visible attribute for the labels
    ui->comboBoxLabelColumn->blockSignals(true);
    ui->comboBoxLabelColumn->clear();
    ui->comboBoxLabelColumn->blockSignals(false);

    for (unsigned int i=0; i< this->glWidget->layoutThread.dataSet.colNames.size();i++)
        this->ui->comboBoxLabelColumn->addItem( QString::fromStdString( this->glWidget->layoutThread.dataSet.colNames.at(i) ) );

    this->glWidget->options.currentVisibleAttribute = 0;
}

/**
 * @brief MainWindow::updateDataSet
 */
void MainWindow::updateDataSet()
{
    DataSet *dataSet = &glWidget->layoutThread.dataSet;
    //ui->tableWidgetDatabase->setSortingEnabled(true);
    ui->tableWidgetDatabase->clear();
    ui->tableWidgetDatabase->setRowCount(glWidget->layoutThread.dataSet.graphGL->nodes.size());
    ui->tableWidgetDatabase->setColumnCount(dataSet->colNames.size()+1);

    // Set the header name, first column is always ID of nodes
    QTableWidgetItem *item = new QTableWidgetItem(QString("Id"));
    ui->tableWidgetDatabase->setHorizontalHeaderItem(0, item);
    // If there are some column names, they are added at the first row as the
    // new columns, it starts from 1 to N...
    for(unsigned int i = 0; i < dataSet->colNames.size(); i++)
    {  QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(dataSet->colNames[i]));
        ui->tableWidgetDatabase->setHorizontalHeaderItem(i+1, item);
    }

    if (dataSet->colNames.size()==0)
    {
        this->ui->labelLabelColumn->hide();
        this->ui->comboBoxLabelColumn->hide();
    }
    else
    {
        this->ui->labelLabelColumn->show();
        this->ui->comboBoxLabelColumn->show();
    }

    // Fill the table with correct entities
    for (NodesRand::iterator iter = dataSet->graphGL->nodesRand.begin();iter!=dataSet->graphGL->nodesRand.end();++iter)
    {
        // Set the 0-th column of the i-th row of table with value of the node ID
        LNode *n = static_cast<LNode*>(*iter);
        QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(n->id));
        ui->tableWidgetDatabase->setItem(n->index-1,0,newItem);
        // Fill up the other columns with values from the attributes of the entities
        int col = 1;
        for ( std::vector<EntityAttribute*>::iterator iter2 = n->ptrEntity->attributes.begin(); iter2 != n->ptrEntity->attributes.end(); ++iter2)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(QString::fromStdString((*iter2)->valueString));
            ui->tableWidgetDatabase->setItem(n->index-1,col++,newItem);
        }
    }

    ui->treeWidgetSelectedItem->clear();
    for(unsigned int i = 0; i < glWidget->layoutThread.dataSet.colNames.size()+1; i++)
        ui->treeWidgetSelectedItem->addTopLevelItem(new QTreeWidgetItem());
    this->updateDataSetRegexpFiltering();
}

/**
 * @brief updateDataSetRegexpFiltering
**/
void MainWindow::updateDataSetRegexpFiltering()
{
    //XXX large table improvement: http://doc.trolltech.com/3.3/qtable.html#notes-on-large-tables
    if ( !ui->lineEditRegExpFilter->text().isEmpty() )
    {
        int count = 0;
        QRegExp rx(ui->lineEditRegExpFilter->text(),static_cast<Qt::CaseSensitivity>(this->ui->checkBoxRegExpCaseSensitive->isChecked()));
        for(int row_i = 0; row_i < ui->tableWidgetDatabase->rowCount(); row_i++)
        {
            bool found = false;
            // Search in all columns
            for(int column = 0; column < ui->tableWidgetDatabase->columnCount(); column++)
            {
                if ( rx.indexIn(ui->tableWidgetDatabase->item(row_i, column)->text()) != -1 )
                {  found = true;
                    count++;
                    break;
                }
            }
            if(found)
                ui->tableWidgetDatabase->showRow(row_i);
            else
                ui->tableWidgetDatabase->hideRow(row_i);
        }
        statusBar()->showMessage(QString("Matching records (count): ").append(QString::number(count)));
    }
    else
    {
        for(int rowIndex = 0; rowIndex < ui->tableWidgetDatabase->rowCount(); rowIndex++)
        {
            ui->tableWidgetDatabase->showRow(rowIndex);
        }
        statusBar()->showMessage(QString("Matching records (count): ").append(QString::number(ui->tableWidgetDatabase->rowCount())));
    }

    ui->tableWidgetDatabase->setVisible(false);
    ui->tableWidgetDatabase->resizeColumnsToContents();
    ui->tableWidgetDatabase->setVisible(true);
    ui->tableWidgetDatabase->repaint();
}

/**
 * @brief MainWindow::updateColoringMethodsComboBoxes
 */
void MainWindow::updateColoringMethodsComboBoxes()
{
    int comboBoxNodeColor = ui->comboBoxNodeColor->currentIndex();
    int comboBoxEdgeColor = ui->comboBoxEdgeColor->currentIndex();
    ui->comboBoxNodeColor->clear();
    ui->comboBoxEdgeColor->clear();
    for(int i = 0; GraphLayoutGLOptions::nodeColorMethods[i]; i++)
    {
        QString item(GraphLayoutGLOptions::nodeColorMethods[i]);
        ui->comboBoxNodeColor->insertItem(i,item);
        if (  (item == QString("Custom RGB")) && !(this->glWidget->options.useCustomRGBColorMethod ) )
            qobject_cast<QStandardItemModel *>(ui->comboBoxNodeColor->model())->item( i )->setEnabled( false );
        else
            qobject_cast<QStandardItemModel *>(ui->comboBoxNodeColor->model())->item( i )->setEnabled( true );
    }

    for(int i = 0; GraphLayoutGLOptions::edgeColorMethods[i]; i++)
    {
        QString item(GraphLayoutGLOptions::edgeColorMethods[i]);
        ui->comboBoxEdgeColor->insertItem(i,item);
        if (  (item == QString("Custom RGB")) && !(this->glWidget->options.useCustomRGBColorMethod ) )
            qobject_cast<QStandardItemModel *>(ui->comboBoxEdgeColor->model())->item( i )->setEnabled( false );
        else
            qobject_cast<QStandardItemModel *>(ui->comboBoxEdgeColor->model())->item( i )->setEnabled( true );
    }
    ui->comboBoxNodeColor->setCurrentIndex(ui->comboBoxNodeColor->count()-1);
    ui->comboBoxEdgeColor->setCurrentIndex(ui->comboBoxEdgeColor->count()-1);
}

/**
 * @brief MainWindow::updateDataSetElement
 * @param nodeId
 * @param colNumber
 * @param value
 */
void MainWindow::updateDataSetElement(int row, int col, const QString val)
{
    ui->tableWidgetDatabase->item(row,col)->setText(val);
}

/**
 * @brief MainWindow::setSelectedNode
 * @param tableRow
 * @param tableColumn
 */
void MainWindow::setSelectedNode(int tableRow, int tableColumn)
{  if (tableRow==-1 || tableColumn==-1)
        return;
    if(glWidget->layoutThread.dataSet.graphGL->g == glWidget->layoutThread.dataSet.graphGL)
    {
        //qDebug() << "MainWindow::setSelectedNode-->selected node = " << ui->tableWidgetDatabase->item(tableRow,0)->text().toInt();
        emit  selectedNodeChanged(ui->tableWidgetDatabase->item(tableRow,0)->text().toInt());
    }
    glWidget->setFocus();
}

/**
 * @brief MainWindow::tableSetSelectedNode
 * @param lnode
 */
void MainWindow::tableSetSelectedNode(LNode *lnode)
{  if(lnode != NULL && glWidget->layoutThread.dataSet.graphGL->g == glWidget->layoutThread.dataSet.graphGL)
    {  ui->tableWidgetDatabase->scrollToItem(ui->tableWidgetDatabase->item(lnode->index-1,0));
        ui->tableWidgetDatabase->setCurrentCell(lnode->index-1,0);
        ui->tableWidgetDatabase->setFocus();
    }
}

/**
 * @brief MainWindow::autoStartLayout
 * @param index
 */
void MainWindow::autoStartLayout(int index)
{  if(isLayoutRunning)
    {  stopLayout();
        //    cerr << "starting layout!? " << isLayoutRunning << "\n";
        toggleLayout();
    }
}

/**
 * @brief MainWindow::saveImage
 * @param pathname
 */
void MainWindow::saveImage(const QString &pathame)
{
    QString qpathname;

    if(!pathame.isEmpty())
    {  qpathname = QString(pathame);
    }
    else
    {
        QString  *selectedFilter = new QString("PNG (*.png)");
        if (lastDir.isEmpty())
            lastDir = ":/samples/";
        qpathname = QFileDialog::getSaveFileName(
                    this,
                    "Save as image...",
                    lastDir,
                    "PNG (*.png);; XPM (*.xpm);; JPEG (*.jpg)",selectedFilter
            #ifdef __APPLE__ // workaround for a qt4.7.4 bug when using native dialogs
                    ,QFileDialog::DontUseNativeDialog);
#else
                    );
#endif
        if (selectedFilter)
            delete selectedFilter;
    }
    if(qpathname.isEmpty())
        return;
    QFileInfo fi(qpathname);
    lastDir = fi.absolutePath();
    if(glWidget->saveImage(qpathname) == false)
    {  QUtils::criticalMessage(this, "Unable to save image! Please, check pathname and file extension.");
    }
}

/**
 * @brief MainWindow::toggleFullScreen
 * @param v
 */
void MainWindow::toggleFullScreen(bool v)
{  if(v)
    {  QWidget::showFullScreen();
    }
    else
    {  QWidget::showNormal();
    }
    glWidget->keyCmdPressed = false; // questo fixa un bug credo di qt. non cè evento di rilascio del testo command quando si fa command-f, con il side-effect di lasciare abilitato lo spostazmento invece che la rotazione.
}

/**
 * @brief MainWindow::buy
 */
void MainWindow::buy()
{  //   cerr << "buy!\n";
    //glWidget->displayBuy();
    // Here we should start a simple widget to open a web page
}

/**
 * @brief MainWindow::emailUsSupport
 */
void MainWindow::emailUsSupport()
{  QDesktopServices::openUrl(QUrl("mailto:support@graphinsight.com?subject=support request&body=Hello,\n"));
}

/**
 * @brief MainWindow::emailUsPRO
 */
void MainWindow::emailUsPRO()
{  QDesktopServices::openUrl(QUrl("mailto:services@graphinsight.com?subject=licensing or services request&body=Hello,\n"));
}

/**
 * @brief MainWindow::openUrlSupport
 */
void MainWindow::openUrlSupport()
{  QDesktopServices::openUrl(QUrl("http://www.graphinsight.com/documentation"));
}

/**
 * @brief MainWindow::openUrlFeedback
 */
void MainWindow::openUrlFeedback()
{  QDesktopServices::openUrl(QUrl("http://www.graphinsight.com/contact-us"));
}

/**
 * @brief MainWindow::openUrlNews
 */
void MainWindow::openUrlNews()
{  QDesktopServices::openUrl(QUrl("http://www.graphinsight.com"));
}

/**
 * @brief MainWindow::openUrlLicensing
 */
void MainWindow::openUrlLicensing()
{  QDesktopServices::openUrl(QUrl("http://www.graphinsight.com/download"));
}

/**
 * @brief MainWindow::openUrlConsulting
 */
void MainWindow::openUrlConsulting()
{  QDesktopServices::openUrl(QUrl("http://www.graphinsight.com/services"));
}

/**
 * @brief MainWindow::openUrlBlog
 */
void MainWindow::openUrlBlog()
{  QDesktopServices::openUrl(QUrl("http://www.visual-analytics.org"));
}

/**
 * @brief MainWindow::fullScreenDisable
 */
void MainWindow::fullScreenDisable()
{  QWidget::showNormal();
}

/**
 * @brief MainWindow::radiusEdgeNodeChanged
 * @param v
 */
void MainWindow::radiusEdgeNodeChanged(int v)
{  glWidget->setNodeRadius(ui->horizontalSliderNodeRadius->value());
    glWidget->setEdgeRadius(ui->horizontalSliderEdgeRadius->value());
}

/**
 * @brief MainWindow::reloadFile
 */
void MainWindow::reloadFile()
{  return openFile(lastFile);
}

/**
 * @brief MainWindow::saveCurrentFile
 */
void MainWindow::saveCurrentFile()
{
    return saveFile(lastFile);
}

/**
 * @brief MainWindow::setLabelMinNodeDegree
 * @param v
 */
void MainWindow::setLabelMinNodeDegree(int v)
{  glWidget->setLabelMinNodeDegree(v);
}

/**
 * @brief MainWindow::setLabelFontSize
 * @param v
 */
void MainWindow::setLabelFontSize(int v)
{  glWidget->setLabelFontSize(v);
}

/**
 * @brief MainWindow::setSelectionLabel
 * @param v
 */
void MainWindow::setSelectionLabel(int v)
{  switch(v)
    {  case 0:
        glWidget->setLabelShowSelectedItem(false);
        glWidget->setLabelShowSelectedItemAdjacent(false);
        break;
    case 1:
        glWidget->setLabelShowSelectedItem(true);
        glWidget->setLabelShowSelectedItemAdjacent(false);
        break;
    case 2:
        glWidget->setLabelShowSelectedItem(true);
        glWidget->setLabelShowSelectedItemAdjacent(true);
        break;
    }
}

/**
 * @brief MainWindow::setLicensing
 * @param l
 */
void MainWindow::setLicensing(Licensing *l)
{  this->licensing = l;
}

/**
 * @brief MainWindow::quit
 */
void MainWindow::quit()
{
    settings->sync();
    settings->setValue("splitterSize",this->ui->tabWidget->size());
    settings->setValue("mainWindowSize",this->size());

    settings->setValue("tabwidgetSize",this->splitterHorizontalMain->sizes().at(0));
    settings->setValue("glWidgetSize",this->splitterHorizontalMain->sizes().at(1));
    settings->sync();

    if(glWidget->layoutThread.isRunning())
    {  stopLayout();
    }

}

/**
 * @brief MainWindow::overlapCheckBoxClicked
 * @param clicked
 */
void MainWindow::overlapCheckBoxClicked(bool clicked)
{  glWidget->setNonIntersectingLabels(clicked);
    glWidget->update();
}

/**
 * @brief MainWindow::onActionEnableConsoleTriggered Show or hide the console widget under the OpenGL widget
 * @param value
 */
void MainWindow::onActionEnableConsoleTriggered()
{
    this->glWidget->keyCmdPressed=false;
    this->glWidget->keyShiftPressed=false;
#ifdef USE_PYTHONQT
    if ( this->vertSplitterConsoleGlWidget->widget(1)->isHidden() )
    {   this->vertSplitterConsoleGlWidget->widget(1)->show();
        this->vertSplitterConsoleGlWidget->widget(1)->setFocus();
    }
    else
        this->vertSplitterConsoleGlWidget->widget(1)->hide();
    emit this->repaint();
#else
    QMessageBox::information( this, QString("Pro licensing"),QString("Please, buy a license for GraphInsight Pro 1.3.0 to activate the Python scripting console.\n"));
    QDesktopServices::openUrl(QUrl("http://www.graphinsight.com/download"));
#endif
}

void MainWindow::on_actionPreferences_triggered()
{
    OptionsDialog *optionsDialog = new OptionsDialog(this);
    optionsDialog->show();
}

/**
 * @brief MainWindow::printStatusBarStart
 * @param text
 */
void MainWindow::printStatusBarStart()
{
    this->ui->groupBoxGraphDrawing->setEnabled(false);
    this->ui->statusBar->showMessage("Computing ...");
}

/**
 * @brief MainWindow::printStatusBarStop
 */
void MainWindow::printStatusBarStop()
{
    this->ui->groupBoxGraphDrawing->setEnabled(true);
    this->ui->statusBar->showMessage("Finished");
}

/**
 * @brief MainWindow::on_comboBoxLabelColumn_currentIndexChanged
 * @param index
 */
void MainWindow::on_comboBoxLabelColumn_currentIndexChanged(int index)
{
    this->glWidget->options.currentVisibleAttribute=index;
    this->glWidget->updateGL();
}
