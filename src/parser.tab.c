/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./src/parser.y"


#include "globals.h"
#include "executor.h"

int yylex();
void yyerror(const char* s);


#line 81 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN_ARROW_ = 3,              /* ASSIGN_ARROW_  */
  YYSYMBOL_CROSS_ = 4,                     /* CROSS_  */
  YYSYMBOL_DISTINCT_ = 5,                  /* DISTINCT_  */
  YYSYMBOL_JOIN_ = 6,                      /* JOIN_  */
  YYSYMBOL_PROJECT_ = 7,                   /* PROJECT_  */
  YYSYMBOL_SELECT_ = 8,                    /* SELECT_  */
  YYSYMBOL_SORT_ = 9,                      /* SORT_  */
  YYSYMBOL_CLEAR_ = 10,                    /* CLEAR_  */
  YYSYMBOL_INDEX_ = 11,                    /* INDEX_  */
  YYSYMBOL_LIST_ = 12,                     /* LIST_  */
  YYSYMBOL_LOAD_ = 13,                     /* LOAD_  */
  YYSYMBOL_EXPORT_ = 14,                   /* EXPORT_  */
  YYSYMBOL_PRINT_ = 15,                    /* PRINT_  */
  YYSYMBOL_COMPUTE_ = 16,                  /* COMPUTE_  */
  YYSYMBOL_CHECKSYMMETRY_ = 17,            /* CHECKSYMMETRY_  */
  YYSYMBOL_TRANSPOSE_ = 18,                /* TRANSPOSE_  */
  YYSYMBOL_QUIT_ = 19,                     /* QUIT_  */
  YYSYMBOL_RENAME_ = 20,                   /* RENAME_  */
  YYSYMBOL_SOURCE_ = 21,                   /* SOURCE_  */
  YYSYMBOL_MATRIX_ = 22,                   /* MATRIX_  */
  YYSYMBOL_GT_ = 23,                       /* GT_  */
  YYSYMBOL_LT_ = 24,                       /* LT_  */
  YYSYMBOL_EQ_ = 25,                       /* EQ_  */
  YYSYMBOL_NEQ_ = 26,                      /* NEQ_  */
  YYSYMBOL_LTEQ_ = 27,                     /* LTEQ_  */
  YYSYMBOL_GTEQ_ = 28,                     /* GTEQ_  */
  YYSYMBOL_EQGT_ = 29,                     /* EQGT_  */
  YYSYMBOL_EQLT_ = 30,                     /* EQLT_  */
  YYSYMBOL_ASC_ = 31,                      /* ASC_  */
  YYSYMBOL_DESC_ = 32,                     /* DESC_  */
  YYSYMBOL_HASH_ = 33,                     /* HASH_  */
  YYSYMBOL_BTREE_ = 34,                    /* BTREE_  */
  YYSYMBOL_NOTHING_ = 35,                  /* NOTHING_  */
  YYSYMBOL_COMMA_ = 36,                    /* COMMA_  */
  YYSYMBOL_ON_ = 37,                       /* ON_  */
  YYSYMBOL_FROM_ = 38,                     /* FROM_  */
  YYSYMBOL_TO_ = 39,                       /* TO_  */
  YYSYMBOL_USING_ = 40,                    /* USING_  */
  YYSYMBOL_TABLES_ = 41,                   /* TABLES_  */
  YYSYMBOL_BY_ = 42,                       /* BY_  */
  YYSYMBOL_IN_ = 43,                       /* IN_  */
  YYSYMBOL_AND_ = 44,                      /* AND_  */
  YYSYMBOL_OR_ = 45,                       /* OR_  */
  YYSYMBOL_NOT_ = 46,                      /* NOT_  */
  YYSYMBOL_IDENTIFIER_ = 47,               /* IDENTIFIER_  */
  YYSYMBOL_INT_LITERAL_ = 48,              /* INT_LITERAL_  */
  YYSYMBOL_BOOL_LITERAL_ = 49,             /* BOOL_LITERAL_  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_Statement = 51,                 /* Statement  */
  YYSYMBOL_assignment_statement = 52,      /* assignment_statement  */
  YYSYMBOL_result_table_name = 53,         /* result_table_name  */
  YYSYMBOL_relation = 54,                  /* relation  */
  YYSYMBOL_non_assignment_statement = 55,  /* non_assignment_statement  */
  YYSYMBOL_cross_product_statement = 56,   /* cross_product_statement  */
  YYSYMBOL_distinct_statement = 57,        /* distinct_statement  */
  YYSYMBOL_join_statement = 58,            /* join_statement  */
  YYSYMBOL_projection_statement = 59,      /* projection_statement  */
  YYSYMBOL_projection_list = 60,           /* projection_list  */
  YYSYMBOL_selection_statement = 61,       /* selection_statement  */
  YYSYMBOL_condition = 62,                 /* condition  */
  YYSYMBOL_binop = 63,                     /* binop  */
  YYSYMBOL_sort_statement = 64,            /* sort_statement  */
  YYSYMBOL_arg_list = 65,                  /* arg_list  */
  YYSYMBOL_clear_statement = 66,           /* clear_statement  */
  YYSYMBOL_index_statement = 67,           /* index_statement  */
  YYSYMBOL_rename_statement = 68,          /* rename_statement  */
  YYSYMBOL_indexing_strategy = 69,         /* indexing_strategy  */
  YYSYMBOL_list_statement = 70,            /* list_statement  */
  YYSYMBOL_load_statement = 71,            /* load_statement  */
  YYSYMBOL_print_statement = 72,           /* print_statement  */
  YYSYMBOL_export_statement = 73           /* export_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   88

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    81,    82,    85,    91,    98,    99,   100,
     101,   102,   103,   106,   107,   108,   109,   110,   111,   112,
     116,   121,   122,   127,   132,   137,   145,   156,   159,   162,
     170,   175,   182,   190,   197,   206,   207,   208,   209,   210,
     211,   212,   213,   216,   221,   225,   230,   237,   240,   245,
     252,   253,   254,   257,   263,   268,   275,   280,   288,   293
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN_ARROW_",
  "CROSS_", "DISTINCT_", "JOIN_", "PROJECT_", "SELECT_", "SORT_", "CLEAR_",
  "INDEX_", "LIST_", "LOAD_", "EXPORT_", "PRINT_", "COMPUTE_",
  "CHECKSYMMETRY_", "TRANSPOSE_", "QUIT_", "RENAME_", "SOURCE_", "MATRIX_",
  "GT_", "LT_", "EQ_", "NEQ_", "LTEQ_", "GTEQ_", "EQGT_", "EQLT_", "ASC_",
  "DESC_", "HASH_", "BTREE_", "NOTHING_", "COMMA_", "ON_", "FROM_", "TO_",
  "USING_", "TABLES_", "BY_", "IN_", "AND_", "OR_", "NOT_", "IDENTIFIER_",
  "INT_LITERAL_", "BOOL_LITERAL_", "$accept", "Statement",
  "assignment_statement", "result_table_name", "relation",
  "non_assignment_statement", "cross_product_statement",
  "distinct_statement", "join_statement", "projection_statement",
  "projection_list", "selection_statement", "condition", "binop",
  "sort_statement", "arg_list", "clear_statement", "index_statement",
  "rename_statement", "indexing_strategy", "list_statement",
  "load_statement", "print_statement", "export_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,    -2,   -26,   -11,   -10,   -15,     0,     1,   -19,     6,
       7,   -29,     2,     8,   -29,    56,   -29,    54,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,    11,    -2,    -2,
      13,    14,   -29,    20,   -29,   -29,   -29,   -29,   -29,   -29,
      16,   -29,    18,   -29,    19,   -29,    21,   -29,   -29,   -29,
     -29,    22,    25,   -29,   -29,    -2,    23,   -29,    -2,   -29,
     -13,    12,    29,    24,    34,   -29,   -29,   -29,    26,    27,
     -29,   -29,    38,    30,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,    -4,    31,   -14,   -29,    -2,   -29,    41,
      33,   -29,   -29,   -29,   -29,    32,    35,    36,    39,    12,
     -29,   -29,    17,   -29,    40,   -29,   -29,   -29,   -29,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     6,     0,     3,     0,     4,    19,
      13,    14,    21,    15,    16,    17,    18,     0,     0,     0,
       0,     0,    12,     0,     7,     8,     9,    10,    11,    46,
       0,    53,     0,    54,     0,    58,     0,    56,    23,    24,
      25,     0,     0,    22,     1,     0,     0,    27,     0,    31,
       0,     0,     0,     0,     0,    55,    59,    57,     0,     0,
       5,    26,     0,     0,    30,    35,    36,    37,    38,    39,
      40,    41,    42,     0,     0,     0,    43,     0,    49,     0,
       0,    29,    33,    34,    32,     0,     0,     0,     0,     0,
      44,    45,     0,    48,     0,    50,    51,    52,    47,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -29,   -29,   -28,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -17,   -29,     3,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    15,    16,    17,    33,    18,    34,    35,    36,    37,
      60,    38,    62,    83,    19,    86,    20,    21,    22,   108,
      23,    24,    25,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      57,    58,    27,    28,    29,    30,    31,    42,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    39,    44,    46,    51,    73,    40,    70,    48,    95,
      72,    41,    43,    85,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    92,    93,    32,    14,    45,    47,    52,
     105,   106,   107,    49,    50,    53,    54,    55,    56,    97,
      59,    61,    63,    64,    69,    65,    66,    84,    67,    68,
      71,    85,    87,    88,    89,    90,   102,    91,    94,    98,
      99,   100,   104,     0,   101,     0,   103,   109,    96
};

static const yytype_int8 yycheck[] =
{
      28,    29,     4,     5,     6,     7,     8,    22,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    47,    22,    22,    22,    38,    37,    55,    47,    43,
      58,    41,    47,    47,    47,    23,    24,    25,    26,    27,
      28,    29,    30,    47,    48,    47,    47,    47,    47,    47,
      33,    34,    35,    47,    47,    47,     0,     3,    47,    87,
      47,    47,    42,    47,    39,    47,    47,    38,    47,    47,
      47,    47,    38,    47,    47,    37,    40,    47,    47,    38,
      47,    49,    99,    -1,    49,    -1,    47,    47,    85
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    47,    51,    52,    53,    55,    64,
      66,    67,    68,    70,    71,    72,    73,     4,     5,     6,
       7,     8,    47,    54,    56,    57,    58,    59,    61,    47,
      37,    41,    22,    47,    22,    47,    22,    47,    47,    47,
      47,    22,    47,    47,     0,     3,    47,    54,    54,    47,
      60,    47,    62,    42,    47,    47,    47,    47,    47,    39,
      54,    47,    54,    38,    47,    23,    24,    25,    26,    27,
      28,    29,    30,    63,    38,    47,    65,    38,    47,    47,
      37,    47,    47,    48,    47,    43,    65,    54,    38,    47,
      49,    49,    40,    47,    63,    33,    34,    35,    69,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    51,    52,    53,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    57,    58,    59,
      60,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    65,    65,    66,    67,    68,    68,
      69,    69,    69,    70,    71,    71,    72,    72,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     2,     7,     4,
       2,     1,     4,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     2,     7,     6,     4,
       1,     1,     1,     2,     2,     3,     2,     3,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* Statement: non_assignment_statement  */
