// include needed //
#include "list_relasi.h"

void createList(list_relasi &L) {
    // create new list relation //
    first(L) = NULL;
};

address_relasi alokasi(address_child C) {
    // allocate list relation //
    address_relasi P = new elmlist_relasi;

    info(P) = C;
    next(P) = NULL;

    return P;
};

void insertFirst(list_relasi &L, address_relasi P) {
    // insert first list relation //
    next(P) = first(L);
    first(L) = P;

};

void printInfoRChild(list_relasi L) {
    // print info relation list with child list //
    address_relasi P = first(L);

    while(P != NULL) {
        cout << "\n        -> Pasien: " << info(info(P));
        P = next(P);
    };
    cout << endl;
};

void printInfoRFChild(list_relasi L) {
    // print info child list with parent list //
    address_relasi P = first(L);
    int i;

    cout << endl;
    while(P != NULL) {
        cout << "Pasien: " << info(info(P)) << "\n";
        P = next(P);

    };
    cout << "        -> ";

};

void printBusy(list_relasi L, int &i_max) {
    // print busy of parent list with child list//
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


    i_max = i;

};

address_relasi findElm(list_relasi L, address_child C) {
    // find the element of relation list //
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
    // insert after relation list //
    next(P) = next(Prec);
    next(Prec) = P;
};

int maxPasien(list_relasi L, int i_max) {
    // print busy of parent list with child list//
    int i = 0;
    address_relasi P = first(L);

    while(P != NULL) {
        P = next(P);
        i++;
    };


    i_max = i;

};
