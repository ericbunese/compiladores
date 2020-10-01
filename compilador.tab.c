/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compilador.y" /* yacc.c:339  */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

//num_vars: Total de variáveis no programa
int num_vars;
//contVar: Total de variáveis na linha
int contVar, contVar2;
//totalVar[i]: Total de variáveis no nível léxico i
int totalVar[10];
//nivelLexico, deslocamento: variáveis de controle de endereçamento.
int nivelLexico, deslocamento;
//elementoEsquerda: nome do token à esquerda em atribuições, chamadas de função, etc.
char elementoEsquerda[TAM_TOKEN];
//TS: Tabela de Símbolos.
list TS;
//parametroAtual: indica qual a posição do parametro atual.
int parametroAtual;
//ehPassagemParametro: indica se a variável lida deve ser considerada como passagem de parâmetro.
int ehPassagemParametro;

list pilhona;
list parametros;
list parametros2;
list pilhaTipo;

// to deal with - expression
int countTermo[1000];
int nivelExpressao;


#line 101 "compilador.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compilador.tab.h".  */
#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
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
    PROGRAM = 258,
    ABRE_PARENTESES = 259,
    FECHA_PARENTESES = 260,
    VIRGULA = 261,
    PONTO_E_VIRGULA = 262,
    DOIS_PONTOS = 263,
    PONTO = 264,
    T_BEGIN = 265,
    T_END = 266,
    VAR = 267,
    LABEL = 268,
    IDENT = 269,
    NUMERO = 270,
    ATRIBUICAO = 271,
    WHILE = 272,
    DO = 273,
    IF = 274,
    THEN = 275,
    ELSE = 276,
    PROCEDURE = 277,
    FUNCTION = 278,
    IGUAL = 279,
    MENOR = 280,
    MENOR_IGUAL = 281,
    MAIOR = 282,
    MAIOR_IGUAL = 283,
    DIF = 284,
    MAIS = 285,
    MENOS = 286,
    AND = 287,
    OR = 288,
    MULT = 289,
    DIV = 290,
    MOD = 291,
    READ = 292,
    WRITE = 293,
    T_TRUE = 294,
    T_FALSE = 295,
    NUMEROI = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 194 "compilador.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    48,    59,    63,    59,    76,    77,    78,
      79,    80,    87,    91,   108,   138,   153,    90,   174,   178,
     195,   225,   229,   254,   177,   275,   275,   276,   279,   280,
     283,   283,   284,   287,   321,   357,   368,   384,   385,   388,
     389,   392,   393,   396,   399,   401,   408,   409,   412,   413,
     416,   417,   420,   423,   420,   432,   435,   441,   449,   450,
     457,   458,   461,   462,   462,   465,   466,   467,   470,   473,
     474,   475,   475,   476,   477,   478,   481,   484,   507,   535,
     544,   548,   553,   559,   534,   569,   579,   578,   597,   607,
     611,   616,   596,   636,   691,   690,   727,   748,   749,   758,
     759,   760,   760,   764,   763,   808,   896,   895,   901,   901,
     906,   907,   910,   910,   913,   913,   919,   922,   922,   924,
     923,   943,   948,   948,   967,   968,   969,   972,   975,   976,
     979,   980,   981,   984,   985,   988,   988,   989,   989,   990,
     990
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "LABEL", "IDENT", "NUMERO", "ATRIBUICAO",
  "WHILE", "DO", "IF", "THEN", "ELSE", "PROCEDURE", "FUNCTION", "IGUAL",
  "MENOR", "MENOR_IGUAL", "MAIOR", "MAIOR_IGUAL", "DIF", "MAIS", "MENOS",
  "AND", "OR", "MULT", "DIV", "MOD", "READ", "WRITE", "T_TRUE", "T_FALSE",
  "NUMEROI", "$accept", "programa", "$@1", "bloco", "$@2", "$@3",
  "parte_declara_coisas", "parte_declara_procedures", "declara_procedure",
  "$@4", "$@5", "$@6", "$@7", "parte_declara_functions",
  "declara_function", "$@8", "$@9", "$@10", "$@11", "$@12",
  "lista_parametros", "$@13", "lista_id_parametros",
  "lista_id_parametros3", "$@14", "lista_id_parametros2", "id_parametros",
  "parte_declara_labels", "label", "declara_labels", "declara_label",
  "lista_id_label", "parte_declara_vars", "var", "declara_vars",
  "declara_var", "$@15", "$@16", "tipo", "lista_id_var", "lista_idents",
  "comando_composto", "comandos", "$@17", "comando", "rotulo",
  "comando_sem_rotulo", "$@18", "regra_comentario", "lista_ids_read",
  "regra_if", "$@19", "$@20", "$@21", "$@22", "$@23", "talveztemelse",
  "$@24", "regra_while", "$@25", "$@26", "$@27", "$@28", "regra_ident",
  "$@29", "variavel", "$@30", "variavel2", "$@31", "lista_expressoes_call",
  "$@32", "$@33", "lista_expressoes_write", "expressao_completa", "$@34",
  "expressao_completa2", "$@35", "expressao", "$@36", "$@37", "expressao2",
  "$@38", "termo", "termo_intermediario", "termo2", "fator", "compara", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -179

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-179)))

