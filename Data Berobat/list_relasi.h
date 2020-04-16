#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include <iostream>
#include "list_relasi.h"
#include "list_child.h"
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child info;
};

struct list_relasi{
    address_relasi first;
};

void createList(list_relasi &L);
void insertFirst(list_relasi &L, address_relasi P);
void insertLast(list_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(list_relasi &L, address_relasi &P);
void deleteLast(list_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);

address_relasi alokasi(address_child C);
void dealokasi(address_relasi &P);
address_relasi findElm(list_relasi L, address_child C);
void printInfo(list_relasi L);

void printBusy(list_relasi L);

#endif // LIST_RELASI_H_INCLUDED