#line 82 "./src/parser.y"
                                     { return 0; }
#line 1210 "parser.tab.c"
    break;

  case 5: /* assignment_statement: result_table_name ASSIGN_ARROW_ relation  */
#line 86 "./src/parser.y"
                        {
                          cout << "final assign" << endl; return 0; 
                        }
#line 1218 "parser.tab.c"
    break;

  case 6: /* result_table_name: IDENTIFIER_  */
#line 92 "./src/parser.y"
                    {
                      cout << "result: " << (yyvsp[0].strval) << endl;
                      RESULT_TABLE_NAME = (yyvsp[0].strval);
                    }
#line 1227 "parser.tab.c"
    break;

  case 7: /* relation: cross_product_statement  */
#line 98 "./src/parser.y"
                                  { cout << "cross_product_statement" << endl; }
#line 1233 "parser.tab.c"
    break;

  case 12: /* relation: IDENTIFIER_  */
#line 103 "./src/parser.y"
                      { evaluatedTable.push((yyvsp[0].strval)); }
#line 1239 "parser.tab.c"
    break;

  case 19: /* non_assignment_statement: sort_statement  */
#line 113 "./src/parser.y"
                              {
                                cout << "sort complete" << endl;
                              }
#line 1247 "parser.tab.c"
    break;

  case 20: /* non_assignment_statement: QUIT_  */
