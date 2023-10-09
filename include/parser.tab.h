/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ASSIGN_ARROW_ = 258,           /* ASSIGN_ARROW_  */
    CROSS_ = 259,                  /* CROSS_  */
    DISTINCT_ = 260,               /* DISTINCT_  */
    JOIN_ = 261,                   /* JOIN_  */
    PROJECT_ = 262,                /* PROJECT_  */
    SELECT_ = 263,                 /* SELECT_  */
    SORT_ = 264,                   /* SORT_  */
    CLEAR_ = 265,                  /* CLEAR_  */
    INDEX_ = 266,                  /* INDEX_  */
    LIST_ = 267,                   /* LIST_  */
    LOAD_ = 268,                   /* LOAD_  */
    EXPORT_ = 269,                 /* EXPORT_  */
    PRINT_ = 270,                  /* PRINT_  */
    COMPUTE_ = 271,                /* COMPUTE_  */
    CHECKSYMMETRY_ = 272,          /* CHECKSYMMETRY_  */
    TRANSPOSE_ = 273,              /* TRANSPOSE_  */
    QUIT_ = 274,                   /* QUIT_  */
    RENAME_ = 275,                 /* RENAME_  */
    SOURCE_ = 276,                 /* SOURCE_  */
    MATRIX_ = 277,                 /* MATRIX_  */
    GT_ = 278,                     /* GT_  */
    LT_ = 279,                     /* LT_  */
    EQ_ = 280,                     /* EQ_  */
    NEQ_ = 281,                    /* NEQ_  */
    LTEQ_ = 282,                   /* LTEQ_  */
    GTEQ_ = 283,                   /* GTEQ_  */
    EQGT_ = 284,                   /* EQGT_  */
    EQLT_ = 285,                   /* EQLT_  */
    ASC_ = 286,                    /* ASC_  */
    DESC_ = 287,                   /* DESC_  */
    HASH_ = 288,                   /* HASH_  */
    BTREE_ = 289,                  /* BTREE_  */
    NOTHING_ = 290,                /* NOTHING_  */
    COMMA_ = 291,                  /* COMMA_  */
    ON_ = 292,                     /* ON_  */
    FROM_ = 293,                   /* FROM_  */
    TO_ = 294,                     /* TO_  */
    USING_ = 295,                  /* USING_  */
    TABLES_ = 296,                 /* TABLES_  */
    BY_ = 297,                     /* BY_  */
    IN_ = 298,                     /* IN_  */
    AND_ = 299,                    /* AND_  */
    OR_ = 300,                     /* OR_  */
    NOT_ = 301,                    /* NOT_  */
    IDENTIFIER_ = 302,             /* IDENTIFIER_  */
    INT_LITERAL_ = 303,            /* INT_LITERAL_  */
    BOOL_LITERAL_ = 304            /* BOOL_LITERAL_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "./src/parser.y"

    int intval;
    char* strval;
    bool boolval;

#line 119 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
