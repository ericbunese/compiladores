
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

int num_vars, contVar, totalVar;
int maxRotulo;
int nivelLexico;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token WHILE DO IF THEN ELSE
%token IGUAL

%%

programa    :{
              geraCodigo (NULL, "INPP", NULL, NULL, NULL);
              nivelLexico = 0;
             }
             PROGRAM IDENT
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO
             {
              geraCodigo (NULL, "PARA", NULL, NULL, NULL);
             }
;

bloco       : {totalVar = 0}
              parte_declara_vars
              {

              }

              comando_composto
              {
                geraCodigo (NULL, "DMEM", &totalVar, NULL, NULL)
              }
;




parte_declara_vars:  var
                  |  parte_declara_vars var
;


var         : { } VAR declara_vars
            |
;

declara_vars: declara_vars declara_var
            | declara_var
;

declara_var : {contVar = 0}
              lista_id_var DOIS_PONTOS
              tipo
              {
                geraCodigo (NULL, "AMEM", &contVar, NULL, NULL);
                atualizaTS(contVar, token);
              }
              PONTO_E_VIRGULA
;

tipo        : IDENT
;

lista_id_var: lista_id_var VIRGULA IDENT
              { contVar++; totalVar++ /* insere �ltima vars na tabela de s�mbolos */ }
            | IDENT { contVar++ ; totalVar++ /* insere vars na tabela de s�mbolos */}
;

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto: T_BEGIN comandos T_END

comandos: comando | comandos comando
;

comando: comando_sem_rotulo
      |  IDENT DOIS_PONTOS comando_sem_rotulo
;

comando_sem_rotulo:  regra_atribuicao
                  |  regra_condicional
                  |  regra_while
;

regra_atribuicao: IDENT ATRIBUICAO IDENT PONTO_E_VIRGULA
;

regra_condicional: IF expressao THEN {printf("*");} comando_sem_rotulo
;

regra_while: WHILE
    { //gera
    }
expressao DO comando_sem_rotulo
;

expressao: IDENT IGUAL IDENT
;

%%

//Gera rótulo
char* geraRotulo()
{
 char* rot;
 rot = (char*)malloc(sizeof(char)*10);
 sprintf(rot, "R%5.0d", maxRotulo++);
 for (int i=0;i<9;++i)
 {
  if (rot[i]==' ')
   rot[i] = '0';
 }
 return rot;
}

/// Programa principal

int yylex ();
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

 /* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */

 yyin=fp;
 yyparse();

 return 0;
}
