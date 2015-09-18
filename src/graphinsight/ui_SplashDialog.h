/********************************************************************************
** Form generated from reading UI file 'SplashDialog.ui'
**
** Created: Wed Apr 23 09:57:40 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHDIALOG_H
#define UI_SPLASHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SplashDialog
{
public:
    QAction *actionQuit;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QVBoxLayout *verticalLayout;
    QLabel *label_8;
    QFrame *line_3;
    QLabel *label_9;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCommandLinkButton *commandLinkButton_Website;
    QCommandLinkButton *commandLinkButton_PPA;
    QCommandLinkButton *commandLinkButton_SocialNetwork;
    QCommandLinkButton *commandLinkButton_SAT;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_3;

    void setupUi(QDialog *SplashDialog)
    {
        if (SplashDialog->objectName().isEmpty())
            SplashDialog->setObjectName(QString::fromUtf8("SplashDialog"));
        SplashDialog->resize(822, 429);
        SplashDialog->setMinimumSize(QSize(822, 0));
        actionQuit = new QAction(SplashDialog);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionQuit->setCheckable(true);
        gridLayout_2 = new QGridLayout(SplashDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_7 = new QLabel(SplashDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/icons/logoSmall.png")));
        label_7->setScaledContents(false);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_8 = new QLabel(SplashDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setWordWrap(true);

        verticalLayout->addWidget(label_8);

        line_3 = new QFrame(SplashDialog);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        label_9 = new QLabel(SplashDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setWordWrap(true);

        verticalLayout->addWidget(label_9);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(SplashDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAutoFillBackground(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        commandLinkButton_Website = new QCommandLinkButton(groupBox);
        commandLinkButton_Website->setObjectName(QString::fromUtf8("commandLinkButton_Website"));
        sizePolicy.setHeightForWidth(commandLinkButton_Website->sizePolicy().hasHeightForWidth());
        commandLinkButton_Website->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/screenshot2.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_Website->setIcon(icon);
        commandLinkButton_Website->setIconSize(QSize(100, 100));
        commandLinkButton_Website->setCheckable(true);

        gridLayout->addWidget(commandLinkButton_Website, 0, 0, 1, 1);

        commandLinkButton_PPA = new QCommandLinkButton(groupBox);
        commandLinkButton_PPA->setObjectName(QString::fromUtf8("commandLinkButton_PPA"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/screenshot12.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_PPA->setIcon(icon1);
        commandLinkButton_PPA->setIconSize(QSize(100, 100));
        commandLinkButton_PPA->setCheckable(true);

        gridLayout->addWidget(commandLinkButton_PPA, 0, 1, 1, 1);

        commandLinkButton_SocialNetwork = new QCommandLinkButton(groupBox);
        commandLinkButton_SocialNetwork->setObjectName(QString::fromUtf8("commandLinkButton_SocialNetwork"));
        sizePolicy.setHeightForWidth(commandLinkButton_SocialNetwork->sizePolicy().hasHeightForWidth());
        commandLinkButton_SocialNetwork->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/screenshot3.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_SocialNetwork->setIcon(icon2);
        commandLinkButton_SocialNetwork->setIconSize(QSize(100, 100));
        commandLinkButton_SocialNetwork->setCheckable(true);

        gridLayout->addWidget(commandLinkButton_SocialNetwork, 1, 0, 1, 1);

        commandLinkButton_SAT = new QCommandLinkButton(groupBox);
        commandLinkButton_SAT->setObjectName(QString::fromUtf8("commandLinkButton_SAT"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/screenshot7.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_SAT->setIcon(icon3);
        commandLinkButton_SAT->setIconSize(QSize(100, 100));
        commandLinkButton_SAT->setCheckable(true);

        gridLayout->addWidget(commandLinkButton_SAT, 1, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBox_3 = new QCheckBox(SplashDialog);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout->addWidget(checkBox_3);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(SplashDialog);

        QMetaObject::connectSlotsByName(SplashDialog);
    } // setupUi

    void retranslateUi(QDialog *SplashDialog)
    {
        SplashDialog->setWindowTitle(QApplication::translate("SplashDialog", "Quick Start", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("SplashDialog", "Quit", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        label_8->setText(QApplication::translate("SplashDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600;\">GraphInsight</span><span style=\" font-size:20pt; font-weight:600; vertical-align:super;\"> </span><span style=\" font-size:20pt; font-weight:600;\">GRAPHINSIGHT_VERSION</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">GRAPHINSIGHT_LICENSE GRAPHINSIGHT_REVISION</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;"
                        " -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Copyright </span><a name=\"main\"></a><span style=\" font-size:12pt;\">\302\251</span><span style=\" font-size:12pt;\"> 2009-2012 Michele Dallachiesa and Carlo Nicolini. All rights reserved.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SplashDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">An interactive visualization system for graph data exploration.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SplashDialog", "Choose a demo:", 0, QApplication::UnicodeUTF8));
        commandLinkButton_Website->setText(QApplication::translate("SplashDialog", "Website topology", 0, QApplication::UnicodeUTF8));
        commandLinkButton_Website->setDescription(QApplication::translate("SplashDialog", "The structure of connections between pages on a website reveals visually its content.", 0, QApplication::UnicodeUTF8));
        commandLinkButton_PPA->setText(QApplication::translate("SplashDialog", "Computer Networks", 0, QApplication::UnicodeUTF8));
        commandLinkButton_PPA->setDescription(QApplication::translate("SplashDialog", "From the book \"Practical Packet Analysis - Using Wireshark to Solve Real-World Network Problems\" by Chris Sanders.", 0, QApplication::UnicodeUTF8));
        commandLinkButton_SocialNetwork->setText(QApplication::translate("SplashDialog", "Social Networks", 0, QApplication::UnicodeUTF8));
        commandLinkButton_SocialNetwork->setDescription(QApplication::translate("SplashDialog", "Co-Author network of publications at DISI department, University of Trento. The graph revelas the social structure of the department.", 0, QApplication::UnicodeUTF8));
        commandLinkButton_SAT->setText(QApplication::translate("SplashDialog", "SAT (Boolean satisfiability)", 0, QApplication::UnicodeUTF8));
        commandLinkButton_SAT->setDescription(QApplication::translate("SplashDialog", "Logical structure of a problem in bounded model checking. The actual problem is to verify that two algorithms for computing multiplication of 16-bit integers gives the same results.", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_3->setToolTip(QApplication::translate("SplashDialog", "If checked, skip this splash screen on next startups. Only possible in PROFESSIONAL version.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBox_3->setText(QApplication::translate("SplashDialog", "Skip on startup", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SplashDialog: public Ui_SplashDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHDIALOG_H
