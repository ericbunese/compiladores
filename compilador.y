%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

//num_vars: Total de variáveis no programa
int num_vars;
//contVar: Total de variáveis na linha
int contVar;
//totalVar[i]: Total de variáveis no nível léxico i
int totalVar[10];
//nivelLexico, deslocamento: variáveis de controle de endereçamento.
int nivelLexico, deslocamento;
//elementoEsquerda: nome do token à esquerda em atribuições, chamadas de função, etc.
char elementoEsquerda[TAM_TOKEN];
//TS: Tabela de Símbolos.
list TS;

list pilhona = list_new();

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR LABEL IDENT NUMERO ATRIBUICAO
%token WHILE DO IF THEN ELSE PROCEDURE FUNCTION
%token IGUAL MENOR MENOR_IGUAL MAIOR MAIOR_IGUAL DIF
%token MAIS MENOS AND OR MULT DIV MOD
%token READ WRITE

%%

programa    :{
              geraCodigo(NULL, "INPP", NULL, NULL, NULL);
             }
             PROGRAM IDENT
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO
             {
              geraCodigo(NULL, "PARA", NULL, NULL, NULL);
             }
;

bloco       : {totalVar[nivelLexico] = 0}
              parte_declara_coisas
              comando_composto
              {
               if (totalVar[nivelLexico]>0)
               {
                char str[TAM_TOKEN];
                sprintf(str, "%d", totalVar[nivelLexico]);
                geraCodigo(NULL, "DMEM", str, NULL, NULL);
               }
              }
;

parte_declara_coisas: parte_declara_coisas parte_declara_vars
                    | parte_declara_coisas parte_declara_labels
                    | parte_declara_coisas parte_declara_procedures
                    | parte_declara_coisas parte_declara_functions
                    |
;

////////////////////////////////////////////////////////////////
// PROCEDURES E FUNCTIONS
////////////////////////////////////////////////////////////////

parte_declara_procedures: PROCEDURE declara_procedure
;

declara_procedure: IDENT
                   {
                    strcpy(elementoEsquerda, token);
                    char rotulo[10], rotuloSaida[10];
                    strcpy(rotuloSaida, geraRotulo());
                    strcpy(rotulo, geraRotulo());
                    char str[TAM_TOKEN];
                    sprintf(str, "%d", nivelLexico);
                    criaSimboloTS_CP(token, nivelLexico, rotulo, rotuloSaida);
                    geraCodigo(NULL, "DSVS", rotuloSaida, NULL, NULL);
                    geraCodigo(rotulo, "ENPR", str, NULL, NULL);
                   }
                   ABRE_PARENTESES {contVar = 0;} lista_id_parametros
                   {
                    //atualiza nParams na TS.
                    tSimboloTs* ss = buscaTS(elementoEsquerda);
                    if (ss)
                    {
                     if (ss->categoria == TS_CAT_CP)
                     {
                      ss->categoriaTs.c->nParams = contVar;
                     }
                    }
                   } FECHA_PARENTESES PONTO_E_VIRGULA
                   {
                    nivelLexico++;
                   }
                   bloco
                   {
                    imprimeTS();
                    tSimboloTs* ss = buscaTS(elementoEsquerda);
                    if (ss)
                    {
                     if (ss->categoria == TS_CAT_CP)
                     {
                      char str1[TAM_TOKEN], str2[TAM_TOKEN];
                      nivelLexico--;
                      sprintf(str1, "%d", nivelLexico);
                      sprintf(str2, "%d", ss->categoriaTs.c->nParams);
                      geraCodigo(NULL, "RTPR", str1, str2, NULL);
                      geraCodigo(ss->categoriaTs.c->rotulo_saida, "NADA", NULL, NULL, NULL);
                     }
                    }
                   }
;

parte_declara_functions: FUNCTION declara_function
;

declara_function: IDENT ABRE_PARENTESES lista_id_parametros FECHA_PARENTESES DOIS_PONTOS tipo PONTO_E_VIRGULA bloco
;

lista_id_parametros: lista_id_parametros VIRGULA parametros {contVar++;}
                   | parametros {contVar++;}
                   |
;

parametros: IDENT DOIS_PONTOS tipo
          | VAR IDENT DOIS_PONTOS tipo
;

////////////////////////////////////////////////////////////////
// LABELS
////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////
// VARIÁVEIS
////////////////////////////////////////////////////////////////

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
               char str[TAM_TOKEN];
               sprintf(str, "%d", contVar);
               geraCodigo (NULL, "AMEM", str, NULL, NULL);
               atualizaTS(contVar, token);
              }
              PONTO_E_VIRGULA
