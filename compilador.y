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
//parametroAtual: indica qual a posição do parametro atual.
int parametroAtual;
//ehPassagemParametro: indica se a variável lida deve ser considerada como passagem de parâmetro.
int ehPassagemParametro;

list pilhona;
list parametros;
list pilhaAlt;

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
              T_BEGIN
              comandos
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
              T_END
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
                   }
                   ABRE_PARENTESES {contVar = 0; nivelLexico++;} lista_id_parametros
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
                   FECHA_PARENTESES PONTO_E_VIRGULA
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
                   bloco
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
                   PONTO_E_VIRGULA
;

parte_declara_functions: FUNCTION declara_function
;

declara_function: IDENT
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
                  }
                  ABRE_PARENTESES { contVar = 0; nivelLexico++; } lista_id_parametros
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
                  FECHA_PARENTESES DOIS_PONTOS tipo PONTO_E_VIRGULA
                  {
                   node p = list_pop(pilhona);
                   node n = list_first(pilhona);
                   int* params;
                   params = list_value(p);
                   tSimboloTs* ss = list_value(n);
                   if (ss)
                   {
                    if (ss->categoria == TS_CAT_FU)
                    {
                     atualizaSimboloTS_FU(ss, params, ss->categoriaTs.f->nParams*-1-4);
                    }
                   }
                  }
                  bloco
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
                  PONTO_E_VIRGULA
;

lista_id_parametros: lista_id_parametros VIRGULA parametros
                     {
                      node p = list_first(pilhona);
                      int* params = list_value(p);
                      params = (int*)realloc(params, (1+contVar)*sizeof(int));
                      contVar++;
                     }
                   | parametros
                     {
                      node p = list_first(pilhona);
                      int* params = list_value(p);
                      params = (int*)realloc(params, (1+contVar)*sizeof(int));
                      contVar++;
                     }
                   |
;

parametros: IDENT {strcpy(elementoEsquerda, token);} DOIS_PONTOS tipo
            {
             tSimboloTs* ss = criaSimboloTS_PF(elementoEsquerda, nivelLexico);
             ss->categoriaTs.p->tipoPassagem = TS_PAR_VAL;
             node p = list_first(pilhona);
             int* params;
             params = list_value(p);
             params[contVar] = TS_PAR_VAL;
             list_push(ss, parametros);
            }
          | VAR IDENT {strcpy(elementoEsquerda, token);} DOIS_PONTOS tipo
            {
             tSimboloTs* ss = criaSimboloTS_PF(elementoEsquerda, nivelLexico);
             ss->categoriaTs.p->tipoPassagem = TS_PAR_REF;
             node p = list_first(pilhona);
             int* params;
             params = list_value(p);
             params[contVar] = TS_PAR_REF;
             list_push(ss, parametros);
            }
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
                  | READ ABRE_PARENTESES lista_ids_read FECHA_PARENTESES
                  | WRITE ABRE_PARENTESES lista_expressoes_write FECHA_PARENTESES
                  | ABRE_PARENTESES MAIS regra_comentario
;

regra_comentario: MAIS FECHA_PARENTESES
;

lista_ids_read: IDENT
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
                |
                 lista_ids_read VIRGULA IDENT
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

////////////////////////////////////////////////////////////////
// IF / IF THEN ELSE
////////////////////////////////////////////////////////////////

regra_if: IF
          {
           char* rotulo_else;
           rotulo_else = geraRotulo();
           char* rotulo_saida;
           rotulo_saida = geraRotulo();
           list_push(rotulo_saida, pilhona);
           list_push(rotulo_else, pilhona);
          }
          ABRE_PARENTESES
          expressao_completa
          FECHA_PARENTESES
          THEN
          {
           node e = list_first(pilhona);
           char* rotulo_else = list_value(e);
           geraCodigo(NULL, "DSVF", rotulo_else, NULL, NULL);
          }
          comando_composto
          {
           node s = list_next(list_first(pilhona));
           char* rotulo_saida = list_value(s);
           node e = list_first(pilhona);
           char* rotulo_else = list_value(e);
           geraCodigo(NULL, "DSVS", rotulo_saida, NULL, NULL);
          }
          talveztemelse
;

talveztemelse: PONTO_E_VIRGULA
               {
                node e = list_pop(pilhona);
                node s = list_pop(pilhona);
                char *rotulo_saida = list_value(s);
                char *rotulo_else = list_value(e);
                geraCodigo(rotulo_else, "NADA", NULL, NULL, NULL);
                geraCodigo(NULL, "DSVS", rotulo_saida, NULL, NULL);
                geraCodigo(rotulo_saida, "NADA", NULL, NULL, NULL);
               }
             | ELSE
               {
                node e = list_pop(pilhona);
                char *rotulo_else = list_value(e);
                geraCodigo(rotulo_else, "NADA", NULL, NULL, NULL);
               }
               comando_composto
               {
                node s = list_pop(pilhona);
                char *rotulo_saida = list_value(s);
                geraCodigo(rotulo_saida, "NADA", NULL, NULL, NULL);
               }
