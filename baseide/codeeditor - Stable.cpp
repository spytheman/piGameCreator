#include "codeeditor.h"
#include <QStylePainter>
#include <QScrollBar>
#include <QDebug>
#include <QApplication>
#include <QtConcurrentMap>
#include <QFutureWatcher>
#include <QClipboard>
#include "../sharedcode/timer.h"
#include "gcide.h"
#include <QGLWidget>
#include <GL/gl.h>

//codeLine:
CodeEditor::codeLine::codeLine(){isBookmark=0;isHidden=0;lineState=-1;} //linestate -1: unparsed

//codeEditor
CodeEditor::CodeEditor(QWidget* parent)
{
    setProperty("piGameScriptEditor","true");
    setMouseTracking(1);
    //setViewport(new QGLWidget);
    viewport()->setFocusPolicy(Qt::ClickFocus);
    setFocusPolicy(Qt::ClickFocus);
    //setAttribute(Qt::WA_TranslucentBackground);

    //init variables:
    firstDrawnLineNumber=0;
    leftareaWidth=0;
    drawnLinesCount=0;
    lineSpacing=0;
    leftMargin=4;
    cursorVisible=true;
    mousepressed=false;
    columnNumber = 0;
    lineNumber = 10;
    lineIterator = lines.begin();
    lineIterator += lineNumber;
    insertMode = true;
    selLineNumber=0;
    selColumnNumber=0;
    highlighter = NULL;
    QFont f;
    f.setFamily("Courier New");
    f.setPointSize(11);
    setFont(f);
    reloadFont();
    updateLineSize();
    setFrameStyle(0);
    connect( verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(verticalScrollBarMoved(int)) );
    connect( horizontalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(horizontalScrollBarMoved(int)));
    verticalScrollBar()->setMinimum(0);
    verticalScrollBar()->setSingleStep(1);
    horizontalScrollBar()->setSingleStep(50);
    horizontalScrollBar()->setMinimum(0);
    int msec = qApp->cursorFlashTime() / 2;
    cursorBlinkTimer.setInterval(msec);
    connect(&cursorBlinkTimer, SIGNAL(timeout()),this,SLOT(toggleCursorVisible()));
    cursorBlinkTimer.start();
    tabStopPixelSize = fontMetrics().width(' ')*4;
    horizontalScrollBar()->setCursor(Qt::ArrowCursor);
    verticalScrollBar()->setCursor(Qt::ArrowCursor);
}

CodeEditor::~CodeEditor()
{
    //kill the thread
    gswFuture.cancel();
    gcprint("Cancelled");
}

void CodeEditor::reloadFont()
{
    //this will cache the fonts:
    QFont f = font();

    //normal
    f.setBold(0);
    f.setItalic(0);
    f.setUnderline(0);
    normalFont = f;

    //The rest only if performance fails!
}

//gswwrapper
CodeEditor::gswWrapper::gswWrapper(CodeEditor* ce) : instance(ce){}
void CodeEditor::gswWrapper::operator ()(const CodeEditor::codeLine& line)
{
    instance->getThreadedStringWidth(line);
}

void CodeEditor::getThreadedStringWidth(const CodeEditor::codeLine& ln)
{
    int MX = leftareaWidth+leftMargin+fontMetrics().size(Qt::TextExpandTabs,ln.text,tabStopPixelSize).width();
    if(MX>gswMax)gswMax=MX;
}

void CodeEditor::updateLineSize()
{
    lineHeight= QFontMetrics(font()).height() + lineSpacing;
}
void CodeEditor::toggleCursorVisible()
{
    cursorVisible=!cursorVisible;
    viewport()->repaint();  //can reentrancy lead to crash?
}
void CodeEditor::setLineSpacing(int spacing)
{
    lineSpacing = spacing;
    updateLineSize();
}

void CodeEditor::gswProgressChanged(int i)
{
    gcprint("Max str width: "+QString::number(i));
}

void CodeEditor::gswCompleted()
{
    gcprint("Completed: Max width is "+QString::number(gswMax));
    maximumHorizontalTextWidthInPx = gswMax;
}

void CodeEditor::setText(QString s)
{
    lines.clear();
    QStringList L = s.split('\n');
    if(L.count()==0)L.append("");
    QStringList::const_iterator it = L.begin();
    maximumHorizontalTextWidthInPx = 0;
    int charsize = fontMetrics().width(' ');
    for(;it!=L.end();++it)
    {
        codeLine l;
        l.text = (*it);
        l.isBookmark = 0;
        l.isHidden = 0;
        l.lineState = 0;
        int ww = 200 + charsize * l.text.length(); //SLOW: fontMetrics().size(Qt::TextExpandTabs|Qt::TextSingleLine, l.text, tabStopPixelSize).width();
        if(ww>maximumHorizontalTextWidthInPx)maximumHorizontalTextWidthInPx=ww;
        lines.append(l);
    }
    updateLeftAreaWidth();
    horizontalScrollBar()->setMinimum(0);
    horizontalScrollBar()->setPageStep(viewport()->width());

    //These two must be synced:
    lineIterator = lines.begin();
    lineNumber = 0; // lines index!

    //These two must be synced as well:
    firstDrawnLineIterator = lines.begin();
    firstDrawnLineNumber = 0;

    //TODO: slider calculation...
    /*
    gswWrapper wrap(this);
    gswFuture = QtConcurrent::map(lines.begin(),lines.end(), wrap);
    connect(&gswWatcher,SIGNAL(finished()),this,SLOT(gswCompleted()));
    connect(&gswWatcher,SIGNAL(progressValueChanged(int)),this,SLOT(gswProgressChanged(int)));
    gswWatcher.setFuture(gswFuture); /**/

    for(int i=0;i<lines.count();i++)
        updateSyntaxHighlighting(i);
}
void CodeEditor::resizeEvent(QResizeEvent *event)
{
    QAbstractScrollArea::resizeEvent(event);
    QSize s = viewport()->size();
    drawnLinesCount = s.height()/lineHeight;
    if(lines.count()<=drawnLinesCount)
    {
        //no vertical bar
        verticalScrollBar()->setMaximum(0);
    }
    else
    {
        verticalScrollBar()->setMaximum(lines.count()-drawnLinesCount);
    }
    verticalScrollBar()->setPageStep(drawnLinesCount);
    horizontalScrollBar()->setMinimum(0);
    if(maximumHorizontalTextWidthInPx+leftMargin+leftareaWidth>s.width())
        horizontalScrollBar()->setMaximum(maximumHorizontalTextWidthInPx+leftMargin+leftareaWidth - s.width());
    else
        horizontalScrollBar()->setMaximum(0);
    event->accept();
}