#define YYTABLE_NINF -53

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -179,    24,     1,  -179,    -5,    51,    14,  -179,    46,    54,
      64,  -179,  -179,    56,  -179,  -179,    44,    12,  -179,    73,
      78,    90,  -179,  -179,    92,  -179,    94,  -179,    79,  -179,
     100,  -179,  -179,   106,   107,   105,  -179,    26,  -179,  -179,
    -179,    99,  -179,   101,  -179,    73,  -179,    41,  -179,  -179,
    -179,  -179,  -179,  -179,    84,    42,  -179,  -179,  -179,   102,
      38,  -179,   108,  -179,  -179,  -179,     9,  -179,   103,  -179,
     113,   113,   115,  -179,  -179,    38,  -179,  -179,  -179,  -179,
      89,  -179,  -179,    91,  -179,    29,    -2,    12,  -179,   109,
     110,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,    38,
    -179,  -179,   111,  -179,  -179,  -179,    38,    -2,    -2,    -2,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,    45,  -179,
    -179,  -179,  -179,     8,   114,   118,    93,    38,   104,    47,
     112,  -179,    29,    29,  -179,  -179,  -179,  -179,   122,   124,
      -2,    -2,    -2,  -179,  -179,   123,   117,  -179,   128,   127,
      81,  -179,   110,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,    38,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,    85,  -179,  -179,  -179,   121,   110,  -179,
    -179,    38,     4,  -179,     4,  -179,   110,     8,  -179,  -179,
    -179,   129,  -179,    12,  -179,  -179,  -179,  -179,    95,  -179,
    -179,   130,  -179,     0,   119,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,     4,   131,  -179,  -179
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    59,     0,     0,
       0,     4,    58,     0,    11,     3,     0,    67,    52,     0,
       0,     0,     9,    10,     8,    37,     7,    46,     0,    71,
       0,    88,    79,     0,     0,     5,    62,     0,    66,    69,
      70,    48,    51,     0,    45,    39,    42,     0,    13,    12,
      19,    18,    38,    47,     0,    96,    68,    89,    80,     0,
     122,    63,     0,    65,    50,    57,     0,    41,     0,    43,
      27,    27,     0,    75,    94,   122,    72,   112,   112,    77,
       0,   117,   119,     0,   111,   121,     0,    67,     6,     0,
       0,    44,    25,    14,    20,    76,   108,    93,    90,   122,
      81,    73,     0,   122,   122,    74,   122,     0,     0,     0,
     112,   101,    97,    99,   100,    98,   133,   123,   129,    64,
      56,    55,    53,    29,     0,     0,     0,   122,     0,   116,
       0,    78,   118,   120,   110,   124,   125,   126,     0,   105,
       0,     0,     0,   127,   128,     0,     0,    36,     0,    32,
       0,    15,     0,    95,   106,   109,    91,   135,   136,   137,
     138,   139,   140,   113,   122,    82,   134,   103,   102,   132,
     130,   131,    54,     0,    26,    30,    28,     0,     0,     4,
      21,   122,    67,   114,    67,   108,     0,    29,    35,    34,
      16,     0,   107,    67,    92,    61,   115,    83,     0,    33,
      31,     0,    22,     0,    85,   104,    17,     4,    60,    86,
      84,    23,    67,     0,    87,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,  -174,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
      58,  -179,   -48,  -179,  -179,  -179,    -4,  -179,   120,  -179,
      96,  -179,  -179,   125,  -179,   116,  -179,  -179,  -142,  -179,
    -179,  -178,   -50,  -179,   -17,  -179,   126,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,   -40,
    -179,  -179,  -179,   -75,  -179,  -179,  -179,   -74,  -179,  -179,
      -1,  -179,   -26,  -179,  -179,   -56,  -179
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,    14,    62,    16,    22,    49,    70,
     124,   179,   201,    23,    51,    71,   125,   191,   207,   213,
      93,   123,   148,   176,   187,   149,   150,    24,    25,    45,
      46,    47,    26,    27,    41,    42,    43,   145,   122,    66,
       8,   194,    35,    87,   195,    37,    38,    55,    73,    80,
      39,    58,    78,   130,   184,   204,   210,   212,    40,    57,
      77,   128,   182,    76,    96,   116,   139,   168,   185,   126,
     181,   127,    83,    98,    99,   163,   196,    84,   103,   104,
      85,    86,   117,   143,   144,   118,   164
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    97,   110,   100,     4,   190,   197,    61,    28,     5,
     180,   208,   111,   112,   193,    89,    28,    90,    29,    30,
     146,    31,   147,    32,     3,   129,    29,    30,     7,    31,
      28,    32,   134,   211,   214,   138,   189,   113,   114,   115,
      29,    33,    34,    31,   199,    32,    74,    68,    69,    33,
      34,     9,    10,   155,    17,     6,    18,    19,    75,   107,
     108,    11,   109,    33,    34,    15,    20,    21,    81,    82,
     119,   157,   158,   159,   160,   161,   162,   140,    12,   141,
     142,   135,   136,   137,   169,   170,   171,   177,    44,   178,
     183,   177,    48,   186,   101,   102,   105,   106,   153,   154,
     205,   154,   132,   133,    50,    19,    18,   192,    56,    54,
      59,    60,    61,   -52,    72,    65,    79,    92,    91,    88,
      95,   151,   156,   120,   121,   131,   152,   166,   167,    94,
     172,   147,   165,   174,   175,   188,   202,   206,   215,   200,
     209,    67,   173,   203,    52,   198,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,    64,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36
};

