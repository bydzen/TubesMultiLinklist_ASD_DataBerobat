// define list relation //
#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include <iostream>
#include "Header3.h"
#include "Header1.h"
using namespace std;

// define list relation component //
#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

// define a parent type //
typedef struct elmlist_relasi *address_relasi;

// component in parent struct //
struct elmlist_relasi{
    address_relasi next;
    address_child info;
};

struct list_relasi{
    address_relasi first;
};

// all procedure //
void createList(list_relasi &L);
void insertFirstChi(list_relasi& L, address_relasi P, string x, string y);
void insertFirstPar(list_relasi& L, address_relasi P, string x, string y);
void insertLast(list_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(list_relasi &L, address_relasi &P);
void deleteLast(list_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);
void dealokasi(address_relasi &P);
void printInfoRChild(list_relasi L);
void printInfoRFChild(list_relasi L);
void printBusy(list_relasi L, int &i_max);

// all function //
address_relasi alokasi(address_child C);
address_relasi findElm(list_relasi L, address_child C);

#endif // LIST_RELASI_H_INCLUDED