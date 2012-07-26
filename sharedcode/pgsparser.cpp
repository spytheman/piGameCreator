#include "pgsparser.h"
#include "globals.h"
#include "../baseide/gcide.h"

pgsParser::pgsParser()
{
    //possible memory leak in here
    gp = new gameproject;
    deletegp = true;

    gcprint("INITIALIZING pgsParser INSTANCE!!");
    //initialize Framework structures:
    //initialize structures: on SetProject
}
pgsParser::~pgsParser()
{
    if(deletegp)delete gp;
    gcprint("DELETING pgsParser !!!");
}

// THESE APIs must get REALLY implemented!

bool pgsParser::isType(const QString& s)
{
    return types.contains(s);
}
QString pgsParser::getType(const QString& s)
{
    if(s=="procedure")return "void";
    if(s=="integer")return "int";
    if(s=="boolean")return "bool";
    return s;
}
inline bool pgsParser::isFunction(const QString& s, tokenlist* tl, QString* className)
{
    return functions.contains(s);
}
inline bool pgsParser::isClass(const QString& s)
{
    return classes.contains(s);
}
inline bool pgsParser::isResource(const QString& s)
{
    return resources.contains(s);
}
inline bool pgsParser::isConst(const QString& s)
{
    return constants.contains(s);
}
pgsParser::consttype pgsParser::getConst(const QString& name)
{
    //too much work! Must be pre-initialized!
    QList<pgsParser::consttype> types;
    pgsParser::consttype t;
    t.isValid = true;

    // Boolean
    t.type = "bool";

    t.name = "true";
    t.value = "1";
    types << t;
    t.name = "false";
    t.value = "0";
    types << t;

    // Real
    t.type = "real";

    t.name = "pi";
    t.value = "3.141592653589";
    types << t;

    t.value = "0";

    //dynamic constants / unfixed
    t.name = "VERSION";
    types << t;

    // Strings
    t.type = "string";
    t.value = "\"\"";   //empty string

    t.name = "PLATFORM";
    types << t;
    t.name = "EXPORTER";
    types << t;

    t.name = "CLASS";   //current class name
    types << t;
    t.name = "FILE";    //current file name [most likely not applicable]
    types << t;
    t.name = "FUNCTION";    //current function name
    types << t;

    //integer
    t.type = "int";
    t.name = "LINE";    //current line number
    t.value = "0";
    types << t;


    //now check the passed name
    foreach(consttype ct,types)
        if(ct.name==name)
            return ct;

    //and fail
    consttype bad;
    bad.name = "INVALID";
    bad.type = "invalid";
    bad.isValid = false;
    return bad;
}
QString pgsParser::getConstValue(QString name, pgsParser::token* t)
{
    //default implementation
    consttype tk = getConst(name);
    if(tk.isValid)
    {
        //if token is passed
        if(t)
        {
            //let's do the magic constants.
            if(tk.name=="LINE")return QString::number(t->line);
        }
        return tk.value;
    }
    else return "";
}

bool pgsParser::isVar(const QString& s, tokenlist* tl, QString* className)
{
    return variables.contains(s);
}

pgsParser::symboltype pgsParser::ST(QChar c)
{
    if(c>='a' && c<='z')return letter;
    else if(c>='A' && c<='Z')return letter;
    else if(c=='_')return letter;
    else if(c>='0' && c<='9')return digit;
    else if(c==' ' or c==9)return whitespace;
    else if(c=='\n')return newline;
    else if(c=='.' or c==',' or c=='+' or c=='-' or c=='/' or c=='*' or c=='=' or c=='^' or c==';' or c==':'
            or c=='[' or c==']' or c=='(' or c==')' or c=='{' or c=='}'
            or c=='<' or c=='>' or c=='"' or c=='\'' )return symbol;
    else return unknown;
}

//Resets the FSM:
#define RS() {RSd=true;s=0;l.push_back(t);t.begin=i+1;t.length=0;t.kind=junk;t.format=CFnormaltext;t.text="";t.typeName="";i--;}
//Begins new token
#define BG() {t.begin=i;t.line=line;t.col=col;}
//Adds to the text:
#define TT() {t.text+=c;t.length++;}

