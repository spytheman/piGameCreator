#ifndef PGSPARSER_H
#define PGSPARSER_H

#include <QPlainTextEdit>
#include <QString>
#include "gameproject.h"

// -------------------------------   pgsParser   ---------------------------------------

// This class provides the generic gamescript state machines, structures, classes and mothods
// to parse the GameScript Language. This class is CPU-BOUND, so I really don't care about
// maintenance. This class should even not be modified... unless you NEED to change the
// gamescript language itself, which we do NOT recommend!

// ------------------------------   FREE LICENSE   -------------------------------------

// This code is NOT TO BE USED in PRODUCTION (as ALL OTHER code!)
// Free license only allows you to modify Creator IDE for your personal use.
// Games and applications you create with Creator IDE are your intellectual property but you
// cannot distribute Creator IDE with them, unless your games are open-source.

// If you port the GameScript to new platforms and languages,
// you are obligated to send your implementations to Pi-Dev.
// Any implementations of GameScript must be known to Pi-Dev!
// YOU UNDERSTAND THAT PI-DEV IS THE ONLY COPYRIGHT HOLDER TO THE GameScript LANGUAGE

// Free license DOES NOT PERMIT you to distribute MOD IDE with your games, be they free
// or commercial! Creator IDE downloaded as free is locked to execute this feature by default.
// If you compiled the IDE from source, you should be noted that the Free license only allows
// MOD IDE for open-source games. If your particular game is open-source, then check the
// "Open-source" section below.

// Free license only allows you to use creator IDE to make your games and publish them.
// If you want your games to be user-moddable, please, contact us for possible MOD IDE
// Exceptions. Or, you can implement your own modding functionality and your own level editors.
// Also, free license have resource limits for games published in our Game Store, and to platforms
// the IDE can export.

// Please note, that revenue over $1500 from game sales, be it in-game sales for items in Free To Play
// games or buying commercial or shareware games IN the Game Store, obligates you to upgrade your license.
// Also, do not forget that posting a game on real media, like CD/DVD in stores requires that
// you have established legal company and encourages you to buy commercial license (If you are distributing
// your game in both Real Media And the Game store, you must upgrade to Commercial license).

// ---------------------------   COMMERCIAL LICENSE   ----------------------------------

// This class is under the PRIVATE USE ONLY clause

// You are not permited to use this class in end-user commercial products in its originally intended way.
// This means, "Classes" functionality must NOT appear in the MOD IDE in its original implementation.
// "Classes" functionality can be there, for example, only to show class reference data.

// To be more precise, end-user commercial products, including the MOD IDE, should NOT be able to COMPILE
// gamescript, or to INTERPRET gamescript. It is OKAY this class to be linked and used for validation purposes
// of user input, or to be linked and unused at all. Where Scene Editor in default MOD IDE uses this class,
// such usage it is perfectly okay.

// If you think this clause is limiting scripting of user mods in your game, either implement "visual scripting"
// like Serious Engine 1 for your game, and interpret it by yourself, incorporatee some other scripting engine,
// like LUA runtime, or upgrade your license.

// If you want to use this class in commercial applications, you must have Unlimited Commercial license.

// If you port the GameScript to new platforms and languages,
// you are obligated to send your implementations to Pi-Dev.
// Any implementations of GameScript must be known to Pi-Dev!
// YOU UNDERSTAND THAT PI-DEV IS THE ONLY COPYRIGHT HOLDER TO THE GameScript LANGUAGE

// ----------------------   UNLIMITED COMMERCIAL LICENSE   -----------------------------

// Unlimited commercial license (UCL) gives you full rights to
// use this class with only one notable exception:
// If you port the GameScript to new platforms and languages,
// you are obligated to send your implementations to Pi-Dev.
// Any implementations of GameScript must be known to Pi-Dev!
// YOU UNDERSTAND THAT PI-DEV IS THE ONLY COPYRIGHT HOLDER TO THE GameScript LANGUAGE

// You are free to distribute MOD IDE with Classes support and needed compilers as you wish,
// but you must comply with the compiler's license. For example, if you distribute MOD IDE
// with GNU C++ Compiler or MingW, you should not forget that GCC/MingW fall under GNU GPL,
// Users MUST KNOW that GNU GCC is Open Source program, and CREATOR IDE is just an IDE that uses it!

// ---------------------------   OPEN SOURCE LICENSE   ---------------------------------

// If you received this file as part of the GPL version of piGameCreator, or the Free Indie license
// then this file is subject to the GNU General Public License version 3 or any later version.

// You know that games you create with Creator IDE are your intellectual property but you
// cannot distribute creator IDE with them, unless your games are GPL-compatible.
// You are free to distribute your games as you like if there are NO parts from Creator IDE in them.