;

tipo        : IDENT
;

lista_id_var: lista_id_var VIRGULA IDENT
              {
               contVar++;
               totalVar[nivelLexico]++;
               criaSimboloTS_VS(token, TS_CAT_VS, nivelLexico, totalVar[nivelLexico]-1)
              }
            | IDENT
              {
               contVar++;
               totalVar[nivelLexico]++;
               criaSimboloTS_VS(token, TS_CAT_VS, nivelLexico, totalVar[nivelLexico]-1)
              }
;

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;

////////////////////////////////////////////////////////////////
// COMANDOS
////////////////////////////////////////////////////////////////

comando_composto: T_BEGIN comandos T_END
                | comando
;

comandos: comando
        | comandos PONTO_E_VIRGULA comando
        |
;

comando: rotulo comando_sem_rotulo
       | comando_sem_rotulo
;

rotulo: NUMERO DOIS_PONTOS
;

comando_sem_rotulo: regra_if
                  | regra_while
                  | IDENT {strcpy(elementoEsquerda, token);} regra_ident
                  | READ ABRE_PARENTESES IDENT {strcpy(elementoEsquerda, token);} FECHA_PARENTESES
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
                       geraCodigo(NULL, "LEIT", nl, ds, NULL);
                      }
                      else
                      {
                       char str[100];
                       sprintf(str, "O token %s não é da categoria Variável Simples\n", token);
                       imprimeErro(str);
                      }
                     }
                    }
                  | WRITE ABRE_PARENTESES lista_expressoes_write FECHA_PARENTESES
;

////////////////////////////////////////////////////////////////
// IF / IF THEN ELSE
////////////////////////////////////////////////////////////////

regra_if: IF expressao_completa THEN comando_composto talveztemelse
;

talveztemelse: PONTO_E_VIRGULA
             | ELSE comando_composto
;

////////////////////////////////////////////////////////////////
// WHILE
////////////////////////////////////////////////////////////////

regra_while: WHILE
    { //gera
    }
    expressao_completa DO comando_composto
;

////////////////////////////////////////////////////////////////
// REGRAS COM IDENTIFICADORES
////////////////////////////////////////////////////////////////

regra_ident: ATRIBUICAO expressao                                               //Atribuição.
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
                geraCodigo(NULL, "LEIT", nl, ds, NULL);
               }
               else
               {
                char str[100];
                sprintf(str, "O token %s não é da categoria Variável Simples\n", token);
                imprimeErro(str);
               }
              }
             }
           | ABRE_PARENTESES lista_idents FECHA_PARENTESES                      //Chamada Função ou procedimento.
;

variavel: NUMERO {geraCodigo(NULL, "CRCT", token, NULL, NULL);}
        | IDENT
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
             geraCodigo(NULL, "LEIT", nl, ds, NULL);
            }
            else
            {
             char str[100];
             sprintf(str, "O token %s não é da categoria Variável Simples\n", token);
             imprimeErro(str);
            }
           }
          }
;

////////////////////////////////////////////////////////////////
// EXPRESSÕES
////////////////////////////////////////////////////////////////

lista_expressoes_write: lista_expressoes_write VIRGULA expressao {geraCodigo(NULL, "IMPR", NULL, NULL, NULL);}
                      | expressao {geraCodigo(NULL, "IMPR", NULL, NULL, NULL);}
;

expressao_completa: expressao expressao_completa2
;

expressao_completa2: compara expressao
                   |
;

expressao: termo expressao_intermediaria
         |
;

expressao_intermediaria: expressao2
                       |
;

expressao2: MAIS termo {geraCodigo(NULL, "SOMA", NULL, NULL, NULL);}
          | MENOS termo {geraCodigo(NULL, "SUBT", NULL, NULL, NULL);}
          | AND termo {geraCodigo(NULL, "CONJ", NULL, NULL, NULL);}
;

termo: fator termo_intermediario
;

termo_intermediario: termo2
                   |
;

termo2: MULT fator {geraCodigo(NULL, "MULT", NULL, NULL, NULL);}
      | DIV fator {geraCodigo(NULL, "DIVI", NULL, NULL, NULL);}
      | OR fator {geraCodigo(NULL, "DISJ", NULL, NULL, NULL);}
;

fator: variavel
     | ABRE_PARENTESES expressao FECHA_PARENTESES
;

compara: IGUAL | MENOR | MENOR_IGUAL | MAIOR | MAIOR_IGUAL | DIF
;

////////////////////////////////////////////////////////////////
// THANK YOU FOR WATCHING
////////////////////////////////////////////////////////////////

%%

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

   return 0;
}