void CodeEditor::updateVerticalScrollBarSettings()
{
    QSize s = viewport()->size();
    drawnLinesCount = s.height()/lineHeight;
    if(lines.count()<=drawnLinesCount)
    {
        //no vertical bar
        verticalScrollBar()->setMaximum(0);
    }
    else
    {
        verticalScrollBar()->setMaximum(lines.count()-drawnLinesCount);
    }
    verticalScrollBar()->setPageStep(drawnLinesCount);
}

void CodeEditor::updateLeftAreaWidth()
{
    //16 is the size of bookmark/breakpoint area
    leftareaWidth = 16;
    int digits = 1;
    int max = qMax(1, lines.count());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }
    leftareaWidth += fontMetrics().width(QLatin1Char('9')) * digits;
}
QString CodeEditor::getText()
{
    QString s;
    LINESLISTTYPE::const_iterator i = lines.begin();
    for(;i!=lines.end();++i)s+=(*i).text + "\n";
    return s;
}

void CodeEditor::clearSelection()
{
    //must delete ALL selected text.
    LINESLISTTYPE::iterator i = lines.begin();

    //Determine first and last line and columns?
    int firstLineNumber, lastLineNumber, firstLineColumn, lastLineColumn;

    if(lineNumber<selLineNumber)
    {
        firstLineNumber = lineNumber;
        firstLineColumn = columnNumber;
        lastLineNumber = selLineNumber;
        lastLineColumn = selColumnNumber;
    }
    else if(selLineNumber<lineNumber)
    {
        firstLineNumber = selLineNumber;
        firstLineColumn = selColumnNumber;
        lastLineNumber = lineNumber;
        lastLineColumn = columnNumber;
    }
    if(selLineNumber==lineNumber)
    {
        //selection is on this same row:
        int b,e;
        b = qMin(columnNumber,selColumnNumber);
        e = qMax(columnNumber,selColumnNumber);
        if(b==e) return;    //nothing was selected - nothing to clear
        //replace the line with deleted text line:
        i+=lineNumber;
        (*i).text = (*i).text.mid(0,b)+(*i).text.mid(e);
        selLineNumber = lineNumber;
        selColumnNumber = b;
        columnNumber = b;
        lineIterator = lines.begin();
        lineIterator += lineNumber;
        updateLeftAreaWidth();
        updateSyntaxHighlighting();
        return;
    }

    //First line:
    i+=firstLineNumber;
    QString rest = lines.at(lastLineNumber).text.mid(lastLineColumn);
    (*i).text = (*i).text.mid(0,firstLineColumn) + rest;

    //remove rest lines
    int numlines = lastLineNumber-firstLineNumber-1;
    for(int ii=0;ii<=numlines;++ii)
        lines.removeAt(firstLineNumber+1);

    lineNumber = firstLineNumber;
    columnNumber = firstLineColumn;
    selLineNumber = lineNumber;
    selColumnNumber = columnNumber;
    lineIterator = lines.begin();
    lineIterator += lineNumber;
    updateCursorXPos();
    updateHorizontalScrollBarPos();
    updateVerticalScrollBarPos();
    updateLeftAreaWidth();
    updateSyntaxHighlighting();
}

QString CodeEditor::getSelectedText()
{
    //Returns only the selected text!
    QString s;
    LINESLISTTYPE::const_iterator i = lines.begin();

    //Determine first and last line and columns?
    int firstLineNumber, lastLineNumber, firstLineColumn, lastLineColumn;

    if(lineNumber<selLineNumber)
    {
        firstLineNumber = lineNumber;
        firstLineColumn = columnNumber;
        lastLineNumber = selLineNumber;
        lastLineColumn = selColumnNumber;
    }
    else if(selLineNumber<lineNumber)
    {
        firstLineNumber = selLineNumber;
        firstLineColumn = selColumnNumber;
        lastLineNumber = lineNumber;
        lastLineColumn = columnNumber;
    }
    if(selLineNumber==lineNumber)
    {
        //selection is on this same row:
        int b,e;
        b = qMin(columnNumber,selColumnNumber);
        e = qMax(columnNumber,selColumnNumber);
        i+=lineNumber;
        return (*i).text.mid(b,e-b);
    }

    // selected text is the text that starts from cursor position in first line
    // and ends at cursor position in last line, with all lines in between

    //Go to the first line...
    i+=firstLineNumber;

    //Take it
    const codeLine& ln = (*i);
    s.append(ln.text.mid(firstLineColumn) + "\n");
    i++;

    //Take all lines until last line:
    int numlines = lastLineNumber-firstLineNumber-2;
    for(int ii=0;ii<=numlines;++ii,++i)
        s.append((*i).text+"\n" );

    //Take the last line:
    s.append((*i).text.mid(0,lastLineColumn));

    return s;
}

void CodeEditor::verticalScrollBarMoved(int y)
{
    firstDrawnLineNumber = y;
    firstDrawnLineIterator = lines.begin();
    firstDrawnLineIterator += y;
}

void CodeEditor::horizontalScrollBarMoved(int x)
{
    return;
}

//SyntaxHighlighter
int CodeEditor::SyntaxHighlighter::previousLineState()
{
    if(currentLineIterator == editor->lines.begin())return 0;
    --currentLineIterator;
    int res = (*currentLineIterator).lineState;
    ++currentLineIterator;
    return res;
}

void CodeEditor::SyntaxHighlighter::setCurrentLineState(int state)
{
    (*currentLineIterator).lineState = state;
}

