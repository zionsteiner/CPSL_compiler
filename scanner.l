%{
#include <cstdlib>

#include "parser.hpp"
%}

%option noyywrap

%%
ARRAY|array { return ARRAY ;}
BEGIN|begin { return BEGIN ;}
CHR|chr { return CHR ;}
CONST|const { return CONST ;}
DO|do { return DO ;}
DOWNTO|downto { return DOWNTO ;}
ELSE|else { return ELSE ;}
ELSEIF|elseif { return ELSEIF ;}
END|end { return END ;}
FOR|for { return FOR ;}
FORWARD|forward { return FORWARD ;}
FUNCTION|function { return FUNCTION ;}
IF|if { return IF ;}
OF|of { return OF ;}
ORD|ord { return ORD ;}
PRED|pred { return PRED ;}
PROCEDURE|procedure { return PROCEDURE ;}
READ|read { return READ ;}
RECORD|record { return RECORD ;}
REF|ref { return REF ;}
REPEAT|repeat { return REPEAT ;}
RETURN|return { return RETURN ;}
STOP|stop { return STOP ;}
SUCC|succ { return SUCC ;}
THEN|then { return THEN ;}
TO|to { return TO ;}
TYPE|type { return TYPE ;}
UNTIL|until { return UNTIL ;}
VAR|var { return VAR ;}
WHILE|while { return WHILE ;}
WRITE|write { return WRITE ;}

[a-zA-Z]{1}[\w]* { yylval.id = strdup(yytext); return ID; }
"+" { return ADD ;}
"-" { return SUB ;}
"*" { return MULT ;}
"/" { return DIV ;}
"&" { return AMP ;}
"|" { return PIPE ;}
"~" { return NOT ;}
"=" { return EQ ;}
"<>" { return NEQ ;}
"<" { return LT ;}
"<=" { return LEQ ;}
">" { return GT ;}
">=" { return GEQ ;}
"." { return PERIOD ;}
"," { return COMMA ;}
";" { return SEMICOLON ;}
":" { return COLON ;}
"(" { return L_PAREN ;}
")" { return R_PAREN ;}
"[" { return L_BRACK ;}
"]" { return R_BRACK ;}
":=" { return ASSIGN ;}
"%" { return MOD ;}

0[0-7]+ { yylval.int_val = atoi(yytext); return INT_CONST; }
0x[\dA-F]+ { yylval.int_val = atoi(yytext); return INT_CONST; }
[1-9]{1}\d* { yylval.int_val = atoi(yytext); return INT_CONST; }
0 { yylval.int_val = atoi(yytext); return INT_CONST; }

'\\n' { yylval.chr_val = yytext[1]; return CHR_CONST; }
'\\r' { yylval.chr_val = yytext[1]; return CHR_CONST; }
'\' { yylval.chr_val = yytext[1]; return CHR_CONST; }
'\\t' { yylval.chr_val = yytext[1]; return CHR_CONST; }
'\\f' { yylval.chr_val = yytext[1]; return CHR_CONST; }
'[\x20-\x7E]{1}' { yylval.chr_val = strdup(yytext[1]); return CHR_CONST; }
"[\x20-\x7E]*" { yylval.str_val = strdup(yytext); return STR_CONST; }
\$.*\n {}

%%