pgsParser::tokenlist pgsParser::tokenize(QString str)
{
    str.append("\n");
    tokenlist l;
    token t;
    int blocklevel = 0;
    t.blocklevel=0;
    t.kind=junk;
    t.begin=0;
    t.line=1;
    t.col=1;
    int line=1, col=1;
    t.length=0;
    bool RSd=false;
    short s = 0; //the state
    for(int i=0;i<str.length();i++)
    {
        RSd=false;
        QChar c = str.at(i);

        //Tokenize() FSM as drawn in The FSM.jpg
        switch(s)
        {
        case 0: //Free/begin state
            if(ST(c)==letter){BG() t.format=CFnormaltext; t.kind=nameId;TT()s=1;} //nameId
            else if(ST(c)==digit){BG() s=2;t.kind=IntVal;t.typeName="int";t.format=CFnumber; TT()}
            //the symbols
            else if(c=='+'){BG() s=4;t.kind=arithmeticOp;t.format=CFoperator; TT()}
            else if(c=='-'){BG() s=7;t.kind=arithmeticOp;t.format=CFoperator;TT()}
            else if(c=='*'){BG() s=10;t.kind=arithmeticOp;t.format=CFoperator;TT()}
            else if(c=='/'){BG() s=12;t.kind=arithmeticOp;t.format=CFoperator;TT()}
            else if(c=='='){BG() s=14;t.kind=equalOp;t.format=CFoperator;TT()}
            else if(c==':'){BG() s=16;t.kind=assignOp;t.format=CFoperator;TT()} //assignOp is : from :=, assignmentOp is :=
            else if(c=='^'){BG() s=18;t.kind=arithmeticOp;t.format=CFoperator;TT()}
            else if(c=='.'){BG() s=19;t.kind=memberOp;t.format=CFoperator;TT()}
            else if(c=='('){BG() s=20;t.kind=bracketS;t.format=CFoperator;TT()}
            else if(c==')'){BG() s=21;t.kind=bracketE;t.format=CFoperator;TT()}
            else if(c==','){BG() s=22;t.kind=comma;t.format=CFoperator;TT()}
            else if(c=='"'){BG() s=23;t.kind=StringVal;t.typeName="string";t.format=CFstring;TT()}
            else if(c=='\''){BG() s=25;t.kind=StringVal;t.typeName="string";t.format=CFstring;TT()}
            else if(c==';'){BG() s=30;t.kind=semicolon;t.format=CFoperator;TT()}
            else if(c=='{'){BG() s=31;t.blocklevel++;t.format=CFoperator;t.kind=blockbegin;TT()}
            else if(c=='}'){BG() s=32;t.blocklevel--;t.format=CFoperator;t.kind=blockend;TT()}
            else if(c=='['){BG() s=33;t.kind=arrayS;t.format=CFoperator;TT()}
            else if(c==']'){BG() s=34;t.kind=arrayE;t.format=CFoperator;TT()}
            else if(c=='>'){BG() s=35;t.kind=comparisonOp;t.format=CFoperator;TT()}
            else if(c=='<'){BG() s=37;t.kind=comparisonOp;t.format=CFoperator;TT()}
            else if(c=='#'){BG() s=41;t.kind=preproc;t.format=CFpreproc;TT()}
            //add here
            break;
        case 1: //nameIDs
            if(ST(c)==letter or ST(c)==digit)TT()
            else    //recognise that named identifier and complete the token
            {

                //is it a keyword and which?
                QString ls = t.text.toLower();
                if(ls=="if"){t.kind=IFkw;t.format=CFkeyword;}
                else if(ls=="else"){t.kind=ELSEkw;t.format=CFkeyword;}
                else if(ls=="for"){t.kind=FORkw;t.format=CFkeyword;}
                else if(ls=="do"){t.kind=DOkw;t.format=CFkeyword;}
                else if(ls=="while"){t.kind=WHILEkw;t.format=CFkeyword;}
                else if(ls=="until"){t.kind=UNTILkw;t.format=CFkeyword;}
                else if(ls=="repeat"){t.kind=REPEATkw;t.format=CFkeyword;}
                else if(ls=="new"){t.kind=NEWkw;t.format=CFkeyword;}
                else if(ls=="delete"){t.kind=DELETEkw;t.format=CFkeyword;}
                else if(ls=="class"){t.kind=CLASSkw;t.format=CFkeyword;}
                else if(ls=="extends"){t.kind=EXTENDSkw;t.format=CFkeyword;}
                else if(ls=="implements"){t.kind=IMPLEMENTSkw;t.format=CFkeyword;}
                else if(ls=="static"){t.kind=STATICkw;t.format=CFkeyword;}
                else if(ls=="switch"){t.kind=SWITCHkw;t.format=CFkeyword;}
                else if(ls=="case"){t.kind=CASEkw;t.format=CFkeyword;}
                else if(ls=="default"){t.kind=DEFAULTkw;t.format=CFkeyword;}
                else if(ls=="break"){t.kind=BREAKkw;t.format=CFkeyword;}
                else if(ls=="continue"){t.kind=CONTINUEkw;t.format=CFkeyword;}

                //keywords okay
                else if(isType(t.text)){t.kind=typeId;t.typeName=getType(t.text);t.format=CFclass;}
                else if(isConst(t.text))
                {
                    t.kind=constId;
                    t.format=CFresource;
                    t.typeName=getConst(t.text).type;
                }
                else if(isClass(t.text))
                {
                    t.kind=classId;t.typeName=t.text;t.format=CFclass;
                }
                else if(isFunction(t.text, &l))
                {
                    //it must check against class member!
                    //check the function return type and set the proper typeName
                    t.kind=FuncId;
                    t.typeName="int";
                    t.format=CFfunction;
                }
                else if(isResource(t.text)){t.kind=typeId;t.format=CFresource;} //that one later
                else if(isVar(t.text))
                {
                    //must check for var type as well
                    t.kind=varId;
                    t.typeName="int";
                    t.format=CFvariable;
                }
                RS()
                //why here???
            }
            break;
        case 2:
            if(c=='.'){s=3;TT()}
            else if(ST(c)==digit)TT()
            else RS();
            break;
        case 3:
            if(ST(c)==digit){t.kind=RealVal;t.typeName="real";TT()} else RS();
            break;
        case 4:
            if(c=='+'){s=5;t.kind=incDecOp;TT()}
            else if(c=='='){s=6;t.kind=assignmentOp;TT()}
            else RS()
            break;
        case 5:case 6: RS()break;
        case 7:
            if(c=='-'){s=8;t.kind=incDecOp;TT()}
            else if(c=='='){s=9;t.kind=assignmentOp;TT()}
            else RS()
            break;
        case 8: case 9: RS() break;
        case 10:
            if(c=='='){s=11;t.kind=assignmentOp;TT()}
            else RS()
            break;
        case 11: RS(); break;
        case 12:
            if(c=='='){s=13;t.kind=assignmentOp;TT()}
            else if(c=='/'){s=27;t.kind=comment;t.format=CFcomment;TT()}
            else if(c=='*'){s=28;t.kind=incompleteComment;t.format=CFcomment;TT()}
            else RS()
            break;
        case 13: RS() break;
        case 14:
            if(c=='='){s=15;t.kind=comparisonOp;TT()}
            else RS()
            break;
        case 15: RS() break;
        case 16:
            if(c=='='){s=17;t.kind=assignmentOp;TT()}
            else RS()
            break;
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22: RS() break;
        case 23: //string
            if(c=='"'){TT() s=5;}//end string
            else if(ST(c)==newline){t.kind=PartStringVal; RS()}
            else if(c=='\\'){TT() s=24;}
            else TT()
            break;
        case 24: TT() if(c!='\\'){s=23;}
            break;
        case 25:
            if(c=='\''){TT() s=5;}//end string
            else if(ST(c)==newline){t.kind=PartStringVal; RS()}
            else if(c=='\\'){TT() s=26;}
            else TT()
            break;
        case 26: TT() if(c!='\\'){s=25;}
            break;
        case 27:
            if(c=='\n')RS()else TT();
            break;
        case 28:
            if(c=='*'){s=29;TT()}else TT();
            break;
        case 29:
            if(c=='/'){t.kind=comment;s=5;TT()}
            else if(c=='*')TT()
            else {s=28;TT()}
            break;
        case 30:
        case 31:
        case 32:
        case 33:
        case 34: RS() break;
        case 35:
            if(c=='='){TT() s=36; t.kind=comparisonOp;}
            else RS()
            break;
        case 36: RS()
            break;
        case 37:
            if(c=='='){TT() s=38; t.kind=comparisonOp;}
            else if(c=='<'){TT() s=39; t.kind=appendOp;}
            else if(c=='['){TT() s=40; t.kind=embed;t.format=CFpreproc;}
            else RS()
            break;
        case 38:
        case 39:RS()break;
        case 40:
            {
                //todo
                int btend = str.indexOf("]>",i);
                if(btend!=-1)
                {
                    //begin tag's end   ]> is found
                    int endtag = str.indexOf("<[END]>",btend,Qt::CaseInsensitive);
                    if(endtag!=-1)
                    {
                        //there is a end tag
                        t.text+= str.mid(i, endtag-i+7);
                        t.length=t.text.length();
                        i = endtag+7;
                        RS()
                    }
                    else
                    {
                        //there is not!
                        //accept all to the end
                        t.text += str.mid(i,str.length());
                        t.length=t.text.length();
                        i=str.length();
                        RS()
                    }
                }
                else
                {
                    //there is not
                    //Accept all to the end of input
                    t.text += str.mid(i,str.length());
                    t.length=t.text.length();
                    i=str.length();
                    RS()
                }
            }
            break;
        case 41:
            if(c=='\n')RS()
                else TT()
            break;
            /**/
        default:

            break;
        }

        if(!RSd)
        {
            //int tabwidth=4; //load from the CFG
            if(c==9)col+=3; //tabwidth-1
            if(c=='\n'){line++;col=1;} else col++;
        }
    }
    blocklevel = t.blocklevel;
    if(t.text!="")l.push_back(t);
    return l;
}
#undef RS
#undef BG
#undef TT

