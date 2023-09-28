/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_ASSIGN_ARROW = 258,
     TOK_CROSS = 259,
     TOK_DISTINCT = 260,
     TOK_JOIN = 261,
     TOK_PROJECT = 262,
     TOK_SELECT = 263,
     TOK_SORT = 264,
     TOK_CLEAR = 265,
     TOK_INDEX = 266,
     TOK_LIST = 267,
     TOK_LOAD = 268,
     TOK_PRINT = 269,
     TOK_COMPUTE = 270,
     TOK_TRANSPOSE = 271,
     TOK_QUIT = 272,
     TOK_RENAME = 273,
     TOK_SOURCE = 274,
     TOK_IDENTIFIER = 275,
     TOK_INT_LITERAL = 276,
     TOK_GT = 277,
     TOK_LT = 278,
     TOK_EQ = 279,
     TOK_NEQ = 280,
     TOK_LTEQ = 281,
     TOK_GTEQ = 282,
     TOK_EQGT = 283,
     TOK_EQLT = 284,
     TOK_MATRIX = 285,
     TOK_EOL = 286,
     TOK_EXPORT = 287,
     TOK_CHECKSYMMETRY = 288,
     TOK_ASC = 289,
     TOK_DESC = 290,
     TOK_HASH = 291,
     TOK_BTREE = 292,
     TOK_NOTHING = 293,
     TOK_COMMA = 294,
     TOK_ON = 295,
     TOK_FROM = 296,
     TOK_TO = 297,
     TOK_USING = 298,
     TOK_TABLES = 299,
     TOK_BY = 300,
     TOK_IN = 301,
     TOK_AND = 302,
     TOK_OR = 303,
     TOK_NOT = 304
   };
#endif
/* Tokens.  */
#define TOK_ASSIGN_ARROW 258
#define TOK_CROSS 259
#define TOK_DISTINCT 260
#define TOK_JOIN 261
#define TOK_PROJECT 262
#define TOK_SELECT 263
#define TOK_SORT 264
#define TOK_CLEAR 265
#define TOK_INDEX 266
#define TOK_LIST 267
#define TOK_LOAD 268
#define TOK_PRINT 269
#define TOK_COMPUTE 270
#define TOK_TRANSPOSE 271
#define TOK_QUIT 272
#define TOK_RENAME 273
#define TOK_SOURCE 274
#define TOK_IDENTIFIER 275
#define TOK_INT_LITERAL 276
#define TOK_GT 277
#define TOK_LT 278
#define TOK_EQ 279
#define TOK_NEQ 280
#define TOK_LTEQ 281
#define TOK_GTEQ 282
#define TOK_EQGT 283
#define TOK_EQLT 284
#define TOK_MATRIX 285
#define TOK_EOL 286
#define TOK_EXPORT 287
#define TOK_CHECKSYMMETRY 288
#define TOK_ASC 289
#define TOK_DESC 290
#define TOK_HASH 291
#define TOK_BTREE 292
#define TOK_NOTHING 293
#define TOK_COMMA 294
#define TOK_ON 295
#define TOK_FROM 296
#define TOK_TO 297
#define TOK_USING 298
#define TOK_TABLES 299
#define TOK_BY 300
#define TOK_IN 301
#define TOK_AND 302
#define TOK_OR 303
#define TOK_NOT 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 8 "./src/parser.y"
{
    int intval;
    char* strval;
}
/* Line 1529 of yacc.c.  */
#line 152 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

