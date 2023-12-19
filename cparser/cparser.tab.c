/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cparser.y"

#include "generate.h"

#line 74 "cparser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_CPARSER_TAB_H_INCLUDED
# define YY_YY_CPARSER_TAB_H_INCLUDED
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
    ID = 258,
    TYPE = 259,
    INT_LITERAL = 260,
    CHAR_LITERAL = 261,
    STRING_LITERAL = 262,
    SIZEOF = 263,
    OR_OP = 264,
    AND_OP = 265,
    EQ_OP = 266,
    NE_OP = 267,
    LE_OP = 268,
    GE_OP = 269,
    LEFT_OP = 270,
    RIGHT_OP = 271,
    INC_OP = 272,
    DEC_OP = 273,
    PTR_OP = 274,
    STAR_OP = 275,
    IF = 276,
    ELSE = 277,
    WHILE = 278,
    FOR = 279,
    GOTO = 280,
    CONTINUE = 281,
    BREAK = 282,
    RETURN = 283,
    TRUE = 284,
    FALSE = 285,
    CONST = 286,
    SWITCH = 287,
    CASE = 288,
    DEFAULT = 289,
    DO = 290,
    SCANF = 291,
    PRINTF = 292,
    ASSIGNDIV = 293,
    ASSIGNSTAR = 294,
    ASSIGNCOM = 295,
    ASSIGNPLUS = 296,
    ASSIGNMINUS = 297,
    FLOAT_LITERAL = 298,
    HEAD = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 5 "cparser.y"

    struct ast *a;
    char * c;

#line 176 "cparser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_CPARSER_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   517

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

#define YYUNDEFTOK  2
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,    47,    43,     2,
      29,    30,    38,    36,    66,    37,    33,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    65,
      34,    48,    35,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,    41,    68,    42,     2,     2,     2,
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
      25,    26,    27,    28,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    31,    31,    34,    44,    46,    50,    54,    58,    62,
      64,    68,    72,    73,    76,    78,    82,    84,    86,    88,
      90,    92,    97,   102,   104,   108,   110,   114,   116,   121,
     123,   125,   127,   129,   131,   136,   141,   143,   147,   149,
     153,   155,   157,   159,   163,   169,   171,   175,   177,   181,
     183,   187,   189,   193,   195,   199,   201,   205,   207,   209,
     213,   215,   217,   219,   221,   225,   227,   229,   233,   235,
     237,   241,   243,   245,   247,   251,   253,   257,   259,   261,
     263,   265,   267,   269,   271,   273,   275,   277,   281,   283,
     285,   287,   289,   291,   293,   297,   299,   301,   303,   305,
     309,   311,   315,   317,   322,   324,   328,   330,   334,   336,
     338,   342,   344,   346,   348,   350
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TYPE", "INT_LITERAL",
  "CHAR_LITERAL", "STRING_LITERAL", "SIZEOF", "OR_OP", "AND_OP", "EQ_OP",
  "NE_OP", "LE_OP", "GE_OP", "LEFT_OP", "RIGHT_OP", "INC_OP", "DEC_OP",
  "PTR_OP", "STAR_OP", "IF", "ELSE", "WHILE", "FOR", "GOTO", "CONTINUE",
  "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'?'", "'|'", "'~'", "'&'", "'^'", "':'",
  "'!'", "'%'", "'='", "TRUE", "FALSE", "CONST", "SWITCH", "CASE",
  "DEFAULT", "DO", "SCANF", "PRINTF", "ASSIGNDIV", "ASSIGNSTAR",
  "ASSIGNCOM", "ASSIGNPLUS", "ASSIGNMINUS", "FLOAT_LITERAL", "HEAD", "';'",
  "','", "'{'", "'}'", "$accept", "program", "external_declaration",
  "function_definition", "var_declaration", "declaration_specifiers",
  "type_specifier", "params", "param_list", "param", "compound_statement",
  "statement_list_opt", "statement_list", "statement_and_declaration",
  "statement", "call_statement", "expression_statement", "expression",
  "assignment_expression", "assignment_operator", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusize_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "postfix_expression", "primary_expression",
  "primary_expression_list", "argument_expression_list",
  "selection_statement", "else_statement", "iteration_statement",
  "jump_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    40,
      41,    91,    93,    46,    60,    62,    43,    45,    42,    47,
      63,   124,   126,    38,    94,    58,    33,    37,    61,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    59,    44,   123,   125
};
# endif

