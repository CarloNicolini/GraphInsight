#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class OptionsDialog;
}

/**
 * @brief The OptionsDialog class Is needed to modify the user preferences (parameters for layout algorithms, advanced visualization etc)
 */
class OptionsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();

private:
    Ui::OptionsDialog *ui;
};

#endif // OPTIONSDIALOG_H