void CodeEditor::SyntaxHighlighter::setFormat(int begin, int length, bool bold, bool italic, bool underline, QColor color)
{
    codeLine& l = (*currentLineIterator);
    codeLineToken t;
    t.begin = begin;
    t.length = length;
    t.color = color;
    t.bold = bold;
    t.italic = italic;
    t.underline = underline;
    l.tokens.append(t);
}

void CodeEditor::setSyntaxHighlighter(SyntaxHighlighter *highlighter)
{
    this->highlighter = highlighter;
    highlighter->editor = this;
}

//highlighter TODO: Move out of this compilation unit... when more highlighters become needed!
pgsHighlighter::pgsHighlighter()
{
    gcprint("GameScript Syntax Highlighter INIT");
    parser = new pgsParser;
}

pgsHighlighter::~pgsHighlighter()
{
    delete parser;
}

// 1 - normal, 2 - comment

void pgsHighlighter::highlightLine(const QString& text)
{
    //gcprint(text);
    if(previousLineState()!=2)  //is not block comment
    {
        pgsParser::tokenlist l = parser->tokenize(text);
        pgsParser::tokenlistConstIterator i = l.begin();
        for(;i!=l.end();++i)
        {
            int j = (*i).format;
            setFormat( (*i).begin, (*i).length,
                       creatorIDE->codeFormats[j].bold,
                       creatorIDE->codeFormats[j].italic,
                       creatorIDE->codeFormats[j].underline,
                       creatorIDE->codeFormats[j].color
            );
        }
        short state = 1;    //normal
        if(!l.isEmpty())
        if( l.at(l.count()-1).kind == pgsParser::incompleteComment) state=2;    //comment
        setCurrentLineState(state);
    }
    else
    {
        int j = CFcomment;

        int pos = text.indexOf("*/");
        if(pos!=-1)
        {
            setFormat(0,pos+2,
                       creatorIDE->codeFormats[j].bold,
                       creatorIDE->codeFormats[j].italic,
                       creatorIDE->codeFormats[j].underline,
                       creatorIDE->codeFormats[j].color );
            setCurrentLineState(1);
            QStringRef nt = text.midRef(pos+2);
            pgsParser::tokenlist l = parser->tokenize(nt.toString());
            pgsParser::tokenlistConstIterator i = l.begin();
            for(;i!=l.end();++i)
            {
                j = (*i).format;
                setFormat( (*i).begin+pos+2, (*i).length,
                           creatorIDE->codeFormats[j].bold,
                           creatorIDE->codeFormats[j].italic,
                           creatorIDE->codeFormats[j].underline,
                           creatorIDE->codeFormats[j].color );
            }
            short state = 1;    //normal
            if(!l.isEmpty())
            if( l.at(l.count()-1).kind == pgsParser::incompleteComment) state=2;    //comment
            setCurrentLineState(state);
        }
        else
        {
            setFormat(0,text.length(),
                      creatorIDE->codeFormats[j].bold,
                      creatorIDE->codeFormats[j].italic,
                      creatorIDE->codeFormats[j].underline,
                      creatorIDE->codeFormats[j].color);
            setCurrentLineState(2); //comment
        }
    } /**/
}

void CodeEditor::updateSyntaxHighlighting(int linenum)
{
    if(highlighter)
    {
        highlighter->currentLineIterator = lines.begin();
        highlighter->currentLineIterator += linenum;
        highlighter->highlightLine( (*(highlighter->currentLineIterator)).text );
    }
}

void CodeEditor::updateSyntaxHighlighting()
{
    updateSyntaxHighlighting(lineNumber);
}

inline uint8_t paintEvent_getFormatIndex(bool b, bool i, bool u)
{
    //  0x00000biu
    return u | i<<1 | b<<2;
}
inline void paintEvent_extractFormatBits(uint8_t format, bool* b, bool* i, bool* u)
{
    uint8_t boldMask = 1 << 2, italicMask = 1 << 1, underlineMask = 1;
    *b =  (format & boldMask)      ? 1 : 0;
    *i =  (format & italicMask)    ? 1 : 0;
    *u =  (format & underlineMask) ? 1 : 0;
}

struct paintEvent_textblock
{
    int x,y,w;
    //uint8_t format;    //bin  00000biu    //stored into its INDEX
    QColor color;
    bool selected;
    QStringRef text;
};


paintEvent_textblock makeBlock(QStringRef text,int x,int y,int w,QColor color=Qt::black)
{
    paintEvent_textblock tb;
    tb.x = x;
    tb.y = y;
    tb.w = w;
    tb.color = color;
    tb.text = text;
    return tb;
}

