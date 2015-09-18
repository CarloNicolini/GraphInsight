#include "SplashDialog.h"
#include "ui_SplashDialog.h"
#include <iostream>
#include <string>
#include "LicenseType.h"

using namespace std;

/**
 * @brief SplashDialog::SplashDialog
 * @param parent
 */
SplashDialog::SplashDialog(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::SplashDialog)
{  ui->setupUi(this);
   this->setFixedSize(this->width(),this->height());
   QString splashTitle =  ui->label_8->text();
   splashTitle.replace("GRAPHINSIGHT_LICENSE", QString( getLicenseType().c_str() ) );
   //splashTitle.replace("GRAPHINSIGHT_REVISION", " Rev. " + QString::number(getRevisionNumber() ));
   splashTitle.replace("GRAPHINSIGHT_VERSION", QString( getVersionNumber().c_str() ) );
   ui->label_8->setText(splashTitle);

   selectedExample=QString("quit");
}

/**
 * @brief SplashDialog::~SplashDialog
 */
SplashDialog::~SplashDialog()
{  delete ui;
}

/**
 * @brief SplashDialog::getSelectedExample
 * @return
 */
QString SplashDialog::getSelectedExample()
{  return selectedExample;
}

/**
 * @brief SplashDialog::on_commandLinkButton_Website_clicked
 */
void SplashDialog::on_commandLinkButton_Website_clicked()
{  selectedExample =  QString(":/samples/website.net");
   emit close();
}

/**
 * @brief SplashDialog::on_commandLinkButton_PPA_clicked
 */
void SplashDialog::on_commandLinkButton_PPA_clicked()
{  selectedExample = QString(":/samples/ppa_capture.net");
   emit close();
}

/**
 * @brief SplashDialog::on_commandLinkButton_SocialNetwork_clicked
 */
void SplashDialog::on_commandLinkButton_SocialNetwork_clicked()
{  selectedExample = QString(":/samples/disi-authors.net");
   emit close();
}

/**
 * @brief SplashDialog::on_commandLinkButton_SAT_clicked
 */
void SplashDialog::on_commandLinkButton_SAT_clicked()
{  selectedExample = QString(":/samples/longmult5-UP.net");
   emit close();
}

/**
 * @brief SplashDialog::on_checkBox_3_clicked
 * @param checked
 */
void SplashDialog::on_checkBox_3_clicked(bool checked)
{  skipOnStartup=checked;
}

/**
 * @brief SplashDialog::getIfSkipOnStartup
 * @return
 */
bool SplashDialog::getIfSkipOnStartup()
{  return skipOnStartup;
}

/**
 * @brief SplashDialog::setSkipOnStartupVisible
 * @param val
 */
void SplashDialog::setSkipOnStartupVisible(bool val)
{  ui->checkBox_3->setEnabled(val);
}

/**
 * @brief SplashDialog::on_actionQuit_triggered
 */
void SplashDialog::on_actionQuit_triggered()
{  cerr << "XXXXXX" << endl;
   exit(0);
}

/**
 * @brief SplashDialog::on_actionQuit_triggered
 * @param checked
 */
void SplashDialog::on_actionQuit_triggered(bool checked)
{  cerr << "XXXXX" << endl;
   exit(0);
}
