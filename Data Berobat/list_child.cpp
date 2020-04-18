#include "list_child.h"

void createListChild(list_child &L) {
    // membuat list baru pasien //
    first(L) = NULL;
    last(L) = NULL;
};

address_child alokasi_child(infotype_child x) {
    // alokasi pasen //
    address_child P = new elmlist_child;

    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
};

void insertFirstChild(list_child &L, address_child P) {
    // insert first pasien //
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    };
};

void printInfoChild(list_child L) {
    // print info child/pasien //
    address_child P = first(L);

    while(P != NULL) {
        cout << "Pasien: " << info(P) << endl;
        P = next(P);
    };
};

address_child findElmChild(list_child L, infotype_child x) {
    // mencari elemen pasien //
    address_child P = first(L);

    while(P != NULL) {
        if(info(P) == x) {
            return P;
        };
        P = next(P);
    };
    return NULL;
};

void insertAfterChild(address_child &Prec, address_child P) {
    // insert after pasien //
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
};
