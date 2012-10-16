#ifndef NEWRESOURCE_H
#define NEWRESOURCE_H

#include <QWizard>
#include <QCommandLinkButton>

class OpenedProject;
class gcresource;
class dllForResourceEditor;

namespace Ui {
class newResource;
}

class newResource : public QWizard
{
    Q_OBJECT
    
public:
    explicit newResource(QWidget *parent = 0);
    ~newResource();

    void setKind(QString kind);
    void init();
    gcresource* resource;
    OpenedProject* selectedProject;
    dllForResourceEditor* selectedResourceEditor;
    QString selectedType, selectedKind, selectedOption, selectedOptionDesc;
    bool isContentProvider;

    bool validateCurrentPage();
    void initializePage(int id);
    
private slots:
    void setUsedEditor();

    private:
    Ui::newResource *ui;
    QList<QCommandLinkButton*> cmlButtons;
};

#endif // NEWRESOURCE_H
