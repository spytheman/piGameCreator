#include "getkeyevent.h"
#include "ui_getkeyevent.h"
#include <QCoreApplication>
#include <QKeyEvent>

getKeyEvent::getKeyEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getKeyEvent)
{
    keyName = "";
    keyCode = 0;
    etype=-1;
    ui->setupUi(this);
    EF = new GetGlobalKeyEventFilter(this);
    QApplication::instance()->installEventFilter(EF);
}

getKeyEvent::~getKeyEvent()
{
    QApplication::instance()->removeEventFilter(EF);
    delete ui;
}

void getKeyEvent::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void getKeyEvent::setKey(int k)
{
    keyName = QString::fromStdString(getKeyName(k));
    keyCode = k;
    etype = ui->EventTypeCB->currentIndex();
    ui->keyLabel->setText(keyName);
    ui->OKbutton->setEnabled(true);
}

bool GetGlobalKeyEventFilter::eventFilter(QObject *o, QEvent *e)
{
    if(e->type()==QEvent::KeyPress)
    {
        QKeyEvent* f = (QKeyEvent*)e;
        window->setKey(f->nativeVirtualKey());
        return true;
    }
    return false;
}

GetGlobalKeyEventFilter::GetGlobalKeyEventFilter(){}

GetGlobalKeyEventFilter::GetGlobalKeyEventFilter(getKeyEvent* w)
{
    window = w;
}

std::string getKeyEvent::getKeyName(int argument0)
{
bool argument1 = true;
std::string n;
switch(argument0)
{
    case 65: n = "A"; break;
    case 66: n = "B"; break;
    case 67: n = "C"; break;
    case 68: n = "D"; break;
    case 69: n = "E"; break;
    case 70: n = "F"; break;
    case 71: n = "G"; break;
    case 72: n = "H"; break;
    case 73: n = "I"; break;
    case 74: n = "J"; break;
    case 75: n = "K"; break;
    case 76: n = "L"; break;
    case 77: n = "M"; break;
    case 78: n = "N"; break;
    case 79: n = "O"; break;
    case 80: n = "P"; break;
    case 81: n = "Q"; break;
    case 82: n = "R"; break;
    case 83: n = "S"; break;
    case 84: n = "T"; break;
    case 85: n = "U"; break;
    case 86: n = "V"; break;
    case 87: n = "W"; break;
    case 88: n = "X"; break;
    case 89: n = "Y"; break;
    case 90: n = "Z"; break;
    case 226: n = "\\"; break;
    case 220: n = "\\"; break;
    case 188: n = "<"; break;
    case 190: n = ">"; break;
    case 191: n = "?"; break;
    case 186: n = ";"; break;
    case 222: n = "\""; break;
    case 219: n = "["; break;
    case 221: n = "]"; break;
    case 48: n = "0"; break;
    case 49: n = "1"; break;
    case 50: n = "2"; break;
    case 51: n = "3"; break;
    case 52: n = "4"; break;
    case 53: n = "5"; break;
    case 54: n = "6"; break;
    case 55: n = "7"; break;
    case 56: n = "8"; break;
    case 57: n = "9"; break;
    case 192: n = "~"; break;
    case 189: n = "-"; break;
    case 187: n = "="; break;
    case 8: n = "Backspace"; break;
    case 32: n = "Space"; break;
    case 91: n = "Win"; break; //The left one
    case 92: n = "Win"; break; //The right one
    case 93: n = "Menu"; break;
    case 17: n = "Control"; break; //both
    case 16: n = "Shift"; break;   //both
    case 18: n = "Alt"; break;     //both
    case 13: n = "Enter"; break;   //both text and numpad
    case 37: n = "Left arrow"; break;
    case 38: n = "Up arrow"; break;
    case 39: n = "Right arrow"; break;
    case 40: n = "Down arrow"; break;
    case 20: n = "Caps Lock"; break;
    case 144: n = "Num Lock"; break;
    case 19: n = "Pause/Break"; break;
    case 145: n = "Scroll Lock"; break;
    case 45: n = "Insert"; break;
    case 46: n = "Delete"; break;
    case 36: n = "Home"; break;
    case 35: n = "End"; break;
    case 33: n = "Page Up"; break;
    case 34: n = "Page Down"; break;
    case 112: n = "F1"; break;
    case 113: n = "F2"; break;
    case 114: n = "F3"; break;
    case 115: n = "F4"; break;
    case 116: n = "F5"; break;
    case 117: n = "F6"; break;
    case 118: n = "F7"; break;
    case 119: n = "F8"; break;
    case 120: n = "F9"; break;
    case 121: n = "F10"; break;
    case 122: n = "F11"; break;
    case 123: n = "F12"; break;

    case 124: n = "F13"; break;
    case 125: n = "F14"; break;
    case 126: n = "F15"; break;
    case 127: n = "F16"; break;
    case 128: n = "F17"; break;
    case 129: n = "F18"; break;
    case 130: n = "F19"; break;
    case 131: n = "F20"; break;
    case 132: n = "F21"; break;
    case 133: n = "F22"; break;
    case 134: n = "F23"; break;
    case 135: n = "F24"; break;

    //on some new keyboards these reffer to the multimedia keys, or
    //in some other keyboards there REALLY ARE F13 to F24 keys

    case 27: n = "Escape"; break;
    case 96: n = "Numpad 0"; break;
    case 97: n = "Numpad 1"; break;
    case 98: n = "Numpad 2"; break;
    case 99: n = "Numpad 3"; break;
    case 100: n = "Numpad 4"; break;
    case 101: n = "Numpad 5"; break; //numlock ON
    case 12: n = "Numpad 5"; break;  //Numlock OFF
    case 102: n = "Numpad 6"; break;
    case 103: n = "Numpad 7"; break;
    case 104: n = "Numpad 8"; break;
    case 105: n = "Numpad 9"; break;
    case 106: n = "Numpad *"; break;
    case 107: n = "Numpad +"; break;
    case 111: n = "Numpad /"; break;
    case 109: n = "Numpad -"; break;
    case 110: n = "Numpad ,"; break;

    case 9: n = "Tab"; break;
    case 44: n = "Print Screen"; break;
    case 1: n = "Left mouse"; break;
    case 2: n = "Right mouse"; break;
    case 4: n = "Middle mouse"; break;
    case 5: n = "Mouse 4"; break;
    case 6: n = "Mouse 5"; break;
    case 7: n = "Mouse 6"; break;

    case 160: n = "Left Shift"; break;
    case 161: n = "Right Shift"; break;
    case 162: n = "Left Control"; break;
    case 163: n = "Right Control"; break;
    case 164: n = "Left Alt"; break;
    case 165: n = "Right Alt"; break;

    default: n = "Key " + QString::number(argument0).toStdString();
    }
    return n;
}