void CodeEditor::paintEvent(QPaintEvent *e)
{
    //glClearColor(1,1,1,1);
    //glClear(GL_COLOR_BUFFER_BIT);
    //We may paint this more often so it must paint fast!
    e->accept();
    QStylePainter p(this->viewport());
    int horzSliderVal = horizontalScrollBar()->value();

    //PREPARE THE TEXT LINES:
    LINESLISTTYPE::const_iterator l = lines.begin();
    l+=firstDrawnLineNumber;    //safe?

    //Text editor rendering: optimized for fewest Draw Text and setFont calls.
    QList<paintEvent_textblock> renderLists[16];
    QList<paintEvent_textblock> selection;
    int currentLine = -1;

    QString space = " ";
    QStringRef spaceRef = space.midRef(0,1);

    for(int i=0;i<=drawnLinesCount;++i,++l)
    {
        if( l >= lines.constEnd() )break;

        //Current line
        if(l == lineIterator)currentLine = i;

        //prepare text
        const QString& text = (*l).text;

        if(text.length()==0) continue;   //No text in a line means no further processing of that line!

        //First, for each line, create the char format map - just an index array
        //Each integer of this map means which token's formatting options will be used
        //to format the resulting symbol into the text block.
        int* charTokenIndexes = new int[text.length()];

        //Initialize the array with -1 - invalid index:
        for(int x=0;x<text.length();x++)charTokenIndexes[x] = -1;

        //For each token, set its corresponding indexes:
        const QList<codeLineToken>& tokens = (*l).tokens;
        for(int tokenIndex=0; tokenIndex < tokens.count(); ++tokenIndex)
        {
            const codeLineToken& token = tokens.at(tokenIndex); //it MUST exists!
            for(int x=token.begin; x<token.begin+token.length; ++x)
                if(x<text.length())
                    charTokenIndexes[x]=tokenIndex;/**/
        }
        // charTokenIndexes must now be properly filled;

        // Calculate initial x and y position
        int x=leftareaWidth+leftMargin-horzSliderVal;
        int y=i*lineHeight;

        int trpos=0, trlen=0; int lastIndex = charTokenIndexes[0];   //if this text HAVE lines, of course!
        //init a new block
        paintEvent_textblock tb;
        tb.x = x;
        tb.y = y;
        tb.w = 0;
        tb.color = Qt::magenta;
        tb.selected = false;

        //for each prepare what to draw
        //QString db;
        for(int col=0;col<=text.length();col++)
        {
            // fontMetrics().size(Qt::TextExpandTabs | Qt::TextSingleLine, tb.text.toString(), tabStopPixelSize).width();
            if(col==text.length())
            {
                // complete current block
                tb.text = text.midRef(trpos,trlen);
                int tw;
                if(trlen>0)
                {
                    tw = fontMetrics().width(tb.text.toString());
                    tb.w = tw; int format=0;

                    // Colorize the token before commit [NEW]
                    int formatindex = charTokenIndexes[col];
                    if(formatindex!=-1)
                    {
                        const codeLineToken& token = tokens.at(formatindex);
                        tb.color = token.color;
                        format = paintEvent_getFormatIndex(token.bold,token.italic,token.underline);
                    }else tb.color = palette().windowText().color();

                    renderLists[format].append(tb);
                }
                else tw=0;
                continue;
            }
            else if(text.at(col)=='\t')
            {
                if(col-1>=0 && text.at(col-1)=='\t')
                {
                    //db += "|[TAB2]";
                    tb.x = x;
                    tb.w = tabStopPixelSize;
                    //renderLists[format].append(tb);
                    x+=tabStopPixelSize;
                    if(col+1<text.length())
                    //gcprint(text.at(col+1));
                    trpos=col+1;
                    trlen=0;
                    tb.x = x;
                    continue;
                }
                QColor color = QColor(); int format=0; int idx;

                //old buggy coloring code
                if(col+1<=text.length()) idx = col+1; else idx=col;
                idx = col;
                if(charTokenIndexes[idx]!=-1) {
                    const codeLineToken& token = tokens.at(charTokenIndexes[idx]); color = token.color;
                    format = paintEvent_getFormatIndex(token.bold,token.italic,token.underline);}
                tb.color = color;/**/

                // 1. complete current block
                // 2. commit if needed
                int tw;
                tb.text = text.midRef(trpos,trlen);
                if(tb.text.length()>0)
                {
                    tw = fontMetrics().width(tb.text.toString());
                    tb.w = tw;

                    //I HAVE NOT ANY IDEA WHY this works, but anyway... sleep-coding..
                    //COLORIZE the token before commit
                    //if(tb.color.isValid())
                    //{
                        //gcprint("[TAB] INVALID COLOR!");
                        int formatindex = charTokenIndexes[col-1];
                        if(formatindex!=-1)
                        {
                            const codeLineToken& token = tokens.at(formatindex);
                            tb.color = token.color;
                            format = paintEvent_getFormatIndex(token.bold,token.italic,token.underline);
                        }else tb.color = palette().windowText().color();
                    //}
                    renderLists[format].append(tb);
                }
                else tw=0;
                x+=tw;

                // 3. make new block
                trpos=col; trlen=0;
                tb.x+=tb.w;
                x-= leftareaWidth+leftMargin-horzSliderVal;
                tw= tabStopPixelSize - x % tabStopPixelSize;
                x+= leftareaWidth+leftMargin-horzSliderVal;
                tb.w=tw;
                tb.text = spaceRef;
                //renderLists[0].append(tb);    //only if selected
                x+=tw;
                // 4. Recover the states and continue
                tb.x = x;
                ++trpos;
                continue;
            }

            // add to current:
            ++trlen;

            //tab handler....
            if(col+1<text.length() && text.at(col+1)=='\t')continue;

            if(charTokenIndexes[col] != charTokenIndexes[col+1])
            {
                // 1. complete current block
                // 2. commit [this code appears to colorize properly but is old]
                QColor color; int format;
                if(charTokenIndexes[col]!=-1) {
                    const codeLineToken& token = tokens.at(charTokenIndexes[col]); color = token.color;
                    format = paintEvent_getFormatIndex(token.bold,token.italic,token.underline);}
                else{format = 0; color = Qt::cyan;}

                //db+="|";
                tb.text = text.midRef(trpos,trlen);
                int tw;
                if(tb.text.length()>0)
                {
                    tw = fontMetrics().width(tb.text.toString());
                    tb.w = tw;
                    tb.color = color;
                    //if(tb.color==Qt::magenta)gcprint("[DEF] WRONG COMMIT! This block is not colorized: ["+tb.text.toString()+"]");
                    if(tb.text.toString()!=" ") //and not selected
                    renderLists[format].append(tb);
                }
                else tw=0;
                x+=tw;
                // 3. make new block
                trpos=col+1;trlen=0;tb.x=x;
            }
            //else if selection mode changes
        }

        //gcprint(db);


        //No what to do anymore!
        delete[] charTokenIndexes;
        continue;
        //break;  //first line only

        //OLD CODE follows [to copy parts from it]
        QString cstr = ""; int addx;
        for(int col=0;col<text.length();col++)
        {
            //FUTURE: For few draw calls: if this is token boundary, set the font and draw the token
            //if tab, increment x with needed space:
            //else just add to the token string

            cstr = text.at(col);
            addx = fontMetrics().width(cstr);
            if(text.at(col)=='\t')
            {
                x-= leftareaWidth+leftMargin-horzSliderVal;
                addx =  tabStopPixelSize - x % tabStopPixelSize;
                x+= leftareaWidth+leftMargin-horzSliderVal;
            }

            //optimizations:
            if(x > viewport()->width())break;
            if(x+addx < leftareaWidth){x+=addx;continue;}

            //is char selected?
            //col between columnNumber and selColumnNumber
            //is this THE line?
            bool isSelected = false;
            int ci = i+firstDrawnLineNumber;
            int lb = qMin(lineNumber,selLineNumber);
            int le = qMax(lineNumber,selLineNumber);
            if(ci>=lb && ci<=le)
            {
                //SELECTION EXISTS:
                if(lb==le)   //single row?
                {
                    //Selection begin:
                    int b = qMin(columnNumber-1,selColumnNumber-1);
                    int e = qMax(columnNumber,selColumnNumber);
                    if(col > b && col < e)isSelected=true;
                }
                else if(ci==lb)
                {
                    //which point is first? Selection or cursor?
                    int fln,flc;
                    if(lineNumber<selLineNumber){flc=columnNumber;}
                    else if(lineNumber>selLineNumber){flc=selColumnNumber;}
                    int b = flc-1;
                    if(col>b)isSelected=true;
                }
                else if(ci==le)
                {
                    //which point is last? Selection or cursor?
                    int flc;
                    if(lineNumber>selLineNumber){flc=columnNumber;}
                    else if(lineNumber<selLineNumber){flc=selColumnNumber;}
                    int b = flc;
                    if(col<b)isSelected=true;
                }
                else isSelected=true;
            }

            // ***  Set the char format from the current token.
            codeLineToken lt;
            if(charTokenIndexes[col]!=-1)
            if(charTokenIndexes[col]<(*l).tokens.count())
                lt = (*l).tokens.at(charTokenIndexes[col]);
            else gcprint("ERROR!!!");

            QFont f = normalFont;
            f.setBold(lt.bold);
            f.setItalic(lt.italic);
            f.setUnderline(lt.underline);
            //p.setFont(f);   //Slow?

            //Draw it
            if(isSelected)
            {
                p.setPen(palette().color(QPalette::HighlightedText));
                p.fillRect(x,y,addx,lineHeight,palette().color(QPalette::Highlight));
            }
            else p.setPen(lt.color);

            p.drawRect(x,y,addx-2,lineHeight - 2);
            p.drawText(x,y,addx,lineHeight,
                       Qt::AlignLeft | Qt::AlignVCenter,cstr);
            x+=addx;
        }


    }

    //RENDER ALL:
    //p.setRenderHints(QPainter::Antialiasing);

    // 1. current line highlight
    if(currentLine!=-1)
        p.fillRect(leftareaWidth,currentLine*lineHeight,viewport()->width(),lineHeight,
                   QColor(0,0,0,10));

    // 2. Render text blocks

    for(uint8_t li = 0; li<16; li++)
    {
        // li is the list index, but also contains 3 booleans in it!
        bool bold, italic, underline;
        paintEvent_extractFormatBits(li,&bold,&italic,&underline);
        //set the font - total of 16 times...and only if there are tokens in the corresponding list:
        if(renderLists[li].count()>0)
        {
            QFont f(font());
            f.setBold(bold);
            f.setItalic(italic);
            f.setUnderline(underline);
            p.setFont(f);
            for(int bi=0;bi<renderLists[li].count();bi++)
            {
                //render the block:
                const paintEvent_textblock& block = renderLists[li].at(bi);
                /**/
                QColor c = block.color;
                c.setAlpha(140);
                QPen pen(c);
                p.setPen(pen);
                p.drawRect(block.x,block.y,block.w-1,lineHeight-1);/**/
                p.setPen(block.color);
                p.drawText(block.x,block.y,block.w,lineHeight, Qt::AlignLeft | Qt::AlignVCenter, block.text.toString());
            }
        }
    }/**/


    //Draw the text blocks & selections

    // 3. The cursor:
    if(cursorVisible &&
       lineNumber >= firstDrawnLineNumber &&
       lineNumber <= firstDrawnLineNumber + drawnLinesCount)
    {
        const QString& pos = (*lineIterator).text.mid(0,columnNumber);
        int x = leftareaWidth + leftMargin -
                horzSliderVal +
                fontMetrics().size(Qt::TextExpandTabs | Qt::TextSingleLine, pos, tabStopPixelSize).width();

        int y = (lineNumber-firstDrawnLineNumber)*lineHeight;
        p.fillRect(x,y,2,lineHeight,QColor(Qt::black));
        cursorXPos = x;
    }

    //Draw the left area:
    p.fillRect(0,0,leftareaWidth,viewport()->height(),palette().window().color()); //todo: Configurable!
    p.setPen(QColor(palette().midlight().color()));
    p.drawLine(leftareaWidth,0,leftareaWidth,viewport()->height());
    QFont normalfont = font(),boldfont = font();
    boldfont.setBold(1);
    for(int i=0;i<=drawnLinesCount;++i)
    {
        if(firstDrawnLineNumber+i>=lines.count())break;
        if(firstDrawnLineNumber+i==lineNumber)
        {
            p.setPen(QColor(palette().text().color()));
            p.setFont(boldfont);
        }
        else
        {
            QColor c = QColor(palette().text().color());
            c.setAlpha(40);
            p.setPen(c);
            p.setFont(normalfont);
        }
        p.drawText(0,i*lineHeight,leftareaWidth-2,lineHeight,Qt::AlignRight|Qt::AlignVCenter,QString::number(firstDrawnLineNumber+i+1));

        //Line state dump: DEBUG
        p.setPen(Qt::blue);
        p.drawText(0,i*lineHeight,16,lineHeight,Qt::AlignLeft|Qt::AlignVCenter,QString::number(
                      lines.at(firstDrawnLineNumber+i).lineState ));

    }

    //draw some debug stuff:
/*
    QString s = "Total lines: "+QString::number(lines.count())+
            "\nDrawn lines: "+QString::number(drawnLinesCount)+
            "\nFirst Line: "+QString::number(firstDrawnLineNumber)+
            "\nColumn: "+QString::number(columnNumber);
    QFont f;
    f.setFamily("Arial");
    f.setPixelSize(10);
    p.setFont(f);
    p.setPen(QColor::fromRgb(255,0,0));
    p.drawText( viewport()->rect(), Qt::AlignBottom | Qt::AlignRight, s ); /**/
}

