#ifndef COMPILINGSTATUS_H
#define COMPILINGSTATUS_H

#include <QDialog>

namespace Ui {
class CompilingStatus;
}
class ExportThread;
class CompilingStatus : public QDialog
{
    friend class ExportThread;
    Q_OBJECT
    
public:
    explicit CompilingStatus(QWidget *parent = 0);
    ~CompilingStatus();
    QString project;
    void debug();void run(); void build();
    void clean();void deploy();
    
private slots:
    void on_details_toggled(bool checked);

private:
    Ui::CompilingStatus *ui;
    ExportThread* et;
};

#endif // COMPILINGSTATUS_H
