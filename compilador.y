
// Testar se funciona corretamente o empilhamento de parâmetros
// passados por valor ou por referência.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

int num_vars, contVar, totalVar;
int maxRotulo;
int nivelLexico, deslocamento;
char* elementoEsquerda;
list TS;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES 
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR LABEL IDENT NUMERO ATRIBUICAO
%token WHILE DO IF THEN ELSE
%token IGUAL MENOR MENOR_IGUAL MAIOR MAIOR_IGUAL DIF

%%

programa    :{ 
             geraCodigo (NULL, "INPP", NULL, NULL, NULL); 
             }
             PROGRAM IDENT 
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO {
             geraCodigo (NULL, "PARA", NULL, NULL, NULL); 
             }
;

bloco       : 
              parte_declara_coisas
              comando_composto 
;

parte_declara_coisas: parte_declara_coisas parte_declara_vars
                    | parte_declara_coisas parte_declara_rotulos
                    |
;   

parte_declara_rotulos: label
                     | parte_declara_rotulos label
;

label: LABEL declara_labels
     |
;

declara_labels: declara_labels declara_label
              | declara_label
;

declara_label: lista_id_label PONTO_E_VIRGULA
;

lista_id_label: lista_id_label VIRGULA NUMERO 
              { /* insere última label na tabela de símbolos */ }
              | NUMERO { /* insere label na tabela de símbolos */}
;

parte_declara_vars:  var 
                  |  parte_declara_vars var
;

var: VAR declara_vars
   |
;

declara_vars: declara_vars declara_var 
            | declara_var 
;

declara_var : lista_id_var DOIS_PONTOS 
              tipo 
              { /* AMEM */
              }
              PONTO_E_VIRGULA
;

tipo        : IDENT
;

lista_id_var: lista_id_var VIRGULA IDENT 
              { /* insere última vars na tabela de símbolos */ }
            | IDENT { /* insere vars na tabela de símbolos */}
;

lista_idents: lista_idents VIRGULA IDENT  
            | IDENT
;


comando_composto: T_BEGIN comandos T_END 
                | comando
;

comandos: comando
        | comandos PONTO_E_VIRGULA comando   
;

comando: rotulo comando_sem_rotulo
       | comando_sem_rotulo
;

rotulo: NUMERO DOIS_PONTOS
;

comando_sem_rotulo: regra_if
                  | regra_while
                  | IDENT regra_ident
;

regra_if: IF expressao THEN comando_composto talveztemelse
;

talveztemelse: PONTO_E_VIRGULA
             | ELSE comando_composto
;

regra_while: WHILE
    { //gera
    }
    expressao DO comando_composto
;

regra_ident: ATRIBUICAO variavel
           | ABRE_PARENTESES lista_idents FECHA_PARENTESES
;

variavel: NUMERO
        | IDENT
;

expressao: variavel compara variavel
         | ABRE_PARENTESES expressao FECHA_PARENTESES
;

compara: IGUAL | MENOR | MENOR_IGUAL | MAIOR | MAIOR_IGUAL | DIF
;

%%

int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos
 * ------------------------------------------------------------------- */

   yyin=fp;
   yyparse();

   return 0;
}

