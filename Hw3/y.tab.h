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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ADD = 258,
    SUB = 259,
    MUL = 260,
    QUO = 261,
    REM = 262,
    INC = 263,
    DEC = 264,
    GTR = 265,
    LSS = 266,
    GEQ = 267,
    LEQ = 268,
    EQL = 269,
    NEQ = 270,
    ASSIGN = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    MUL_ASSIGN = 274,
    QUO_ASSIGN = 275,
    REM_ASSIGN = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    LPAREN = 280,
    RPAREN = 281,
    LBRACK = 282,
    RBRACK = 283,
    LBRACE = 284,
    RBRACE = 285,
    SEMICOLON = 286,
    COMMA = 287,
    QUOTA = 288,
    PRINT = 289,
    RETURN = 290,
    IF = 291,
    ELSE = 292,
    FOR = 293,
    WHILE = 294,
    INT = 295,
    FLOAT = 296,
    BOOL = 297,
    STRING = 298,
    TRUE = 299,
    FALSE = 300,
    CONTINUE = 301,
    BREAK = 302,
    VOID = 303,
    INT_LIT = 304,
    FLOAT_LIT = 305,
    STRING_LIT = 306,
    BOOL_LIT = 307,
    IDENT = 308
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define QUO 261
#define REM 262
#define INC 263
#define DEC 264
#define GTR 265
#define LSS 266
#define GEQ 267
#define LEQ 268
#define EQL 269
#define NEQ 270
#define ASSIGN 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define MUL_ASSIGN 274
#define QUO_ASSIGN 275
#define REM_ASSIGN 276
#define AND 277
#define OR 278
#define NOT 279
#define LPAREN 280
#define RPAREN 281
#define LBRACK 282
#define RBRACK 283
#define LBRACE 284
#define RBRACE 285
#define SEMICOLON 286
#define COMMA 287
#define QUOTA 288
#define PRINT 289
#define RETURN 290
#define IF 291
#define ELSE 292
#define FOR 293
#define WHILE 294
#define INT 295
#define FLOAT 296
#define BOOL 297
#define STRING 298
#define TRUE 299
#define FALSE 300
#define CONTINUE 301
#define BREAK 302
#define VOID 303
#define INT_LIT 304
#define FLOAT_LIT 305
#define STRING_LIT 306
#define BOOL_LIT 307
#define IDENT 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "compiler_hw3.y"

    int i_val;
    float f_val;
    char *s_val;

#line 169 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