void CodeEditor::updateCursorXPos()
{
    int horzSliderVal = horizontalScrollBar()->value();

    const QString& pos = (*lineIterator).text.mid(0,columnNumber);
    cursorXPos = leftareaWidth + leftMargin -
                 horzSliderVal +
                 fontMetrics().size(Qt::TextExpandTabs | Qt::TextSingleLine, pos, tabStopPixelSize).width();
    //gcmessage(QString::number(cursorXPos));
}

void CodeEditor::updateHorizontalScrollBarPos()
{
    if(cursorXPos<leftareaWidth+leftMargin)
    {
        int chw = fontMetrics().width(' ');
        if(cursorXPos < leftareaWidth+leftMargin+chw)
        {
            int val = horizontalScrollBar()->value() + cursorXPos-leftareaWidth-leftMargin-chw;
            horizontalScrollBar()->setValue(val);
        }
    }
    else if(cursorXPos>viewport()->width()- (width()-viewport()->width()))
    {
        if(cursorXPos>viewport()->width() - (width()-viewport()->width())  )
        {
            int val = horizontalScrollBar()->value() + cursorXPos-viewport()->width() + (width()-viewport()->width());
            horizontalScrollBar()->setValue( val );
        }
    }
}

void CodeEditor::updateVerticalScrollBarPos()
{
    //So the cursor must be inside viewport:
    if(lineNumber<firstDrawnLineNumber)
    {
        int scroll = lineNumber-firstDrawnLineNumber;
        verticalScrollBar()->setValue( verticalScrollBar()->value()+scroll );
    }
    else if(lineNumber-firstDrawnLineNumber>drawnLinesCount-1)
    {
        int scroll = lineNumber-firstDrawnLineNumber-drawnLinesCount+1;
        verticalScrollBar()->setValue( verticalScrollBar()->value()+scroll );

    }
}

