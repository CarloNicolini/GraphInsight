/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Wed Apr 23 09:57:40 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_graph;
    QAction *actionAbout;
    QAction *actionSaveGraphLayout;
    QAction *actionSaveAsImage;
    QAction *actionOnline_documentation;
    QAction *actionFullscreen;
    QAction *actionDocumentationPDF;
    QAction *actionLatest_news;
    QAction *actionSend_feedback;
    QAction *actionPDF_User_tutorial;
    QAction *actionPROLicensing;
    QAction *actionFullScreenEsc;
    QAction *actionReload_this_File;
    QAction *actionSave;
    QAction *actionPROConsulting;
    QAction *actionVisual_analytics_org_blog;
    QAction *actionEmailUsSupport;
    QAction *actionEmailUsPro;
    QAction *actionQuit;
    QAction *actionEnablePythonConsole;
    QAction *actionPreferences;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabDatabase;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelRegExpFilter;
    QLineEdit *lineEditRegExpFilter;
    QCheckBox *checkBoxRegExpCaseSensitive;
    QVBoxLayout *verticalLayoutDatabaseSelectedItem;
    QTableWidget *tableWidgetDatabase;
    QLabel *labelDatabaseSelectedItem;
    QTreeWidget *treeWidgetSelectedItem;
    QWidget *tabVisualization;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxGraphDrawing;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboBoxAlgorithm;
    QHBoxLayout *horizontalLayoutDimensionStart;
    QComboBox *comboBoxDimension;
    QPushButton *pushButtonStartStop;
    QGroupBox *groupBoxGlobalVisualization;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayoutNPolygons;
    QLabel *labelNPolygons;
    QComboBox *comboBoxGlobalQuality;
    QHBoxLayout *horizontalLayoutVirtualWorld;
    QLabel *labelVirtualWorld;
    QCheckBox *checkBoxShowGrid;
    QCheckBox *checkBoxSetNight;
    QGroupBox *groupBoxNodes;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayoutNodeRadius;
    QLabel *labelNodeRadius;
    QSlider *horizontalSliderNodeRadius;
    QSpinBox *spinBoxNodeRadius;
    QHBoxLayout *horizontalLayoutNodeColor;
    QLabel *labelNodeColor;
    QComboBox *comboBoxNodeColor;
    QHBoxLayout *horizontalLayoutNodeDegreeFilter;
    QLabel *labelNodeDegreeFilter;
    QSlider *horizontalSliderFilterMinNodeDegree;
    QSpinBox *spinBoxFilterMinNodeDegree;
    QGroupBox *groupBoxEdges;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelEdgeRadius;
    QSlider *horizontalSliderEdgeRadius;
    QSpinBox *spinBoxEdgeRadius;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelEdgeColor;
    QComboBox *comboBoxEdgeColor;
    QHBoxLayout *horizontalLayout_15;
    QComboBox *comboBoxEdgeType;
    QGroupBox *groupBoxLabels;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayoutNodeLabelDegreeFilter;
    QLabel *labelNodeLabelDegreeFilter;
    QSlider *horizontalSliderLabelMinDegree;
    QSpinBox *spinBoxLabelMinDegree;
    QHBoxLayout *horizontalLayoutLabelFontSize;
    QLabel *labelLabelFontSize;
    QSlider *horizontalSliderLabelFontSize;
    QSpinBox *spinBoxLabelFontSize;
    QHBoxLayout *horizontalLayoutLabelColumn;
    QLabel *labelLabelColumn;
    QComboBox *comboBoxLabelColumn;
    QComboBox *comboBoxSelectLabel;
    QCheckBox *checkBoxRemoveLabelOverlaps;
    QSpacerItem *verticalSpacer;
    QWidget *tabStatistic;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *treeWidgetStatistic;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuGraphInsight;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuPRO;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(380, 922);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionOpen_graph = new QAction(MainWindow);
        actionOpen_graph->setObjectName(QString::fromUtf8("actionOpen_graph"));
        actionOpen_graph->setEnabled(true);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSaveGraphLayout = new QAction(MainWindow);
        actionSaveGraphLayout->setObjectName(QString::fromUtf8("actionSaveGraphLayout"));
        actionSaveGraphLayout->setEnabled(true);
        actionSaveAsImage = new QAction(MainWindow);
        actionSaveAsImage->setObjectName(QString::fromUtf8("actionSaveAsImage"));
        actionOnline_documentation = new QAction(MainWindow);
        actionOnline_documentation->setObjectName(QString::fromUtf8("actionOnline_documentation"));
        actionOnline_documentation->setEnabled(true);
        actionFullscreen = new QAction(MainWindow);
        actionFullscreen->setObjectName(QString::fromUtf8("actionFullscreen"));
        actionFullscreen->setCheckable(true);
        actionFullscreen->setEnabled(true);
        QFont font;
        actionFullscreen->setFont(font);
        actionDocumentationPDF = new QAction(MainWindow);
        actionDocumentationPDF->setObjectName(QString::fromUtf8("actionDocumentationPDF"));
        actionDocumentationPDF->setEnabled(false);
        actionLatest_news = new QAction(MainWindow);
        actionLatest_news->setObjectName(QString::fromUtf8("actionLatest_news"));
        actionLatest_news->setEnabled(false);
        actionSend_feedback = new QAction(MainWindow);
        actionSend_feedback->setObjectName(QString::fromUtf8("actionSend_feedback"));
        actionSend_feedback->setEnabled(false);
        actionPDF_User_tutorial = new QAction(MainWindow);
        actionPDF_User_tutorial->setObjectName(QString::fromUtf8("actionPDF_User_tutorial"));
        actionPROLicensing = new QAction(MainWindow);
        actionPROLicensing->setObjectName(QString::fromUtf8("actionPROLicensing"));
        actionPROLicensing->setEnabled(true);
        actionFullScreenEsc = new QAction(MainWindow);
        actionFullScreenEsc->setObjectName(QString::fromUtf8("actionFullScreenEsc"));
        actionReload_this_File = new QAction(MainWindow);
        actionReload_this_File->setObjectName(QString::fromUtf8("actionReload_this_File"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionPROConsulting = new QAction(MainWindow);
        actionPROConsulting->setObjectName(QString::fromUtf8("actionPROConsulting"));
        actionPROConsulting->setEnabled(true);
        actionVisual_analytics_org_blog = new QAction(MainWindow);
        actionVisual_analytics_org_blog->setObjectName(QString::fromUtf8("actionVisual_analytics_org_blog"));
        actionVisual_analytics_org_blog->setEnabled(true);
        actionEmailUsSupport = new QAction(MainWindow);
        actionEmailUsSupport->setObjectName(QString::fromUtf8("actionEmailUsSupport"));
        actionEmailUsSupport->setEnabled(true);
        actionEmailUsPro = new QAction(MainWindow);
        actionEmailUsPro->setObjectName(QString::fromUtf8("actionEmailUsPro"));
        actionEmailUsPro->setEnabled(true);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionEnablePythonConsole = new QAction(MainWindow);
        actionEnablePythonConsole->setObjectName(QString::fromUtf8("actionEnablePythonConsole"));
        actionEnablePythonConsole->setCheckable(true);
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(9, 9, 362, 856));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setBaseSize(QSize(0, 0));
        tabDatabase = new QWidget();
        tabDatabase->setObjectName(QString::fromUtf8("tabDatabase"));
        sizePolicy.setHeightForWidth(tabDatabase->sizePolicy().hasHeightForWidth());
        tabDatabase->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(tabDatabase);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelRegExpFilter = new QLabel(tabDatabase);
        labelRegExpFilter->setObjectName(QString::fromUtf8("labelRegExpFilter"));

        horizontalLayout_4->addWidget(labelRegExpFilter);

        lineEditRegExpFilter = new QLineEdit(tabDatabase);
        lineEditRegExpFilter->setObjectName(QString::fromUtf8("lineEditRegExpFilter"));

        horizontalLayout_4->addWidget(lineEditRegExpFilter);

        checkBoxRegExpCaseSensitive = new QCheckBox(tabDatabase);
        checkBoxRegExpCaseSensitive->setObjectName(QString::fromUtf8("checkBoxRegExpCaseSensitive"));

        horizontalLayout_4->addWidget(checkBoxRegExpCaseSensitive);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayoutDatabaseSelectedItem = new QVBoxLayout();
        verticalLayoutDatabaseSelectedItem->setSpacing(6);
        verticalLayoutDatabaseSelectedItem->setObjectName(QString::fromUtf8("verticalLayoutDatabaseSelectedItem"));
        tableWidgetDatabase = new QTableWidget(tabDatabase);
        tableWidgetDatabase->setObjectName(QString::fromUtf8("tableWidgetDatabase"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidgetDatabase->sizePolicy().hasHeightForWidth());
        tableWidgetDatabase->setSizePolicy(sizePolicy1);
        tableWidgetDatabase->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetDatabase->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetDatabase->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetDatabase->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidgetDatabase->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidgetDatabase->horizontalHeader()->setStretchLastSection(true);
        tableWidgetDatabase->verticalHeader()->setVisible(false);

        verticalLayoutDatabaseSelectedItem->addWidget(tableWidgetDatabase);

        labelDatabaseSelectedItem = new QLabel(tabDatabase);
        labelDatabaseSelectedItem->setObjectName(QString::fromUtf8("labelDatabaseSelectedItem"));

        verticalLayoutDatabaseSelectedItem->addWidget(labelDatabaseSelectedItem);

        treeWidgetSelectedItem = new QTreeWidget(tabDatabase);
        treeWidgetSelectedItem->setObjectName(QString::fromUtf8("treeWidgetSelectedItem"));
        sizePolicy.setHeightForWidth(treeWidgetSelectedItem->sizePolicy().hasHeightForWidth());
        treeWidgetSelectedItem->setSizePolicy(sizePolicy);
        treeWidgetSelectedItem->setMidLineWidth(0);
        treeWidgetSelectedItem->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        treeWidgetSelectedItem->setAlternatingRowColors(true);
        treeWidgetSelectedItem->setSelectionBehavior(QAbstractItemView::SelectItems);
        treeWidgetSelectedItem->setSortingEnabled(true);
        treeWidgetSelectedItem->setAnimated(false);
        treeWidgetSelectedItem->header()->setHighlightSections(false);

        verticalLayoutDatabaseSelectedItem->addWidget(treeWidgetSelectedItem);


        verticalLayout->addLayout(verticalLayoutDatabaseSelectedItem);

        tabWidget->addTab(tabDatabase, QString());
        tabVisualization = new QWidget();
        tabVisualization->setObjectName(QString::fromUtf8("tabVisualization"));
        sizePolicy.setHeightForWidth(tabVisualization->sizePolicy().hasHeightForWidth());
        tabVisualization->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(tabVisualization);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBoxGraphDrawing = new QGroupBox(tabVisualization);
        groupBoxGraphDrawing->setObjectName(QString::fromUtf8("groupBoxGraphDrawing"));
        sizePolicy.setHeightForWidth(groupBoxGraphDrawing->sizePolicy().hasHeightForWidth());
        groupBoxGraphDrawing->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(groupBoxGraphDrawing);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        comboBoxAlgorithm = new QComboBox(groupBoxGraphDrawing);
        comboBoxAlgorithm->setObjectName(QString::fromUtf8("comboBoxAlgorithm"));
        comboBoxAlgorithm->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBoxAlgorithm->sizePolicy().hasHeightForWidth());
        comboBoxAlgorithm->setSizePolicy(sizePolicy2);
        comboBoxAlgorithm->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_5->addWidget(comboBoxAlgorithm);

        horizontalLayoutDimensionStart = new QHBoxLayout();
        horizontalLayoutDimensionStart->setSpacing(6);
        horizontalLayoutDimensionStart->setObjectName(QString::fromUtf8("horizontalLayoutDimensionStart"));
        comboBoxDimension = new QComboBox(groupBoxGraphDrawing);
        comboBoxDimension->setObjectName(QString::fromUtf8("comboBoxDimension"));
        comboBoxDimension->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBoxDimension->sizePolicy().hasHeightForWidth());
        comboBoxDimension->setSizePolicy(sizePolicy3);

        horizontalLayoutDimensionStart->addWidget(comboBoxDimension);

        pushButtonStartStop = new QPushButton(groupBoxGraphDrawing);
        pushButtonStartStop->setObjectName(QString::fromUtf8("pushButtonStartStop"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButtonStartStop->sizePolicy().hasHeightForWidth());
        pushButtonStartStop->setSizePolicy(sizePolicy4);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonStartStop->setIcon(icon);

        horizontalLayoutDimensionStart->addWidget(pushButtonStartStop);


        verticalLayout_5->addLayout(horizontalLayoutDimensionStart);


        verticalLayout_2->addWidget(groupBoxGraphDrawing);

        groupBoxGlobalVisualization = new QGroupBox(tabVisualization);
        groupBoxGlobalVisualization->setObjectName(QString::fromUtf8("groupBoxGlobalVisualization"));
        verticalLayout_4 = new QVBoxLayout(groupBoxGlobalVisualization);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayoutNPolygons = new QHBoxLayout();
        horizontalLayoutNPolygons->setSpacing(6);
        horizontalLayoutNPolygons->setObjectName(QString::fromUtf8("horizontalLayoutNPolygons"));
        labelNPolygons = new QLabel(groupBoxGlobalVisualization);
        labelNPolygons->setObjectName(QString::fromUtf8("labelNPolygons"));

        horizontalLayoutNPolygons->addWidget(labelNPolygons);

        comboBoxGlobalQuality = new QComboBox(groupBoxGlobalVisualization);
        comboBoxGlobalQuality->setObjectName(QString::fromUtf8("comboBoxGlobalQuality"));
        sizePolicy2.setHeightForWidth(comboBoxGlobalQuality->sizePolicy().hasHeightForWidth());
        comboBoxGlobalQuality->setSizePolicy(sizePolicy2);

        horizontalLayoutNPolygons->addWidget(comboBoxGlobalQuality);


        verticalLayout_4->addLayout(horizontalLayoutNPolygons);

        horizontalLayoutVirtualWorld = new QHBoxLayout();
        horizontalLayoutVirtualWorld->setSpacing(6);
        horizontalLayoutVirtualWorld->setObjectName(QString::fromUtf8("horizontalLayoutVirtualWorld"));
        labelVirtualWorld = new QLabel(groupBoxGlobalVisualization);
        labelVirtualWorld->setObjectName(QString::fromUtf8("labelVirtualWorld"));

        horizontalLayoutVirtualWorld->addWidget(labelVirtualWorld);

        checkBoxShowGrid = new QCheckBox(groupBoxGlobalVisualization);
        checkBoxShowGrid->setObjectName(QString::fromUtf8("checkBoxShowGrid"));
        checkBoxShowGrid->setChecked(false);

        horizontalLayoutVirtualWorld->addWidget(checkBoxShowGrid);

        checkBoxSetNight = new QCheckBox(groupBoxGlobalVisualization);
        checkBoxSetNight->setObjectName(QString::fromUtf8("checkBoxSetNight"));
        checkBoxSetNight->setChecked(false);

        horizontalLayoutVirtualWorld->addWidget(checkBoxSetNight);


        verticalLayout_4->addLayout(horizontalLayoutVirtualWorld);


        verticalLayout_2->addWidget(groupBoxGlobalVisualization);

        groupBoxNodes = new QGroupBox(tabVisualization);
        groupBoxNodes->setObjectName(QString::fromUtf8("groupBoxNodes"));
        verticalLayout_8 = new QVBoxLayout(groupBoxNodes);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayoutNodeRadius = new QHBoxLayout();
        horizontalLayoutNodeRadius->setSpacing(6);
        horizontalLayoutNodeRadius->setObjectName(QString::fromUtf8("horizontalLayoutNodeRadius"));
        horizontalLayoutNodeRadius->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelNodeRadius = new QLabel(groupBoxNodes);
        labelNodeRadius->setObjectName(QString::fromUtf8("labelNodeRadius"));
        sizePolicy3.setHeightForWidth(labelNodeRadius->sizePolicy().hasHeightForWidth());
        labelNodeRadius->setSizePolicy(sizePolicy3);

        horizontalLayoutNodeRadius->addWidget(labelNodeRadius);

        horizontalSliderNodeRadius = new QSlider(groupBoxNodes);
        horizontalSliderNodeRadius->setObjectName(QString::fromUtf8("horizontalSliderNodeRadius"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(horizontalSliderNodeRadius->sizePolicy().hasHeightForWidth());
        horizontalSliderNodeRadius->setSizePolicy(sizePolicy5);
        horizontalSliderNodeRadius->setMinimumSize(QSize(100, 0));
        horizontalSliderNodeRadius->setMinimum(0);
        horizontalSliderNodeRadius->setMaximum(100);
        horizontalSliderNodeRadius->setValue(50);
        horizontalSliderNodeRadius->setSliderPosition(50);
        horizontalSliderNodeRadius->setOrientation(Qt::Horizontal);

        horizontalLayoutNodeRadius->addWidget(horizontalSliderNodeRadius);

        spinBoxNodeRadius = new QSpinBox(groupBoxNodes);
        spinBoxNodeRadius->setObjectName(QString::fromUtf8("spinBoxNodeRadius"));
        sizePolicy3.setHeightForWidth(spinBoxNodeRadius->sizePolicy().hasHeightForWidth());
        spinBoxNodeRadius->setSizePolicy(sizePolicy3);
        spinBoxNodeRadius->setMaximum(100);

        horizontalLayoutNodeRadius->addWidget(spinBoxNodeRadius);


        verticalLayout_8->addLayout(horizontalLayoutNodeRadius);

        horizontalLayoutNodeColor = new QHBoxLayout();
        horizontalLayoutNodeColor->setSpacing(6);
        horizontalLayoutNodeColor->setObjectName(QString::fromUtf8("horizontalLayoutNodeColor"));
        labelNodeColor = new QLabel(groupBoxNodes);
        labelNodeColor->setObjectName(QString::fromUtf8("labelNodeColor"));
        sizePolicy3.setHeightForWidth(labelNodeColor->sizePolicy().hasHeightForWidth());
        labelNodeColor->setSizePolicy(sizePolicy3);

        horizontalLayoutNodeColor->addWidget(labelNodeColor);

        comboBoxNodeColor = new QComboBox(groupBoxNodes);
        comboBoxNodeColor->setObjectName(QString::fromUtf8("comboBoxNodeColor"));
        comboBoxNodeColor->setFocusPolicy(Qt::ClickFocus);

        horizontalLayoutNodeColor->addWidget(comboBoxNodeColor);


        verticalLayout_8->addLayout(horizontalLayoutNodeColor);

        horizontalLayoutNodeDegreeFilter = new QHBoxLayout();
        horizontalLayoutNodeDegreeFilter->setSpacing(6);
        horizontalLayoutNodeDegreeFilter->setObjectName(QString::fromUtf8("horizontalLayoutNodeDegreeFilter"));
        labelNodeDegreeFilter = new QLabel(groupBoxNodes);
        labelNodeDegreeFilter->setObjectName(QString::fromUtf8("labelNodeDegreeFilter"));

        horizontalLayoutNodeDegreeFilter->addWidget(labelNodeDegreeFilter);

        horizontalSliderFilterMinNodeDegree = new QSlider(groupBoxNodes);
        horizontalSliderFilterMinNodeDegree->setObjectName(QString::fromUtf8("horizontalSliderFilterMinNodeDegree"));
        sizePolicy4.setHeightForWidth(horizontalSliderFilterMinNodeDegree->sizePolicy().hasHeightForWidth());
        horizontalSliderFilterMinNodeDegree->setSizePolicy(sizePolicy4);
        horizontalSliderFilterMinNodeDegree->setOrientation(Qt::Horizontal);

        horizontalLayoutNodeDegreeFilter->addWidget(horizontalSliderFilterMinNodeDegree);

        spinBoxFilterMinNodeDegree = new QSpinBox(groupBoxNodes);
        spinBoxFilterMinNodeDegree->setObjectName(QString::fromUtf8("spinBoxFilterMinNodeDegree"));
        sizePolicy3.setHeightForWidth(spinBoxFilterMinNodeDegree->sizePolicy().hasHeightForWidth());
        spinBoxFilterMinNodeDegree->setSizePolicy(sizePolicy3);

        horizontalLayoutNodeDegreeFilter->addWidget(spinBoxFilterMinNodeDegree);


        verticalLayout_8->addLayout(horizontalLayoutNodeDegreeFilter);


        verticalLayout_2->addWidget(groupBoxNodes);

        groupBoxEdges = new QGroupBox(tabVisualization);
        groupBoxEdges->setObjectName(QString::fromUtf8("groupBoxEdges"));
        verticalLayout_9 = new QVBoxLayout(groupBoxEdges);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelEdgeRadius = new QLabel(groupBoxEdges);
        labelEdgeRadius->setObjectName(QString::fromUtf8("labelEdgeRadius"));
        sizePolicy3.setHeightForWidth(labelEdgeRadius->sizePolicy().hasHeightForWidth());
        labelEdgeRadius->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(labelEdgeRadius);

        horizontalSliderEdgeRadius = new QSlider(groupBoxEdges);
        horizontalSliderEdgeRadius->setObjectName(QString::fromUtf8("horizontalSliderEdgeRadius"));
        sizePolicy5.setHeightForWidth(horizontalSliderEdgeRadius->sizePolicy().hasHeightForWidth());
        horizontalSliderEdgeRadius->setSizePolicy(sizePolicy5);
        horizontalSliderEdgeRadius->setMinimumSize(QSize(100, 0));
        horizontalSliderEdgeRadius->setMinimum(0);
        horizontalSliderEdgeRadius->setMaximum(100);
        horizontalSliderEdgeRadius->setValue(50);
        horizontalSliderEdgeRadius->setSliderPosition(50);
        horizontalSliderEdgeRadius->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(horizontalSliderEdgeRadius);

        spinBoxEdgeRadius = new QSpinBox(groupBoxEdges);
        spinBoxEdgeRadius->setObjectName(QString::fromUtf8("spinBoxEdgeRadius"));
        sizePolicy3.setHeightForWidth(spinBoxEdgeRadius->sizePolicy().hasHeightForWidth());
        spinBoxEdgeRadius->setSizePolicy(sizePolicy3);
        spinBoxEdgeRadius->setMaximum(100);

        horizontalLayout_6->addWidget(spinBoxEdgeRadius);


        verticalLayout_9->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelEdgeColor = new QLabel(groupBoxEdges);
        labelEdgeColor->setObjectName(QString::fromUtf8("labelEdgeColor"));
        sizePolicy3.setHeightForWidth(labelEdgeColor->sizePolicy().hasHeightForWidth());
        labelEdgeColor->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(labelEdgeColor);

        comboBoxEdgeColor = new QComboBox(groupBoxEdges);
        comboBoxEdgeColor->setObjectName(QString::fromUtf8("comboBoxEdgeColor"));
        comboBoxEdgeColor->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(comboBoxEdgeColor);


        verticalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        comboBoxEdgeType = new QComboBox(groupBoxEdges);
        comboBoxEdgeType->setObjectName(QString::fromUtf8("comboBoxEdgeType"));

        horizontalLayout_15->addWidget(comboBoxEdgeType);


        verticalLayout_9->addLayout(horizontalLayout_15);


        verticalLayout_2->addWidget(groupBoxEdges);

        groupBoxLabels = new QGroupBox(tabVisualization);
        groupBoxLabels->setObjectName(QString::fromUtf8("groupBoxLabels"));
        verticalLayout_10 = new QVBoxLayout(groupBoxLabels);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayoutNodeLabelDegreeFilter = new QHBoxLayout();
        horizontalLayoutNodeLabelDegreeFilter->setSpacing(6);
        horizontalLayoutNodeLabelDegreeFilter->setObjectName(QString::fromUtf8("horizontalLayoutNodeLabelDegreeFilter"));
        labelNodeLabelDegreeFilter = new QLabel(groupBoxLabels);
        labelNodeLabelDegreeFilter->setObjectName(QString::fromUtf8("labelNodeLabelDegreeFilter"));

        horizontalLayoutNodeLabelDegreeFilter->addWidget(labelNodeLabelDegreeFilter);

        horizontalSliderLabelMinDegree = new QSlider(groupBoxLabels);
        horizontalSliderLabelMinDegree->setObjectName(QString::fromUtf8("horizontalSliderLabelMinDegree"));
        horizontalSliderLabelMinDegree->setOrientation(Qt::Horizontal);

        horizontalLayoutNodeLabelDegreeFilter->addWidget(horizontalSliderLabelMinDegree);

        spinBoxLabelMinDegree = new QSpinBox(groupBoxLabels);
        spinBoxLabelMinDegree->setObjectName(QString::fromUtf8("spinBoxLabelMinDegree"));

        horizontalLayoutNodeLabelDegreeFilter->addWidget(spinBoxLabelMinDegree);


        verticalLayout_10->addLayout(horizontalLayoutNodeLabelDegreeFilter);

        horizontalLayoutLabelFontSize = new QHBoxLayout();
        horizontalLayoutLabelFontSize->setSpacing(6);
        horizontalLayoutLabelFontSize->setObjectName(QString::fromUtf8("horizontalLayoutLabelFontSize"));
        labelLabelFontSize = new QLabel(groupBoxLabels);
        labelLabelFontSize->setObjectName(QString::fromUtf8("labelLabelFontSize"));

        horizontalLayoutLabelFontSize->addWidget(labelLabelFontSize);

        horizontalSliderLabelFontSize = new QSlider(groupBoxLabels);
        horizontalSliderLabelFontSize->setObjectName(QString::fromUtf8("horizontalSliderLabelFontSize"));
        horizontalSliderLabelFontSize->setMinimum(1);
        horizontalSliderLabelFontSize->setMaximum(50);
        horizontalSliderLabelFontSize->setValue(1);
        horizontalSliderLabelFontSize->setOrientation(Qt::Horizontal);

        horizontalLayoutLabelFontSize->addWidget(horizontalSliderLabelFontSize);

        spinBoxLabelFontSize = new QSpinBox(groupBoxLabels);
        spinBoxLabelFontSize->setObjectName(QString::fromUtf8("spinBoxLabelFontSize"));
        spinBoxLabelFontSize->setMinimum(1);
        spinBoxLabelFontSize->setMaximum(30);

        horizontalLayoutLabelFontSize->addWidget(spinBoxLabelFontSize);


        verticalLayout_10->addLayout(horizontalLayoutLabelFontSize);

        horizontalLayoutLabelColumn = new QHBoxLayout();
        horizontalLayoutLabelColumn->setSpacing(6);
        horizontalLayoutLabelColumn->setObjectName(QString::fromUtf8("horizontalLayoutLabelColumn"));
        labelLabelColumn = new QLabel(groupBoxLabels);
        labelLabelColumn->setObjectName(QString::fromUtf8("labelLabelColumn"));

        horizontalLayoutLabelColumn->addWidget(labelLabelColumn);

        comboBoxLabelColumn = new QComboBox(groupBoxLabels);
        comboBoxLabelColumn->setObjectName(QString::fromUtf8("comboBoxLabelColumn"));
        sizePolicy4.setHeightForWidth(comboBoxLabelColumn->sizePolicy().hasHeightForWidth());
        comboBoxLabelColumn->setSizePolicy(sizePolicy4);

        horizontalLayoutLabelColumn->addWidget(comboBoxLabelColumn);


        verticalLayout_10->addLayout(horizontalLayoutLabelColumn);

        comboBoxSelectLabel = new QComboBox(groupBoxLabels);
        comboBoxSelectLabel->setObjectName(QString::fromUtf8("comboBoxSelectLabel"));

        verticalLayout_10->addWidget(comboBoxSelectLabel);

        checkBoxRemoveLabelOverlaps = new QCheckBox(groupBoxLabels);
        checkBoxRemoveLabelOverlaps->setObjectName(QString::fromUtf8("checkBoxRemoveLabelOverlaps"));

        verticalLayout_10->addWidget(checkBoxRemoveLabelOverlaps);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);


        verticalLayout_2->addWidget(groupBoxLabels);

        tabWidget->addTab(tabVisualization, QString());
        tabStatistic = new QWidget();
        tabStatistic->setObjectName(QString::fromUtf8("tabStatistic"));
        verticalLayout_3 = new QVBoxLayout(tabStatistic);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        treeWidgetStatistic = new QTreeWidget(tabStatistic);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidgetStatistic);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidgetStatistic);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidgetStatistic);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidgetStatistic);
        new QTreeWidgetItem(__qtreewidgetitem3);
        treeWidgetStatistic->setObjectName(QString::fromUtf8("treeWidgetStatistic"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(treeWidgetStatistic->sizePolicy().hasHeightForWidth());
        treeWidgetStatistic->setSizePolicy(sizePolicy6);
        treeWidgetStatistic->setMaximumSize(QSize(16777215, 16777215));
        treeWidgetStatistic->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        treeWidgetStatistic->setAlternatingRowColors(true);
        treeWidgetStatistic->setAutoExpandDelay(-1);
        treeWidgetStatistic->setUniformRowHeights(false);
        treeWidgetStatistic->setWordWrap(false);
        treeWidgetStatistic->setColumnCount(2);
        treeWidgetStatistic->header()->setCascadingSectionResizes(false);
        treeWidgetStatistic->header()->setDefaultSectionSize(100);
        treeWidgetStatistic->header()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout_3->addWidget(treeWidgetStatistic);

        tabWidget->addTab(tabStatistic, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 380, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuGraphInsight = new QMenu(menuBar);
        menuGraphInsight->setObjectName(QString::fromUtf8("menuGraphInsight"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuHelp->setEnabled(true);
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuPRO = new QMenu(menuBar);
        menuPRO->setObjectName(QString::fromUtf8("menuPRO"));
        menuPRO->setEnabled(true);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGraphInsight->menuAction());
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuPRO->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_graph);
        menuFile->addAction(actionSaveGraphLayout);
        menuFile->addSeparator();
        menuFile->addAction(actionReload_this_File);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionSaveAsImage);
        menuGraphInsight->addAction(actionAbout);
        menuGraphInsight->addAction(actionQuit);
        menuHelp->addSeparator();
        menuHelp->addAction(actionOnline_documentation);
        menuHelp->addAction(actionEmailUsSupport);
        menuHelp->addSeparator();
        menuHelp->addAction(actionVisual_analytics_org_blog);
        menuView->addAction(actionFullscreen);
        menuView->addAction(actionEnablePythonConsole);
        menuPRO->addAction(actionPROLicensing);
        menuPRO->addAction(actionPROConsulting);
        menuPRO->addSeparator();
        menuPRO->addAction(actionEmailUsPro);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);
        comboBoxDimension->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "nothing", 0, QApplication::UnicodeUTF8));
        actionOpen_graph->setText(QApplication::translate("MainWindow", "Open File...", 0, QApplication::UnicodeUTF8));
        actionOpen_graph->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", 0, QApplication::UnicodeUTF8));
        actionSaveGraphLayout->setText(QApplication::translate("MainWindow", "Export as...", 0, QApplication::UnicodeUTF8));
        actionSaveGraphLayout->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSaveAsImage->setText(QApplication::translate("MainWindow", "Save as image...", 0, QApplication::UnicodeUTF8));
        actionSaveAsImage->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionOnline_documentation->setText(QApplication::translate("MainWindow", "Online Documentation Central", 0, QApplication::UnicodeUTF8));
        actionFullscreen->setText(QApplication::translate("MainWindow", "FullScreen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFullscreen->setToolTip(QApplication::translate("MainWindow", "[PRO] FullScreen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFullscreen->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionDocumentationPDF->setText(QApplication::translate("MainWindow", "User Manual (pdf)", 0, QApplication::UnicodeUTF8));
        actionLatest_news->setText(QApplication::translate("MainWindow", "Latest news...", 0, QApplication::UnicodeUTF8));
        actionSend_feedback->setText(QApplication::translate("MainWindow", "Send feedback...", 0, QApplication::UnicodeUTF8));
        actionPDF_User_tutorial->setText(QApplication::translate("MainWindow", "PDF User tutorial", 0, QApplication::UnicodeUTF8));
        actionPROLicensing->setText(QApplication::translate("MainWindow", "Switch to GraphInsight Pro/Academic", 0, QApplication::UnicodeUTF8));
        actionFullScreenEsc->setText(QApplication::translate("MainWindow", "FullScreenEsc", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFullScreenEsc->setToolTip(QApplication::translate("MainWindow", "FullScreenEsc", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFullScreenEsc->setShortcut(QApplication::translate("MainWindow", "Esc", 0, QApplication::UnicodeUTF8));
        actionReload_this_File->setText(QApplication::translate("MainWindow", "Reload", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionPROConsulting->setText(QApplication::translate("MainWindow", "We offer consulting, integration, customization and training", 0, QApplication::UnicodeUTF8));
        actionVisual_analytics_org_blog->setText(QApplication::translate("MainWindow", "Visit our blog http://www.visual-analytics.org", 0, QApplication::UnicodeUTF8));
        actionEmailUsSupport->setText(QApplication::translate("MainWindow", "Contact Us: support@graphinsight.com", 0, QApplication::UnicodeUTF8));
        actionEmailUsPro->setText(QApplication::translate("MainWindow", "Contact Us: services@graphinsight.com", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionEnablePythonConsole->setText(QApplication::translate("MainWindow", "Show/Hide Python console", 0, QApplication::UnicodeUTF8));
        actionEnablePythonConsole->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences...", 0, QApplication::UnicodeUTF8));
        actionPreferences->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelRegExpFilter->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Search through regular expressions</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelRegExpFilter->setText(QApplication::translate("MainWindow", "Search:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEditRegExpFilter->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Search through regular expressions</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBoxRegExpCaseSensitive->setText(QApplication::translate("MainWindow", "CaseSensitive", 0, QApplication::UnicodeUTF8));
        labelDatabaseSelectedItem->setText(QApplication::translate("MainWindow", "Details of selected item:", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetSelectedItem->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Property", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabDatabase), QApplication::translate("MainWindow", "Database", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabToolTip(tabWidget->indexOf(tabDatabase), QApplication::translate("MainWindow", "Nodes and their attributes", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBoxGraphDrawing->setToolTip(QApplication::translate("MainWindow", "Choose the graph drawing technique to use and no. of dimensions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBoxGraphDrawing->setTitle(QApplication::translate("MainWindow", "Graph drawing", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        comboBoxAlgorithm->setToolTip(QApplication::translate("MainWindow", "Select the layout algorithm (graph drawing problem)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        comboBoxDimension->clear();
        comboBoxDimension->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3D", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBoxDimension->setToolTip(QApplication::translate("MainWindow", "Select the number of dimensions (2D/3D) of the virtual world", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonStartStop->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBoxGlobalVisualization->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        groupBoxGlobalVisualization->setTitle(QApplication::translate("MainWindow", "Global", 0, QApplication::UnicodeUTF8));
        labelNPolygons->setText(QApplication::translate("MainWindow", "No. of Polygons:", 0, QApplication::UnicodeUTF8));
        comboBoxGlobalQuality->clear();
        comboBoxGlobalQuality->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0 (lines and points)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "64", 0, QApplication::UnicodeUTF8)
        );
        labelVirtualWorld->setText(QApplication::translate("MainWindow", "Virtual world:", 0, QApplication::UnicodeUTF8));
        checkBoxShowGrid->setText(QApplication::translate("MainWindow", "Show Grid ", 0, QApplication::UnicodeUTF8));
        checkBoxSetNight->setText(QApplication::translate("MainWindow", "Night", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBoxNodes->setToolTip(QApplication::translate("MainWindow", "Visualization options for nodes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBoxNodes->setTitle(QApplication::translate("MainWindow", "Nodes", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        labelNodeRadius->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Specify nodes radius</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelNodeRadius->setText(QApplication::translate("MainWindow", "Radius:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        horizontalSliderNodeRadius->setToolTip(QApplication::translate("MainWindow", "Scale Up/Down the nodes radius", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelNodeColor->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Specify nodes coloring method</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelNodeColor->setText(QApplication::translate("MainWindow", "Color:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        comboBoxNodeColor->setToolTip(QApplication::translate("MainWindow", "Select the coloring scheme for nodes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelNodeDegreeFilter->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Filter nodes with degree bigger than a threshold</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelNodeDegreeFilter->setText(QApplication::translate("MainWindow", "Degree \342\211\245", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBoxEdges->setToolTip(QApplication::translate("MainWindow", "Visualization options for edges", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBoxEdges->setTitle(QApplication::translate("MainWindow", "Edges", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        labelEdgeRadius->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Specify edges radius</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelEdgeRadius->setText(QApplication::translate("MainWindow", "Radius:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        horizontalSliderEdgeRadius->setToolTip(QApplication::translate("MainWindow", "Scale Up/Down the edges radius", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelEdgeColor->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Specify edges coloring method</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelEdgeColor->setText(QApplication::translate("MainWindow", "Color:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        comboBoxEdgeColor->setToolTip(QApplication::translate("MainWindow", "Select the coloring scheme for edges", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        comboBoxEdgeType->clear();
        comboBoxEdgeType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Undirected", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Directed (pins)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Directed (arrows)", 0, QApplication::UnicodeUTF8)
        );
        groupBoxLabels->setTitle(QApplication::translate("MainWindow", "Labels", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        labelNodeLabelDegreeFilter->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Show labels only for nodes with degree bigger than a threshold</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelNodeLabelDegreeFilter->setText(QApplication::translate("MainWindow", "Node degree \342\211\245", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        labelLabelFontSize->setToolTip(QApplication::translate("MainWindow", "Specify the labels text size", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelLabelFontSize->setText(QApplication::translate("MainWindow", "Font size:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        labelLabelColumn->setToolTip(QApplication::translate("MainWindow", "Specify the column of node attributes to show", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelLabelColumn->setText(QApplication::translate("MainWindow", "Column:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        comboBoxLabelColumn->setToolTip(QApplication::translate("MainWindow", "Specify the column of node attributes to show", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        comboBoxSelectLabel->clear();
        comboBoxSelectLabel->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Do not include selected item", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Include selected item", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Include selected item and neighbors", 0, QApplication::UnicodeUTF8)
        );
        checkBoxRemoveLabelOverlaps->setText(QApplication::translate("MainWindow", "Remove overlaps", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabVisualization), QApplication::translate("MainWindow", "Visualization", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabToolTip(tabWidget->indexOf(tabVisualization), QApplication::translate("MainWindow", "Visualization options", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetStatistic->headerItem();
        ___qtreewidgetitem1->setText(1, QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Property", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidgetStatistic->isSortingEnabled();
        treeWidgetStatistic->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidgetStatistic->topLevelItem(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Graph", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Nodes", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Edges", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem2->child(2);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Components", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem2->child(3);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Max Degree", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem2->child(4);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Min Degree", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem2->child(5);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "Avg. Degree", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem2->child(6);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem10 = treeWidgetStatistic->topLevelItem(1);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "Layout", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem10->child(0);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "Steps", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem10->child(1);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "Time (ms)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem10->child(2);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem14 = treeWidgetStatistic->topLevelItem(2);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "OpenGL", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem14->child(0);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MainWindow", "FPS", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem14->child(1);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MainWindow", "Vendor", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem14->child(2);
        ___qtreewidgetitem17->setText(0, QApplication::translate("MainWindow", "Renderer", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem14->child(3);
        ___qtreewidgetitem18->setText(0, QApplication::translate("MainWindow", "Version", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem19 = treeWidgetStatistic->topLevelItem(3);
        ___qtreewidgetitem19->setText(0, QApplication::translate("MainWindow", "System", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem19->child(0);
        ___qtreewidgetitem20->setText(0, QApplication::translate("MainWindow", "CPUs", 0, QApplication::UnicodeUTF8));
        treeWidgetStatistic->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tabStatistic), QApplication::translate("MainWindow", "Statistics", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabToolTip(tabWidget->indexOf(tabStatistic), QApplication::translate("MainWindow", "Statistics about the graph and the drawing algorithm running state", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuGraphInsight->setTitle(QApplication::translate("MainWindow", "GraphInsight", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuPRO->setTitle(QApplication::translate("MainWindow", "Pro", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
