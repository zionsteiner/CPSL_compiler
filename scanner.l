%{
#include <cstdlib>
#include <iostream>
#include "includes.h"
#include "parser.hpp"
#include "globals.h"

%}

%option noyywrap

%%

ARRAY|array { token++; return ARRAY ;}
BEGIN|begin { token++; return BEGIN_TKN ;}
CHR|chr { token++; return CHR ;}
CONST|const { token++; return CONST ;}
DO|do { token++; return DO ;}
DOWNTO|downto { token++; return DOWNTO ;}
ELSE|else { token++; return ELSE ;}
ELSEIF|elseif { token++; return ELSEIF ;}
END|end { token++; return END ;}
FOR|for { token++; return FOR ;}
FORWARD|forward { token++; return FORWARD ;}
FUNCTION|function { token++; return FUNCTION ;}
IF|if { token++; return IF ;}
OF|of { token++; return OF ;}
ORD|ord { token++; return ORD ;}
PRED|pred { token++; return PRED ;}
PROCEDURE|procedure { token++; return PROCEDURE ;}
READ|read { token++; return READ ;}
RECORD|record { token++; return RECORD ;}
REF|ref { token++; return REF ;}
REPEAT|repeat { token++; return REPEAT ;}
RETURN|return { token++; return RETURN ;}
STOP|stop { token++; return STOP ;}
SUCC|succ { token++; return SUCC ;}
THEN|then { token++; return THEN ;}
TO|to { token++; return TO ;}
TYPE|type { token++; return TYPE ;}
UNTIL|until { token++; return UNTIL ;}
VAR|var { token++; return VAR ;}
WHILE|while { token++; return WHILE ;}
WRITE|write { token++; return WRITE ;}

[a-zA-Z]{1}[a-zA-Z0-9_]* { token++; yylval.idPtr = new Ident(yytext); return ID; }
"+" { token++; return ADD ;}
"-" { token++; return SUB ;}
"*" { token++; return MULT ;}
"/" { token++; return DIV ;}
"&" { token++; return AMP ;}
"|" { token++; return BAR ;}
"~" { token++; return NOT ;}
"=" { token++; return EQ_t ;}
"<>" { token++; return NEQ_t ;}
"<" { token++; return LT_t ;}
"<=" { token++; return LEQ_t ;}
">" { token++; return GT_t ;}
">=" { token++; return GEQ_t ;}
"." { token++; return PERIOD ;}
"," { token++; return COMMA ;}
";" { token++; return SEMICOLON ;}
":" { token++; return COLON ;}
"(" { token++; return L_PAREN ;}
")" { token++; return R_PAREN ;}
"[" { token++; return L_BRACK ;}
"]" { token++; return R_BRACK ;}
":=" { token++; return ASSIGN ;}
"%" { token++; return MOD ;}

\num { token++; yylval.intVal = atoi(yytext); return INT_CONST; }
\xnum { token++; yylval.intVal = atoi(yytext); return INT_CONST; }
[1-9]{1}[0-9]* { token++; yylval.intVal = atoi(yytext); return INT_CONST; }
0 { token++; yylval.intVal = atoi(yytext); return INT_CONST; }

\'\\n\' { token++; yylval.chrVal = yytext[0]; return CHR_CONST; }
\'\\r\' { token++; yylval.chrVal = yytext[0]; return CHR_CONST; }
\'\\' { token++; yylval.chrVal = yytext[0]; return CHR_CONST; }
\'\\t\' { token++; yylval.chrVal = yytext[0]; return CHR_CONST; }
\'\\f\' { token++; yylval.chrVal = yytext[0]; return CHR_CONST; }
\'[ -~]{1}\' { token++; yylval.chrVal = yytext[0]; return CHR_CONST; }
\"[ -~]*\" { token++; yylval.strVal = strdup(yytext); return STR_CONST; }
\$.*\n { token++; return COMMENT; }
\n {line++; token = 1;}

%%