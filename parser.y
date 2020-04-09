%define parse.error verbose

%{
#include <iostream>
#include <map>
#include <vector>

#include "globals.h"
#include "classes.h"

extern int yylex();
void yyerror(const char*);
%}

%union {
    int intVal;
    char chrVal;
    const char* strVal;
    bool boolVal;
    void* nullVal;


    /* Nonterminal types */
    Program* programPtr;
    ConstDecl* constDeclPtr;
    ConstAssign* constAssignPtr;
    std::vector<ConstAssign*>* constAssignListPtr;
    std::vector<Callable*>* callableListPtr;
    Procedure* procPtr;
    Function* funcPtr;
    Param* paramPtr;
    std::vector<Param*>* paramsPtr;
    Body* bodyPtr;
    Block* blockPtr;
    TypeDecl* typeDeclPtr;
    TypeAssign* typeAssignPtr;
    std::vector<TypeAssign*>* typeAssignListPtr;
    Type* typePtr;
    SimpleType* simpleTypePtr;
    RecordType* recordTypePtr;
    ArrayType* arrayTypePtr;
    Ident* idPtr;
    std::vector<Ident*>* idListPtr;
    VarDecl* varDeclPtr;
    VarAssign* varAssignPtr;
    std::vector<VarAssign*>* varAssignListPtr;
    Stmt* stmtPtr;
    std::vector<Stmt*>* stmtListPtr;
    AssnStmt* assnStmtPtr;
    IfStmt* ifStmtPtr;
    std::vector<ElseIfStmt*>* elseIfStmtListPtr;
    ElseIfStmt* elseIfStmtPtr;
    ElseStmt* elseStmtPtr;
    WhileStmt* whileStmtPtr;
    RepeatStmt* repeatStmtPtr;
    ForStmt* forStmtPtr;
    StopStmt* stopStmtPtr;
    ReturnStmt* returnStmtPtr;
    ReadStmt* readStmtPtr;
    LValue* lValPtr;
    std::vector<LValue*>* lValListPtr;
    WriteStmt* writeStmtPtr;
    Expr* exprPtr;
    std::vector<Expr*>* exprListPtr;
    ProcCall* procCallPtr;
    std::vector<Ext*>* extListPtr;
    Ext* extPtr;
    DotExt* dotPtr;
    IndexExt* indexPtr;
    IntConstExpr* intConstPtr;
    ChrConstExpr* chrConstPtr;
    StrConstExpr* strConstPtr;
}

%token ARRAY
%token BEGIN_TKN
%token CHR
%token CONST
%token DO
%token DOWNTO
%token ELSE
%token ELSEIF
%token END
%token FOR
%token FORWARD
%token FUNCTION
%token IF
%token OF
%token ORD
%token PRED
%token PROCEDURE
%token READ
%token RECORD
%token REF
%token REPEAT
%token RETURN
%token STOP
%token SUCC
%token THEN
%token TO
%token TYPE
%token UNTIL
%token VAR
%token WHILE
%token WRITE
%token <idPtr> ID
%token ADD
%token SUB
%token MULT
%token DIV
%token AMP
%token BAR
%token NOT
%token EQ_t
%token NEQ_t
%token LT_t
%token LEQ_t
%token GT_t
%token GEQ_t
%token PERIOD
%token COMMA
%token SEMICOLON
%token COLON
%token L_PAREN
%token R_PAREN
%token L_BRACK
%token R_BRACK
%token ASSIGN
%token MOD
%token <intVal> INT_CONST
%token <chrVal> CHR_CONST
%token <strVal> STR_CONST
%token COMMENT

