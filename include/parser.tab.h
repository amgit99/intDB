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
     ORDER_ = 265,
     GROUP_ = 266,
     HAVING_ = 267,
     RETURN_ = 268,
     CLEAR_ = 269,
     INDEX_ = 270,
     LIST_ = 271,
     LOAD_ = 272,
     EXPORT_ = 273,
     PRINT_ = 274,
     COMPUTE_ = 275,
     CHECKSYMMETRY_ = 276,
     TRANSPOSE_ = 277,
     QUIT_ = 278,
     RENAME_ = 279,
     SOURCE_ = 280,
     MATRIX_ = 281,
     GT_ = 282,
     LT_ = 283,
     EQ_ = 284,
     NEQ_ = 285,
     LTEQ_ = 286,
     GTEQ_ = 287,
     EQGT_ = 288,
     EQLT_ = 289,
     MIN_ = 290,
     MAX_ = 291,
     SUM_ = 292,
     COUNT_ = 293,
     AVG_ = 294,
     ASC_ = 295,
     DESC_ = 296,
     CURLY_OPEN_ = 297,
     CURLY_CLOSE_ = 298,
     HASH_ = 299,
     BTREE_ = 300,
     NOTHING_ = 301,
     COMMA_ = 302,
     ON_ = 303,
     FROM_ = 304,
     TO_ = 305,
     USING_ = 306,
     TABLES_ = 307,
     BY_ = 308,
     IN_ = 309,
     AND_ = 310,
     OR_ = 311,
     NOT_ = 312,
     IDENTIFIER_ = 313,
     INT_LITERAL_ = 314,
     BOOL_LITERAL_ = 315
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
#define ORDER_ 265
#define GROUP_ 266
#define HAVING_ 267
#define RETURN_ 268
#define CLEAR_ 269
#define INDEX_ 270
#define LIST_ 271
#define LOAD_ 272
#define EXPORT_ 273
#define PRINT_ 274
#define COMPUTE_ 275
#define CHECKSYMMETRY_ 276
#define TRANSPOSE_ 277
#define QUIT_ 278
#define RENAME_ 279
#define SOURCE_ 280
#define MATRIX_ 281
#define GT_ 282
#define LT_ 283
#define EQ_ 284
#define NEQ_ 285
#define LTEQ_ 286
#define GTEQ_ 287
#define EQGT_ 288
#define EQLT_ 289
#define MIN_ 290
#define MAX_ 291
#define SUM_ 292
#define COUNT_ 293
#define AVG_ 294
#define ASC_ 295
#define DESC_ 296
#define CURLY_OPEN_ 297
#define CURLY_CLOSE_ 298
#define HASH_ 299
#define BTREE_ 300
#define NOTHING_ 301
#define COMMA_ 302
#define ON_ 303
#define FROM_ 304
#define TO_ 305
#define USING_ 306
#define TABLES_ 307
#define BY_ 308
#define IN_ 309
#define AND_ 310
#define OR_ 311
#define NOT_ 312
#define IDENTIFIER_ 313
#define INT_LITERAL_ 314
#define BOOL_LITERAL_ 315




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 11 "./src/parser.y"
{
    int intval;
    char* strval;
    bool boolval;
}
/* Line 1529 of yacc.c.  */
#line 175 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

