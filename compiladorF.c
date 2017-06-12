
/* -------------------------------------------------------------------
 *            Aquivo: compilador.c
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Fun��es auxiliares ao compilador
 *
 * ------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

extern list TS;

//maxRotulo: Valor do último rótulo gerado.
int maxRotulo;

/* -------------------------------------------------------------------
 *  vari�veis globais
 * ------------------------------------------------------------------- */

FILE* fp=NULL;
void geraCodigo (char* rot, char* comando, char* arg1, char* arg2, char* arg3)
{
  if (fp == NULL) {
    fp = fopen ("MEPA", "w");
  }
  if (rot == NULL) {
    fprintf(fp, "     %s", comando); fflush(fp);
  } else {
    fprintf(fp, "%s: %s", rot, comando); fflush(fp);
  }
  if (arg1 != NULL)
  {
    fprintf(fp, " %s", arg1);
  }
  if (arg2 != NULL)
  {
    fprintf(fp, ", %s", arg2);
  }
  if (arg3 != NULL)
  {
    fprintf(fp, ", %s", arg3);
  }
  fprintf(fp, "\n");
}

int imprimeErro ( char* erro ) {
  fprintf (stderr, "Erro na linha %d - %s\n", nl, erro);
  exit(-1);
}

tSimboloTs* criaSimboloTS(char* rot, int categoria, int nivel)
{
 printf("\nTentando criar símbolo com o nome %s e categoria %s\n", rot, catTS(categoria));
 tSimboloTs* t = (tSimboloTs*)malloc(sizeof(tSimboloTs));
 if (t)
 {
  t->ident = rot;
  t->categoria = categoria;
  t->nivel = nivel;

  if (!insereTS(t))
   printf("Catástrofe detectada:\nNão foi possível inserir o símbolo na TS\n");
 }
 return t;
}

tSimboloTs* criaSimboloTS_VS(char *rot, int categoria, int nivel, int deslocamento)
{
  tSimboloTs* t = (tSimboloTs*)malloc(sizeof(tSimboloTs));
  t->categoriaTs.v = (tVsTs*)malloc(sizeof(tVsTs));
  if (t)
  {
   t->ident = (char*)malloc(sizeof(char)*TAM_TOKEN);
   strcpy(t->ident, rot);
   t->categoria = categoria;
   t->nivel = nivel;
   t->categoriaTs.v->deslocamento = deslocamento;

   if (!insereTS(t))
    printf("Catástrofe detectada:\nNão foi possível inserir o símbolo na TS\n");
  }
  return t;
}

tSimboloTs* criaSimboloTS_CP(char* rot, int nivel, char* rotulo_chamada, char* rotulo_saida)
{
  tSimboloTs* t = (tSimboloTs*)malloc(sizeof(tSimboloTs));
  t->categoriaTs.c = (tCpTs*)malloc(sizeof(tCpTs));
  t->categoria = TS_CAT_CP;
  if (t)
  {
   t->ident = (char*)malloc(sizeof(char)*TAM_TOKEN);
   strcpy(t->ident, rot);
   t->nivel = nivel;
   t->categoriaTs.c->rotulo = rotulo_chamada;
   t->categoriaTs.c->rotulo_saida = rotulo_saida;
   t->categoriaTs.c->nivel = nivel;

   if (!insereTS(t))
    printf("Catástrofe detectada:\nNão foi possível inserir o símbolo na TS\n");
  }
  return t;
}

tSimboloTs* criaSimboloTS_FU(char* rot, int nivel, char* rotulo_chamada, char* rotulo_saida)
{
  tSimboloTs* t = (tSimboloTs*)malloc(sizeof(tSimboloTs));
  t->categoriaTs.f = (tFuTs*)malloc(sizeof(tFuTs));
  t->categoria = TS_CAT_FU;
  if (t)
  {
   t->ident = (char*)malloc(sizeof(char)*TAM_TOKEN);
   strcpy(t->ident, rot);
   t->nivel = nivel;
   t->categoriaTs.f->rotulo = rotulo_chamada;
   t->categoriaTs.f->rotulo_saida = rotulo_saida;
   t->categoriaTs.f->nivel = nivel;

   if (!insereTS(t))
    printf("Catástrofe detectada:\nNão foi possível inserir o símbolo na TS\n");
  }
  return t;
}