%type <programPtr> program
%type <constDeclPtr> constDeclOpt
%type <constDeclPtr> constDecl
%type <constAssignListPtr> constAssignPlus
%type <constAssignPtr> constAssign
%type <callableListPtr> procOrFuncStar
%type <procPtr> procDecl
%type <funcPtr> funcDecl
%type <paramsPtr> paramsOpt
%type <paramsPtr> params
%type <paramPtr> param
%type <boolVal> varOrRefOpt
%type <bodyPtr> body
%type <blockPtr> block
%type <typeDeclPtr> typeDeclOpt
%type <typeDeclPtr> typeDecl
%type <typeAssignListPtr> typeAssignPlus
%type <typeAssignPtr> typeAssign
%type <typePtr> type
%type <simpleTypePtr> simpleType
%type <recordTypePtr> recordType
%type <varAssignListPtr> varAssignStar
%type <arrayTypePtr> arrayType
%type <idListPtr> idList
%type <varDeclPtr> varDeclOpt
%type <varDeclPtr> varDecl
%type <varAssignListPtr> varAssignPlus
%type <varAssignPtr> varAssign
%type <stmtListPtr> stmts
%type <stmtPtr> stmt
%type <assnStmtPtr> assnStmt
%type <ifStmtPtr> ifStmt
%type <elseIfStmtListPtr> elseIfStmtsOpt
%type <elseIfStmtListPtr> elseIfStmts
%type <elseIfStmtPtr> elseIfStmt
%type <elseStmtPtr> elseStmtOpt
%type <whileStmtPtr> whileStmt
%type <repeatStmtPtr> repeatStmt
%type <forStmtPtr> forStmt
%type <stopStmtPtr> stopStmt
%type <returnStmtPtr> returnStmt
%type <readStmtPtr> readStmt
%type <lValListPtr> lValPlus
%type <writeStmtPtr> writeStmt
%type <exprListPtr> exprPlus
%type <procCallPtr> procCall
%type <exprListPtr> exprPlusOpt
%type <stmtPtr> nullStmt
%type <exprPtr> expr
%type <lValPtr> lVal
%type <extListPtr> dotOrIndexPlusOpt
%type <extListPtr> dotOrIndexPlus
%type <extPtr> dotOrIndex
%type <extPtr> dot
%type <extPtr> index


%left BAR
%left AMP
%right NOT
%nonassoc EQ_t NEQ_t LT_t LEQ_t GT_t GEQ_t
%left ADD SUB
%left MULT DIV MOD
%right UNARYMINUS

%%
/* CPSL Declarations */
//program: constDeclOpt typeDeclOpt varDeclOpt procOrFuncStar block PERIOD {$$ = new Program($1, $2, $3, $4, $5); std::cout<<std::endl; $$->emitMips(); YYACCEPT;}
program: constDeclOpt typeDeclOpt varDeclOpt procOrFuncStar block PERIOD {$$ = new Program($1, $2, $3, $4, $5); std::cout << std::endl << $$->toString() << std::endl; YYACCEPT;}

/* 3.1.1 Constant Rules */
constDeclOpt: constDecl {$$ = $1;}
             | {$$ = nullptr;}
             ;

constDecl: CONST constAssignPlus {$$ = new ConstDecl($2);}
         ;

constAssignPlus: constAssignPlus constAssign {$$ = $1; $$->push_back($2);}
               | constAssign {$$ = new std::vector<ConstAssign*>(); $$->push_back($1);}
               ;

constAssign: ID EQ_t expr SEMICOLON {$$ = new ConstAssign($1, $3);}
           ;

/* 3.1.2 Procedure and Function Rules */
procOrFuncStar: procOrFuncStar procDecl {$$ = $1; $$->push_back($2);}
              | procOrFuncStar funcDecl {$$ = $1; $$->push_back($2);}
              | {$$ = new std::vector<Callable*>();}
              ;

procDecl: PROCEDURE ID L_PAREN paramsOpt R_PAREN SEMICOLON FORWARD SEMICOLON {$$ = new Procedure($2, $4);}
        | PROCEDURE ID L_PAREN paramsOpt R_PAREN SEMICOLON body SEMICOLON {$$ = new Procedure($2, $4, $7);}

funcDecl: FUNCTION ID L_PAREN paramsOpt R_PAREN COLON type SEMICOLON FORWARD SEMICOLON {$$ = new Function($2, $4, $7);}
        | FUNCTION ID L_PAREN paramsOpt R_PAREN COLON type SEMICOLON body SEMICOLON {$$ = new Function($2, $4, $7, $9);}
        ;

paramsOpt: params {$$ = $1;}
         | {$$ = nullptr;}
         ;

params: params SEMICOLON param {$$ = $1; $$->push_back($3);}
      | param {$$ = new std::vector<Param*>(); $$->push_back($1);}
      ;

param: varOrRefOpt idList COLON type {$$ = new Param($1, $2, $4);}
     ;