void CodeEditor::getLineAndColumnFromPos(int x, int y, int *line, int *column, bool updateLineIterator)
{

    int horzSliderVal = horizontalScrollBar()->value();
    int LN = y/lineHeight + firstDrawnLineNumber;
    if(LN>=lines.count())LN=lines.count()-1;
    if(LN<0)LN=0;
    (*line) = LN;

    LINESLISTTYPE::iterator iter = lines.begin();
    iter += LN;
    if(updateLineIterator)lineIterator = iter;

    int COL=0, clx = leftareaWidth+leftMargin-horzSliderVal;
    const QString& text = (*iter).text;
    int i=0;
    if(text.length()>0)
        while(clx<x)
        {
            const QChar& c = text.at(i);
            if(c=='\t')
            {
                clx-= leftareaWidth+leftMargin-horzSliderVal;
                clx+= tabStopPixelSize - clx % tabStopPixelSize;
                clx+= leftareaWidth+leftMargin-horzSliderVal;
            }
            else clx+=fontMetrics().width(c);
            ++COL;++i;if(i>=text.length())break;
        }
    (*column)=COL;
    //line and column are set now.
}

void CodeEditor::getLineAndColumnFromPos(QPoint pos, int *line, int *column, bool updateLineIterator)
{
    getLineAndColumnFromPos(pos.x(),pos.y(),line,column,updateLineIterator);
}

int CodeEditor::getLineFromPos(int y)
{
    //Just mathematical check!
    int LN = y/lineHeight + firstDrawnLineNumber;
    if(LN>=lines.count())LN=lines.count()-1;
    return LN;
}

bool CodeEditor::event(QEvent *event)
{
    //Default TAB key must be ignored!
    if(event->type()==QEvent::KeyPress)
    {
        keyPressEvent( (QKeyEvent*)event );
        return true;
    }
    else return QAbstractScrollArea::event(event);
}





//Key press event: Does most of the things in this editor:
void CodeEditor::keyPressEvent(QKeyEvent *e)
{
    e->accept();
    /* Code Editor features:
        • Code completion
        • Auto Indentation
        • Autoclose for  () [] {} " ' and comments
    */

    //First: The keyboard controlling
    Qt::KeyboardModifiers mods =  e->modifiers();
    bool Shift = mods.testFlag(Qt::ShiftModifier);
    bool Ctrl  = mods.testFlag(Qt::ControlModifier);    // COMMAND key on Mac OS
    bool Alt   = mods.testFlag(Qt::AltModifier);

    switch(e->key())
    {
    //Movement & selection
    case Qt::Key_Right:
        moveRight(Ctrl,Shift);
        break;
    case Qt::Key_Left:
        moveLeft(Ctrl,Shift);
        break;
    case Qt::Key_Up:
        moveUp(Shift);
        break;
    case Qt::Key_Down:
        moveDown(Shift);
        break;
    case Qt::Key_Home:
        if(Ctrl)moveToBeginOfDocument(Shift);
        else moveToLineBegin(Shift);
        break;
    case Qt::Key_End:
        if(Ctrl)moveToEndOfDocument(Shift);
        else moveToLineEnd(Shift);
        break;

    //Deleting and clearing
    case Qt::Key_Backspace:
        deleteLeft(Ctrl);
        break;
    case Qt::Key_Delete:
        deleteRight(Ctrl);
        break;

    //Misc
    case Qt::Key_Escape:
        //Close the completer if it's shown
        break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
        newLineAtCursor();
        break;

    //Function keys
    case Qt::Key_Tab:
        insertTextAtCursor("\t");
        break;
    case Qt::Key_Insert:
        if(Shift)paste();
        else if(Ctrl)copySelection();
        else insertMode=!insertMode;
        break;
    case Qt::Key_F3:
        //Search & replace functionality TODO: not important
        break;
    case Qt::Key_F1:
    case Qt::Key_F2:
    case Qt::Key_F4:
    case Qt::Key_F5:
    case Qt::Key_F6:
    case Qt::Key_F7:
    case Qt::Key_F8:
    case Qt::Key_F9:
    case Qt::Key_F10:
    case Qt::Key_F11:
    case Qt::Key_F12:
    case Qt::Key_F13:
    case Qt::Key_F14:
    case Qt::Key_F15:
    case Qt::Key_F16:
    case Qt::Key_F17:
    case Qt::Key_F18:
    case Qt::Key_F19:
    case Qt::Key_F20:
    case Qt::Key_F21:
    case Qt::Key_F22:
    case Qt::Key_F23:
    case Qt::Key_F24:
        //Just NO-OP for now!
        break;

    //NO-OPs:
    case Qt::Key_CapsLock:
    case Qt::Key_NumLock:
    case Qt::Key_ScrollLock:
    case Qt::Key_Pause:
    case Qt::Key_Print:
    case Qt::Key_SysReq:
    case Qt::Key_Control:
    case Qt::Key_Alt:
    case Qt::Key_AltGr:
    case Qt::Key_Super_L:
    case Qt::Key_Super_R:
    case Qt::Key_Meta:
        break;

    default:
             if(e->key()==Qt::Key_V && Ctrl)paste();
        else if(e->key()==Qt::Key_C && Ctrl)copySelection();
        else if(e->key()==Qt::Key_X && Ctrl){copySelection();clearSelection();}
        else if(e->key()==Qt::Key_Z && Ctrl)undo();
        else if(e->key()==Qt::Key_Y && Ctrl)redo();
        else if(e->key()==Qt::Key_A && Ctrl)selectAll();
        //Type the character:
        else if(!Ctrl)insertTextAtCursor(e->text());
    }
    cursorVisible=true;
    viewport()->repaint();
}

