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
#line 2 "compiler_hw2.y"

    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table structure */

    struct node{
        int index;
        int address;
        int lineno;
        char *name;
        char *type;
        char *element;
        struct node *next;
    };

    typedef struct ST {
        int scope;
        int index;
        struct node *head;
        struct ST *next;
    } symbol_table_t;

    /* variables */
    symbol_table_t *symbolTable;

    int scope = 0;
    int addr = 0;

    /* Symbol table function - you can add new function if needed. */
    static symbol_table_t *create_symbol(int s);
    static symbol_table_t *find_symbol_table(int s);
    static void insert_symbol(char *name, char *type, char *element, int lineno);
    static struct node *lookup_symbol(char *name);
    static void dump_symbol();
    static char get_short_type(char *type);
    static void error_check(char *a, char *b, char *op);

#line 119 "y.tab.c"

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
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 56 "compiler_hw2.y"

    int i_val;
    float f_val;
    char *s_val;

#line 283 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   101,   105,   106,   107,   108,   112,   113,
     118,   119,   123,   124,   128,   129,   133,   134,   138,   139,
     151,   152,   153,   154,   155,   156,   160,   161,   165,   166,
     167,   171,   172,   173,   177,   178,   179,   183,   184,   195,
     199,   200,   201,   202,   203,   207,   211,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   228,   232,   233,
     234,   238,   242,   243,   247,   248,   249,   250,   251,   252,
     256,   260,   261,   265,   269,   273,   277,   281,   282,   283,
     287,   291,   295,   299,   303,   307,   311,   312,   313,   317,
     324,   332
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "QUO", "REM", "INC",
  "DEC", "GTR", "LSS", "GEQ", "LEQ", "EQL", "NEQ", "ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "AND", "OR",
  "NOT", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
  "SEMICOLON", "COMMA", "QUOTA", "PRINT", "RETURN", "IF", "ELSE", "FOR",
  "WHILE", "INT", "FLOAT", "BOOL", "STRING", "TRUE", "FALSE", "CONTINUE",
  "BREAK", "VOID", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "BOOL_LIT",
  "IDENT", "$accept", "Program", "Type", "TypeName", "Expression", "Expr7",
  "Expr6", "Expr5", "Expr4", "UnaryExpr", "cmp_op", "add_op", "mul_op",
  "unary_op", "PrimaryExpr", "Operand", "Literal", "IndexExpr",
  "ConversionExpr", "Statement", "ExpressionStmt", "DeclarationStmt",
  "AssignmentStmt", "AssignmentExpr", "assign_op", "IncDecStmt",
  "IncDecExpr", "Block", "Lbrace", "Rbrace", "StatementList", "IfStmt",
  "Condition", "WhileStmt", "ForStmt", "ForClause", "InitStmt", "PostStmt",
  "SimpleExpr", "PrintStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,   -54,   -54,   -54,   118,   -54,   -12,    14,    23,    25,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
      51,     9,   -54,     3,    32,    80,    41,    35,   -54,    14,
      29,   -54,   129,   -54,   -54,    74,   -54,   -54,   -54,    26,
     -54,    37,   -54,    74,   -54,   -54,   -54,   -54,   -54,    43,
       5,   -54,   128,    47,    42,    14,    14,   -54,    -2,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,    14,   -54,    14,
      14,   -54,   -54,   -54,   -54,   -54,   -54,    14,   -54,   -54,
      14,   -54,   -54,   -54,    14,   -54,    14,    14,    74,   -54,
     -54,    44,    14,   -54,    20,    10,    45,   166,   -54,   -54,
      53,    49,   -54,    55,    14,    14,   -54,    32,    47,    80,
      41,    35,   -54,   -13,    47,   -54,   -54,    47,    54,    48,
      65,     1,    42,    14,    42,   -15,     4,   -54,   -54,    72,
     -54,   -54,   -54,   -54,    73,   -54,   -54,    75,    79,    14,
     -54,    76,   -54,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    31,    32,    33,     0,    74,     0,     0,     0,     0,
       4,     5,     7,     6,    43,    44,    40,    41,    42,    38,
       0,     0,     3,     0,     9,    11,    13,    15,    17,     0,
      18,    34,    37,    35,    36,    76,    48,    49,    50,     0,
      51,     0,    52,     0,     2,    53,    54,    55,    56,     0,
       0,    37,     0,    80,     0,     0,     0,     1,     0,    71,
      72,    64,    65,    66,    67,    68,    69,     0,    57,     0,
       0,    24,    22,    25,    23,    20,    21,     0,    26,    27,
       0,    28,    29,    30,     0,    19,     0,     0,    47,    61,
      70,     0,     0,    39,    38,     0,    77,    87,    86,    88,
       0,     0,    84,     0,     0,     0,    58,     8,    63,    10,
      12,    14,    16,     0,    62,    75,    73,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,    89,     0,
      91,    79,    78,    82,     0,    81,    59,     0,     0,     0,
      60,     0,    83,    85,    90
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   105,   -54,    -3,    59,    58,    34,    50,   -23,
     -54,   -54,   -54,   -54,   -54,   -54,     0,   -54,   -54,   -28,
     -54,   -54,   -54,   -53,    97,   -54,   -52,   -49,   -54,   -54,
      90,    13,   -47,   -54,   -54,   -54,   -54,   -54,    -4,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      77,    80,    84,    29,    30,    31,    51,    33,    34,    35,
      36,    37,    38,    39,    69,    40,    41,    42,    43,   116,
      44,    45,    54,    46,    47,   100,   101,   142,   102,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    50,    98,    99,    53,    96,    85,    88,    67,   103,
      67,    59,    60,    52,   104,   127,   136,     1,     2,    61,
      62,    63,    64,    65,    66,   105,    67,    67,    67,   106,
       5,    93,   137,    67,    68,    32,   120,     7,     3,     4,
      81,    82,    83,    32,    78,    79,   118,   119,    55,    95,
      56,    57,    97,    53,    70,    32,    86,    89,    14,    15,
      88,   112,    58,    16,    17,    18,   108,    19,    90,    92,
      67,     5,   131,   133,   115,   135,   134,     1,     2,   122,
     123,   124,   121,   113,   114,   128,    98,    99,    32,   117,
      71,    72,    73,    74,    75,    76,   130,   129,     3,     4,
     138,   125,   126,     5,   139,   141,   140,   144,     6,    49,
       7,   110,     8,     9,    10,    11,    12,    13,    14,    15,
      53,     1,     2,    16,    17,    18,   107,    19,   109,    87,
     111,     1,     2,    91,   132,   143,    97,     0,     0,    32,
       0,     0,     3,     4,     0,    61,    62,    63,    64,    65,
      66,     0,     3,     4,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    16,    17,    18,
       0,    19,    14,    15,    59,    60,     0,    16,    17,    18,
       0,    94,    61,    62,    63,    64,    65,    66,     0,    67
};