tSimboloTs* criaSimboloTS_PF(char* rot, int nivel, int tipo)
{
 tSimboloTs* t = (tSimboloTs*)malloc(sizeof(tSimboloTs));
 t->categoriaTs.p = (tPfTs*)malloc(sizeof(tPfTs));
 if (t)
 {
  t->ident = (char*)malloc(sizeof(char)*TAM_TOKEN);
  strcpy(t->ident, rot);
  t->categoria = TS_CAT_PF;
  t->nivel = nivel;
  t->categoriaTs.p->tipo = tipo;

  if (!insereTS(t))
   printf("Catástrofe detectada:\nNão foi possível inserir o símbolo na TS\n");
 }
 return t;
}

void atualizaSimboloTS_VS(tSimboloTs* s, int tipo)
{
 if (s->categoria==TS_CAT_VS)
 {
  s->categoriaTs.v->tipo = tipo;
 }
 else printf("Catástrofe detectada:\nTentando atualizar simbolo TS do tipo VS porém a categoria é %d\n\n", s->categoria);
}

void atualizaSimboloTS_PF(tSimboloTs* s, int deslocamento)
{
 if (s->categoria==TS_CAT_PF)
 {
  s->categoriaTs.p->deslocamento = deslocamento;
 }
 else printf("Catástrofe detectada:\nTentando atualizar simbolo TS do tipo PF porém a categoria é %d\n\n", s->categoria);
}

void atualizaSimboloTS_CP(tSimboloTs* s, int* tipoPassagem)
{
 if (s->categoria==TS_CAT_CP)
 {
  if (s->categoriaTs.c->tipoPassagem)
      free(s->categoriaTs.c->tipoPassagem);
  s->categoriaTs.c->tipoPassagem = tipoPassagem;
 }
 else printf("Catástrofe detectada:\nTentando atualizar simbolo TS do tipo CP porém a categoria é %d\n\n", s->categoria);
}

void atualizaSimboloTS_FU(tSimboloTs* s, int* tipoPassagem, int deslocamento, int tipoRetorno)
{
 if (s->categoria==TS_CAT_FU)
 {
  if (s->categoriaTs.f->tipoPassagem)
      free(s->categoriaTs.f->tipoPassagem);
  s->categoriaTs.f->tipoPassagem = tipoPassagem;
  s->categoriaTs.f->deslocamento = deslocamento;
  s->categoriaTs.f->tipoRetorno = tipoRetorno;
 }
 else printf("Catástrofe detectada:\nTentando atualizar simbolo TS do tipo FU porém a categoria é %d\n\n", s->categoria);
}

int insereTS(tSimboloTs* s)
{
 if (s)
 {
  if (list_push(s, TS)!=NULL)
   return 1;
 }
 return 0;
}

tSimboloTs* buscaTS(char* rot)
{
 tSimboloTs* s;
 for (node n=list_first(TS);n;n=list_next(n))
 {
  s = list_value(n);
  if (strcmp(s->ident, rot)==0)
   return s;
 }
 return NULL;
}

void atualizaTS(int num, char token[TAM_TOKEN])
{
  int i = 0;
  for (node n=list_first(TS); n && i<num; n=list_next(n))
  {
   tSimboloTs* t = list_value(n);
   if (t->categoria==TS_CAT_VS)
   {
    printf("\n%s\n", token);
    if (strcmp(token, "integer")==0)
     atualizaSimboloTS_VS(t, TS_TIP_INT);
    else if (strcmp(token, "boolean")==0)
     atualizaSimboloTS_VS(t, TS_TIP_BOO);
    else if (strcmp(token, "imaginario")==0)
     atualizaSimboloTS_VS(t, TS_TIP_IMG);
    else imprimeErro("Tipo Inválido\n");
    i++;
   }
  }
}

int removeTS(int n)
{
 while(n>0)
 {
  list_pop(TS);
  n--;
 }
 return 0;
}

list criaTS()
{
 list l = list_new();
 return l;
}

