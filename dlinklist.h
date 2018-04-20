#pragma once
#define HEADER printf("\n--------------%s-------------\n",__FUNCTION__)
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
typedef char dlinktype;
typedef struct dlinklist
{
    dlinktype data;
    struct dlinklist *next;
    struct dlinklist *prev;
}dlinklist;
dlinklist *head;
dlinklist *dcreat(dlinktype value);
void dlinklist_init(dlinklist **head);
void dlinklist_print(dlinklist *head);
void dlinklist_pushback(dlinklist *head,dlinktype value);
void dlinklist_popback(dlinklist *head);
void dlinklist_pushfront(dlinklist *head,dlinktype value);
void dlinklist_popfront(dlinklist *head);
dlinklist * dlinklist_find(dlinklist *head,dlinktype value);
void dlinklist_pushleft(dlinklist *head,dlinklist *pos,dlinktype value);
void dlinklist_pushright(dlinklist *head,dlinklist *pos,dlinktype value);
void dlinklist_erase(dlinklist *head,dlinklist *pos);
void dlinklist_remove(dlinklist *head,dlinktype value);
void dlinklist_removeall(dlinklist *head,dlinktype value);
size_t dlinklist_size(dlinklist *head);