QString pgsParser::tokenkindToString(tokenkind t)
{
    if(t==nameId)return "nameId";		// if not defined
    if(t==varId)return "varId";                 // if defined
    if(t==constId)return "constId";
    if(t==assignmentOp)return "assignmentOp";	// += *= -= /=
    if(t==incDecOp)return "incDecOp";           // ++ --
    if(t==comparisonOp)return "comparisonOp";	// ==
    if(t==equalOp)return "equalOp";             // =
    if(t==assignOp)return "assignOp";           // := set
    if(t==arithmeticOp)return "arithmeticOp";	// + - * / ^
    if(t==memberOp)return "memberOp";           // .
    if(t==bracketS)return "bracketS";           // ( expr or func
    if(t==bracketE)return "bracketE";           // )
    if(t==comma)return "comma";

    if(t==FuncId)return "FuncId";
    if(t==IntVal)return "IntVal";
    if(t==RealVal)return "RealVal";
    if(t==StringVal)return "StringVal";
    if(t==PartStringVal)return "PartStringVal";

    if(t==typeId)return "typeId";		//int string
    if(t==classId)return "classId";
    if(t==NEWkw)return "NEWkw";
    if(t==DELETEkw)return "DELETEkw";
    if(t==FORkw)return "FORkw";
    if(t==IFkw)return "IFkw";
    if(t==ELSEkw)return "ELSEkw";
    if(t==DOkw)return "DOkw";
    if(t==UNTILkw)return "UNTILkw";
    if(t==WHILEkw)return "WHILEkw";
    if(t==STATICkw)return "STATICkw";
    if(t==REPEATkw)return "REPEATkw";   

    if(t==CLASSkw)return "CLASSkw";
    if(t==EXTENDSkw)return "EXTENDSkw";
    if(t==IMPLEMENTSkw)return "IMPLEMENTSkw";

    if(t==SWITCHkw)return "SWITCHkw";
    if(t==CASEkw)return "CASEkw";
    if(t==DEFAULTkw)return "DEFAULTkw";
    if(t==BREAKkw)return "BREAKkw";
    if(t==CONTINUEkw)return "CONTINUEkw";

    if(t==semicolon)return "semicolon";         // stmtend for
    if(t==blockbegin)return "blockbegin";	// {
    if(t==blockend)return "blockend";           // }
    if(t==arrayS)return "arrayS";		// [
    if(t==arrayE)return "arrayE";		// ]
    if(t==appendOp)return "appendOp";           // << array append
    if(t==embed)return "embed";                 // <[*]> ... <[END]>
    if(t==comment)return "comment";             // /* ... */
    if(t==incompleteComment)return "incompleteComment";             // /* ... */
    if(t==preproc)return "preproc";
    if(t==junk)return "junk";
}