#line 117 "./src/parser.y"
                              { 
                                cout << "matching here" << endl;
                                return 69; 
                              }
#line 1256 "parser.tab.c"
    break;

  case 22: /* non_assignment_statement: SOURCE_ IDENTIFIER_  */
#line 123 "./src/parser.y"
                              { 
                                if(semanticParseSOURCE((yyvsp[0].strval))) 
                                    executeSOURCE((yyvsp[0].strval)); 
                              }
#line 1265 "parser.tab.c"
    break;

  case 23: /* non_assignment_statement: COMPUTE_ IDENTIFIER_  */
#line 128 "./src/parser.y"
                              { 
                                if(semanticParseCOMPUTE((yyvsp[0].strval))) 
                                    executeCOMPUTE((yyvsp[0].strval)); 
                              }
#line 1274 "parser.tab.c"
    break;

  case 24: /* non_assignment_statement: CHECKSYMMETRY_ IDENTIFIER_  */
#line 133 "./src/parser.y"
                              { 
                                if(semanticParseCHECKSYMMETRY((yyvsp[0].strval))) 
                                    executeCHECKSYMMETRY((yyvsp[0].strval)); 
                              }
#line 1283 "parser.tab.c"
    break;

  case 25: /* non_assignment_statement: TRANSPOSE_ IDENTIFIER_  */