varOrRefOpt: VAR {$$ = true;}
           | REF {$$ = false;}
           | {$$ = true;}
           ;

body: constDeclOpt typeDeclOpt varDeclOpt block {$$ = new Body($1, $2, $3, $4);}
    ;

block: BEGIN_TKN stmts END {$$ = new Block($2);}
     ;

/* 3.1.3 Type Rules */
typeDeclOpt: typeDecl {$$ = $1;}
            | {$$ = nullptr;}
            ;

typeDecl: TYPE typeAssignPlus {$$ = new TypeDecl($2);}
        ;

typeAssignPlus: typeAssignPlus typeAssign {$$ = $1; $$->push_back($2);}
              | typeAssign {$$ = new std::vector<TypeAssign*>(); $$->push_back($1);}
              ;

typeAssign: ID EQ_t type SEMICOLON {$$ = new TypeAssign($1, $3);}
          ;

type: simpleType {$$ = $1;}
    | recordType {$$ = $1;}
    | arrayType {$$ = $1;}
    ;

simpleType: ID {$$ = new SimpleType($1);}
          ;

recordType: RECORD varAssignStar END {$$ = new RecordType($2);}
          ;

varAssignStar: varAssignStar varAssign {$$->push_back($2);}
             | {$$ = new std::vector<VarAssign*>();}
             ;

arrayType: ARRAY L_BRACK expr COLON expr R_BRACK OF type {$$ = new ArrayType($3, $5, $8);}
         ;

idList: idList COMMA ID {$1->push_back($3); $$ = $1;}
      | ID {$$ = new std::vector<Ident*>(); $$->push_back($1);}
      ;

/* 3.1.4 Variable Rules */
varDeclOpt: varDecl {$$ = $1;}
           | {$$ = nullptr;}
           ;

varDecl: VAR varAssignPlus {$$ = new VarDecl($2);}
       ;

varAssignPlus: varAssignPlus varAssign {$1->push_back($2); $$ = $1;}
             | varAssign {$$ = new std::vector<VarAssign*>(); $$->push_back($1);}
             ;

varAssign: idList COLON type SEMICOLON {$$ = new VarAssign($1, $3);}
         ;

/* 3.2 CPSL Statements */
stmts: stmts SEMICOLON stmt {if ($3 != nullptr) {$1->push_back($3);} $$ = $1;}
     | stmt {$$ = new std::vector<Stmt*>(); $$->push_back($1);}
     ;

stmt: assnStmt {$$ = $1;}
    | ifStmt {$$ = $1;}
    | whileStmt {$$ = $1;}
    | repeatStmt {$$ = $1;}
    | forStmt {$$ = $1;}
    | stopStmt {$$ = $1;}
    | returnStmt {$$ = $1;}
    | readStmt {$$ = $1;}
    | writeStmt {$$ = $1;}
    | procCall {$$ = $1;}
    | nullStmt {$$ = $1;}
    ;

assnStmt: lVal ASSIGN expr {$$ = new AssnStmt($1, $3);}
        ;

ifStmt: IF expr THEN stmts elseIfStmtsOpt elseStmtOpt END {$$ = new IfStmt($2, $4, $5, $6);}
      ;

elseIfStmtsOpt: elseIfStmts {$$ = $1;}
              | {$$ = nullptr;}
              ;

elseIfStmts: elseIfStmts elseIfStmt {$1->push_back($2); $$ = $1;}
           | elseIfStmt {$$ = new std::vector<ElseIfStmt*>(); $$->push_back($1);}
           ;

elseIfStmt: ELSEIF expr THEN stmts {$$ = new ElseIfStmt($2, $4);}
          ;

elseStmtOpt: ELSE stmts {$$ = new ElseStmt($2);}
           | {$$ = nullptr;}
           ;

whileStmt: WHILE expr DO stmts END {$$ = new WhileStmt($2, $4);}
         ;

repeatStmt: REPEAT stmts UNTIL expr {$$ = new RepeatStmt($2, $4);}
          ;

forStmt: FOR ID ASSIGN expr TO expr DO stmts END {$$ = new ForStmt($2, $4, "to", $6, $8);}
       | FOR ID ASSIGN expr DOWNTO expr DO stmts END {$$ = new ForStmt($2, $4, "downto", $6, $8);}
       ;