#define YYPACT_NINF (-138)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -138,   100,  -138,  -138,  -138,  -138,  -138,    74,  -138,   -23,
    -138,  -138,  -138,    46,   282,  -138,     9,  -138,    41,   -10,
    -138,   309,   417,   417,   417,   336,   444,   444,   444,   417,
     444,   363,   -12,  -138,  -138,    16,    48,    22,    29,    56,
      71,    62,   115,    96,    14,  -138,    58,   182,  -138,  -138,
     117,   282,   123,   133,  -138,  -138,  -138,  -138,  -138,   136,
     111,  -138,    78,  -138,  -138,  -138,  -138,  -138,  -138,   120,
    -138,  -138,  -138,  -138,  -138,  -138,    58,  -138,   282,   444,
     282,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,  -138,   282,
    -138,  -138,    -7,   131,  -138,   116,    98,    41,   444,   109,
    -138,    48,    -4,    22,    29,    56,    71,    62,    62,   115,
     115,   115,   115,    96,    96,    14,    14,  -138,  -138,  -138,
    -138,  -138,   282,  -138,   137,   201,  -138,  -138,  -138,    81,
    -138,   444,  -138,  -138,   142,   144,   150,   151,   183,   122,
     125,   228,  -138,  -138,   390,  -138,   126,   201,  -138,  -138,
    -138,  -138,    69,  -138,  -138,  -138,  -138,    39,  -138,    41,
     282,   282,   255,   130,  -138,  -138,  -138,    88,   471,     9,
    -138,  -138,  -138,    81,  -138,   161,    -1,     1,   255,   255,
    -138,  -138,   -10,  -138,   132,    98,   201,   282,   282,  -138,
     174,  -138,     2,     3,   -17,  -138,   201,   201,   173,  -138,
    -138,  -138,   282,     6,    98,   174,  -138
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    11,     3,     4,     5,     0,     9,    95,
      96,    97,    98,     0,     0,    10,     0,    88,    13,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    40,    45,    47,    49,    51,    53,
      55,    57,    60,    65,    68,    71,    75,    77,    93,    94,
       0,     0,     0,     0,     7,    21,    19,    20,    18,     0,
       0,    12,    15,     8,    87,    86,    78,    79,    80,    11,
      82,    75,    83,    85,    81,    84,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,     0,
      92,   102,     0,     0,    91,    16,     0,     0,     0,     0,
      39,    48,     0,    50,    52,    54,    56,    58,    59,    63,
      64,    61,    62,    66,    67,    69,    70,    72,    73,    74,
      41,    90,     0,    89,     0,    23,     6,    14,    76,     0,
      42,     0,   103,    17,    95,     0,     0,     0,     0,     0,
       0,     0,    36,    27,     0,    30,     0,    24,    25,    28,
      34,    29,     0,    31,    32,    33,   100,     0,    46,    13,
       0,     0,     0,     0,   112,   113,   114,     0,     0,    77,
      22,    26,    37,     0,    43,     0,     0,     0,     0,     0,
     111,   115,    95,   101,     0,     0,     0,     0,     0,    35,
     104,   108,     0,     0,     0,   105,     0,     0,     0,   106,
     110,   109,     0,     0,     0,     0,   107
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,  -138,     0,    13,    12,    43,   103,  -138,
    -103,  -138,  -138,    57,   -98,  -138,  -137,    -9,   -39,   140,
      76,  -138,   141,   158,   159,   157,   139,    82,    35,    68,
      84,    -6,   -14,    -5,  -126,  -138,  -138,  -138,    27,  -138,
    -138
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,   153,    31,     8,    60,    61,    62,
     155,   156,   157,   158,   159,   160,   161,   162,    33,    99,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    71,    47,    17,   167,   102,   163,   205,   164,
     165
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,     6,    16,   136,   208,    32,    18,    65,    66,    67,
      68,    46,   101,   166,     7,    74,    32,    76,    77,    15,
      70,    72,    73,   131,    75,    79,    48,    49,    50,   195,
      59,   196,   206,   207,    95,   189,   214,    46,    51,   110,
      52,   141,    53,    15,    55,     3,    56,    57,    58,    19,
     135,   197,   198,    96,    78,    63,    80,   193,    81,   132,
     130,    97,    78,    82,    46,    78,    46,    78,    78,    78,
     140,   112,    78,    83,    54,    87,    88,     9,     3,    10,
      11,    12,    85,    86,    20,    46,    10,    11,    12,   127,
     128,   129,   200,   142,    13,    46,    89,    90,   201,    84,
       2,   209,   138,    14,     3,   183,    98,   184,   210,   211,
      14,   215,    20,     3,    10,    11,    12,    21,    46,    59,
     100,    46,   119,   120,   121,   122,    22,    23,   103,    24,
      91,    92,    93,    94,   182,    78,   104,    46,    25,   105,
      76,   106,   177,    46,   107,    26,    27,   134,   154,   179,
     108,    28,    29,   191,    78,    30,    46,    46,    46,   123,
     124,   186,   187,   133,    68,   135,    15,   117,   118,   143,
     154,   169,   188,   170,    46,    46,   139,   125,   126,   171,
     172,    59,    46,    46,    46,   154,   173,   174,   202,   203,
     175,   194,    46,    46,   180,   190,   204,   199,    46,    48,
      49,    50,   212,   213,   144,     3,    10,    11,    12,    21,
     137,    51,   185,    52,   181,    53,   109,   168,    22,    23,
     111,    24,   145,   116,   146,   147,   148,   149,   150,   151,
      25,    20,     3,    10,    11,    12,    21,    26,    27,   113,
     115,   114,   216,    28,    29,    22,    23,    30,    24,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    20,     3,
      10,    11,    12,    21,    26,    27,   152,     0,   135,     0,
      28,    29,    22,    23,    30,    24,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    20,     3,    10,    11,    12,
      21,    26,    27,   176,     0,     0,     0,    28,    29,    22,
      23,    30,    24,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    20,    64,    10,    11,    12,    21,    26,    27,
     152,     0,     0,     0,    28,    29,    22,    23,    30,    24,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    20,
      69,    10,    11,    12,    21,    26,    27,     0,     0,     0,
       0,    28,    29,    22,    23,    30,    24,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    20,     3,    10,    11,
      12,    21,    26,    27,     0,     0,     0,     0,    28,    29,
      22,    23,    30,    24,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    20,     3,    10,    11,    12,    21,    26,
      27,     0,     0,     0,     0,    28,    29,    22,    23,    30,
     178,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      20,     0,    10,    11,    12,    21,    26,    27,     0,     0,
       0,     0,    28,    29,    22,    23,    30,    24,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    20,     0,    10,
      11,    12,    21,    26,    27,     0,     0,     0,     0,    28,
      29,    22,    23,    30,    24,     0,     0,     0,     0,     0,
       0,     0,     0,    25,   192,     0,    10,    11,    12,    21,
      26,    27,     0,     0,     0,     0,    28,    29,    22,    23,
      30,    24,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,     0,     0,    30
};

