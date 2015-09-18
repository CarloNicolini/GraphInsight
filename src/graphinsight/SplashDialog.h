#ifndef SPLASHDIALOG_H
#define SPLASHDIALOG_H

#include <QDialog>

namespace Ui
{
class SplashDialog;
}

class SplashDialog : public QDialog
{  Q_OBJECT

public:
   explicit SplashDialog(QWidget *parent = 0);
   ~SplashDialog();
   QString getSelectedExample();
   bool getIfSkipOnStartup();
   void setSkipOnStartupVisible(bool val);

private slots:
   void on_commandLinkButton_Website_clicked();

   void on_commandLinkButton_PPA_clicked();

   void on_commandLinkButton_SocialNetwork_clicked();

   void on_commandLinkButton_SAT_clicked();

   void on_checkBox_3_clicked(bool checked);

   void on_actionQuit_triggered();

   void on_actionQuit_triggered(bool checked);

private:
   QString selectedExample;
   bool skipOnStartup;
   Ui::SplashDialog *ui;
};

#endif // SPLASHDIALOG_H