void pgsParser::setProject(gameproject *p)
{
    gp = p;
    deletegp = false;
}
gameproject* pgsParser::project()
{
    return gp;
}

pgsParser::expression pgsParser::parseExpression(tokenlist l)
{
    //Classic old Shunting Yard With Priority And Functions goes here
    //but for now, only
    expression e;
    e.parts=l;
    return e;
}

pgsParser::expression pgsParser::parseExpression(QString s)
{
    return parseExpression(tokenize(s));
}

int pgsParser::tokenIndexAtPos(tokenlist tl, int pos)
{
    int i=0;
    foreach(token t,tl){ if(t.begin>=pos) return i; i++;}
    return -1;
}

int pgsParser::tokenIndexAtLC(tokenlist tl, int line, int column)
{
    int i=0;
    foreach(token t,tl){ if(t.line>=line && t.col>=column) return i; i++;}
    return -1;
}

QString pgsParser::generateCode(parseTreeNode* root, vObject settings)
{
    //TODO: Possible codeGenerator class that uses pgsParser
    gcerror("Cannot generate GameScript code! This function must be overloaded by pgsParser's derivates");
    return "";
}


//Parse Tree  Node structure implementations

int pgsParser::parseTreeNode::nodeCount(){return nodes.count();}
pgsParser::parseTreeNode* pgsParser::parseTreeNode::at(int i){ return nodes.at(i);}
pgsParser::parseTreeNode* pgsParser::parseTreeNode::operator[](int i){ return nodes.at(i);}
void pgsParser::parseTreeNode::append(parseTreeNode *t){nodes.append(t);}