void imprimeSimboloTS(tSimboloTs* t)
{
 switch(t->categoria)
 {
  case TS_CAT_VS:
   printf("\nSimbolo TS:\nRot\tCat\tNiv\tDesl\tTipo\n%s\t%s\t%d\t%d\t%s\n\n", t->ident, catTS(t->categoria), t->nivel, t->categoriaTs.v->deslocamento, tipoTS(t->categoriaTs.v->tipo));
  break;

  case TS_CAT_PF:
   printf("\nSimbolo TS:\nRot\tCat\tNiv\tDesl\tTipoP\tTipo\n%s\t%s\t%d\t%d\t%s\t%s\n\n", t->ident, catTS(t->categoria), t->nivel, t->categoriaTs.p->deslocamento, tipoPassagemTS(t->categoriaTs.p->tipoPassagem), tipoTS(t->categoriaTs.p->tipo));
  break;

  case TS_CAT_CP:
   printf("\nSimbolo TS:\nRot\tCat\tNiv\tRot\tNiv\tnParams\n%s\t%s\t%d\t%s\t%d\t%d\n", t->ident, catTS(t->categoria), t->nivel, t->categoriaTs.c->rotulo, t->categoriaTs.c->nivel, t->categoriaTs.c->nParams);
   if (t->categoriaTs.c->tipoPassagem!=NULL && t->categoriaTs.c->nParams>0)
   {
    printf("Tipos Passagem: [%d", t->categoriaTs.c->tipoPassagem[0]);
    for (int i=1;i<t->categoriaTs.c->nParams;++i)
     printf(", %d", t->categoriaTs.c->tipoPassagem[i]);
    printf("]\n\n");
   }
  break;

  case TS_CAT_FU:
   printf("\nSimbolo TS:\nRot\tCat\tNiv\tRot\tNiv\tnParams\tDeslocamento\tTipo Ret\n%s\t%s\t%d\t%s\t%d\t%d\t%d\t\t%s\n", t->ident, catTS(t->categoria), t->nivel, t->categoriaTs.f->rotulo, t->categoriaTs.f->nivel, t->categoriaTs.f->nParams, t->categoriaTs.f->deslocamento, tipoTS(t->categoriaTs.f->tipoRetorno));
   if (t->categoriaTs.f->tipoPassagem!=NULL && t->categoriaTs.f->nParams>0)
   {
    printf("Tipos Passagem: [%d", t->categoriaTs.f->tipoPassagem[0]);
    for (int i=1;i<t->categoriaTs.f->nParams;++i)
     printf(", %d", t->categoriaTs.f->tipoPassagem[i]);
    printf("]\n\n");
   }
  break;
 }
}

char *catTS(int categoria)
{
 switch(categoria)
 {
  case TS_CAT_VS:
   return "VS";
  break;

  case TS_CAT_CP:
   return "CP";
  break;

  case TS_CAT_PF:
   return "PF";
  break;

  case TS_CAT_FU:
   return "FU";
  break;

  default:
   return "?";
  break;
 }
}

char *tipoTS(int tipo)
{
 switch(tipo)
 {
  case TS_TIP_INT:
   return "INT";
  break;

  case TS_TIP_BOO:
   return "BOOL";
  break;

  case TS_TIP_IMG:
   return "IMG";
  break;

  default:
   return "?";
  break;
 }
}

char *tipoPassagemTS(int tipo)
{
 switch(tipo)
 {
  case TS_TIP_INT:
   return "VAL";
  break;

  case TS_TIP_BOO:
   return "REF";
  break;

  default:
   return "?";
  break;
 }
}

//Gera rótulo
char* geraRotulo()
{
 char* rot;
 rot = (char*)malloc(sizeof(char)*10);
 sprintf(rot, "R%2.0d", maxRotulo++);
 for (int i=0;i<9;++i)
 {
  if (rot[i]==' ')
   rot[i] = '0';
 }
 return rot;
}

void imprimeTS()
{
 printf("\n\n==================\n\nTABELA DE SÍMBOLOS\n\n==================\n");
 for (node n=list_first(TS); n; n=list_next(n))
 {
  tSimboloTs* t = list_value(n);
  imprimeSimboloTS(t);
 }
 printf("\n\n==================\n");
}
