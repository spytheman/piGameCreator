#ifndef BUILDTARGETS_H
#define BUILDTARGETS_H

#include <QDialog>
#include "../sharedcode/gameproject.h"
#include <QListWidgetItem>

namespace Ui {
    class BuildTargets;
}
class OpenedProject;

class BuildTargets : public QDialog
{
    Q_OBJECT

public:
    explicit BuildTargets(OpenedProject* p, QWidget *parent = 0);
    ~BuildTargets();
    OpenedProject* project;
    buildtarget* currentTarget;

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_helpbutton_clicked();

    void on_DisplayName_textChanged(const QString &arg1);

    void on_codeName_textChanged(const QString &arg1);

    void on_DescText_textChanged();

    void on_ExporterComboBox_currentIndexChanged(int index);

    void on_OptionsButton_clicked();

    void on_AddTarget_clicked();

    void on_DelTarget_clicked();

    void on_TargetsLV_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_OKbutton_clicked();

    void on_toolButton_clicked();

    void on_exporterLineEdit_textChanged(const QString &arg1);

    void on_toolButton_2_clicked();

private:
    Ui::BuildTargets *ui;
};

#endif // BUILDTARGETS_H