static const yytype_int16 yycheck[] =
{
      14,     1,     7,   106,    21,    14,    29,    21,    22,    23,
      24,    25,    51,   139,     1,    29,    25,    31,    30,     7,
      26,    27,    28,    30,    30,     9,    17,    18,    19,    30,
      18,    30,    30,    30,    20,   172,    30,    51,    29,    78,
      31,    45,    33,    31,     3,     4,     5,     6,     7,     3,
      67,   188,   189,    39,    66,    65,    40,   183,    10,    66,
      99,    47,    66,    41,    78,    66,    80,    66,    66,    66,
     109,    80,    66,    44,    65,    13,    14,     3,     4,     5,
       6,     7,    11,    12,     3,    99,     5,     6,     7,    95,
      96,    97,   195,   132,    20,   109,    34,    35,   196,    43,
       0,   204,   108,    29,     4,    66,    48,    68,   206,   207,
      29,   214,     3,     4,     5,     6,     7,     8,   132,   107,
       3,   135,    87,    88,    89,    90,    17,    18,     5,    20,
      15,    16,    36,    37,    65,    66,     3,   151,    29,     3,
     154,    30,   151,   157,    66,    36,    37,    31,   135,   154,
      30,    42,    43,    65,    66,    46,   170,   171,   172,    91,
      92,   170,   171,    32,   178,    67,   154,    85,    86,    32,
     157,    29,   172,    29,   188,   189,    67,    93,    94,    29,
      29,   169,   196,   197,   198,   172,     3,    65,   197,   198,
      65,    30,   206,   207,    68,    65,    22,    65,   212,    17,
      18,    19,    29,   212,     3,     4,     5,     6,     7,     8,
     107,    29,   169,    31,   157,    33,    76,   141,    17,    18,
      79,    20,    21,    84,    23,    24,    25,    26,    27,    28,
      29,     3,     4,     5,     6,     7,     8,    36,    37,    81,
      83,    82,   215,    42,    43,    17,    18,    46,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     3,     4,
       5,     6,     7,     8,    36,    37,    65,    -1,    67,    -1,
      42,    43,    17,    18,    46,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,     3,     4,     5,     6,     7,
       8,    36,    37,    65,    -1,    -1,    -1,    42,    43,    17,
      18,    46,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,     3,     4,     5,     6,     7,     8,    36,    37,
      65,    -1,    -1,    -1,    42,    43,    17,    18,    46,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     3,
       4,     5,     6,     7,     8,    36,    37,    -1,    -1,    -1,
      -1,    42,    43,    17,    18,    46,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,     3,     4,     5,     6,
       7,     8,    36,    37,    -1,    -1,    -1,    -1,    42,    43,
      17,    18,    46,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,     3,     4,     5,     6,     7,     8,    36,
      37,    -1,    -1,    -1,    -1,    42,    43,    17,    18,    46,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
       3,    -1,     5,     6,     7,     8,    36,    37,    -1,    -1,
      -1,    -1,    42,    43,    17,    18,    46,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,     3,    -1,     5,
       6,     7,     8,    36,    37,    -1,    -1,    -1,    -1,    42,
      43,    17,    18,    46,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,     3,    -1,     5,     6,     7,     8,
      36,    37,    -1,    -1,    -1,    -1,    42,    43,    17,    18,
      46,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    70,     0,     4,    71,    72,    73,    74,    75,     3,
       5,     6,     7,    20,    29,    75,   102,   103,    29,     3,
       3,     8,    17,    18,    20,    29,    36,    37,    42,    43,
      46,    74,    86,    87,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    17,    18,
      19,    29,    31,    33,    65,     3,     5,     6,     7,    75,
      76,    77,    78,    65,     4,   101,   101,   101,   101,     4,
     100,   101,   100,   100,   101,   100,   101,    30,    66,     9,
      40,    10,    41,    44,    43,    11,    12,    13,    14,    34,
      35,    15,    16,    36,    37,    20,    39,    47,    48,    88,
       3,    87,   105,     5,     3,     3,    30,    66,    30,    88,
      87,    91,    86,    92,    93,    94,    95,    96,    96,    97,
      97,    97,    97,    98,    98,    99,    99,   100,   100,   100,
      87,    30,    66,    32,    31,    67,    79,    77,   100,    67,
      87,    45,    87,    32,     3,    21,    23,    24,    25,    26,
      27,    28,    65,    73,    74,    79,    80,    81,    82,    83,
      84,    85,    86,   106,   108,   109,   103,   104,    89,    29,
      29,    29,    29,     3,    65,    65,    65,    86,    20,   102,
      68,    82,    65,    66,    68,    76,    86,    86,    73,    85,
      65,    65,     3,   103,    30,    30,    30,    85,    85,    65,
      79,    83,    86,    86,    22,   107,    30,    30,    21,    79,
      83,    83,    29,    86,    30,    79,   107
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    72,    73,    73,    74,
      74,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    78,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      98,    99,    99,    99,    99,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   103,   103,   103,   103,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     108,   109,   109,   109,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     6,     3,     4,     1,
       2,     1,     1,     0,     3,     1,     2,     4,     1,     1,
       1,     1,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     2,     1,     3,
       1,     3,     4,     6,     1,     1,     5,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     4,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     4,
       4,     3,     3,     2,     2,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     5,     6,     2,     7,     5,     7,
       7,     3,     2,     2,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 31 "cparser.y"
               {
        printf("starting print syntex tree \n");
    }
#line 1689 "cparser.tab.c"
    break;

  case 3:
#line 35 "cparser.y"
    { 
      (yyval.a) = newast("program", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a));
      eval((yyval.a), 0);
      gen_code((yyval.a));
      free((yyval.a));
    }
