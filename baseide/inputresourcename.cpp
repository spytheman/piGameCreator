#include "inputresourcename.h"
#include "ui_inputresourcename.h"
#include "../sharedcode/pgsparser.h"

InputResourceName::InputResourceName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputResourceName)
{
    ui->setupUi(this);
    project = 0;
}

InputResourceName::~InputResourceName()
{
    delete ui;
}

void InputResourceName::on_pushButton_2_clicked()
{
    pgsParser p;
    p.setProject(project);
    pgsParser::tokenlist l = p.tokenize(ui->lineEdit->text());
    if(l.count()==1)
    {
        pgsParser::token t = l.at(0);
        if(t.kind != pgsParser::nameId)
        {
            gcerror("This name conflicts with Gamescript reserved word or is already used in this project");
            return;
        }
        else
        {
            enteredName = ui->lineEdit->text();
            close();
        }
    }
    else
    {
        gcerror("Name must only contain letters, digits and underscore, and cannot start with digit");
    }
}
