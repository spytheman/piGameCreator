#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QAbstractScrollArea>
#include <QLinkedList>
#include "../sharedcode/pgsparser.h"
#include <QTimer>
#include <QFuture>
#include <QFutureWatcher>

#define LINESLISTTYPE QList<codeLine>
class CodeEditor : public QAbstractScrollArea
{
    friend struct gswWrapper;
        Q_OBJECT

    public:
        CodeEditor(QWidget *parent = 0);
        ~CodeEditor();

        //This scroll area is actually a text editor!
        //It have lines, each line have text and token data and settings
        struct codeLineToken
        {
            int begin, length, formatIndex;
        };
        struct codeLine
        {
            QString text;       //The text of this line
            char lineState, oldLineState;    //line state as in QTextEdit for highlighting [blockState]
            bool isBookmark, isHidden, isBreakpoint;
            QList<codeLineToken> tokens;    //Tokens and their data
            codeLine();
        };
        LINESLISTTYPE lines;

        //These iterator and int define where is the cursor
        LINESLISTTYPE::iterator lineIterator;
        int lineNumber, columnNumber,            // Cursor line & column
            selLineNumber, selColumnNumber;  // Selection end line & column

        //Text editing routines
        void clearSelection();
        void copySelection();
        void cutSelection();
        void paste();
        void insertTextAtCursor(const QString& text);
        void newLineAtCursor();
        void deleteLeft(bool word);
        void deleteRight(bool word);
        void undo();
        void redo();
        void clearUndoStates();

        //Cursor navigation and selection
        void moveLeft(bool word=false, bool select=false);
        void moveRight(bool word=false, bool select=false);
        void moveUp(bool select=false);
        void moveDown(bool select=false);
        void moveToLineBegin(bool select=false);
        void moveToLineEnd(bool select=false);
        void moveToBeginOfDocument(bool select=false);
        void moveToEndOfDocument(bool select=false);
        void selectAll();
        void updateHorizontalScrollBarPos();
        void updateVerticalScrollBarPos();
        void updateVerticalScrollBarSettings();

        //Mathematics:
        void getLineAndColumnFromPos(int x,int y,int* line,int* column, bool updateLineIterator=false);
        void getLineAndColumnFromPos(QPoint pos,int* line,int* column, bool updateLineIterator=false);
        int getLineFromPos(int y);
        void updateCursorXPos();
        bool isLetter(const QChar& c);

        //pointer to first drawn line for fast drawing
        LINESLISTTYPE::iterator firstDrawnLineIterator;
        int firstDrawnLineNumber;

        int leftareaWidth;  //width of the left area
        int drawnLinesCount, lineHeight, lineSpacing, leftMargin;
        int cursorXPos;

        //Get string widths in threads
        /*
        QFuture<void> gswFuture;
        QFutureWatcher<void> gswWatcher;
        int gswMax; /**/

        //set and get the text
        void setText(QString s);
        QString getSelectedText();
        QString getText();

        //events
        void keyPressEvent(QKeyEvent *event);
        void paintEvent(QPaintEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void mouseDoubleClickEvent(QMouseEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void resizeEvent(QResizeEvent *event);
        bool event(QEvent *event);

        //other
        void setLineSpacing(int);
        void updateLineSize();
        void updateSyntaxHighlighting();
        void updateSyntaxHighlighting(int line);

        //unused:
        void CursorMoved();

        //visual settings:
        QColor selectionColor, backgroundColor, currentLineColor;
        int tabStopPixelSize, maximumHorizontalTextWidthInPx;

        //For syntax coloring: available color formats
        struct codeTokenFormat
        {
            bool bold,italic,underline;
            QColor color;
            codeTokenFormat& operator= (const fontsetting& s);
        };
        QList<codeTokenFormat> codeFormats();
        void setCodeFormats(QList<codeTokenFormat> formats, int defaultFormat = 0);

        //These formats will be written in a way to respect formatting options from pgsParser

        //Caching:
        QFont normalFont;
        void reloadFont();

        //other settings:
        bool insertMode;

        //associated classes
        class SyntaxHighlighter
        {
            friend class CodeEditor;
        public:

            // Highlight a line of text. Call setFormat to set the format index
            virtual void highlightLine(const QString& text) = 0;

            // init the highlighter.
            // Editor pointer WILL be properly set here. Good place to reapplyFontSettings() as well
            virtual void init() = 0;

            // set the code formats to the editor here. If you don't set them,
            // the editor will crash.
            virtual void reapplyFontSettings() = 0;

        protected:
            LINESLISTTYPE::iterator currentLineIterator;
            char previousLineState();
            void setCurrentLineState(int state);
            void setFormat(int begin, int length, int codeFormatIndex);
            CodeEditor* editor;
        };
        void setSyntaxHighlighter(SyntaxHighlighter* highlighter);
        SyntaxHighlighter* getSyntaxHighlighter();
        QTimer cursorBlinkTimer;
        bool cursorVisible;

    private slots:
        void verticalScrollBarMoved(int y);
        void horizontalScrollBarMoved(int x);
        void toggleCursorVisible();
        void gswCompleted();
        void gswProgressChanged(int);
        void highlighterReapplyFontSettings();
        void onIDESettingsChanged();

    private:
        void getThreadedStringWidth(const codeLine& ln);
        void updateLeftAreaWidth();
        bool mousepressed;
        SyntaxHighlighter* highlighter;
        QList<codeTokenFormat> codeTokenFormats;
        int defaultTokenFormat;
};

//The piGameScript syntax highlighter

class pgsHighlighter: public CodeEditor::SyntaxHighlighter
{
    public:
        pgsHighlighter();
        ~pgsHighlighter();
        pgsParser* parser;
    protected:
        void highlightLine(const QString& text);
        void init();
        void reapplyFontSettings();
};


#endif // CODEEDITOR_H
