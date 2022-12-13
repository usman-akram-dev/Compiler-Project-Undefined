/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAIN = 258,
    LOOP = 259,
    NUM = 260,
    OPERATOR_A = 261,
    OPERATOR_R = 262,
    OPERATOR_U = 263,
    OPERATOR_E = 264,
    IDENTIFIER = 265,
    BOOL = 266,
    INPUT = 267,
    OUTPUT = 268,
    STRING = 269,
    IF = 270,
    ELSE = 271,
    ELSEIF = 272,
    IMPORT = 273,
    RETURN = 274,
    YES = 275,
    NO = 276,
    TERMINATOR = 277,
    ERROR = 278,
    COMMENT = 279,
    OPEN_BR = 280,
    OPEN_PR = 281,
    CLOSE_BR = 282,
    CLOSE_PR = 283,
    HEADER_FILE = 284,
    BOOL_YES = 285,
    BOOL_NO = 286,
    OTHER = 287,
    SEMICOLON = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "bison.y"

	int datatype;
	char *op;
	char *keyword;
	char *identifier;
	char *charStr;
	char *terminator;
	char *error;
	char *other;
	char *comment;
	char *openBr;
	char *openPr;
	char *closeBr;
	char *closePr;
	char *headerFile;
	char *boolYes;
	char *boolNo;

#line 110 "bison.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