#line 1700 "cparser.tab.c"
    break;

  case 4:
#line 45 "cparser.y"
    { (yyval.a) = newast("external_declaration", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1706 "cparser.tab.c"
    break;

  case 5:
#line 47 "cparser.y"
    { (yyval.a) = newast("external_declaration", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1712 "cparser.tab.c"
    break;

  case 6:
#line 51 "cparser.y"
    { (yyval.a) = newast("function_definition", (yyvsp[-5].a)->line_num, 4, (yyvsp[-5].a), newtoken("ID", (yyvsp[-4].c), (yylsp[-4]).first_line), (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1718 "cparser.tab.c"
    break;

  case 7:
#line 55 "cparser.y"
    { 
        (yyval.a) = newast("var_declaration", (yyvsp[-2].a)->line_num, 2, (yyvsp[-2].a), (yyvsp[-1].a));
    }
#line 1726 "cparser.tab.c"
    break;

  case 8:
#line 59 "cparser.y"
    { (yyval.a) = newast("var_declaration", (yyvsp[-3].a)->line_num, 3, (yyvsp[-3].a), newtoken("STAR_OP", (yyvsp[-2].c), (yylsp[-2]).first_line), newtoken("ID", (yyvsp[-1].c), (yylsp[-1]).first_line));}
#line 1732 "cparser.tab.c"
    break;

  case 9:
#line 63 "cparser.y"
    { (yyval.a) = newast("declaration_specifiers", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1738 "cparser.tab.c"
    break;

  case 10:
#line 65 "cparser.y"
    { (yyval.a) = newast("declaration_specifiers", (yyvsp[-1].a)->line_num, 2, (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1744 "cparser.tab.c"
    break;

  case 11:
#line 69 "cparser.y"
    { (yyval.a) = newast("type_specifier", (yylsp[0]).first_line, 1, newtoken("TYPE", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 1750 "cparser.tab.c"
    break;

  case 12:
#line 72 "cparser.y"
                        { (yyval.a) = newast("params", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1756 "cparser.tab.c"
    break;

  case 13:
#line 73 "cparser.y"
                { (yyval.a) = NULL; }
#line 1762 "cparser.tab.c"
    break;

  case 14:
#line 77 "cparser.y"
    { (yyval.a) = newast("param_list", (yyvsp[-2].a)->line_num, 2, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1768 "cparser.tab.c"
    break;

  case 15:
#line 79 "cparser.y"
    { (yyval.a) = newast("param_list", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1774 "cparser.tab.c"
    break;

  case 16:
#line 83 "cparser.y"
    { (yyval.a) = newast("param", (yyvsp[-1].a)->line_num, 2, (yyvsp[-1].a), newtoken("ID", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 1780 "cparser.tab.c"
    break;

  case 17:
#line 85 "cparser.y"
    { (yyval.a) = newast("param", (yyvsp[-3].a)->line_num, 2, (yyvsp[-3].a), newtoken("ID", (yyvsp[-2].c), (yylsp[-2]).first_line)); }
#line 1786 "cparser.tab.c"
    break;

  case 18:
#line 87 "cparser.y"
    { (yyval.a) = newast("param", (yylsp[0]).first_line, 1, newtoken("STRING_LITERAL", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 1792 "cparser.tab.c"
    break;

  case 19:
#line 89 "cparser.y"
    { (yyval.a) = newast("param", (yylsp[0]).first_line, 1, newtoken("INT_LITERAL", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 1798 "cparser.tab.c"
    break;

  case 20:
#line 91 "cparser.y"
    { (yyval.a) = newast("param", (yylsp[0]).first_line, 1, newtoken("CHAR_LITERAL", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 1804 "cparser.tab.c"
    break;

  case 21:
#line 93 "cparser.y"
    { (yyval.a) = newast("param", (yylsp[0]).first_line, 1, newtoken("ID", (yyvsp[0].c), (yylsp[0]).first_line));}
#line 1810 "cparser.tab.c"
    break;

  case 22:
#line 98 "cparser.y"
    { (yyval.a) = newast("compound_statement", (yylsp[-2]).first_line, 1, (yyvsp[-1].a)); }
#line 1816 "cparser.tab.c"
    break;

  case 23:
#line 102 "cparser.y"
    { (yyval.a)=NULL; }
#line 1822 "cparser.tab.c"
    break;

  case 24:
#line 105 "cparser.y"
    { (yyval.a) = newast("statement_list_opt", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1828 "cparser.tab.c"
    break;

  case 25:
#line 109 "cparser.y"
     { (yyval.a) = newast("statement_list", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1834 "cparser.tab.c"
    break;

  case 26:
#line 111 "cparser.y"
    { (yyval.a) = newast("statement_list", (yyvsp[-1].a)->line_num, 2, (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1840 "cparser.tab.c"
    break;

  case 27:
#line 115 "cparser.y"
    { (yyval.a) = newast("statement_and_declaration", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1846 "cparser.tab.c"
    break;

  case 28:
#line 117 "cparser.y"
    { (yyval.a) = newast("statement_and_declaration", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1852 "cparser.tab.c"
    break;

  case 29:
#line 122 "cparser.y"
    { (yyval.a) = newast("statement", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1858 "cparser.tab.c"
    break;

  case 30:
#line 124 "cparser.y"
    { (yyval.a) = newast("statement", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1864 "cparser.tab.c"
    break;

  case 31:
#line 126 "cparser.y"
    { (yyval.a) = newast("statement", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1870 "cparser.tab.c"
    break;

  case 32:
#line 128 "cparser.y"
    { (yyval.a) = newast("statement", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1876 "cparser.tab.c"
    break;

  case 33:
#line 130 "cparser.y"
    { (yyval.a) = newast("statement", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1882 "cparser.tab.c"
    break;

  case 34:
#line 132 "cparser.y"
    { (yyval.a) = newast("statement", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1888 "cparser.tab.c"
    break;

  case 35:
#line 137 "cparser.y"
     { (yyval.a) = newast("call_statement", (yylsp[-4]).first_line, 2, newtoken("ID", (yyvsp[-4].c), (yylsp[-4]).first_line), (yyvsp[-2].a)); }
#line 1894 "cparser.tab.c"
    break;

  case 36:
#line 142 "cparser.y"
    { (yyval.a) = NULL; }
#line 1900 "cparser.tab.c"
    break;

  case 37:
#line 144 "cparser.y"
    { (yyval.a) = newast("expression_statement", (yyvsp[-1].a)->line_num, 1, (yyvsp[-1].a)); }
#line 1906 "cparser.tab.c"
    break;

  case 38:
#line 148 "cparser.y"
    { (yyval.a) = newast("expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1912 "cparser.tab.c"
    break;

  case 39:
#line 150 "cparser.y"
    { (yyval.a) = newast("expression", (yyvsp[-2].a)->line_num, 2, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1918 "cparser.tab.c"
    break;

  case 40:
#line 154 "cparser.y"
    { (yyval.a) = newast("assignment_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1924 "cparser.tab.c"
    break;

  case 41:
#line 156 "cparser.y"
    { (yyval.a) = newast("assignment_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1930 "cparser.tab.c"
    break;

  case 42:
#line 158 "cparser.y"
    { (yyval.a) = newast("assignment_expression", (yyvsp[-3].a)->line_num, 4, (yyvsp[-3].a), (yyvsp[-2].a), (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1936 "cparser.tab.c"
    break;

  case 43:
#line 160 "cparser.y"
    { (yyval.a) = newast("assignment_expression", (yyvsp[-5].a)->line_num, 4, (yyvsp[-5].a), (yyvsp[-4].a), (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 1942 "cparser.tab.c"
    break;

  case 44:
#line 164 "cparser.y"
    { 
        (yyval.a) = newast("assignment_operator", (yylsp[0]).first_line, 1, newtoken("ASSIGNOP", (yyvsp[0].c), (yylsp[0]).first_line)); 
        }
#line 1950 "cparser.tab.c"
    break;

  case 45:
#line 170 "cparser.y"
    { (yyval.a) = newast("conditional_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1956 "cparser.tab.c"
    break;

  case 46:
#line 172 "cparser.y"
    { (yyval.a) = newast("conditional_expression", (yyvsp[-4].a)->line_num, 5, (yyvsp[-4].a), newtoken("QUESTION_MARK", (yyvsp[-3].c), (yylsp[-3]).first_line), (yyvsp[-2].a), newtoken("COLON", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 1962 "cparser.tab.c"
    break;

  case 47:
#line 176 "cparser.y"
    { (yyval.a) = newast("logical_or_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1968 "cparser.tab.c"
    break;

  case 48:
#line 178 "cparser.y"
    { (yyval.a) = newast("logical_or_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("OR_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 1974 "cparser.tab.c"
    break;

  case 49:
#line 182 "cparser.y"
    { (yyval.a) = newast("logical_and_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1980 "cparser.tab.c"
    break;

  case 50:
#line 184 "cparser.y"
    { (yyval.a) = newast("logical_and_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("AND_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 1986 "cparser.tab.c"
    break;

  case 51:
#line 188 "cparser.y"
    { (yyval.a) = newast("inclusize_or_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 1992 "cparser.tab.c"
    break;

  case 52:
#line 190 "cparser.y"
    { (yyval.a) = newast("inclusize_or_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("PIPE", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 1998 "cparser.tab.c"
    break;

  case 53:
#line 194 "cparser.y"
    { (yyval.a) = newast("exclusive_or_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2004 "cparser.tab.c"
    break;

  case 54:
#line 196 "cparser.y"
    { (yyval.a) = newast("exclusive_or_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("CARET", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2010 "cparser.tab.c"
    break;

  case 55:
#line 200 "cparser.y"
    { (yyval.a) = newast("and_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2016 "cparser.tab.c"
    break;

  case 56:
#line 202 "cparser.y"
    { (yyval.a) = newast("and_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("AMPERSAND", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2022 "cparser.tab.c"
    break;

  case 57:
#line 206 "cparser.y"
    { (yyval.a) = newast("equality_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2028 "cparser.tab.c"
    break;

  case 58:
#line 208 "cparser.y"
    { (yyval.a) = newast("equality_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("EQ_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2034 "cparser.tab.c"
    break;

  case 59:
#line 210 "cparser.y"
    { (yyval.a) = newast("equality_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("NE_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2040 "cparser.tab.c"
    break;

  case 60:
#line 214 "cparser.y"
    { (yyval.a) = newast("relational_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2046 "cparser.tab.c"
    break;

  case 61:
#line 216 "cparser.y"
    { (yyval.a) = newast("relational_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("L_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2052 "cparser.tab.c"
    break;

  case 62:
#line 218 "cparser.y"
    { (yyval.a) = newast("relational_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("G_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2058 "cparser.tab.c"
    break;

  case 63:
#line 220 "cparser.y"
    { (yyval.a) = newast("relational_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("LE_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2064 "cparser.tab.c"
    break;

  case 64:
#line 222 "cparser.y"
    { (yyval.a) = newast("relational_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("GE_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2070 "cparser.tab.c"
    break;

  case 65:
#line 226 "cparser.y"
    { (yyval.a) = newast("shift_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2076 "cparser.tab.c"
    break;

  case 66:
#line 228 "cparser.y"
    { (yyval.a) = newast("shift_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("LEFT_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2082 "cparser.tab.c"
    break;

  case 67:
#line 230 "cparser.y"
    { (yyval.a) = newast("shift_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("RIGHT_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2088 "cparser.tab.c"
    break;

  case 68:
#line 234 "cparser.y"
    { (yyval.a) = newast("additive_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2094 "cparser.tab.c"
    break;

  case 69:
#line 236 "cparser.y"
    { (yyval.a) = newast("additive_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("ADD_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2100 "cparser.tab.c"
    break;

  case 70:
#line 238 "cparser.y"
    { (yyval.a) = newast("additive_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a),newtoken("SUB_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2106 "cparser.tab.c"
    break;

  case 71:
#line 242 "cparser.y"
    { (yyval.a) = newast("multiplicative_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2112 "cparser.tab.c"
    break;

  case 72:
#line 244 "cparser.y"
    { (yyval.a) = newast("multiplicative_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("MUL_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2118 "cparser.tab.c"
    break;

  case 73:
#line 246 "cparser.y"
    { (yyval.a) = newast("multiplicative_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("DIV_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2124 "cparser.tab.c"
    break;

  case 74:
#line 248 "cparser.y"
    { (yyval.a) = newast("multiplicative_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("REMAIN_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2130 "cparser.tab.c"
    break;

  case 75:
#line 252 "cparser.y"
    { (yyval.a) = newast("cast_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2136 "cparser.tab.c"
    break;

  case 76:
#line 254 "cparser.y"
    { (yyval.a) = newast("cast_expression", (yylsp[-3]).first_line, 2, newtoken("TYPE", (yyvsp[-2].c), (yylsp[-2]).first_line), (yyvsp[0].a));}
#line 2142 "cparser.tab.c"
    break;

  case 77:
#line 258 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2148 "cparser.tab.c"
    break;

  case 78:
#line 260 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yylsp[-1]).first_line, 2, newtoken("INC_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2154 "cparser.tab.c"
    break;

  case 79:
#line 262 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yylsp[-1]).first_line, 2, newtoken("DEC_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2160 "cparser.tab.c"
    break;

  case 80:
#line 264 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yylsp[-1]).first_line, 2, newtoken("STAR_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2166 "cparser.tab.c"
    break;

  case 81:
#line 266 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yylsp[-1]).first_line, 2, newtoken("AMPERSAND", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2172 "cparser.tab.c"
    break;

  case 82:
#line 268 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yylsp[-1]).first_line, 2, newtoken("ADD_OP", "+", (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2178 "cparser.tab.c"
    break;

  case 83:
#line 270 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yylsp[-1]).first_line, 2, newtoken("MINUS_OP", "-", (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2184 "cparser.tab.c"
    break;

  case 84:
#line 272 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yylsp[-1]).first_line, 2, newtoken("YES_OP", "!", (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2190 "cparser.tab.c"
    break;

  case 85:
#line 274 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yylsp[-1]).first_line, 2, newtoken("NO_OP", "~", (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2196 "cparser.tab.c"
    break;

  case 86:
#line 276 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yylsp[-1]).first_line, 2, newtoken("SIZEOF", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2202 "cparser.tab.c"
    break;

  case 87:
#line 278 "cparser.y"
    { (yyval.a) = newast("unary_expression", (yylsp[-1]).first_line, 2, newtoken("SIZEOF", (yyvsp[-1].c), (yylsp[-1]).first_line), newtoken("TYPE", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 2208 "cparser.tab.c"
    break;

  case 88:
#line 282 "cparser.y"
    { (yyval.a) = newast("postfix_expression", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2214 "cparser.tab.c"
    break;

  case 89:
#line 284 "cparser.y"
    { (yyval.a) = newast("postfix_expression", (yyvsp[-3].a)->line_num, 2, (yyvsp[-3].a), newtoken("INT_LITERAL", (yyvsp[-1].c), (yylsp[-1]).first_line));}
#line 2220 "cparser.tab.c"
    break;

  case 90:
#line 286 "cparser.y"
    { (yyval.a) = newast("postfix_expression", (yyvsp[-3].a)->line_num, 2, (yyvsp[-3].a), (yyvsp[-1].a));}
#line 2226 "cparser.tab.c"
    break;

  case 91:
#line 288 "cparser.y"
    { (yyval.a) = newast("postfix_expression", (yyvsp[-2].a)->line_num, 2, (yyvsp[-2].a), newtoken("ID", (yyvsp[0].c), (yylsp[0]).first_line));}
#line 2232 "cparser.tab.c"
    break;

  case 92:
#line 290 "cparser.y"
    { (yyval.a) = newast("postfix_expression", (yyvsp[-2].a)->line_num, 3, (yyvsp[-2].a), newtoken("PTR_OP", (yyvsp[-1].c), (yylsp[-1]).first_line), newtoken("ID", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 2238 "cparser.tab.c"
    break;

  case 93:
#line 292 "cparser.y"
    { (yyval.a) = newast("postfix_expression", (yyvsp[-1].a)->line_num, 2, (yyvsp[-1].a), newtoken("INC_OP", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 2244 "cparser.tab.c"
    break;

  case 94:
#line 294 "cparser.y"
    { (yyval.a) = newast("postfix_expression", (yyvsp[-1].a)->line_num, 2, (yyvsp[-1].a), newtoken("DEC_OP", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 2250 "cparser.tab.c"
    break;

  case 95:
#line 298 "cparser.y"
    { (yyval.a) = newast("primary_expression", (yylsp[0]).first_line, 1, newtoken("ID", (yyvsp[0].c), (yylsp[0]).first_line));}
#line 2256 "cparser.tab.c"
    break;

  case 96:
#line 300 "cparser.y"
    { (yyval.a) = newast("primary_expression", (yylsp[0]).first_line, 1, newtoken("INT_LITERAL", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 2262 "cparser.tab.c"
    break;

  case 97:
#line 302 "cparser.y"
    { (yyval.a) = newast("primary_expression", (yylsp[0]).first_line, 1, newtoken("CHAR_LITERAL", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 2268 "cparser.tab.c"
    break;

  case 98:
#line 304 "cparser.y"
    { (yyval.a) = newast("primary_expression", (yylsp[0]).first_line, 1, newtoken("STRING_LITERAL", (yyvsp[0].c), (yylsp[0]).first_line)); }
#line 2274 "cparser.tab.c"
    break;

  case 99:
#line 306 "cparser.y"
    { (yyval.a) = newast("primary_expression", (yylsp[-2]).first_line, 1, (yyvsp[-1].a)); }
#line 2280 "cparser.tab.c"
    break;

  case 100:
#line 310 "cparser.y"
    { (yyval.a) = newast("primary_expression_list", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2286 "cparser.tab.c"
    break;

  case 101:
#line 312 "cparser.y"
    { (yyval.a) = newast("primary_expression_list", (yyvsp[-2].a)->line_num, 2, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2292 "cparser.tab.c"
    break;

  case 102:
#line 316 "cparser.y"
    { (yyval.a) = newast("argument_expression_list", (yyvsp[0].a)->line_num, 1, (yyvsp[0].a)); }
#line 2298 "cparser.tab.c"
    break;

  case 103:
#line 318 "cparser.y"
    { (yyval.a) = newast("argument_expression_list", (yyvsp[-2].a)->line_num, 2, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2304 "cparser.tab.c"
    break;

  case 104:
#line 323 "cparser.y"
    { (yyval.a) = newast("selection_statement", (yylsp[-4]).first_line, 3, newtoken("IF", (yyvsp[-4].c), (yylsp[-4]).first_line), (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2310 "cparser.tab.c"
    break;

  case 105:
#line 325 "cparser.y"
    { (yyval.a) = newast("selection_statement", (yylsp[-5]).first_line, 4, newtoken("IF", (yyvsp[-5].c), (yylsp[-5]).first_line), (yyvsp[-3].a), (yyvsp[-1].a), (yyvsp[0].a)); }
#line 2316 "cparser.tab.c"
    break;

  case 106:
#line 329 "cparser.y"
    { (yyval.a) = newast("else_statement", (yylsp[-1]).first_line, 2, newtoken("ELSE", (yyvsp[-1].c), (yylsp[-1]).first_line), (yyvsp[0].a)); }
#line 2322 "cparser.tab.c"
    break;

  case 107:
#line 331 "cparser.y"
    { (yyval.a) = newast("else_statement", (yylsp[-6]).first_line, 5, newtoken("ELSE", (yyvsp[-6].c), (yylsp[-6]).first_line), newtoken("IF", (yyvsp[-5].c), (yylsp[-5]).first_line), (yyvsp[-3].a), (yyvsp[-1].a), (yyvsp[0].a)); }
#line 2328 "cparser.tab.c"
    break;

  case 108:
#line 335 "cparser.y"
    { (yyval.a) = newast("iteration_statement", (yylsp[-4]).first_line, 3, newtoken("WHILE", (yyvsp[-4].c), (yylsp[-4]).first_line), (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2334 "cparser.tab.c"
    break;

  case 109:
#line 337 "cparser.y"
    { (yyval.a) = newast("iteration_statement", (yylsp[-6]).first_line, 5, newtoken("FOR", (yyvsp[-6].c), (yylsp[-6]).first_line), (yyvsp[-4].a), (yyvsp[-3].a), (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2340 "cparser.tab.c"
    break;

  case 110:
#line 339 "cparser.y"
    { (yyval.a) = newast("iteration_statement", (yylsp[-6]).first_line, 5, newtoken("FOR", (yyvsp[-6].c), (yylsp[-6]).first_line), (yyvsp[-4].a), (yyvsp[-3].a), (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2346 "cparser.tab.c"
    break;

  case 111:
#line 343 "cparser.y"
    { (yyval.a) = newast("jump_statement", (yylsp[-2]).first_line, 2, newtoken("GOTO", (yyvsp[-2].c), (yylsp[-2]).first_line), newtoken("ID", (yyvsp[-1].c), (yylsp[-1]).first_line)); }
#line 2352 "cparser.tab.c"
    break;

  case 112:
#line 345 "cparser.y"
    { (yyval.a) = newast("jump_statement", (yylsp[-1]).first_line, 1, newtoken("CONTINUE", (yyvsp[-1].c), (yylsp[-1]).first_line)); }
#line 2358 "cparser.tab.c"
    break;

  case 113:
#line 347 "cparser.y"
    { (yyval.a) = newast("jump_statement", (yylsp[-1]).first_line, 1, newtoken("BREAK", (yyvsp[-1].c), (yylsp[-1]).first_line)); }
#line 2364 "cparser.tab.c"
    break;

  case 114:
#line 349 "cparser.y"
    { (yyval.a) = newast("jump_statement", (yylsp[-1]).first_line, 1, newtoken("RETURN", (yyvsp[-1].c), (yylsp[-1]).first_line)); }
#line 2370 "cparser.tab.c"
    break;

  case 115:
#line 351 "cparser.y"
    { (yyval.a) = newast("jump_statement", (yylsp[-2]).first_line, 2, newtoken("RETURN", (yyvsp[-2].c), (yylsp[-2]).first_line), (yyvsp[-1].a)); }
#line 2376 "cparser.tab.c"
    break;


#line 2380 "cparser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 353 "cparser.y"





