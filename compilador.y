%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

int num_vars, contVar, totalVar;
int maxRotulo;
int nivelLexico, deslocamento;
char elementoEsquerda[TAM_TOKEN];
list TS;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR LABEL IDENT NUMERO ATRIBUICAO
%token WHILE DO IF THEN ELSE PROCEDURE
%token IGUAL MENOR MENOR_IGUAL MAIOR MAIOR_IGUAL DIF

%%

programa    :{
              geraCodigo (NULL, "INPP", NULL, NULL, NULL);
             }
             PROGRAM IDENT
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO
             {
              geraCodigo (NULL, "PARA", NULL, NULL, NULL);
             }
;

bloco       : {totalVar = 0}
              parte_declara_coisas
              comando_composto
              {
               if (totalVar>0)
                   geraCodigo (NULL, "DMEM", &totalVar, NULL, NULL)
              }
;

parte_declara_coisas: parte_declara_coisas parte_declara_vars
                    | parte_declara_coisas parte_declara_labels
                    | parte_declara_coisas parte_declara_procedures
                    |
;

parte_declara_procedures: procedure
                          | parte_declara_procedures procedure
;

procedure: PROCEDURE declara_procedure
           |
;

declara_procedure: IDENT ABRE_PARENTESES lista_id_parametros FECHA_PARENTESES PONTO_E_VIRGULA bloco
;

lista_id_parametros: lista_id_parametros VIRGULA parametros
                   | parametros
;

parametros: IDENT DOIS_PONTOS tipo
          | VAR IDENT DOIS_PONTOS tipo
;

parte_declara_labels: label
                     | parte_declara_labels label
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
              {
               contVar++;
               totalVar++;
               criaSimboloTS_VS(token, TS_CAT_VS, nivelLexico, totalVar-1)
              }
            | IDENT
              {
               contVar++;
               totalVar++;
               criaSimboloTS_VS(token, TS_CAT_VS, nivelLexico, totalVar-1)
              }
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

   yyin=fp;
   yyparse();

   printf("\n\nTABELA DE SÍMBOLOS\n");
   for (node n=list_first(TS); n; n=list_next(n))
   {
    tSimboloTs* t = list_value(n);
    imprimeSimboloTS(t);
   }

   return 0;
}