// The pi|ENGINE runtimes are copyrighted but free for commercial use.

// If your game is GPL v3 compatible open-source game, you are free to distribute Creator IDE with
// it as you like, modified and unmodified, but do not forget: GPL means: Open Source!

// If your game is free but not Open-source and you want to distribute Creator MOD IDE with it,
// without distributing your game's source code, contact Pi-Dev to obtain a written permission,
// if we decide to give such to you. Better, create your own level and game editing tools, so
// users can mod your game without the need for Mod IDE.

// -------------------------------------------------------------------------------------


class pgsParser
{
public:
    struct token;
    typedef QVector<token> tokenlist;
    typedef QVector<token>::const_iterator tokenlistConstIterator;
    typedef QVector<token>::iterator tokenlistIterator;

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

        funcId,
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

        CLASSkw,
        EXTENDSkw,
        IMPLEMENTSkw,

        STATICkw,
        SWITCHkw,
        CASEkw,
        DEFAULTkw,
        BREAKkw,
        CONTINUEkw,

        semicolon,	// ;	stmtend, for
        blockbegin,	// {
        blockend,	// }
        arrayS,		// [
        arrayE,		// ]
        appendOp,	// << array append

        embed,		// <[*]> ... <[END]>
        comment,        // /* ... */
        incompleteComment,  // /* ...
        preproc,        // #something
        junk
    };
    bool isTextToken(tokenkind t);
    enum symboltype{letter,digit,whitespace,newline,symbol,unknown};
    struct token
    {
        tokenkind kind;     //token kind
        int begin, length;  //the position in the entry string for this token and its length
        int matchingtoken;  //for matching braces and s.th.
        int line, col;      //the line in source string that token BEGINS and the column
        int blocklevel;     //the block level for that token.
        QString text;       //the text for this token
        QString tag;        //For embeds, the tag name
        QString value;      //for strings, the value of the string, for embeds: the code
        QString typeName;   //if token have TYPE - for VARIABLES, FUNCTIONS and TYPEIDs
        QString tooltip;    //tooltip to display - if there is such
        int format;         //format type for that token, used by the code coloring routine
    };
    struct expression
    {
        tokenlist parts;
    };
    struct consttype
    {
        QString name,type,value;
        bool isValid;
    };
    //needed for vars:
    struct variable
    {
        QString name,type,description,defaultValue;
        bool isStatic;
        bool isValid;
    };
    struct functionArgument
    {
        QString name,type,value,description;
        bool isValid;
    };
    struct function
    {
        QString name,type,description;
        QList<functionArgument> arguments;
        bool isStatic, isValid;
    };
    struct classDef
    {
        //for lookup and issers
        QString name, description, baseClass;
        QStringList variables, functions;
        bool isValid;
    };

    pgsParser();
    ~pgsParser();

    gameproject* project();

    // ISsers for both framework and project data
    // These functions must be AS FAST AS POSSIBLE!!!!
    bool isKeyword(const QString& s);   // UNUSED
    bool isType(const QString& s);
    bool isClass(const QString& s);
    bool isResource(const QString& s);
    bool isConst(const QString& s);
    bool isVar(const QString& s, tokenlist* l = 0, QString* className=0);        //must support CLASS MEMBERS
    bool isFunction(const QString& s, tokenlist* l = 0, QString* className=0);   //must support CLASS MEMBERS
    // in isVar & isFunction className is output variable

    // QStringLists for FAST name lookup: framework and project data's issers
    // These lists are updated by the constructor and reparseProject
    QVector<QString> keywords, types, classes, resources, constants, functions, variables;

    // for fast lookup of classmembers:
    QHash<QString, QVector<QString> > classMemberVars, classMemberFuncs;
    QHash<QString, QVector<variable> > classMemberVarDefs;
    QHash<QString, QVector<function> > classMemberFuncDefs;

    // Nextly, these lists are used to separate the framework data and project data
    QVector<QString>
            frameworkClasses, projectClasses,
            frameworkFunctions, projectFunctions,
            frameworkConstants, projectConstants,
            frameworkGlobalVars, projectGlobalVars  ;

    // Data containers that are filled by the constructor and reparseProject
    QVector<classDef>  framewrokClassDefs, projectClassDefs;
    QVector<function>  frameworkGlobalFunctionDefs, projectGlobalFunctionDefs;
    QVector<variable>  frameworkGlobalVarDefs, projectGlobalVarDefs;
    QVector<consttype> frameworkConstDefs, projectConstDefs;
    QVector<variable>  projectResources;

    // Getters that return actual resource by its name. Issers are fastest, getters can be more slower.
    QString getType(const QString& s); //converts dialect types - procedure to void, integer to int and so on - hardcoded
    classDef getClass(const QString& name);
    variable getResource(const QString& name);
    consttype getConst(const QString& name);
    variable getVar(const QString& name, const QString& className);       //className can be determined by the Isser method
    function getFunction(const QString& name, const QString& className);  //empty className means global scope


    //Even if value is consttype field, there can be dynamic constants, like CLASS, LINE, FUNCTION and so on, so:
    virtual QString getConstValue(QString name, token* t = 0);    //will call getConst, virtual, for target language/latform exporter to implement
    tokenlist tokenize(QString str);


    // The Parse Tree related
    struct parseError
    {
        QString message, className;
        int line, col;
        enum errorType{warning, error, fatal};
    };
    struct parseTreeNode
    {
        // base for all parse tree node types
        QList<parseTreeNode*> nodes;
        int nodeCount();
        parseTreeNode* at(int i);
        parseTreeNode* operator[](int i);
        void append(parseTreeNode* t);
        void clear();
        ~parseTreeNode();
        virtual QString nodeType(); //node type as a string
        virtual QString data();
        QString comment;
        int currentLevel(); //nesting level
    };
    //All the node types:
    enum constantType{integerType, realType, booleanType, stringType};
    struct constantNode: public parseTreeNode
    {
        QString nodeType();
        QString data();
        constantType type;
        union value
        {
            long long integer;
            long double real;
            bool boolean;
        };
        QString string; //only if it is a string
    };
    struct functionCallNode: public parseTreeNode
    {
        QString nodeType();
        QString data();
        QString name,type;

    };
    struct variableDefinitionNode: public parseTreeNode
    {
        QString nodeType();
        QString data();
        QString name, type;  //value only if variable is initialized constantly
        bool isInitialized; // is this variable initialized?

        // Child must only be one: The variable value: either constant OR expression!
        // Allowed child typed: expressionNode
    };
    /*      NO comments for now!
    struct commentNode: public parseTreeNode
    {
        QString nodeType();
        QString data();
        bool blockComment;
    };*/

    struct variableAssignmentNode: public parseTreeNode
    {
        QString nodeType();
        QString data();
    };
    struct ifNode: public parseTreeNode
    {
        QString nodeType();
        QString data();
    };
    struct forNode: public parseTreeNode
    {
        QString nodeType();
        QString data();
    };
    struct statementNode: public parseTreeNode
    {
        QString nodeType();
        QString data();
    };
    struct functionDefinitionNode: public parseTreeNode
    {
        QString nodeType();
        QString data();
        QString name, type;
        QString className();
        /*  Function definition:
          in some class:   type name(arguments) { statements; }
        */
        QList<variableDefinitionNode> arguments;
        // Allowed childs: statementNode
    };
    struct classNode: public parseTreeNode
    {
        QString nodeType();
        QString data();

        // class data:
        QString baseClassName;
        QStringList interfaces; //Will I ever have them? NOT for now!

        // Allowed childs:    variableDefinitionNode, functionDefinitionNode
    };

    // The parse tree itself
    parseTreeNode* rootNode;

    // Parsing functions and state, set by Parse
    QList<parseError> parseErrors;
    tokenlist* tokensToParse;
    int parsePotition;  //position to last successfully expected thing

    //Preprocessor will do its best to filter the passed tokenlist to parse-ready tokenlist
    enum preProcType {ppIfdef, ppIfndef, ppTarget, ppExporter, ppElse, ppEnd, ppInvalid};
    preProcType parsePreProcTerm(QString s);
    tokenlist preProcess(tokenlist* tokens, QString target, QString exporter, QStringList defines);

    void parse(tokenlist* tokens);

    // Expecters that "expects" something

    // The CLASS:
    bool expectClass(); // Each class have MEMBERS:
        bool expectClassMember();
            bool expectVariableDef();   //in its full const-only form?
            bool expectFunctionDef();   //Each function have STATEMENTS
                bool expectStatement();     //What does each statement have?

    void printTree(parseTreeNode* root);

    virtual QString generateCode(parseTreeNode* root, vObject settings = vObject()); //TODO: plan!

    expression parseExpression(tokenlist);
    expression parseExpression(QString);
    int tokenIndexAtPos(tokenlist tl, int pos);
    int tokenIndexAtLC(tokenlist tl, int line, int column);

    QString tokenkindToString(tokenkind t);

    void setProject(gameproject* gp);

    //This function re-parses the project and updates parser's data
    void reparseProject();

    symboltype ST(QChar c);
private:
    gameproject* gp;
    bool deletegp;
};
typedef QList<pgsParser::token> tokenList;

#endif // PGSPARSER_H