static const yytype_int16 yycheck[] =
{
      17,    75,     4,    78,     3,   179,   184,     7,     4,    14,
     152,    11,    14,    15,    10,     6,     4,     8,    14,    15,
      12,    17,    14,    19,     0,    99,    14,    15,    14,    17,
       4,    19,   106,   207,   212,   110,   178,    39,    40,    41,
      14,    37,    38,    17,   186,    19,     4,     6,     7,    37,
      38,     5,     6,   127,    10,     4,    12,    13,    16,    30,
      31,     7,    33,    37,    38,     9,    22,    23,    30,    31,
      87,    24,    25,    26,    27,    28,    29,    32,    14,    34,
      35,   107,   108,   109,   140,   141,   142,     6,    15,     8,
     164,     6,    14,     8,     5,     6,     5,     6,     5,     6,
       5,     6,   103,   104,    14,    13,    12,   181,     8,    30,
       4,     4,     7,    14,    30,    14,    14,     4,    15,    11,
       5,     7,    18,    14,    14,    14,     8,     5,     4,    71,
       7,    14,    20,     5,     7,    14,     7,     7,     7,   187,
      21,    45,   146,   193,    24,   185,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    44,     0,     3,    14,     4,    14,    82,     5,
       6,     7,    14,    45,    46,     9,    48,    10,    12,    13,
      22,    23,    49,    55,    69,    70,    74,    75,     4,    14,
      15,    17,    19,    37,    38,    84,    86,    87,    88,    92,
     100,    76,    77,    78,    15,    71,    72,    73,    14,    50,
      14,    56,    70,    75,    30,    89,     8,   101,    93,     4,
       4,     7,    47,    88,    77,    14,    81,    72,     6,     7,
      51,    57,    30,    90,     4,    16,   105,   102,    94,    14,
      91,    30,    31,   114,   119,   122,   123,    85,    11,     6,
       8,    15,     4,    62,    62,     5,   106,   119,   115,   116,
     115,     5,     6,   120,   121,     5,     6,    30,    31,    33,
       4,    14,    15,    39,    40,    41,   107,   124,   127,    86,
      14,    14,    80,    63,    52,    58,   111,   113,   103,   119,
      95,    14,   122,   122,   119,   124,   124,   124,   115,   108,
      32,    34,    35,   125,   126,    79,    12,    14,    64,    67,
      68,     7,     8,     5,     6,   119,    18,    24,    25,    26,
      27,    28,    29,   117,   128,    20,     5,     4,   109,   127,
     127,   127,     7,    68,     5,     7,    65,     6,     8,    53,
      80,   112,   104,   119,    96,   110,     8,    66,    14,    80,
      45,    59,   119,    10,    83,    86,   118,    83,   111,    80,
      64,    54,     7,    84,    97,     5,     7,    60,    11,    21,
      98,    45,    99,    61,    83,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    43,    46,    47,    45,    48,    48,    48,
      48,    48,    49,    51,    52,    53,    54,    50,    55,    57,
      58,    59,    60,    61,    56,    63,    62,    62,    64,    64,
      66,    65,    65,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    78,    79,    77,    80,    81,    81,    82,    82,
      83,    83,    84,    85,    84,    86,    86,    86,    87,    88,
      88,    89,    88,    88,    88,    88,    90,    91,    91,    93,
      94,    95,    96,    97,    92,    98,    99,    98,   101,   102,
     103,   104,   100,   105,   106,   105,   105,   107,   107,   107,
     107,   108,   107,   110,   109,   109,   112,   111,   113,   111,
     114,   114,   116,   115,   118,   117,   117,   120,   119,   121,
     119,   119,   123,   122,   122,   122,   122,   124,   125,   125,
     126,   126,   126,   127,   127,   128,   128,   128,   128,   128,
     128
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     0,     0,     6,     2,     2,     2,
       2,     0,     2,     0,     0,     0,     0,     9,     2,     0,
       0,     0,     0,     0,    12,     0,     4,     0,     2,     0,
       0,     3,     0,     4,     3,     3,     1,     1,     2,     2,
       0,     2,     1,     2,     3,     1,     1,     2,     2,     0,
       2,     1,     0,     0,     6,     1,     3,     1,     3,     1,
       3,     1,     1,     0,     4,     2,     1,     0,     2,     1,
       1,     0,     3,     4,     4,     3,     2,     1,     3,     0,
       0,     0,     0,     0,    10,     0,     0,     3,     0,     0,
       0,     0,     8,     2,     0,     4,     0,     1,     1,     1,
       1,     0,     3,     0,     4,     0,     0,     4,     0,     2,
       3,     1,     0,     3,     0,     3,     0,     0,     3,     0,
       3,     1,     0,     2,     3,     3,     3,     2,     1,     0,
       2,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 48 "compilador.y" /* yacc.c:1646  */
    {
              geraCodigo(NULL, "INPP", NULL, NULL, NULL);
             }
#line 1445 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 54 "compilador.y" /* yacc.c:1646  */
    {
              geraCodigo(NULL, "PARA", NULL, NULL, NULL);
             }
#line 1453 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 59 "compilador.y" /* yacc.c:1646  */
    {totalVar[nivelLexico] = 0;}
#line 1459 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 63 "compilador.y" /* yacc.c:1646  */
    {
               //Desaloca variáveis locais do bloco.
               if (totalVar[nivelLexico]>0)
               {
                char str[TAM_TOKEN];
                sprintf(str, "%d", totalVar[nivelLexico]);
                geraCodigo(NULL, "DMEM", str, NULL, NULL);
               }
               //Remove funções e procedimentos deste nível léxico da TS:
              }
#line 1474 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 91 "compilador.y" /* yacc.c:1646  */
    {
                    char rotulo[10], rotuloSaida[10];
                    strcpy(rotuloSaida, geraRotulo());
                    strcpy(rotulo, geraRotulo());
                    char str[TAM_TOKEN];
                    sprintf(str, "%d", nivelLexico);
                    tSimboloTs* ss = criaSimboloTS_CP(token, nivelLexico, rotulo, rotuloSaida);
                    //Empilha o símbolo na pilhona, assim fica mais fácil acessar...
                    list_push(ss, pilhona);
                    //Empilha o vetor de tipo de passagem de parâmetros
                    int* params=(int*)malloc(sizeof(int));
                    list_push(params, pilhona);
                    geraCodigo(NULL, "DSVS", rotuloSaida, NULL, NULL);
                    geraCodigo(rotulo, "ENPR", str, NULL, NULL);
                    nivelLexico++;
                   }
#line 1495 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 108 "compilador.y" /* yacc.c:1646  */
    {
                    //atualiza nParams na TS.
                    node n = list_next(list_first(pilhona));
                    tSimboloTs* ss = list_value(n);
                    if (ss)
                    {
                     if (ss->categoria == TS_CAT_CP)
                     {
                      ss->categoriaTs.c->nParams = contVar;
                     }
                    }
                    //Agora atualiza os símbolos de parâmetros com seus deslocamentos.
                    node c = list_next(list_first(pilhona));
                    tSimboloTs* sp = list_value(c);
                    if (sp && sp->categoria == TS_CAT_CP)
                    {
                     int np = sp->categoriaTs.c->nParams, i=-4;
                     while(np>0)
                     {
                      node n = list_pop(parametros);
                      tSimboloTs* ss = list_value(n);
                      if (ss && ss->categoria == TS_CAT_PF)
                      {
                       ss->categoriaTs.p->deslocamento = i--;
                      }
                      np--;
                     }
                    }
                   }
#line 1529 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 138 "compilador.y" /* yacc.c:1646  */
    {
                    node p = list_pop(pilhona);
                    node n = list_first(pilhona);
                    int* params;
                    params = list_value(p);
                    tSimboloTs* ss = list_value(n);
                    if (ss)
                    {
                     if (ss->categoria == TS_CAT_CP)
                     {
                      atualizaSimboloTS_CP(ss, params);
                     }
                    }
                   }
#line 1548 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "compilador.y" /* yacc.c:1646  */
    {
                    node n = list_pop(pilhona);
                    tSimboloTs* ss = list_value(n);
                    if (ss)
                    {
                     if (ss->categoria == TS_CAT_CP)
                     {
                      char str1[TAM_TOKEN], str2[TAM_TOKEN];
                      removeTS(totalVar[nivelLexico]);
                      nivelLexico--;
                      sprintf(str1, "%d", nivelLexico);
                      sprintf(str2, "%d", ss->categoriaTs.c->nParams);
                      geraCodigo(NULL, "RTPR", str1, str2, NULL);
                      geraCodigo(ss->categoriaTs.c->rotulo_saida, "NADA", NULL, NULL, NULL);
                     }
                    }
                    imprimeTS();
                   }
#line 1571 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 178 "compilador.y" /* yacc.c:1646  */
    {
                   char rotulo[10], rotuloSaida[10];
                   strcpy(rotuloSaida, geraRotulo());
                   strcpy(rotulo, geraRotulo());
                   char str[TAM_TOKEN];
                   sprintf(str, "%d", nivelLexico);
                   tSimboloTs* ss = criaSimboloTS_FU(token, nivelLexico, rotulo, rotuloSaida);
                   //Empilha o símbolo na pilhona, assim fica mais fácil acessar...
                   list_push(ss, pilhona);
                   //Empilha o vetor de tipo de passagem de parâmetros
                   int* params=(int*)malloc(sizeof(int));
                   list_push(params, pilhona);
                   geraCodigo(NULL, "DSVS", rotuloSaida, NULL, NULL);
                   geraCodigo(rotulo, "ENPR", str, NULL, NULL);
                   nivelLexico++;
                  }
#line 1592 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 195 "compilador.y" /* yacc.c:1646  */
    {
                   //atualiza nParams na TS.
                   node n = list_next(list_first(pilhona));
                   tSimboloTs* ss = list_value(n);
                   if (ss)
                   {
                    if (ss->categoria == TS_CAT_FU)
                    {
                     ss->categoriaTs.f->nParams = contVar;
                    }
                   }
                   //Agora atualiza os símbolos de parâmetros com seus deslocamentos.
                   node c = list_next(list_first(pilhona));
                   tSimboloTs* sp = list_value(c);
                   if (sp && sp->categoria == TS_CAT_FU)
                   {
                    int np = sp->categoriaTs.f->nParams, i=-4;
                    while(np>0)
                    {
                     node n = list_pop(parametros);
                     tSimboloTs* ss = list_value(n);
                     if (ss && ss->categoria == TS_CAT_PF)
                     {
                      ss->categoriaTs.p->deslocamento = i--;
                     }
                     np--;
                    }
                   }
                  }
#line 1626 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 225 "compilador.y" /* yacc.c:1646  */
    {
                   empilhaString(token, pilhona);
                  }
#line 1634 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "compilador.y" /* yacc.c:1646  */
    {
                   node t = list_pop(pilhona);
                   char *tipo = list_value(t);
                   node p = list_pop(pilhona);
                   node n = list_first(pilhona);
                   int* params;
                   int tp;
                   params = list_value(p);
                   tSimboloTs* ss = list_value(n);
                   if (ss)
                   {
                    if (ss->categoria == TS_CAT_FU)
                    {
                     if (strcmp(tipo, "integer")==0)
                      tp = TS_TIP_INT;
                     else if (strcmp(tipo, "boolean")==0)
                      tp = TS_TIP_BOO;
                     else if (strcmp(tipo, "imaginario")==0)
                      tp = TS_TIP_IMG;
                     else imprimeErro("Tipo Inválido\n");
                     atualizaSimboloTS_FU(ss, params, ss->categoriaTs.f->nParams*-1-4, tp);
                    }
                   }
                  }
#line 1663 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 254 "compilador.y" /* yacc.c:1646  */
    {
                   node n = list_pop(pilhona);
                   tSimboloTs* ss = list_value(n);
                   if (ss)
                   {
                    if (ss->categoria == TS_CAT_FU)
                    {
                     char str1[TAM_TOKEN], str2[TAM_TOKEN];
                     removeTS(totalVar[nivelLexico]);
                     nivelLexico--;
                     sprintf(str1, "%d", nivelLexico);
                     sprintf(str2, "%d", ss->categoriaTs.f->nParams);
                     geraCodigo(NULL, "RTPR", str1, str2, NULL);
                     geraCodigo(ss->categoriaTs.f->rotulo_saida, "NADA", NULL, NULL, NULL);
                    }
                   }
                   imprimeTS();
                  }
#line 1686 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 275 "compilador.y" /* yacc.c:1646  */
    {contVar = 0; contVar2 = 0;}
#line 1692 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 283 "compilador.y" /* yacc.c:1646  */
    {contVar2 = 0;}
#line 1698 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 288 "compilador.y" /* yacc.c:1646  */
    {
                       int tipo;
                       if (strcmp(token, "integer")==0)
                        tipo = TS_TIP_INT;
                       else if (strcmp(token, "boolean")==0)
                        tipo = TS_TIP_BOO;
                       else if (strcmp(token, "imaginario")==0)
                        tipo = TS_TIP_IMG;
                       else imprimeErro("Tipo Inválido\n");

                       node f = list_next(list_first(pilhona));
                       tSimboloTs* simbp = list_value(f);
                       node p = list_first(pilhona);
                       int* params;
                       params = list_value(p);
                       //list_push(ss, parametros);
                       node n;
                       char* nome;
                       tSimboloTs* ss;
                       for (int i=contVar-contVar2;i<contVar;++i)
                       {
                        n = list_pop(parametros2);
                        nome = list_value(n);
                        params[i] = TS_PAR_REF;
                        ss = criaSimboloTS_PF(nome, nivelLexico, tipo);
                        if (ss && ss->categoria == TS_CAT_PF)
                        {
                         ss->categoriaTs.p->tipoPassagem = TS_PAR_REF;
                         ss->categoriaTs.p->tipo = tipo;
                        }
                        list_push(ss, parametros);
                       }
                      }
#line 1736 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 322 "compilador.y" /* yacc.c:1646  */
    {
                       int tipo;
                       if (strcmp(token, "integer")==0)
                        tipo = TS_TIP_INT;
                       else if (strcmp(token, "boolean")==0)
                        tipo = TS_TIP_BOO;
                       else if (strcmp(token, "imaginario")==0)
                        tipo = TS_TIP_IMG;
                       else imprimeErro("Tipo Inválido\n");

                       node f = list_next(list_first(pilhona));
                       tSimboloTs* simbp = list_value(f);
                       node p = list_first(pilhona);
                       int* params;
                       params = list_value(p);
                       //list_push(ss, parametros);
                       node n;
                       char* nome;
                       tSimboloTs* ss;
                       for (int i=contVar-contVar2;i<contVar;++i)
                       {
                        n = list_pop(parametros2);
                        nome = list_value(n);
                        params[i] = TS_PAR_VAL;
                        ss = criaSimboloTS_PF(nome, nivelLexico, tipo);
                        if (ss && ss->categoria == TS_CAT_PF)
                        {
                         ss->categoriaTs.p->tipoPassagem = TS_PAR_VAL;
                         ss->categoriaTs.p->tipo = tipo;
                        }
                        list_push(ss, parametros);
                       }
                      }
#line 1774 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 358 "compilador.y" /* yacc.c:1646  */
    {
               node p = list_first(pilhona);
               int* params = list_value(p);
               params = (int*)realloc(params, (1+contVar)*sizeof(int));
               params[contVar] = -1;
               contVar2++;
               contVar++;
               empilhaString(token, parametros2);
              }
#line 1788 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 369 "compilador.y" /* yacc.c:1646  */
    {
               node p = list_first(pilhona);
               int* params = list_value(p);
               params = (int*)realloc(params, (1+contVar)*sizeof(int));
               params[contVar] = -1;
               contVar2++;
               contVar++;
               empilhaString(token, parametros2);
              }
#line 1802 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 400 "compilador.y" /* yacc.c:1646  */
    { /* insere última label na tabela de símbolos */ }
#line 1808 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 401 "compilador.y" /* yacc.c:1646  */
    { /* insere label na tabela de símbolos */}
#line 1814 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 420 "compilador.y" /* yacc.c:1646  */
    {contVar = 0;}
#line 1820 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 423 "compilador.y" /* yacc.c:1646  */
    {
               char str[TAM_TOKEN];
               sprintf(str, "%d", contVar);
               geraCodigo (NULL, "AMEM", str, NULL, NULL);
               atualizaTS(contVar, token);
              }
#line 1831 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 436 "compilador.y" /* yacc.c:1646  */
    {
               contVar++;
               totalVar[nivelLexico]++;
               criaSimboloTS_VS(token, TS_CAT_VS, nivelLexico, totalVar[nivelLexico]-1);
              }
#line 1841 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 442 "compilador.y" /* yacc.c:1646  */
    {
               contVar++;
               totalVar[nivelLexico]++;
               criaSimboloTS_VS(token, TS_CAT_VS, nivelLexico, totalVar[nivelLexico]-1);
              }
#line 1851 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 461 "compilador.y" /* yacc.c:1646  */
    {printf("primeiro\n");}
#line 1857 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 462 "compilador.y" /* yacc.c:1646  */
    {printf("meio\n");}
#line 1863 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 475 "compilador.y" /* yacc.c:1646  */
    {printf("aqui\n");strcpy(elementoEsquerda, token);}
#line 1869 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 485 "compilador.y" /* yacc.c:1646  */
    {
                  tSimboloTs* ss = buscaTS(token);
                  //Verifica se o símbolo buscado existe.
                  if (ss)
                  {
                   if (ss->categoria == TS_CAT_VS)
                   {
                    char nl[TAM_TOKEN], ds[TAM_TOKEN];
                    sprintf(nl, "%d", ss->nivel);
                    sprintf(ds, "%d", ss->categoriaTs.v->deslocamento);
                    geraCodigo(NULL, "LEIT", NULL, NULL, NULL);
                    geraCodigo(NULL, "ARMZ", nl, ds, NULL);
                   }
                   else
                   {
                    char str[100];
                    sprintf(str, "O token %s não é de categoria válida\n", token);
                    imprimeErro(str);
                   }
                  }
                 }
#line 1895 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 508 "compilador.y" /* yacc.c:1646  */
    {
                  tSimboloTs* ss = buscaTS(token);
                  //Verifica se o símbolo buscado existe.
                  if (ss)
                  {
                   if (ss->categoria == TS_CAT_VS)
                   {
                    char nl[TAM_TOKEN], ds[TAM_TOKEN];
                    sprintf(nl, "%d", ss->nivel);
                    sprintf(ds, "%d", ss->categoriaTs.v->deslocamento);
                    geraCodigo(NULL, "LEIT", NULL, NULL, NULL);
                    geraCodigo(NULL, "ARMZ", nl, ds, NULL);
                   }
                   else
                   {
                    char str[100];
                    sprintf(str, "O token %s não é de categoria válida\n", token);
                    imprimeErro(str);
                   }
                  }
                 }
#line 1921 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 535 "compilador.y" /* yacc.c:1646  */
    {
           char* rotulo_else;
           rotulo_else = geraRotulo();
           char* rotulo_saida;
           rotulo_saida = geraRotulo();
           list_push(rotulo_saida, pilhona);
           list_push(rotulo_else, pilhona);
          }
#line 1934 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 544 "compilador.y" /* yacc.c:1646  */
    {
           empilhaTipo(TS_TIP_BOO);
          }
#line 1942 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 548 "compilador.y" /* yacc.c:1646  */
    {
           consomeTipo(1, 0);
          }
#line 1950 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 553 "compilador.y" /* yacc.c:1646  */
    {
           node e = list_first(pilhona);
           char* rotulo_else = list_value(e);
           geraCodigo(NULL, "DSVF", rotulo_else, NULL, NULL);
          }
#line 1960 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 559 "compilador.y" /* yacc.c:1646  */
    {
           node s = list_next(list_first(pilhona));
           char* rotulo_saida = list_value(s);
           node e = list_first(pilhona);
           char* rotulo_else = list_value(e);
           geraCodigo(NULL, "DSVS", rotulo_saida, NULL, NULL);
          }
#line 1972 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 566 "compilador.y" /* yacc.c:1646  */
    {printf("aqui sai do if\n");}
#line 1978 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 569 "compilador.y" /* yacc.c:1646  */
    {
                node e = list_pop(pilhona);
                node s = list_pop(pilhona);
                char *rotulo_saida = list_value(s);
                char *rotulo_else = list_value(e);
                geraCodigo(rotulo_else, "NADA", NULL, NULL, NULL);
                geraCodigo(NULL, "DSVS", rotulo_saida, NULL, NULL);
                geraCodigo(rotulo_saida, "NADA", NULL, NULL, NULL);
               }
#line 1992 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 579 "compilador.y" /* yacc.c:1646  */
    {
                node e = list_pop(pilhona);
                char *rotulo_else = list_value(e);
                geraCodigo(rotulo_else, "NADA", NULL, NULL, NULL);
               }
#line 2002 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 585 "compilador.y" /* yacc.c:1646  */
    {
                node s = list_pop(pilhona);
                char *rotulo_saida = list_value(s);
                geraCodigo(rotulo_saida, "NADA", NULL, NULL, NULL);
               }
#line 2012 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 597 "compilador.y" /* yacc.c:1646  */
    {
     char* rotulo_saida;
     rotulo_saida = geraRotulo();
     char* rotulo_entrada;
     rotulo_entrada = geraRotulo();
     list_push(rotulo_entrada, pilhona);
     list_push(rotulo_saida, pilhona);
     geraCodigo(rotulo_entrada, "NADA", NULL, NULL, NULL);
    }
#line 2026 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 607 "compilador.y" /* yacc.c:1646  */
    {
     empilhaTipo(TS_TIP_BOO);
    }
#line 2034 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 611 "compilador.y" /* yacc.c:1646  */
    {
     consomeTipo(1, 0);
    }
#line 2042 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 616 "compilador.y" /* yacc.c:1646  */
    {
     node s = list_first(pilhona);
     char* rotulo_saida = list_value(s);
     geraCodigo(NULL, "DSVF", rotulo_saida, NULL, NULL);
    }
#line 2052 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 622 "compilador.y" /* yacc.c:1646  */
    {
     node s = list_pop(pilhona);
     char* rotulo_saida = list_value(s);
     node e = list_pop(pilhona);
     char* rotulo_entrada = list_value(e);
     geraCodigo(NULL, "DSVS", rotulo_entrada, NULL, NULL);
     geraCodigo(rotulo_saida, "NADA", NULL, NULL, NULL);
    }
#line 2065 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 637 "compilador.y" /* yacc.c:1646  */
    {
              tSimboloTs* ss = buscaTS(elementoEsquerda);
              //Verifica se o símbolo buscado existe.
              if (ss)
              {
               if (ss->categoria == TS_CAT_VS)
               {
                char nl[TAM_TOKEN], ds[TAM_TOKEN];
                sprintf(nl, "%d", ss->nivel);
                sprintf(ds, "%d", ss->categoriaTs.v->deslocamento);
                geraCodigo(NULL, "ARMZ", nl, ds, NULL);

                empilhaTipo(ss->categoriaTs.v->tipo);
                consomeTipo(1, 0);
               }
               else if (ss->categoria == TS_CAT_PF)
               {
                if (ss->categoriaTs.p->tipoPassagem == TS_PAR_VAL)              //Escrita em PF - valor.
                {
                 char nl[TAM_TOKEN], ds[TAM_TOKEN];
                 sprintf(nl, "%d", ss->nivel);
                 sprintf(ds, "%d", ss->categoriaTs.p->deslocamento);
                 geraCodigo(NULL, "ARMZ", nl, ds, NULL);
                }
                else if (ss->categoriaTs.p->tipoPassagem == TS_PAR_REF)         //Escrita em PF - referência.
                {
                 char nl[TAM_TOKEN], ds[TAM_TOKEN];
                 sprintf(nl, "%d", ss->nivel);
                 sprintf(ds, "%d", ss->categoriaTs.p->deslocamento);
                 geraCodigo(NULL, "ARMI", nl, ds, NULL);
                }

                empilhaTipo(ss->categoriaTs.p->tipo);
                consomeTipo(1, 0);
               }
               else if (ss->categoria == TS_CAT_FU)                             //Escrita em valor de retorno de Função.
               {
                char nl[TAM_TOKEN], ds[TAM_TOKEN];
                sprintf(nl, "%d", ss->nivel+1);
                sprintf(ds, "%d", ss->categoriaTs.f->deslocamento);
                geraCodigo(NULL, "ARMZ", nl, ds, NULL);

                empilhaTipo(ss->categoriaTs.f->tipoRetorno);
                consomeTipo(1, 0);
               }
               else
               {
                char str[100];
                sprintf(str, "O token %s não é de categoria válida\n", token);
                imprimeErro(str);
               }
              }
             }
#line 2123 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 691 "compilador.y" /* yacc.c:1646  */
    {
              parametroAtual=0;
              char str[100];
              strcpy(str, elementoEsquerda);
              list_push(str, pilhona);

              tSimboloTs* ss = buscaTS(str);
              if (ss && ss->categoria == TS_CAT_FU)
              {
               geraCodigo(NULL, "AMEM 1", NULL, NULL, NULL);
              }
             }
#line 2140 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 704 "compilador.y" /* yacc.c:1646  */
    {
              node n = list_pop(pilhona);
              char *tok = list_value(n);
              tSimboloTs* ss = buscaTS(tok);
              if (ss)
              {
               if (ss->categoria == TS_CAT_CP)
               {
                chamaProcedimento(tok);
               }
               else if (ss->categoria == TS_CAT_FU)
               {
                chamaFuncao(tok);
               }
               else
               {
                char str[100];
                sprintf(str, "O token '%s' não é da categoria correta\n", tok);
                imprimeErro(str);
               }
              }
             }
#line 2167 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 727 "compilador.y" /* yacc.c:1646  */
    {
             tSimboloTs* ss = buscaTS(elementoEsquerda);
             //Verifica se o símbolo buscado existe.
             if (ss)
             {
              if (ss->categoria == TS_CAT_CP)
              {
               chamaProcedimento(elementoEsquerda);
              }
              else if (ss->categoria == TS_CAT_FU)
              {
               chamaFuncao(elementoEsquerda);
              }
              else
              {
               imprimeErro("Símbolo não encontrado.\n");
              }
             }
            }
#line 2191 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 748 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "CRCT", token, NULL, NULL); empilhaTipo(TS_TIP_INT);}
#line 2197 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 750 "compilador.y" /* yacc.c:1646  */
    {
           char str[TAM_TOKEN];
           int tam = strlen(token)-1;
           strncpy(str, token, tam);
           str[tam] = '\0';
           geraCodigo(NULL, "CRCT", str, NULL, NULL);
           empilhaTipo(TS_TIP_IMG);
          }
#line 2210 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 758 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "CRCT", "1", NULL, NULL); empilhaTipo(TS_TIP_BOO);}
#line 2216 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 759 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "CRCT", "0", NULL, NULL); empilhaTipo(TS_TIP_BOO);}
#line 2222 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 760 "compilador.y" /* yacc.c:1646  */
    {empilhaString(token, pilhona); }
#line 2228 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 764 "compilador.y" /* yacc.c:1646  */
    {
            parametroAtual=0;
            node n = list_first(pilhona);
            char *nome;
            nome = list_value(n);
            tSimboloTs* ss = buscaTS(nome);
            if (ss && ss->categoria == TS_CAT_FU)
            {
             geraCodigo(NULL, "AMEM 1", NULL, NULL, NULL);
             empilhaTipo(ss->categoriaTs.f->tipoRetorno);
            }
            list_push(nome, pilhona);
           }
#line 2246 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 778 "compilador.y" /* yacc.c:1646  */
    {
            node n = list_pop(pilhona);
            printf(".%p\n", n);
            char *tok = list_value(n);
            printf("->%s\n", tok);
            tSimboloTs* ss = buscaTS(tok);
            if (ss)
            {
             if (ss->categoria == TS_CAT_CP)
             {
              chamaProcedimento(tok);
             }
             else if (ss->categoria == TS_CAT_FU)
             {
              chamaFuncao(tok);
             }
             else
             {
              char str[100];
              sprintf(str, "O token '%s' não é da categoria correta\n", tok);
              imprimeErro(str);
             }
            }
            else
            {
             char *erro = "Símbolo não encontrado.\n";
             imprimeErro(erro);
            }
           }
#line 2280 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 808 "compilador.y" /* yacc.c:1646  */
    {
           node n = list_pop(pilhona);
           char *tok = list_value(n);
           tSimboloTs* ss = buscaTS(tok);
           //Verifica se o símbolo buscado existe.
           if (ss)
           {
            if (ss->categoria == TS_CAT_VS)
            {
             char nl[TAM_TOKEN], ds[TAM_TOKEN];
             sprintf(nl, "%d", ss->nivel);
             sprintf(ds, "%d", ss->categoriaTs.v->deslocamento);
             if (ehPassagemParametro)
             {
              node n = list_pop(parametros);
              int *tipop = list_value(n);
              if (tipop[parametroAtual] == TS_PAR_VAL)
              {
               geraCodigo(NULL, "CRVL", nl, ds, NULL);
              }
              else if (tipop[parametroAtual] == TS_PAR_REF)
              {
               geraCodigo(NULL, "CREN", nl, ds, NULL);
              }
             }
             else geraCodigo(NULL, "CRVL", nl, ds, NULL);

             empilhaTipo(ss->categoriaTs.v->tipo);
            }
            else if (ss->categoria == TS_CAT_PF)
            {
             if (ss->categoriaTs.p->tipoPassagem == TS_PAR_VAL)                 //Leitura em PF - Valor
             {
              char nl[TAM_TOKEN], ds[TAM_TOKEN];
              sprintf(nl, "%d", ss->nivel);
              sprintf(ds, "%d", ss->categoriaTs.p->deslocamento);
              if (ehPassagemParametro)
              {
               node n = list_pop(parametros);
               int* tipop = list_value(n);
               if (tipop[parametroAtual] == TS_PAR_VAL)
               {
                geraCodigo(NULL, "CRVL", nl, ds, NULL);
               }
               else if (tipop[parametroAtual] == TS_PAR_REF)
               {
                geraCodigo(NULL, "CREN", nl, ds, NULL);
               }
              }
              else geraCodigo(NULL, "CRVL", nl, ds, NULL);
             }
             else if (ss->categoriaTs.p->tipoPassagem == TS_PAR_REF)            //Leitura em PF - Referência
             {
              char nl[TAM_TOKEN], ds[TAM_TOKEN];
              sprintf(nl, "%d", ss->nivel);
              sprintf(ds, "%d", ss->categoriaTs.p->deslocamento);
              if (ehPassagemParametro)
              {
               node n = list_pop(parametros);
               int *tipop = list_value(n);
               if (tipop[parametroAtual] == TS_PAR_VAL)
               {
                geraCodigo(NULL, "CRVI", nl, ds, NULL);
               }
               else if (tipop[parametroAtual] == TS_PAR_REF)
               {
                geraCodigo(NULL, "CRVL", nl, ds, NULL);
               }
              }
              else geraCodigo(NULL, "CRVI", nl, ds, NULL);
             }

             empilhaTipo(ss->categoriaTs.p->tipo);
            }
            else
            {
             char str[100];
             sprintf(str, "O token %s não é de categoria válida\n", token);
             imprimeErro(str);
            }
           }
          }
#line 2367 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 896 "compilador.y" /* yacc.c:1646  */
    {
                        empilhaTipoPassagemParametro();
                       }
#line 2375 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 899 "compilador.y" /* yacc.c:1646  */
    { parametroAtual++; ehPassagemParametro=0; }
#line 2381 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 901 "compilador.y" /* yacc.c:1646  */
    {
                        empilhaTipoPassagemParametro();
                       }
#line 2389 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 904 "compilador.y" /* yacc.c:1646  */
    { parametroAtual++; ehPassagemParametro=0; }
#line 2395 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 906 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "IMPR", NULL, NULL, NULL);}
#line 2401 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 907 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "IMPR", NULL, NULL, NULL);}
#line 2407 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 910 "compilador.y" /* yacc.c:1646  */
    {}
#line 2413 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 913 "compilador.y" /* yacc.c:1646  */
    { consomeTipo(1, 0); empilhaTipo(TS_TIP_BOO); }
#line 2419 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 914 "compilador.y" /* yacc.c:1646  */
    {
                      node n = list_pop(pilhona);
                      char* func = list_value(n);
                      geraCodigo(NULL, func, NULL, NULL, NULL);
                     }
#line 2429 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 922 "compilador.y" /* yacc.c:1646  */
    {printf("aaa\n");}
#line 2435 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 924 "compilador.y" /* yacc.c:1646  */
    {

          // deals with minus signal before expression
          // since there may be an expression inside another expression (using parenthesis)
          // we must know in which level we are 
          nivelExpressao++;
          char str[1000];
          sprintf(str, "%s %s","CRCT","0"); 
          geraCodigo(NULL, str, NULL, NULL, NULL);
          // initialize with 1 so se know we have a minus signal to deal with
          countTermo[nivelExpressao] = 1;
        }
#line 2452 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 937 "compilador.y" /* yacc.c:1646  */
    {
          // restore to 0 since we already dealed with it
          countTermo[nivelExpressao] = 0;
          // decreases level
          nivelExpressao--;
        }
#line 2463 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 948 "compilador.y" /* yacc.c:1646  */
    {
                // only increments if it was initialized with one
                // that means only expression levels with minus signals will be incremented
                countTermo[nivelExpressao]+= countTermo[nivelExpressao] > 0;
          }
#line 2473 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 955 "compilador.y" /* yacc.c:1646  */
    {
              // decreases counter. 
              // We only generate the SUBT code if we're in the "first" term of the tree
              // i can explain this but it's too big an explanation to put in comments
              countTermo[nivelExpressao]-= countTermo[nivelExpressao] > 0;
              // if expression started with minus signal, generate SUBT code
              if (countTermo[nivelExpressao] == 1) 
              {
                geraCodigo(NULL, "SUBT", NULL, NULL, NULL);
              }

          }
#line 2490 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 967 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "SOMA", NULL, NULL, NULL); consomeTipo(0, 0);}
#line 2496 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 968 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "SUBT", NULL, NULL, NULL); consomeTipo(0, 0);}
#line 2502 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 969 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "DISJ", NULL, NULL, NULL); consomeTipo(0, 0);}
#line 2508 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 979 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "MULT", NULL, NULL, NULL); consomeTipo(1, 1);}
#line 2514 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 980 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "DIVI", NULL, NULL, NULL); consomeTipo(1, 1);}
#line 2520 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 981 "compilador.y" /* yacc.c:1646  */
    {geraCodigo(NULL, "CONJ", NULL, NULL, NULL); consomeTipo(0, 0);}
#line 2526 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 988 "compilador.y" /* yacc.c:1646  */
    {list_push("CMIG", pilhona);}
#line 2532 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 988 "compilador.y" /* yacc.c:1646  */
    {list_push("CMME", pilhona);}
#line 2538 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 989 "compilador.y" /* yacc.c:1646  */
    {list_push("CMEG", pilhona);}
#line 2544 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 989 "compilador.y" /* yacc.c:1646  */
    {list_push("CMMA", pilhona);}
#line 2550 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 990 "compilador.y" /* yacc.c:1646  */
    {list_push("CMAG", pilhona);}
#line 2556 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 990 "compilador.y" /* yacc.c:1646  */
    {list_push("CMDG", pilhona);}
#line 2562 "compilador.tab.c" /* yacc.c:1646  */
    break;


#line 2566 "compilador.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 997 "compilador.y" /* yacc.c:1906  */

void chamaFuncao(char *token)
{
 tSimboloTs* ss = buscaTS(token);
 if (ss)
 {
  if (ss->categoria == TS_CAT_FU)
  {
   char str[TAM_TOKEN];
   sprintf(str, "%d", nivelLexico);
   geraCodigo(NULL, "CHPR", ss->categoriaTs.f->rotulo, str, NULL);
  }
 }
}

void chamaProcedimento(char *token)
{
 tSimboloTs* ss = buscaTS(token);
 if (ss)
 {
  if (ss->categoria == TS_CAT_CP)
  {
   char str[TAM_TOKEN];
   sprintf(str, "%d", nivelLexico);
   geraCodigo(NULL, "CHPR", ss->categoriaTs.c->rotulo, str, NULL);
  }
 }
}

void empilhaTipoPassagemParametro()
{
 int* params;
 node n = list_first(pilhona);
 char* proced = list_value(n);
 printf("empilhaTipoPassagemParametro %s\n", proced);
 tSimboloTs* ss = buscaTS(proced);
 if (ss)
 {
  if (ss->categoria == TS_CAT_CP)                        //PROCEDURE
  {
   params = ss->categoriaTs.c->tipoPassagem;
  }
  else if (ss->categoria == TS_CAT_FU)                   //FUNCTION
  {
   params = ss->categoriaTs.f->tipoPassagem;
  }
  list_push(params, parametros);
  ehPassagemParametro = 1;
 }
}

void empilhaString(char *str1, list l)
{
 char *str2 = (char*)malloc(sizeof(char)*(strlen(str1)+1));
 strcpy(str2, str1);
 list_push(str2, l);
}

void empilhaTipo(int tipo)
{
 int *t = (int*)malloc(sizeof(int));
 *t = tipo;
 list_push(t, pilhaTipo);
}

void consomeTipo(int limpar, int ehMult)
{
 node n1 = list_pop(pilhaTipo);
 node n2 = list_pop(pilhaTipo);
 int *t1, *t2;
 t1 = list_value(n1);
 t2 = list_value(n2);
 if (*t1 == *t2)
 {
  if (!limpar)
      empilhaTipo(*t1);

  if (ehMult)
      empilhaTipo(TS_TIP_INT);
 }
 else
 {
  char str[100];
  sprintf(str, "Erro catastrófico com tipos: %s-%s\n", tipoTS(*t1), tipoTS(*t2));
  imprimeErro(str);
 }
}

int main (int argc, char** argv)
{
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2)
   {
    printf("usage compilador <arq>a %d\n", argc);
    return(-1);
   }

   fp=fopen (argv[1], "r");
   if (fp == NULL)
   {
    printf("usage compilador <arq>b\n");
    return(-1);
   }

   //Cria a tabela de símbolos.
   TS = criaTS();
   pilhona = list_new();
   parametros = list_new();
   parametros2 = list_new();
   pilhaTipo = list_new();
   ehPassagemParametro = 0;

   yyin=fp;
   yyparse();

   return 0;
}
