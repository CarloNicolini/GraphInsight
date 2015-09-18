/********************************************************************************
** Form generated from reading UI file 'Activate.ui'
**
** Created: Wed Apr 23 09:57:40 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVATE_H
#define UI_ACTIVATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ActivateDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFrame *line;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ActivateDialog)
    {
        if (ActivateDialog->objectName().isEmpty())
            ActivateDialog->setObjectName(QString::fromUtf8("ActivateDialog"));
        ActivateDialog->resize(455, 203);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ActivateDialog->sizePolicy().hasHeightForWidth());
        ActivateDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ActivateDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(ActivateDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setWordWrap(true);

        verticalLayout->addWidget(label_3);

        line = new QFrame(ActivateDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_2 = new QLabel(ActivateDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(ActivateDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_2);

        label = new QLabel(ActivateDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(ActivateDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(ActivateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ActivateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ActivateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ActivateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ActivateDialog);
    } // setupUi

    void retranslateUi(QDialog *ActivateDialog)
    {
        ActivateDialog->setWindowTitle(QApplication::translate("ActivateDialog", "GraphInsight - activation", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ActivateDialog", "Please, enter the email and the product key we sent to you. For any problem, mail us at support@graphinsight.com.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ActivateDialog", "Email:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ActivateDialog", "Product key:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ActivateDialog: public Ui_ActivateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVATE_H
