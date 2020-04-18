#include "list_relasi.h"

void createList(list_relasi &L) {
    // membuat list relasi baru //
    first(L) = NULL;
};

address_relasi alokasi(address_child C) {
    // alokasi relasi //
    address_relasi P = new elmlist_relasi;

    info(P) = C;
    next(P) = NULL;
    return P;
};

void insertFirst(list_relasi &L, address_relasi P) {
    // insert first relasi //
    next(P) = first(L);
    first(L) = P;
};

void printInfo(list_relasi L) {
    // print info relasi dengan pasien //
    address_relasi P = first(L);

    while(P != NULL) {
        cout << "\n        -> Pasien: " << info(info(P));
        P = next(P);
    };
    cout << endl;
};

void printBusy(list_relasi L) {
    // print status dokter sibuk/tidak //
    int i = 0;
    address_relasi P = first(L);

    while(P != NULL) {
        P = next(P);
        i++;
    };

    if (i == 0) {
        cout << " (tidak sibuk)";
    } else if (i > 0) {
        cout << " (sedang sibuk dengan " << i << " Pasien)";
    };
};

address_relasi findElm(list_relasi L, address_child C) {
    // mencari elemen relasi pasien //
    address_relasi P = first(L);

    while(P != NULL) {
        if(info(P) == C) {
            return P;
        };
        P = next(P);
    };

    return NULL;
};

void insertAfter(address_relasi &Prec, address_relasi P) {
    // insert after  relasi parent //
    next(P) = next(Prec);
    next(Prec) = P;
};
