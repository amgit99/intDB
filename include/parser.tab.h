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
     ASSIGN_ARROW_ = 258,
     CROSS_ = 259,
     DISTINCT_ = 260,
     JOIN_ = 261,
     PROJECT_ = 262,
     SELECT_ = 263,
     SORT_ = 264,
     CLEAR_ = 265,
     INDEX_ = 266,
     LIST_ = 267,
     LOAD_ = 268,
     EXPORT_ = 269,
     PRINT_ = 270,
     COMPUTE_ = 271,
     CHECKSYMMETRY_ = 272,
     TRANSPOSE_ = 273,
     QUIT_ = 274,
     RENAME_ = 275,
     SOURCE_ = 276,
     MATRIX_ = 277,
     GT_ = 278,
     LT_ = 279,
     EQ_ = 280,
     NEQ_ = 281,
     LTEQ_ = 282,
     GTEQ_ = 283,
     EQGT_ = 284,
     EQLT_ = 285,
     ASC_ = 286,
     DESC_ = 287,
     HASH_ = 288,
     BTREE_ = 289,
     NOTHING_ = 290,
     COMMA_ = 291,
     ON_ = 292,
     FROM_ = 293,
     TO_ = 294,
     USING_ = 295,
     TABLES_ = 296,
     BY_ = 297,
     IN_ = 298,
     AND_ = 299,
     OR_ = 300,
     NOT_ = 301,
     IDENTIFIER_ = 302,
     INT_LITERAL_ = 303,
     BOOL_LITERAL_ = 304
   };
#endif
/* Tokens.  */
#define ASSIGN_ARROW_ 258
#define CROSS_ 259
#define DISTINCT_ 260
#define JOIN_ 261
#define PROJECT_ 262
#define SELECT_ 263
#define SORT_ 264
#define CLEAR_ 265
#define INDEX_ 266
#define LIST_ 267
#define LOAD_ 268
#define EXPORT_ 269
#define PRINT_ 270
#define COMPUTE_ 271
#define CHECKSYMMETRY_ 272
#define TRANSPOSE_ 273
#define QUIT_ 274
#define RENAME_ 275
#define SOURCE_ 276
#define MATRIX_ 277
#define GT_ 278
#define LT_ 279
#define EQ_ 280
#define NEQ_ 281
#define LTEQ_ 282
#define GTEQ_ 283
#define EQGT_ 284
#define EQLT_ 285
#define ASC_ 286
#define DESC_ 287
#define HASH_ 288
#define BTREE_ 289
#define NOTHING_ 290
#define COMMA_ 291
#define ON_ 292
#define FROM_ 293
#define TO_ 294
#define USING_ 295
#define TABLES_ 296
#define BY_ 297
#define IN_ 298
#define AND_ 299
#define OR_ 300
#define NOT_ 301
#define IDENTIFIER_ 302
#define INT_LITERAL_ 303
#define BOOL_LITERAL_ 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 12 "./src/parser.y"
{
    int intval, argc_;
    char* strval;
    bool boolval;
}
/* Line 1529 of yacc.c.  */
#line 153 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