;

////////////////////////////////////////////////////////////////
// WHILE
////////////////////////////////////////////////////////////////

regra_while: WHILE
    {
     char* rotulo_saida;
     rotulo_saida = geraRotulo();
     char* rotulo_entrada;
     rotulo_entrada = geraRotulo();
     list_push(rotulo_entrada, pilhona);
     list_push(rotulo_saida, pilhona);
     geraCodigo(rotulo_entrada, "NADA", NULL, NULL, NULL);
    }
    ABRE_PARENTESES
    expressao_completa
    FECHA_PARENTESES
    DO
    {
     node s = list_first(pilhona);
     char* rotulo_saida = list_value(s);
     geraCodigo(NULL, "DSVF", rotulo_saida, NULL, NULL);
    }
    comando_composto
    {
     node s = list_pop(pilhona);
     char* rotulo_saida = list_value(s);
     node e = list_pop(pilhona);
     char* rotulo_entrada = list_value(e);
     geraCodigo(NULL, "DSVS", rotulo_entrada, NULL, NULL);
     geraCodigo(rotulo_saida, "NADA", NULL, NULL, NULL);
    }
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
                geraCodigo(NULL, "ARMZ", nl, ds, NULL);
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
               }
               else if (ss->categoria == TS_CAT_FU)                             //Escrita em valor de retorno de Função.
               {
                char nl[TAM_TOKEN], ds[TAM_TOKEN];
                sprintf(nl, "%d", ss->nivel+1);
                sprintf(ds, "%d", ss->categoriaTs.f->deslocamento);
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
           | ABRE_PARENTESES
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
             lista_expressoes_call FECHA_PARENTESES                      //Chamada Função ou procedimento.
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
;

variavel: NUMERO {geraCodigo(NULL, "CRCT", token, NULL, NULL);}
        | IDENT {empilhaString(token, pilhona); } variavel2
;

variavel2: ABRE_PARENTESES
           {
            parametroAtual=0;
            node n = list_first(pilhona);
            char *nome;
            nome = list_value(n);
            tSimboloTs* ss = buscaTS(nome);
            if (ss && ss->categoria == TS_CAT_FU)
            {
             geraCodigo(NULL, "AMEM 1", NULL, NULL, NULL);
            }
            list_push(nome, pilhona);
           }
           lista_expressoes_call FECHA_PARENTESES                      //Chamada Função ou procedimento.
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
         |
          {
           node n = list_pop(pilhona);
           printf("-%p\n", n);
           char *tok = list_value(n);
           tSimboloTs* ss = buscaTS(tok);
           printf(">-%s\n", tok);
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
            }
            else
            {
             char str[100];
             sprintf(str, "O token %s não é de categoria válida\n", token);
             imprimeErro(str);
            }
           }
          }

////////////////////////////////////////////////////////////////
// EXPRESSÕES
////////////////////////////////////////////////////////////////

lista_expressoes_call: lista_expressoes_call VIRGULA
                       {
                        empilhaTipoPassagemParametro();
                       }
                       expressao { parametroAtual++; ehPassagemParametro=0; }
                    |
                       {
                        empilhaTipoPassagemParametro();
                       }
                       expressao { parametroAtual++; ehPassagemParametro=0; }

lista_expressoes_write: lista_expressoes_write VIRGULA expressao {geraCodigo(NULL, "IMPR", NULL, NULL, NULL);}
                      | expressao {geraCodigo(NULL, "IMPR", NULL, NULL, NULL);}
;

expressao_completa: expressao expressao_completa2
;

expressao_completa2: compara expressao
                     {
                      node n = list_pop(pilhona);
                      char* func = list_value(n);
                      geraCodigo(NULL, func, NULL, NULL, NULL);
                     }
                   |
;

expressao: termo expressao_intermediaria expressao_intermediaria2
         | expressao_intermediaria2
;

expressao_intermediaria2: expressao2 expressao
                        | termo2 expressao
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

compara: IGUAL {list_push("CMIG", pilhona);} | MENOR {list_push("CMME", pilhona);}
       | MENOR_IGUAL {list_push("CMEG", pilhona);} | MAIOR {list_push("CMMA", pilhona);}
       | MAIOR_IGUAL {list_push("CMAG", pilhona);} | DIF {list_push("CMDG", pilhona);}
;

////////////////////////////////////////////////////////////////
// THANK YOU FOR WATCHING
////////////////////////////////////////////////////////////////

%%
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
  if (ss->categoria == TS_CAT_FU)
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

void imprimeAlt()
{
 for (node n=list_first(pilhaAlt);n;n=list_next(n))
      printf(".[%p]=%s(%p)\n", n, (char*)list_value(n),list_value(n));
}

void empilhaString(char *str1, list l)
{
 char *str2 = (char*)malloc(sizeof(char)*(strlen(str1)+1));
 strcpy(str2, str1);
 list_push(str2, l);
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
   pilhaAlt = list_new();
   ehPassagemParametro = 0;

   yyin=fp;
   yyparse();

   return 0;
}