//All KeyPressEvent functions here:
bool CodeEditor::isLetter(const QChar &c)
{
    if(c>='a' && c<='z')return true;
    else if(c>='A' && c<='Z')return true;
    else if(c>='0' && c<='9')return true;   //treat this as letter too
    else if(c=='_')return true;
    return false;
}

void CodeEditor::moveLeft(bool word, bool select)
{
    const QString& text = (*lineIterator).text;
    if(word)
    {
        bool right=1;
        int state=0;
        do
        {
            moveLeft(false,select);
            const QString& text2 = (*lineIterator).text+" ";
            QChar c = text2.at(columnNumber==text2.length()?text2.length()-1:columnNumber );
            if(state==0 && isLetter(c))state=1;
            else if(state==1 && isLetter(c)==false)state=2;
            if(lineNumber==0 && columnNumber==0){state=2;right=0;}
        }
        while(state!=2);
        if(right)moveRight(false,select);
    }
    else
    {
        //do
        if(lineNumber==0 && columnNumber==0)return;
        --columnNumber;
        if(!select){selColumnNumber=columnNumber;selLineNumber=lineNumber;}
        if(columnNumber<0)
        {
            moveUp(select);
            moveToLineEnd(select);
        }
    }
    cursorVisible=true;
    updateCursorXPos();
    updateHorizontalScrollBarPos();
}

void CodeEditor::moveRight(bool word, bool select)
{
    const QString& text = (*lineIterator).text;
    if(word)
    {
        bool left=1;
        int state=0;
        do
        {
            moveRight(false,select);
            const QString& text2 = (*lineIterator).text+" ";
            QChar c = text2.at(columnNumber==text2.length()?text2.length()-1:columnNumber );
            if(state==0 && isLetter(c))state=1;
            else if(state==1 && isLetter(c)==false)state=2;
            if(lineNumber==lines.count()-1 && columnNumber==lines.at(lines.count()-1).text.length())state=2;
        }
        while(state!=2);
        if(left && columnNumber==0)moveLeft(false,select);
    }
    else
    {
        if(lineNumber==lines.count()-1 && columnNumber==lines.at(lines.count()-1).text.length())return;
        ++columnNumber;
        if(!select){selColumnNumber=columnNumber;selLineNumber=lineNumber;}
        if(columnNumber>text.length())
        {
            moveDown(select);
            moveToLineBegin(select);
        }
    }
    updateCursorXPos();
    updateHorizontalScrollBarPos();
    cursorVisible=true;
}

void CodeEditor::moveToLineBegin(bool select)
{
    columnNumber=0;
    if(!select)selColumnNumber=0;
    int chw = fontMetrics().width(' ');
    if(cursorXPos < leftareaWidth+leftMargin+chw)
    {
        int val = horizontalScrollBar()->value() + cursorXPos-leftareaWidth-leftMargin-chw;
        horizontalScrollBar()->setValue(val);
    }
    cursorVisible=true;
    updateCursorXPos();
    updateHorizontalScrollBarPos();
}

void CodeEditor::moveToLineEnd(bool select)
{
    const QString& text = (*lineIterator).text;
    columnNumber=text.length();
    if(!select)selColumnNumber=columnNumber;
    cursorVisible=true;
    updateCursorXPos();
    updateHorizontalScrollBarPos();
}

void CodeEditor::moveUp(bool select)
{
    //TODO: Selecting!
    --lineNumber;
    if(lineNumber<0)lineNumber=0;
    lineIterator = lines.begin();
    lineIterator += lineNumber;
    const QString& text = (*lineIterator).text;
    if(columnNumber>=text.length())columnNumber=text.length();
    if(columnNumber<0)columnNumber=0;
    if(!select){selLineNumber=lineNumber;selColumnNumber=columnNumber;}

    updateCursorXPos();
    updateHorizontalScrollBarPos();
    updateVerticalScrollBarPos();
}

void CodeEditor::moveDown(bool select)
{
    ++lineNumber;
    if(lineNumber>=lines.count()-1)lineNumber=lines.count()-1;
    lineIterator = lines.begin();
    lineIterator += lineNumber;
    const QString& text = (*lineIterator).text;
    if(columnNumber>=text.length())columnNumber=text.length();
    if(columnNumber<0)columnNumber=0;
    if(!select){selLineNumber=lineNumber;selColumnNumber=columnNumber;}

    updateCursorXPos();
    updateHorizontalScrollBarPos();
    updateVerticalScrollBarPos();
}

void CodeEditor::moveToBeginOfDocument(bool select)
{
    lineNumber=0;
    columnNumber=0;
    lineIterator = lines.begin();
    if(!select){selLineNumber=lineNumber;selColumnNumber=columnNumber;}
    updateCursorXPos();
    updateHorizontalScrollBarPos();
    updateVerticalScrollBarPos();

}

