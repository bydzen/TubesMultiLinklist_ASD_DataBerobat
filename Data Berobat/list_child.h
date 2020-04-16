#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define parent(P) P->parent

typedef string infotype_child;
typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct list_child{
    address_child first;
    address_child last;
};

void createList(list_child &L);
void insertFirst(list_child &L, address_child P);
void insertLast(list_child &L, address_child P);
void insertAfter(address_child Prec, address_child P);
void deleteFirst(list_child &L, address_child &P);
void deleteLast(list_child &L, address_child &P);
void deleteAfter(address_child Prec, address_child &P);

address_child alokasi_child(infotype_child x);
void dealokasi(address_child &P);
address_child findElm(list_child L, infotype_child x);
void printInfo(list_child L);

#endif // LIST_CHILD_H_INCLUDED
