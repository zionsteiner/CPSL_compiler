%{
#include <cstdlib>

#include "parser.hpp"
%}

%option noyywrap

%%
\bARRAY\b|\barray\b { return ARRAY ;}
\bBEGIN\b|\bbegin\b { return BEGIN ;}
\bCHR\b|\bchr\b { return CHR ;}
\bCONST\b|\bconst\b { return CONST ;}
\bDO\b|\bdo\b { return DO ;}
\bDOWNTO\b|\bdownto\b { return DOWNTO ;}
\bELSE\b|\belse\b { return ELSE ;}
\bELSEIF\b|\belseif\b { return ELSEIF ;}
\bEND\b|\bend\b { return END ;}
\bFOR\b|\bfor\b { return FOR ;}
\bFORWARD\b|\bforward\b { return FORWARD ;}
\bFUNCTION\b|\bfunction\b { return FUNCTION ;}
\bIF\b|\bif\b { return IF ;}
\bOF\b|\bof\b { return OF ;}
\bORD\b|\bord\b { return ORD ;}
\bPRED\b|\bpred\b { return PRED ;}
\bPROCEDURE\b|\bprocedure\b { return PROCEDURE ;}
\bREAD\b|\bread\b { return READ ;}
\bRECORD\b|\brecord\b { return RECORD ;}
\bREF\b|\bref\b { return REF ;}
\bREPEAT\b|\brepeat\b { return REPEAT ;}
\bRETURN\b|return\b { return RETURN ;}
\bSTOP\b|\bstop\b { return STOP ;}
\bSUCC\b|\bsucc\b { return SUCC ;}
\bTHEN\b|\bthen\b { return THEN ;}
\bTO\b|\bto\b { return TO ;}
\bTYPE\b|\btype\b { return TYPE ;}
\bUNTIL\b|\buntil\b { return UNTIL ;}
\bVAR\b|\bvar\b { return VAR ;}
\bWHILE\b|\bwhile\b { return WHILE ;}
\bWRITE\b|\bwrite\b { return WRITE ;}

[a-zA-Z]{1}[\w]* { yylval.id = strdup(yytext); return ID; }
"+" { return ADD ;}
"-" { return SUB ;}
"*" { return MULT ;}
"/" { return DIV ;}
"&" { return AMP ;}
"|" { return PIPE ;}
"~" { return INV ;}
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

0[0-7]+ { yylval.int_val = atoi(yytext); return OCTAL_CONST; }
0x[\dA-F]+ { yylval.int_val = atoi(yytext); return HEX_CONST; }
0\b|\b[1-9]{1}\d* { yylval.int_val = atoi(yytext); return INT_CONST; }

'\\n' { yylval.chr_val = yytext[1]; return CHR_CONST; }
'\\r' { yylval.chr_val = yytext[1]; return CHR_CONST; }
'\\b' { yylval.chr_val = yytext[1]; return CHR_CONST; }
'\\t' { yylval.chr_val = yytext[1]; return CHR_CONST; }
'\\f' { yylval.chr_val = yytext[1]; return CHR_CONST; }
'[\x20-\x7E]{1}' { yylval.chr_val = strdup(yytext[1]); return CHR_CONST; }
"[\x20-\x7E]*" { yylval.str_val = strdup(yytext); return STR_CONST; }
\$.*\n {}

%%