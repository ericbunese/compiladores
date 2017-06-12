/* -------------------------------------------------------------------
 *            Arquivo: compilaodr.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, prot�tipos e vai�veis globais do compilador
 *
 * ------------------------------------------------------------------- */

#include "list.h"

#define TAM_TOKEN 16
//Categoria da tabela de símbolos: Variável Simples
#define TS_CAT_VS 0
//Categoria da tabela de símboloes: Parâmetro Formal
#define TS_CAT_PF 1
//Categoria da tabela de símbolos: Procedimento
#define TS_CAT_CP 2
//Categoria da tabela de símbolos: Função
#define TS_CAT_FU 3
//Tipo Integer
#define TS_TIP_INT 0
//Tipo Boolean
#define TS_TIP_BOO 1
//Tipo Maldito
#define TS_TIP_IMG 2
//Tipo de passagem de parâmetro: Valor
#define TS_PAR_VAL 0
//Tipo de passagem de parâmetro: Referência
#define TS_PAR_REF 1

typedef enum simbolos {
  simb_program, simb_var, simb_label, simb_begin, simb_end,
  simb_identificador, simb_numero,
  simb_ponto, simb_virgula, simb_ponto_e_virgula, simb_dois_pontos,
  simb_atribuicao, simb_abre_parenteses, simb_fecha_parenteses,
  simb_while, simb_do, simb_if, simb_then, simb_else, simb_procedure, simb_function,
  simb_igual, simb_menor, simb_menor_igual, simb_maior, simb_maior_igual, simb_dif,
  simb_and, simb_or, simb_mais, simb_menos, simb_div, simb_mod, simb_mult, simb_read, simb_write,
  simb_true, simb_false, simb_numeroI
} simbolos;

//Campos da tabela de símbolos para variáveis simples
typedef struct vsTs
{
 int deslocamento;
 int tipo;
}tVsTs;

//Campos da tabela de símbolos para parâmetros formais
typedef struct pfTs
{
 int deslocamento;
 int tipoPassagem;
 int tipo;
}tPfTs;

//Campos da tabela de símbolos para chamada de procedimentos
typedef struct cpTs
{
 char* rotulo;
 char* rotulo_saida;
 int nivel;
 int nParams;
 int* tipoPassagem;
}tCpTs;

//Campos da tabela de símbolos para chamada de função
typedef struct fuTs
{
 char* rotulo;
 char* rotulo_saida;
 int nivel;
 int nParams;
 int* tipoPassagem;
 int deslocamento;
 int tipoRetorno;
}tFuTs;

typedef struct simboloTs
{
 char* ident;
 int categoria;
 int nivel;
 union categoriaTs
 {
  tVsTs* v;
  tPfTs* p;
  tCpTs* c;
  tFuTs* f;
 }categoriaTs;
}tSimboloTs;

/* -------------------------------------------------------------------
 * vari�veis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;


simbolos simbolo, relacao;
char token[TAM_TOKEN];


int yylex();
void yyerror(const char *s);
void geraCodigo (char* rot, char* comando, char* arg1, char* arg2, char* arg3);
int imprimeErro(char* erro);

list criaTS();
void imprimeSimboloTS(tSimboloTs* t);
tSimboloTs* criaSimboloTS(char* rot, int categoria, int nivel);
tSimboloTs* criaSimboloTS_VS(char *rot, int categoria, int nivel, int deslocamento);
tSimboloTs* criaSimboloTS_CP(char* rot, int nivel, char* rotulo_chamada, char* rotulo_saida);
tSimboloTs* criaSimboloTS_FU(char* rot, int nivel, char* rotulo_chamada, char* rotulo_saida);
tSimboloTs* criaSimboloTS_PF(char* rot, int nivel, int tipo);

void atualizaSimboloTS_VS(tSimboloTs* s, int tipo);
void atualizaSimboloTS_PF(tSimboloTs* s, int deslocamento);
void atualizaSimboloTS_CP(tSimboloTs* s, int* tipoPassagem);
void atualizaSimboloTS_FU(tSimboloTs* s, int* tipoPassagem, int deslocamento, int tipoRetorno);

int insereTS(tSimboloTs* s);
tSimboloTs* buscaTS(char* rot);
void atualizaTS(int num, char token[TAM_TOKEN]);
int removeTS(int s);
char *intToStr(int n);
char *catTS(int categoria);
char *tipoTS(int tipo);
char *tipoPassagemTS(int tipo);

char* geraRotulo();
void imprimeTS();

void chamaFuncao(char* token);
void chamaProcedimento(char *token);
void empilhaTipoPassagemParametro();
void imprimeAlt();
void empilhaString(char *str1, list l);


void empilhaTipo(int tipo);
void consomeTipo(int limpar, int ehMult);
