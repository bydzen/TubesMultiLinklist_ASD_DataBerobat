// include needed //
#include "Header3.h"

void createList(list_relasi& L) {
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

void insertFirstPar(list_relasi& L, address_relasi P, string x, string y) {
    // insert first list relation //
    if (first(L) != NULL) {
        address_relasi Q = first(L);

        while (Q != NULL) {
            if (info(P) == info(Q)) {
                goto NOINSERTFIRST;
            };
            Q = next(Q);
        };
    };

    next(P) = first(L);
    first(L) = P;

    system("CLS");
    cout << "\nDokter " << x << " telah direlasikan dengan Pasien " << y << ".\n";
    system("TIMEOUT /T 7");

    if (info(P) != info(P)) {
    NOINSERTFIRST:
        system("CLS");
        cout << "\nTerjadi duplikasi, relasi tidak ditambahkan.\n";
        system("TIMEOUT /T 7");
    };
};

void insertFirstChi(list_relasi& L, address_relasi P, string x, string y) {
    // insert first list relation //
    if (first(L) != NULL) {
        address_relasi Q = first(L);

        while (Q != NULL) {
            if (info(P) == info(Q)) {
                goto NOINSERTFIRST;
            };
            Q = next(Q);
        };
    };

    next(P) = first(L);
    first(L) = P;

    system("CLS");
    cout << "\nPasien " << x << " telah direlasikan dengan Dokter " << y << ".\n";
    system("TIMEOUT /T 7");

    if (info(P) != info(P)) {
    NOINSERTFIRST:
        system("CLS");
        cout << "\nTerjadi duplikasi, relasi tidak ditambahkan.\n";
        system("TIMEOUT /T 7");
    };
};

void printInfoRChild(list_relasi L) {
    // print info relation list with child list //
    address_relasi P = first(L);

    while (P != NULL) {
        cout << "\n        -> Pasien: " << info(info(P));
        P = next(P);
    };
    cout << endl;
};

void printInfoRFChild(list_relasi L) {
    // print info child list with parent list //
    address_relasi P = first(L);

    while (P != NULL) {
        cout << "Pasien: " << info(info(P)) << "\n";
        P = next(P);
    };
    cout << "        -> ";
};

void printBusy(list_relasi L, int& i_max) {
    // print busy of parent list with child list//
    int i = 0;
    address_relasi P = first(L);

    while (P != NULL) {
        P = next(P);
        i++;
    };

    i_max = i;
};

address_relasi findElm(list_relasi L, address_child C) {
    // find the element of relation list //
    address_relasi P = first(L);

    while (P != NULL) {
        if (info(P) == C) {
            return P;
        };
        P = next(P);
    };

    return NULL;
};

void insertAfter(address_relasi& Prec, address_relasi P) {
    // insert after relation list //
    next(P) = next(Prec);
    next(Prec) = P;
};