void CodeEditor::moveToEndOfDocument(bool select)
{
    lineNumber=lines.count()-1;
    lineIterator = lines.begin();
    lineIterator += lineNumber;
    const QString& text = (*lineIterator).text;
    columnNumber=text.length();
    if(!select){selLineNumber=lineNumber;selColumnNumber=columnNumber;}
    updateCursorXPos();
    updateHorizontalScrollBarPos();
    updateVerticalScrollBarPos();
}

void CodeEditor::newLineAtCursor()
{
    insertTextAtCursor("\n");
}

void CodeEditor::insertTextAtCursor(const QString &text)
{
    //TODO: Lines!
    if(text.length()==0)return;
    clearSelection();

    QStringList lns = text.split("\n");
    if(lns.count()==1)    //only one line:
    {
        codeLine ln = (*lineIterator);
        ln.text = ln.text.insert(columnNumber,text);
        //TODO: Recolorize
        columnNumber+=text.length();
        lines[lineNumber] = ln;
        selColumnNumber = columnNumber;
        updateCursorXPos();
        updateHorizontalScrollBarPos();
        updateLeftAreaWidth();
    }
    else
    {
        //3 phases: First line, middle lines, last line

        //First Line:
        codeLine ln = (*lineIterator);
        //this will be appended to the last line
        QString rest = ln.text.mid(columnNumber);
        //insert from cursor point to the end!
        ln.text = ln.text.mid(0,columnNumber)+ lns.at(0);
        lines[lineNumber]=ln;

        //middle lines
        for(int ii=1;ii<lns.count()-1;ii++)
        {
            codeLine ln2;
            ln2.text = lns.at(ii);
            lines.insert(lineNumber+ii,ln2);
        }

        //last line
        codeLine ln2;
        ln2.text = lns.at(lns.count()-1) + rest;
        int lpos = lns.at(lns.count()-1).length();
        lines.insert(lineNumber+lns.count()-1,ln2);

        lineNumber += lns.count()-1;
        lineIterator = lines.begin();
        lineIterator += lineNumber;
        selLineNumber = lineNumber;
        columnNumber = lpos;
        selColumnNumber = columnNumber;

        updateCursorXPos();
        updateHorizontalScrollBarPos();
        updateVerticalScrollBarSettings();
        updateLeftAreaWidth();
    }
    selLineNumber = lineNumber;
    selColumnNumber = columnNumber;
    updateSyntaxHighlighting();
    updateVerticalScrollBarPos();
}

void CodeEditor::deleteLeft(bool word)
{
    if(getSelectedText().length()!=0)
        clearSelection();
    else
    {
        moveLeft(word,true);
        clearSelection();
    }
    updateCursorXPos();
    updateHorizontalScrollBarPos();
}

void CodeEditor::deleteRight(bool word)
{
    if(getSelectedText().length()!=0)
        clearSelection();
    else
    {
        moveRight(word,true);
        clearSelection();
    }
    updateCursorXPos();
    updateHorizontalScrollBarPos();
}

void CodeEditor::paste()
{
    insertTextAtCursor(qApp->clipboard()->text());
    updateCursorXPos();
    updateHorizontalScrollBarPos();
}

void CodeEditor::copySelection()
{
    qApp->clipboard()->setText(getSelectedText());
}

void CodeEditor::undo()
{
    //TODO
}

void CodeEditor::redo()
{
    //TODO
}

void CodeEditor::selectAll()
{
    int fdr = firstDrawnLineNumber;
    moveToBeginOfDocument(false);
    moveToEndOfDocument(true);
    firstDrawnLineNumber = fdr;
}

void CodeEditor::mouseDoubleClickEvent(QMouseEvent *e)
{
    //select the word
    moveLeft(1,0);
    moveRight(1,1);
    viewport()->repaint();
}

void CodeEditor::mousePressEvent(QMouseEvent * e)
{
    mousepressed=true;

    //press will directly update the line number and col as well as selection
    getLineAndColumnFromPos(e->x(),e->y(),&lineNumber,&columnNumber,true);
    selLineNumber = lineNumber;
    selColumnNumber = columnNumber;

    e->accept();
    viewport()->repaint();
}

void CodeEditor::mouseReleaseEvent(QMouseEvent *e)
{
    mousepressed=false;
}

void CodeEditor::mouseMoveEvent(QMouseEvent *e)
{
    if(mousepressed)
    {
        int line,col;
        getLineAndColumnFromPos(e->pos(),&line,&col,true);
        columnNumber = col;
        lineNumber = line;
        viewport()->repaint();
        updateHorizontalScrollBarPos();
        updateVerticalScrollBarPos();
    }
    if(e->x()>leftareaWidth)setCursor(Qt::IBeamCursor);
    else setCursor(Qt::ArrowCursor);
}

//when cursor is moved or changed, for debugging
/*
void CodeEditor::cursorMoved()
{
    //unused
    return;
    QTextCursor t = source->textCursor();
    int l,c, cp;
    l = t.blockNumber();
    c = t.columnNumber();
    cp= t.position();
    tokens = parser.tokenize(Text());   //FULL reparse??
    int cpos = parser.tokenIndexAtPos(tokens,cp);
    int lc =   parser.tokenIndexAtLC(tokens,l,c);

    gcprint(QString("Pos: %1, index: %2").arg(QString::number(cp),  QString::number(parser.tokenIndexAtPos(tokens,cp))) );
    gcprint(QString("Line: %1, Column: %2, index: %3").arg(QString::number(l),QString::number(c),QString::number(parser.tokenIndexAtPos(tokens,cp))) );

    if(cpos>-1)
    gcprint("Cursor at: " + tokens.at( cpos ).text);
    else
    {
        if(tokens.count()==0){gcprint("No tokens!");return;}
        gcprint("Curson in INVALID POSITION!");
        if(cp >= Text().length())gcprint("possibly AFTER the text: getting LAST token");
        else if(cp < tokens.at(0).begin ) gcprint("possibly BEFORE first valid token, getting FIRST token");
    }
}/**/
