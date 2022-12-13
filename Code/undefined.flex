%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "bison.tab.h"
    using namespace std;
    int yylex();
    int lineno=1 ;
%}
%option noyywrap

main globlPrnt 
loop untilSatisfied
bool isValid
input store
output console
if check 
else ifNot 
elseif checkAgain
return out
import in
true Yes 
false No
comment \#([^\\\"|\\.])*\#
number [0-9]
assignment \=
arithmetic (-|\+|\*|\/|\%)
relational (==|\<|\>|\>=|\<=|\!=)
unary ((\+|-|\*|\\|\^)(\+|\-))
letter  [a-zA-Z]
identifier {letter}+
charStr \"([^\\\"|\\.])*\"
error1 \.{identifier}
error2 \;{number}
error3 \;{identifier}
terminator \;
other [0-9][_a-zA-Z]*
%%
{main}        {yylval.keyword = strdup(yytext); return (MAIN);}
{loop}        {yylval.keyword = strdup(yytext); return (LOOP);}
{bool}        {yylval.keyword = strdup(yytext); return (BOOL);}
{input}       {yylval.keyword = strdup(yytext); return (INPUT);}
{output}     {yylval.keyword = strdup(yytext); return (OUTPUT);}
{if}         {yylval.keyword = strdup(yytext); return (IF);}
{else}       {yylval.keyword = strdup(yytext); return (ELSE);}
{elseif}     {yylval.keyword = strdup(yytext); return (ELSEIF);}
{import}     {yylval.keyword = strdup(yytext); return (IMPORT);}
{return}     {yylval.keyword = strdup(yytext); return (RETURN);}
{true}       {yylval.keyword = strdup(yytext); return (YES);}
{false}      {yylval.keyword = strdup(yytext); return (NO);}
{number}     {yylval.datatype = atoi(yytext); return (NUM);}
{assignment}    {yylval.op = strdup(yytext); return (OPERATOR_E);}
{arithmetic}    {yylval.op = strdup(yytext); return (OPERATOR_A);}
{relational}    {yylval.op = strdup(yytext); return (OPERATOR_R);}
{unary}    {yylval.op = strdup(yytext); return (OPERATOR_U);}
{identifier}  {yylval.identifier = strdup(yytext); return (IDENTIFIER);}
{charStr}      {yylval.charStr = strdup(yytext); return (STRING);}
{error1}      {yylval.error = strdup(yytext); return (ERROR);}
{error2}      {yylval.error = strdup(yytext); return (ERROR);}
{error3}      {yylval.error = strdup(yytext); return (ERROR);}
{terminator}  {yylval.terminator = strdup(yytext); return(TERMINATOR);}
{comment}     {yylval.comment = strdup(yytext); return (COMMENT);}
{other}       {yylval.other = strdup(yytext); return (OTHER);}
"("           {yylval.openBr = strdup(yytext); return (OPEN_BR);}
")"           {yylval.closeBr = strdup(yytext); return (CLOSE_BR);}
"{"           {yylval.openPr = strdup(yytext); return (OPEN_PR);}
"}"           {yylval.closePr = strdup(yytext); return (CLOSE_PR);}
"undefinedlib.h" {yylval.headerFile = strdup(yytext); return (HEADER_FILE);}
[\n] 	{lineno++;}
" " {}
%%