static const yytype_int16 yycheck[] =
{
       0,     4,    55,    55,     7,    54,    29,    35,    23,    56,
      23,     8,     9,    25,    16,    28,    31,     3,     4,    16,
      17,    18,    19,    20,    21,    27,    23,    23,    23,    31,
      29,    26,    28,    23,    31,    35,    26,    36,    24,    25,
       5,     6,     7,    43,     3,     4,    26,    27,    25,    52,
      25,     0,    55,    56,    22,    55,    27,    31,    44,    45,
      88,    84,    53,    49,    50,    51,    69,    53,    31,    26,
      23,    29,   121,   122,    30,   124,   123,     3,     4,    26,
      31,    26,    37,    86,    87,    31,   139,   139,    88,    92,
      10,    11,    12,    13,    14,    15,    31,    49,    24,    25,
      28,   104,   105,    29,    31,    26,    31,    31,    34,     4,
      36,    77,    38,    39,    40,    41,    42,    43,    44,    45,
     123,     3,     4,    49,    50,    51,    67,    53,    70,    32,
      80,     3,     4,    43,   121,   139,   139,    -1,    -1,   139,
      -1,    -1,    24,    25,    -1,    16,    17,    18,    19,    20,
      21,    -1,    24,    25,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    50,    51,
      -1,    53,    44,    45,     8,     9,    -1,    49,    50,    51,
      -1,    53,    16,    17,    18,    19,    20,    21,    -1,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    24,    25,    29,    34,    36,    38,    39,
      40,    41,    42,    43,    44,    45,    49,    50,    51,    53,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      79,    80,    81,    82,    84,    85,    87,    88,    93,    56,
      58,    70,    25,    58,    86,    25,    25,     0,    53,     8,
       9,    16,    17,    18,    19,    20,    21,    23,    31,    78,
      22,    10,    11,    12,    13,    14,    15,    64,     3,     4,
      65,     5,     6,     7,    66,    63,    27,    78,    73,    31,
      31,    84,    26,    26,    53,    58,    81,    58,    77,    80,
      89,    90,    92,    86,    16,    27,    31,    59,    58,    60,
      61,    62,    63,    58,    58,    30,    83,    58,    26,    27,
      26,    37,    26,    31,    26,    58,    58,    28,    31,    49,
      31,    81,    85,    81,    86,    81,    31,    28,    28,    31,
      31,    26,    91,    92,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    57,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    67,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    70,    71,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    75,
      75,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      79,    80,    80,    81,    82,    83,    84,    85,    85,    85,
      86,    87,    88,    89,    90,    91,    92,    92,    92,    93,
      93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     4,     4,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     5,
       6,     2,     3,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     3,     1,     1,     1,     3,     5,     5,
       1,     5,     5,     5,     1,     1,     1,     1,     1,     5,
       8,     5
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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
  case 3:
#line 101 "compiler_hw2.y"
               { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1579 "y.tab.c"
    break;

  case 4:
#line 105 "compiler_hw2.y"
          { (yyval.s_val) = "int"; }
#line 1585 "y.tab.c"
    break;

  case 5:
#line 106 "compiler_hw2.y"
            { (yyval.s_val) = "float"; }
#line 1591 "y.tab.c"
    break;

  case 6:
#line 107 "compiler_hw2.y"
             { (yyval.s_val) = "string"; }
#line 1597 "y.tab.c"
    break;

  case 7:
#line 108 "compiler_hw2.y"
           { (yyval.s_val) = "bool"; }
#line 1603 "y.tab.c"
    break;

  case 8:
#line 112 "compiler_hw2.y"
                          { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), "OR"); printf("OR\n"); (yyval.s_val) = (yyvsp[0].s_val); }
