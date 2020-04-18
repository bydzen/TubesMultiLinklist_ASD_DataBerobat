#include "list_parent.h"

void createListParent(list_parent &L) {
    // membuat list null //
    first(L) = NULL;
};

address_parent alokasi_parent(infotype_parent x) {
    // alokasi dokter //
    address_parent P;

    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));

    return P;
};

void insertFirstParent(list_parent &L, address_parent P) {
    // insert first dokter //
    address_parent Q;

    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        };
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    };
};


void printInfoParent(list_parent L) {
    // print nama dokter dengan pasien relasi //
    address_parent P = first(L);

    if(first(L) != NULL) {
        do {
            cout << "Dokter: " << info(P);
            printInfo(child(P));
            P = next(P);
        } while((P) != first(L));
    };
};

void printInfoParentOnly(list_parent L) {
    // print nama-nama dokter //
    address_parent P = first(L);

    if(first(L) != NULL) {
        do {
            cout << "Dokter: " << info(P) << endl;
            P = next(P);
        } while((P) != first(L));
    };
};

void printBusyParent(list_parent L) {
    // print nama-nama dokter dan status kesibukan //
    address_parent P = first(L);

    if(first(L) != NULL) {
        do {
            cout << "Dokter: " << info(P);
            printBusy(child(P));
            printInfo(child(P));
            P = next(P);
        } while((P) != first(L));
    };
};

address_parent findElmParent(list_parent L, infotype_parent x) {
    address_parent P = first(L);

    do {
        if(info(P) == x) {
            return P;
        };
        P = next(P);
    } while(P != first(L));

    return NULL;
};

void deleteFirstParent(list_parent &L, address_parent &P) {
	first(L) = next(P);
    next(P) = NULL;
}

void deleteAfterParent(list_parent &L, address_parent &P, address_parent Q) {
	next(Q) = next(P);
	next(P) = NULL;
}

void deleteLastParent(list_parent &L, address_parent &P) {
	address_parent  Q = first(L);
	while (next(Q) != P) {
		Q = next(Q);
	}
	next(Q) = NULL;
}

void removeParent(list_parent L, infotype_parent x){
    if (first(L) == NULL)
	{
		cout << "Data Dokter Kosong" << endl;
	}
	else {
		address_parent P = first(L);
		while ((info(P) != x) && (P != NULL))
		{
			P = next(P);
		}
		if (P == first(L))
		{
			deleteFirstParent(L, P);
		}
		else if (next(P) == NULL )
		{
			deleteLastParent(L, P);
		}
		else {
			address_parent Q = first(L);
			while (next(Q) != P) {
				Q = next(Q);
			}
			deleteAfterParent(L, P, Q);

		}

	}
}