void pgsParser::parseTreeNode::clear()
{
    //must delete NODES
    qDeleteAll(nodes);
    nodes.clear();
}

pgsParser::parseTreeNode::~parseTreeNode()
{
    // Must delete ALL nodes:
    gcmessage("Deleting "+nodeType());
    qDeleteAll(nodes);
    nodes.clear();
}


void pgsParser::printTree(parseTreeNode *root)
{

}

QString pgsParser::parseTreeNode::nodeType(){return "INVALID";}
QString pgsParser::parseTreeNode::data(){return "INVALID";}

// Parse tree nodes
#define NTYPE(node, type) QString pgsParser::node::nodeType() {return type;}
#define NDATA(node) QString pgsParser::node::data()

NTYPE(constantNode,"const")
NTYPE(functionCallNode,"fcall")
NTYPE(variableDefinitionNode,"vardef")
NTYPE(variableAssignmentNode,"varassign")
NTYPE(ifNode,"if")
NTYPE(forNode,"for")
NTYPE(statementNode,"statement")
NTYPE(functionDefinitionNode,"funcdef")
NTYPE(classNode,"class")
NTYPE(commentNode,"comment")

//TODO: Real implementation for these DATAs
NDATA(constantNode){return "";}
NDATA(functionCallNode){return "";}
NDATA(variableDefinitionNode){return "";}
NDATA(variableAssignmentNode){return "";}
NDATA(ifNode){return "";}
NDATA(forNode){return "";}
NDATA(statementNode){return "";}
NDATA(functionDefinitionNode){return "";}
NDATA(classNode){return "";}
NDATA(commentNode){return "";}

#undef NTYPE
#undef NDATA

// Expecters:
bool pgsParser::expectClass()
{
    //expect it
}

// PARSE!
void pgsParser::parse(tokenlist *tokenlist)
{
    //parse MUST return on error!

    //prepare to parse
    tokensToParse = tokenlist;
    parsePotition = 0;
    parseErrors.clear();

    //let's begin: We just need a class ;]
    expectClass();
}






