#line 138 "./src/parser.y"
                              { 
                                if(semanticParseTRANSPOSEMATRIX((yyvsp[0].strval))) 
                                    executeTRANSPOSEMATRIX((yyvsp[0].strval)); 
                              }
#line 1292 "parser.tab.c"
    break;

  case 26: /* cross_product_statement: CROSS_ IDENTIFIER_ IDENTIFIER_  */
#line 146 "./src/parser.y"
                              {
                                cout << "cross" << endl;
                                crossQuery.resultTableName = RESULT_TABLE_NAME;
                                crossQuery.table1Name = (yyvsp[-1].strval);
                                crossQuery.table2Name = (yyvsp[0].strval);
                                if(semanticParseCROSS())
                                    executeCROSS();
                              }
#line 1305 "parser.tab.c"
    break;

  case 29: /* projection_statement: PROJECT_ projection_list FROM_ IDENTIFIER_  */
#line 163 "./src/parser.y"
                        {
                          projectionQuery.sourceTableName = (yyvsp[0].strval);
                          if(semanticParsePROJECTION())
                              executePROJECTION();
                        }
#line 1315 "parser.tab.c"
    break;

  case 30: /* projection_list: projection_list IDENTIFIER_  */
#line 171 "./src/parser.y"
                  {
                    // cout << $2 << endl;
                    projectionQuery.projectedColumns.push_back((yyvsp[0].strval));
                  }
#line 1324 "parser.tab.c"
    break;

  case 31: /* projection_list: IDENTIFIER_  */
#line 176 "./src/parser.y"
                  {
                    // cout << $1 << endl;
                    projectionQuery.projectedColumns.push_back((yyvsp[0].strval));
                  }
#line 1333 "parser.tab.c"
    break;

  case 32: /* selection_statement: SELECT_ condition FROM_ IDENTIFIER_  */
#line 183 "./src/parser.y"
                      {
                        selectionQuery.sourceTableName = (yyvsp[0].strval);
                        if(semanticParseSELECTION())
                            executeSELECTION();
                      }
#line 1343 "parser.tab.c"
    break;

  case 33: /* condition: IDENTIFIER_ binop IDENTIFIER_  */
#line 191 "./src/parser.y"
            {
              CONDITION_L_COLUMN_NAME = (yyvsp[-2].strval);
              CONDITION_BINOP = (yyvsp[-1].strval);
              selectionQuery.selectType = COLUMN;
              CONDITION_R_COLUMN_NAME = (yyvsp[0].strval);
            }
#line 1354 "parser.tab.c"
    break;

  case 34: /* condition: IDENTIFIER_ binop INT_LITERAL_  */
#line 198 "./src/parser.y"
            {
              CONDITION_L_COLUMN_NAME = (yyvsp[-2].strval);
              CONDITION_BINOP = (yyvsp[-1].strval);
              selectionQuery.selectType = INT_LITERAL;
              CONDITION_R_INTVAL = (yyvsp[0].intval);
            }
