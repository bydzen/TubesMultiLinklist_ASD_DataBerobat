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

int counterStopper(list_relasi &L) {
    /** PENAMBAHAN */

    address_relasi Q = first(L);
    address_relasi R = first(L);
    int p_max = 0;

    while (Q != NULL) {
        while (R != NULL) {
            R = next(R);
            if (info(info(Q)) == info(info(R))) {
                p_max++;
                if (p_max == 4) {
                    goto STOPPER;
                }
                cout << p_max << endl;
            };
        };
        Q = next(Q);
        R = first(L);
    };
    STOPPER:system("PAUSE");

    return p_max;

    /** AKHIR */
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