#line 1609 "y.tab.c"
    break;

  case 9:
#line 113 "compiler_hw2.y"
            { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1615 "y.tab.c"
    break;

  case 10:
#line 118 "compiler_hw2.y"
                      { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), "AND"); printf("AND\n"); (yyval.s_val) = (yyvsp[0].s_val); }
#line 1621 "y.tab.c"
    break;

  case 11:
#line 119 "compiler_hw2.y"
            { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1627 "y.tab.c"
    break;

  case 12:
#line 123 "compiler_hw2.y"
                         { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); (yyval.s_val) = "bool"; }
#line 1633 "y.tab.c"
    break;

  case 13:
#line 124 "compiler_hw2.y"
            { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1639 "y.tab.c"
    break;

  case 14:
#line 128 "compiler_hw2.y"
                         { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); (yyval.s_val) = (yyvsp[0].s_val); }
#line 1645 "y.tab.c"
    break;

  case 15:
#line 129 "compiler_hw2.y"
            { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1651 "y.tab.c"
    break;

  case 16:
#line 133 "compiler_hw2.y"
                             { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); (yyval.s_val) = (yyvsp[0].s_val); }
#line 1657 "y.tab.c"
    break;

  case 17:
#line 134 "compiler_hw2.y"
                { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1663 "y.tab.c"
    break;

  case 18:
#line 138 "compiler_hw2.y"
                  { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1669 "y.tab.c"
    break;

  case 19:
#line 139 "compiler_hw2.y"
                         { printf("%s\n", (yyvsp[-1].s_val)); (yyval.s_val) = (yyvsp[0].s_val); }
#line 1675 "y.tab.c"
    break;

  case 20:
#line 151 "compiler_hw2.y"
          { (yyval.s_val) = "EQL"; }
#line 1681 "y.tab.c"
    break;

  case 21:
#line 152 "compiler_hw2.y"
          { (yyval.s_val) = "NEQ"; }
#line 1687 "y.tab.c"
    break;

  case 22:
#line 153 "compiler_hw2.y"
          { (yyval.s_val) = "LSS"; }
#line 1693 "y.tab.c"
    break;

  case 23:
#line 154 "compiler_hw2.y"
          { (yyval.s_val) = "LEQ"; }
#line 1699 "y.tab.c"
    break;

  case 24:
#line 155 "compiler_hw2.y"
          { (yyval.s_val) = "GTR"; }
#line 1705 "y.tab.c"
    break;

  case 25:
#line 156 "compiler_hw2.y"
          { (yyval.s_val) = "GEQ"; }
#line 1711 "y.tab.c"
    break;

  case 26:
#line 160 "compiler_hw2.y"
          { (yyval.s_val) = "ADD"; }
#line 1717 "y.tab.c"
    break;

  case 27:
#line 161 "compiler_hw2.y"
          { (yyval.s_val) = "SUB"; }
#line 1723 "y.tab.c"
    break;

  case 28:
#line 165 "compiler_hw2.y"
          { (yyval.s_val) = "MUL"; }
#line 1729 "y.tab.c"
    break;

  case 29:
#line 166 "compiler_hw2.y"
          { (yyval.s_val) = "QUO"; }
#line 1735 "y.tab.c"
    break;

  case 30:
#line 167 "compiler_hw2.y"
          { (yyval.s_val) = "REM"; }
#line 1741 "y.tab.c"
    break;

  case 31:
#line 171 "compiler_hw2.y"
          { (yyval.s_val) = "POS"; }
#line 1747 "y.tab.c"
    break;

  case 32:
#line 172 "compiler_hw2.y"
          { (yyval.s_val) = "NEG"; }
#line 1753 "y.tab.c"
    break;

  case 33:
#line 173 "compiler_hw2.y"
          { (yyval.s_val) = "NOT"; }
#line 1759 "y.tab.c"
    break;

  case 34:
#line 177 "compiler_hw2.y"
              { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1765 "y.tab.c"
    break;

  case 35:
#line 178 "compiler_hw2.y"
                { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1771 "y.tab.c"
    break;

  case 36:
#line 179 "compiler_hw2.y"
                     { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1777 "y.tab.c"
    break;

  case 37:
#line 183 "compiler_hw2.y"
              { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1783 "y.tab.c"
    break;

  case 38:
#line 184 "compiler_hw2.y"
            {
        struct node *n = lookup_symbol((yyvsp[0].s_val)); 
        if(n)
        {
            (yyval.s_val) = n->type;
        }
        else
        {
            (yyval.s_val) = "undefined";
        }
    }
#line 1799 "y.tab.c"
    break;

  case 39:
#line 195 "compiler_hw2.y"
                               { (yyval.s_val) = (yyvsp[-1].s_val); }
#line 1805 "y.tab.c"
    break;

  case 40:
#line 199 "compiler_hw2.y"
              { printf("INT_LIT %d\n", (yyval.i_val)); (yyval.s_val) = "int"; }
#line 1811 "y.tab.c"
    break;

  case 41:
#line 200 "compiler_hw2.y"
                { printf("FLOAT_LIT %f\n", (yyval.f_val)); (yyval.s_val) = "float"; }
#line 1817 "y.tab.c"
    break;

  case 42:
#line 201 "compiler_hw2.y"
                 { printf("STRING_LIT %s\n", (yyval.s_val)); (yyval.s_val) = "string"; }
#line 1823 "y.tab.c"
    break;

  case 43:
#line 202 "compiler_hw2.y"
           { printf("TRUE\n"); (yyval.s_val) = "bool"; }
#line 1829 "y.tab.c"
    break;

  case 44:
#line 203 "compiler_hw2.y"
            { printf("FALSE\n"); (yyval.s_val) = "bool"; }
#line 1835 "y.tab.c"
    break;

  case 45:
#line 207 "compiler_hw2.y"
                                           { (yyval.s_val) = (yyvsp[-3].s_val); }
#line 1841 "y.tab.c"
    break;

  case 46:
#line 211 "compiler_hw2.y"
                                    { printf("%c to %c\n", get_short_type((yyvsp[0].s_val)), get_short_type((yyvsp[-2].s_val))); (yyval.s_val) = (yyvsp[-2].s_val); }
#line 1847 "y.tab.c"
    break;

  case 58:
#line 232 "compiler_hw2.y"
                           { insert_symbol((yyvsp[-1].s_val), (yyvsp[-2].s_val), "-", yylineno); }
#line 1853 "y.tab.c"
    break;

  case 59:
#line 233 "compiler_hw2.y"
                                             { insert_symbol((yyvsp[-3].s_val), (yyvsp[-4].s_val), "-", yylineno); }
#line 1859 "y.tab.c"
    break;

  case 60:
#line 234 "compiler_hw2.y"
                                                    { insert_symbol((yyvsp[-4].s_val), "array", (yyvsp[-5].s_val), yylineno); }
#line 1865 "y.tab.c"
    break;

  case 62:
#line 242 "compiler_hw2.y"
                                   { printf("error:%d: cannot assign to %s\n", yylineno, (yyvsp[-2].s_val)); printf("%s\n", (yyvsp[-1].s_val)); }
#line 1871 "y.tab.c"
    break;

  case 63:
#line 243 "compiler_hw2.y"
                                      { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); }
#line 1877 "y.tab.c"
    break;

  case 64:
#line 247 "compiler_hw2.y"
             { (yyval.s_val) = "ASSIGN"; }
#line 1883 "y.tab.c"
    break;

  case 65:
#line 248 "compiler_hw2.y"
                 { (yyval.s_val) = "ADD_ASSIGN"; }
#line 1889 "y.tab.c"
    break;

  case 66:
#line 249 "compiler_hw2.y"
                 { (yyval.s_val) = "SUB_ASSIGN"; }
#line 1895 "y.tab.c"
    break;

  case 67:
#line 250 "compiler_hw2.y"
                 { (yyval.s_val) = "MUL_ASSIGN"; }
#line 1901 "y.tab.c"
    break;

  case 68:
#line 251 "compiler_hw2.y"
                 { (yyval.s_val) = "QUO_ASSIGN"; }
#line 1907 "y.tab.c"
    break;

  case 69:
#line 252 "compiler_hw2.y"
                 { (yyval.s_val) = "REM_ASSIGN"; }
#line 1913 "y.tab.c"
    break;

  case 71:
#line 260 "compiler_hw2.y"
                     { printf("INC\n"); }
#line 1919 "y.tab.c"
    break;

  case 72:
#line 261 "compiler_hw2.y"
                     { printf("DEC\n"); }
#line 1925 "y.tab.c"
    break;

  case 74:
#line 269 "compiler_hw2.y"
             { scope++;}
#line 1931 "y.tab.c"
    break;

  case 75:
#line 273 "compiler_hw2.y"
             { dump_symbol(); scope--; }
#line 1937 "y.tab.c"
    break;

  case 80:
#line 287 "compiler_hw2.y"
                 { error_check((yyvsp[0].s_val), (yyvsp[0].s_val), "condition"); }
#line 1943 "y.tab.c"
    break;

  case 89:
#line 317 "compiler_hw2.y"
                                          {
        struct node *n = lookup_symbol((yyvsp[-2].s_val));
        if(n)
        {
            printf("PRINT %s\n", n->type);
        }
    }
#line 1955 "y.tab.c"
    break;

  case 90:
#line 324 "compiler_hw2.y"
                                                                {
        struct node *n = lookup_symbol((yyvsp[-5].s_val));
        printf("INT_LIT %d\n", (yyvsp[-3].i_val));
        if(n)
        {
            printf("PRINT %s\n", n->element);
        }
    }
#line 1968 "y.tab.c"
    break;

  case 91:
#line 332 "compiler_hw2.y"
                                               {
        printf("PRINT %s\n", (yyvsp[-2].s_val));
    }
#line 1976 "y.tab.c"
    break;


#line 1980 "y.tab.c"

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 337 "compiler_hw2.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    symbolTable = malloc(sizeof(symbol_table_t));
    symbolTable->scope = 0;
    symbolTable->index = 0;
    symbolTable->head = malloc(sizeof(struct node));
    symbolTable->next = NULL;

    yyparse();
    dump_symbol();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

/* symbol table function */
static symbol_table_t *create_symbol(int s)
{
    symbol_table_t *new_s, *curr = symbolTable;
    new_s = malloc(sizeof(symbol_table_t));
    new_s->scope = s;
    new_s->index = 0;
    new_s->head = malloc(sizeof(struct node));
    new_s->next = NULL;

    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_s;
    return new_s;
}

static symbol_table_t *find_symbol_table(int s)
{
    symbol_table_t *curr = symbolTable;
    while(curr != NULL)
    {
        if(curr->scope == s)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

static void insert_symbol(char *name, char *type, char *element, int lineno)
{
    symbol_table_t *st = find_symbol_table(scope);
    if(!st)
    {
        st = create_symbol(scope);
    }
    else
    {
        struct node *n = st->head->next;
        int found = 0;
        while(n != NULL)
        {
            if(strcmp(name, n->name) == 0)
            {
                found = 1;
                break;
            }
            n = n->next;
        }

        if(found == 1)
        {
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", lineno, name, n->lineno);
            return;
        }
    }

    printf("> Insert {%s} into symbol table (scope level: %d)\n", name, scope);

    struct node *new_n = malloc(sizeof(struct node));
    new_n->index = st->index++;
    new_n->address = addr++;
    new_n->lineno = lineno;
    new_n->name = strdup(name);
    new_n->type = strdup(type);
    new_n->element = strdup(element);
    new_n->next = NULL;

    struct node *curr = st->head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_n;

}

static struct node *lookup_symbol(char *name)
{
    int s = scope;
    do{
        symbol_table_t *st = find_symbol_table(s);
        if(!st)
        {
            continue;
        }

        struct node *curr = st->head->next;
        while(curr != NULL)
        {
            if(strcmp(name, curr->name) == 0)
            {
                printf("IDENT (name=%s, address=%d)\n", curr->name, curr->address);
                return curr;
            }
            curr = curr->next;
        }
    } while(--s >= 0);

    printf("error:%d: undefined: %s\n", yylineno, name);

    return NULL;
}

static void dump_symbol()
{
    symbol_table_t *st = find_symbol_table(scope);
    int s;
    if(st == NULL)
    {
        s = scope;
    }
    else 
    {
        s = st->scope;
    }
    printf("> Dump symbol table (scope level: %d)\n", s);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n", "Index", "Name", "Type", "Address", "Lineno", "Element type");
    
    if(st == NULL)
    {
        return;
    }

    struct node *curr = st->head->next, *tmp;
    while(curr != NULL)
    {
        printf("%-10d%-10s%-10s%-10d%-10d%s\n", curr->index, curr->name, curr->type, curr->address, curr->lineno, curr->element);
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    st->head->next = NULL;
    free(st);
    // if(scope > 0){
    //     symbol_table_t *prev = find_symbol_table(scope-1);
    //     prev->next = NULL;
    // }    
}

static char get_short_type(char *type)
{
    if(strcmp(type, "int") == 0) return 'I';
    if(strcmp(type, "float") == 0) return 'F';
    if(strcmp(type, "string") == 0) return 'S';
    if(strcmp(type, "bool") == 0) return 'B';
    return 'N'; //not a type
}

static void error_check(char *a, char *b, char *op)
{

    if(strcmp(a, "undefined") == 0 || strcmp(b, "undefined") == 0)
    {
        return;
    }

    if(strcmp(op, "condition") == 0)
    {
        if(strcmp(a, "bool") != 0)
        {
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, a);
        }
        return;
    }

    if(strcmp(op, "REM") == 0)
    {
        if(strcmp(a, "int") != 0 || strcmp(b, "int") != 0)
        {
            printf("error:%d: invalid operation: (operator REM not defined on float)\n", yylineno);
        }
        return;
    }

    if(strcmp(op, "AND") == 0 || strcmp(op, "OR") == 0 )
    {
        if(strcmp(a, "bool") != 0)
        {
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", yylineno, op, a);
        }

        if(strcmp(b, "bool") != 0)
        {
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", yylineno, op, b);
        }
        return;
    }

    if(strcmp(a, b) != 0)
    {
        if(strcmp(a, "array") == 0 || strcmp(b, "array") == 0)
        {
            return;
        }
        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, op, a, b);
    }
}
