#include "config.h"
#include "ui_config.h"

Config::Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
    //ui->frame->setContentsMargins(0,0,0,0);
    setWindowIcon( QIcon(":/resources/RES/ffficons/page_white_cplusplus.png"));
}

Config::~Config()
{
    delete ui;
}
