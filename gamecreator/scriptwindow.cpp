#include "gamecreator.h"
#include "scriptwindow.h"
#include "ui_scriptwindow.h"
#include <QPainter>
#include <QTextBlock>
#include <QTextStream>
#include <QTextCursor>
#include <QFile>
#include <QTextDocumentFragment>
#include <QTextBlockFormat>


scriptwindow::scriptwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scriptwindow)
{
    debug=true;
    DebugString.clear();
    ui->setupUi(this);
    source = new CodeEditor;
    source->SW = this;
    QFont F("Courier New",10);
    source->setFont(F);
    ui->Sourcezone->layout()->addWidget(source);
    source->setWordWrapMode(QTextOption::NoWrap);
    source->setFrameStyle(0);
    setBackgroundColor(codeBackground);
    int tabwidth = 4;   //todo: add to the CONFIG ;]
    source->setTabStopWidth(source->fontMetrics().width(QLatin1Char('9'))*tabwidth);
    connect(source->document(), SIGNAL(contentsChange(int,int,int)), this,SLOT(colorize_slot(int,int,int)));
    HL = new pgsHighlighter(source->document());
}

scriptwindow::~scriptwindow()
{
    delete HL;
    delete source;
    delete ui;
}

void scriptwindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void CodeEditor::focusInEvent(QFocusEvent *e)
{
    QPlainTextEdit::focusInEvent(e);
    SW->setBackgroundColor(codeBackground);
}/**/

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
 {
     setProperty("piGameScriptEditor","true");
     lineNumberArea = new LineNumberArea(this);

     connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
     connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
     connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

     updateLineNumberAreaWidth(0);
     highlightCurrentLine();
 }

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 20 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(codeBackground).darker(106);
        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), QColor(Qt::lightGray).lighter(120));

    QTextBlock block = firstVisibleBlock();
       int blockNumber = block.blockNumber();
       int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
       int bottom = top + (int) blockBoundingRect(block).height();
       while (block.isValid() && top <= event->rect().bottom()) {
           if (block.isVisible() && bottom >= event->rect().top()) {
               QString number = QString::number(blockNumber + 1);
               painter.setPen(Qt::black);
               painter.drawText(0, top, lineNumberArea->width()-3, fontMetrics().height(),
                                Qt::AlignRight, number);
           }

           block = block.next();
           top = bottom;
           bottom = top + (int) blockBoundingRect(block).height();
           ++blockNumber;
       }

       painter.setPen(QPen(QColor(Qt::lightGray)));
       painter.drawLine(lineNumberArea->width()-1,0,lineNumberArea->width()-1,height());
   }

LineNumberArea::LineNumberArea(CodeEditor *editor) : QWidget(editor) {
    codeEditor = editor;
}

QSize LineNumberArea::sizeHint() const {
    return QSize(codeEditor->lineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    codeEditor->lineNumberAreaPaintEvent(event);
}

void scriptwindow::tokenize()
{
    //colorizes the code in the editor (and initiates the helpers)
    QString s = source->toPlainText();
    pgsParser p;
    tokens = p.tokenize(s);
    DebugString = "Debug:\n";

    if(debug)
    {
        //debug tokens
        for(int i=0;i<tokens.count();i++)
        {
            DebugString += p.tokenkindToString(tokens.at(i).kind)+
                  "("+QString::number(tokens.at(i).line)+", "+
                  QString::number(tokens.at(i).col)+"): "+tokens.at(i).text+"\n"; /**/
        }
        if(!tokens.isEmpty())
        {
            int blocklevel = tokens.at(tokens.count()-1).blocklevel;
            DebugString.prepend("BLOCKLEVEL: "+QString::number(blocklevel)+"\n");
        }
    }
}

void scriptwindow::colorize_slot(int position, int added, int deleted)
{
    tokenize();
    emit codeChanged();
}

void scriptwindow::setText(QString s)
{
    source->setPlainText(s);
}

QString scriptwindow::Text()
{
    return source->toPlainText();
}

//highlighter
pgsHighlighter::pgsHighlighter(QTextDocument *parent):
        QSyntaxHighlighter(parent)
{

}

// 0 - normal, 1 - comment

void pgsHighlighter::highlightBlock(const QString &text)
{

    if(previousBlockState()==-1)  //is not block comment
    {
        pgsParser p;
        QList<pgsParser::token> l = p.tokenize(text);
        int i;
        for(i=0;i<l.count();i++)
        {
            int j = l.at(i).format;
            QTextCharFormat f;
            f.setForeground( CodeFormats[j].color );
            f.setFontItalic(CodeFormats[j].italic);
            f.setFontWeight(CodeFormats[j].bold?255:0);
            f.setFontUnderline(CodeFormats[j].underline);
            setFormat(l.at(i).begin,l.at(i).length,f);
            //gcprint(i);
            //gcprint(p.tokenkindToString(l.at(i).kind));
        }
        setCurrentBlockState(-1);
        if(!l.isEmpty())
        if(l.at(i-1).kind == pgsParser::incompleteComment)setCurrentBlockState(1);
    }
    else
    {
        int j = CFcomment;
        QTextCharFormat f;
        f.setForeground( CodeFormats[j].color );
        f.setFontItalic(CodeFormats[j].italic);
        f.setFontWeight(CodeFormats[j].bold?255:0);
        f.setFontUnderline(CodeFormats[j].underline);

        int pos = text.indexOf("*/");
        if(pos!=-1)
        {
            setFormat(0,pos+2,f);setCurrentBlockState(-1);
        }
        else
        {
            setFormat(0,text.length(),f); setCurrentBlockState(1);
        }
    }
}

void scriptwindow::recolorize()
{
    HL->rehighlight();
}

void scriptwindow::setBackgroundColor(QColor c)
{
    codeBackground = c;
    QApplication::processEvents();
    QPalette P(source->palette());
    P.setColor(QPalette::Window,c);
    P.setColor(QPalette::Base,c);
    source->setBackgroundVisible(true);
    source->setPalette(P);
    source->setStyleSheet("QPlainTextEdit{background-color:"+c.name()+"}");
    source->highlightCurrentLine();
}