#line 1365 "parser.tab.c"
    break;

  case 43: /* sort_statement: SORT_ relation BY_ arg_list  */
#line 217 "./src/parser.y"
              {
                sortQuery.execute();
              }
#line 1373 "parser.tab.c"
    break;

  case 44: /* arg_list: IDENTIFIER_ IN_ BOOL_LITERAL_  */
#line 222 "./src/parser.y"
              { 
                sortQuery.updateArgList((yyvsp[-2].strval), (yyvsp[0].boolval));
              }
#line 1381 "parser.tab.c"
    break;

  case 45: /* arg_list: IDENTIFIER_ arg_list BOOL_LITERAL_  */
#line 226 "./src/parser.y"
              { 
                sortQuery.updateArgList((yyvsp[-2].strval), (yyvsp[0].boolval));
              }
#line 1389 "parser.tab.c"
    break;

  case 46: /* clear_statement: CLEAR_ IDENTIFIER_  */
#line 231 "./src/parser.y"
                        { 
                          if(semanticParseCLEAR((yyvsp[0].strval))) 
                              executeCLEAR((yyvsp[0].strval)); 
                        }
#line 1398 "parser.tab.c"
    break;

  case 48: /* rename_statement: RENAME_ IDENTIFIER_ TO_ IDENTIFIER_ FROM_ IDENTIFIER_  */
#line 241 "./src/parser.y"
                          { 
                            if(semanticParseRENAME((yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval))) 
                                executeRENAME((yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval)); 
                          }
#line 1407 "parser.tab.c"
    break;

  case 49: /* rename_statement: RENAME_ MATRIX_ IDENTIFIER_ IDENTIFIER_  */
#line 246 "./src/parser.y"
                          { 
                            if(semanticParseRENAMEMATRIX((yyvsp[-1].strval), (yyvsp[0].strval))) 
                                executeRENAMEMATRIX((yyvsp[-1].strval), (yyvsp[0].strval)); 
                          }
#line 1416 "parser.tab.c"
    break;

  case 53: /* list_statement: LIST_ TABLES_  */
#line 258 "./src/parser.y"
                  {
                    executeLIST();
                  }
#line 1424 "parser.tab.c"
    break;

  case 54: /* load_statement: LOAD_ IDENTIFIER_  */
#line 264 "./src/parser.y"
                    {
                      if(semanticParseLOAD((yyvsp[0].strval))) 
                          executeLOAD((yyvsp[0].strval)); 
                    }
#line 1433 "parser.tab.c"
    break;

  case 55: /* load_statement: LOAD_ MATRIX_ IDENTIFIER_  */
#line 269 "./src/parser.y"
                    { 
                      if(semanticParseLOADMATRIX((yyvsp[0].strval))) 
                          executeLOADMATRIX((yyvsp[0].strval)); 
                    }
#line 1442 "parser.tab.c"
    break;

  case 56: /* print_statement: PRINT_ IDENTIFIER_  */
#line 276 "./src/parser.y"
                    { 
                      if(semanticParsePRINT((yyvsp[0].strval))) 
                          executePRINT((yyvsp[0].strval)); 
                    }
#line 1451 "parser.tab.c"
    break;

  case 57: /* print_statement: PRINT_ MATRIX_ IDENTIFIER_  */
#line 281 "./src/parser.y"
                    { 
                      if(semanticParsePRINTMATRIX((yyvsp[0].strval))) 
                          executePRINTMATRIX((yyvsp[0].strval)); 
                    }
#line 1460 "parser.tab.c"
    break;

  case 58: /* export_statement: EXPORT_ IDENTIFIER_  */
#line 289 "./src/parser.y"
                        { 
                              if(semanticParseEXPORT((yyvsp[0].strval))) 
                              executeEXPORT((yyvsp[0].strval)); 
                        }
#line 1469 "parser.tab.c"
    break;

  case 59: /* export_statement: EXPORT_ MATRIX_ IDENTIFIER_  */
#line 294 "./src/parser.y"
                        { 
                              if(semanticParseEXPORTMATRIX((yyvsp[0].strval))) 
                              executeEXPORTMATRIX((yyvsp[0].strval)); 
                        }
#line 1478 "parser.tab.c"
    break;


#line 1482 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 299 "./src/parser.y"


void yyerror(const char* s) {
    std::cout << "this is an Error: " << s << std::endl;
}
