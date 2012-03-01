#ifndef PGSPARSER_H
#define PGSPARSER_H

#include <QPlainTextEdit>
#include <QString>
#include "gameproject.h"

// This class provides the generic piGameScript state machine to parse the GameScript Language

// This code is copyrighted and is under the Pi-Dev PRIVATE USE ONLY License
// if you are using the Commercial Version.

// You are not permited to use this code in shippable commercial products
// EVEN if you ship piGameCreator as a mod tool to your game!
// (this solely means, "Classes" functionality must NOT appear in the piGameCreator for Mods IDE)
// If you want to use this library in commercial applications, you must have Unlimited Commercial license.

// The only valid use of this code is if you port the piGameScript to new platforms and languages
// You are hereby obligated to return this code to Pi-Dev for future release!
// YOU UNDERSTAND THAT PI-DEV IS THE ONLY COPYRIGHT HOLDER TO THE piGameScript LANGUAGE

                // --------------- ELSE ---------------

// If you received this file as part of the GPL version of piGameCreator,
// then this file is subject to the GNU General Public License version 3 or any later version.
// You know that games you create with piGameCreator are your intellectual property but you
// cannot distribute piGameCreator with them, unless your games are GPL-compatible.
// you are free to distribute your games as you like if there are NO parts from piGameCreator IDE in them.
// The piGameCreator runtimes are copyrighted but free for commercial use.
// If your game is free but not Open-source and you want to distribute piGameCreator for Mods with it,
// without distributing your game's source code, contact Pi-Dev to obtain a free written permission.


class pgsParser
{
public:
    pgsParser();
    enum tokenkind
    {
        //original tokens.txt file coming

        nameId,		// if not defined
        varId,		// if defined
        constId,
        assignmentOp,	// += *= -= /=
        incDecOp,	// ++ --
        comparisonOp,	// == <= >= < >
        equalOp,	// =
        assignOp,	// := set
        arithmeticOp,	// + - * / ^
        memberOp,	// .
        bracketS,	// ( expr or func
        bracketE,       // )
        comma,		// ,

        FuncId,
        IntVal,
        RealVal,
        StringVal,
        PartStringVal,

        typeId,		//int string
        classId,

        NEWkw,
        DELETEkw,
        FORkw,
        IFkw,
        ELSEkw,
        DOkw,
        UNTILkw,
        WHILEkw,
        REPEATkw,

        semicolon,	// ;	stmtend, for
        blockbegin,	// {
        blockend,	// }
        arrayS,		// [
        arrayE,		// ]
        appendOp,	// << array append

        embed,		// <[*]> ... <[END]>
        comment,        // /* ... */
        incompleteComment,  // /* ...  :}
        preproc,        // #something
        junk
    };
    enum symboltype{letter,digit,whitespace,newline,symbol,unknown};
    struct token
    {
        tokenkind kind;     //token kind
        int begin, length;  //the position in the entry string for this token and its length
        int matchingtoken;  //for matching braces and s.th.
        int line, col;      //the line in source string that token BEGINS and tyhe column
        int blocklevel;     //the block level for that token.
        QString text;       //the text for this token
        QString tag;        //For embeds, the tag name
        QString value;      //for strings, the value of the string, for embeds: the code
        QString typeName;   //if token have TYPE
        QString tooltip;    //tooltip to display
        int format;         //format type for that token, used by the code coloring routine
    };
    bool isKeyword(QString s);
    bool isType(QString s);
    bool isFunction(QString s);
    bool isClass(QString s);
    bool isResource(QString s);
    bool isConst(QString s);
    bool isVar(QString s);

    QList<token> tokenize(QString str);
    void colorize(QPlainTextEdit* Editor, QList<token> * tokenlist);
    virtual void parse(QList<token> * tokenlist);
    int tokenIndexAtPos(int pos);

    QString tokenkindToString(tokenkind t);

    //next APIs are call-backs and will be called by parse().
    //Subclasses of this must reimplement them.
    //default implementations will be "Not Implemented" error message

    void setProject(gameproject* gp);
    symboltype ST(QChar c);
    gameproject* gp;
};
typedef QList<pgsParser::token> tokenList;

#endif // PGSPARSER_H