stopStmt: STOP {$$ = new StopStmt();}
        ;

returnStmt: RETURN expr {$$ = new ReturnStmt($2);}
          | RETURN {$$ = new ReturnStmt(nullptr);}
          ;

readStmt: READ L_PAREN lValPlus R_PAREN {$$ = new ReadStmt($3);}
        ;

lValPlus: lValPlus COMMA lVal {$1->push_back($3); $$ = $1;}
        | lVal {$$ = new std::vector<LValue*>(); $$->push_back($1);}
        ;

writeStmt: WRITE L_PAREN exprPlus R_PAREN {$$ = new WriteStmt($3);}
         ;

exprPlus: exprPlus COMMA expr {$1->push_back($3); $$ = $1;}
        | expr {$$ = new std::vector<Expr*>(); $$->push_back($1);}
        ;

procCall: ID L_PAREN exprPlusOpt R_PAREN {$$ = new ProcCall($1, $3);}
        ;

exprPlusOpt: exprPlus {$$ = $1;}
           | {$$ = nullptr;}
           ;

nullStmt: {$$ = new NullStmt();}
        ;

/* 3.3 Expressions */
expr: expr BAR expr {$$ = BoolBinOpExpr::binOp<Bar>($1, $3);}
    | expr AMP expr {$$ = BoolBinOpExpr::binOp<Amp>($1, $3);}
    | expr EQ_t expr {$$ = CmprBinOpExpr::binOp<Eq>($1, $3);}
    | expr NEQ_t expr {$$ = CmprBinOpExpr::binOp<Neq>($1, $3);}
    | expr LEQ_t expr {$$ = CmprBinOpExpr::binOp<Leq>($1, $3);}
    | expr GEQ_t expr {$$ = CmprBinOpExpr::binOp<Geq>($1, $3);}
    | expr LT_t expr {$$ = CmprBinOpExpr::binOp<Lt>($1, $3);}
    | expr GT_t expr {$$ = CmprBinOpExpr::binOp<Gt>($1, $3);}
    | expr ADD expr {$$ = ArithBinOpExpr::binOp<Add>($1, $3);}
    | expr SUB expr {$$ = ArithBinOpExpr::binOp<Sub>($1, $3);}
    | expr MULT expr {$$ = ArithBinOpExpr::binOp<Mult>($1, $3);}
    | expr DIV expr {$$ = ArithBinOpExpr::binOp<Div>($1, $3);}
    | expr MOD expr {$$ = ArithBinOpExpr::binOp<Mod>($1, $3);}
    | NOT expr {$$ = Not::op($2);}
    | SUB expr %prec UNARYMINUS {$$ = UnaryMinus::op($2);}
    | L_PAREN expr R_PAREN {$$ = $2;}
    | CHR L_PAREN expr R_PAREN {$$ = ChrFunc::op($3);}
    | ORD L_PAREN expr R_PAREN {$$ = OrdFunc::op($3);}
    | PRED L_PAREN expr R_PAREN {$$ = PredFunc::op($3);}
    | SUCC L_PAREN expr R_PAREN {$$ = SuccFunc::op($3);}
    | lVal {$$ = $1;}
    | INT_CONST {$$ = new IntConstExpr($1);}
    | CHR_CONST {$$ = new ChrConstExpr($1);}
    | STR_CONST {$$ = new StrConstExpr($1);}
    ;

lVal: ID dotOrIndexPlusOpt {$$ = new LValue($1, $2);}
    ;

dotOrIndexPlusOpt: dotOrIndexPlus {$$ = $1;}
                 | {$$ = nullptr;}
                 ;

dotOrIndexPlus: dotOrIndexPlus dotOrIndex {$1->push_back($2); $$ = $1;}
              | dotOrIndex {$$ = new std::vector<Ext*>(); $$->push_back($1);}
              ;

dotOrIndex: dot {$$ = $1;}
          | index {$$ = $1;}
          ;

dot: PERIOD ID {$$ = new DotExt($2);}
   ;

index: L_BRACK expr R_BRACK {$$ = new IndexExt($2);}
     ;
%%

void yyerror(const char* err) {
    std::cerr << err << std::endl;
    std::cerr << "line " << line << " token " << token << std::endl;
}