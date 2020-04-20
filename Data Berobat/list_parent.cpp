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
            printInfoRChild(child(P));
            P = next(P);
        } while((P) != first(L));
    } else {
        cout << "Tidak ada Dokter dan relasi.\n";
    };
};

void printInfoCRel(list_parent L) {
    // print nama dokter dengan pasien relasi //
    address_parent P = first(L);

    if(first(L) != NULL) {
        do {
            printInfoRFChild(child(P));
            /*char x = printInfoRFChildS(child(P));
            if (x == "") {
                    cout << "Tidak ada Pasien";
            };*/
            if (info(P) != "") {
                cout << "Dokter: " << info(P);
            };
            cout << endl;
            P = next(P);
        } while((P) != first(L));
    } else {
        cout << "Tidak ada Pasien dan relasi.\n";
    };
}

void printInfoParentOnly(list_parent L) {
    // print nama-nama dokter //
    address_parent P = first(L);

    if(first(L) != NULL) {
        do {
            if (info(P) != "") {
                cout << "Dokter: " << info(P) << endl;
            };
            P = next(P);
        } while((P) != first(L));
    } else {
        cout << "Tidak ada Dokter.\n";
    };
};

void printBusyParent(list_parent L) {
    // print nama-nama dokter dan status kesibukan //
    address_parent P = first(L);

    if(first(L) != NULL) {
        do {
            cout << "Dokter: " << info(P);
            printBusy(child(P));
            printInfoRChild(child(P));
            P = next(P);
        } while((P) != first(L));
    } else {
        cout << "Tidak ada dokter.\n";
    };
};

address_parent findElmParent(list_parent L, infotype_parent x) {
    // mencari elemen dokter //
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
    // delete first dokter //
    P = first(L);
    first(L) = next(P);
    info(P) = "";
};


void deleteAfterParent(list_parent &L, address_parent &P, address_parent Q) {
    // delete after dokter //
	next(Q) = next(P);
	next(P) = NULL;
};

void deleteLastParent(list_parent &L, address_parent &P) {
 // delete last dokter //
	address_parent  Q = first(L);
	while (next(Q) != P) {
		Q = next(Q);
	}

	next(Q) = NULL;

;}

void removeParent(list_parent &L, infotype_parent x) {
    // delete dokter //
    bool NPfound = false;

    if (first(L) == NULL) {
		cout << "\nData Dokter kosong." << endl;

	} else {
		address_parent P = first(L);

		while ((info(P) != x) && (next(P) != first(L))) {
			P = next(P);
		};

		if (next(P) == first(L) && info(P) != x) {
            NPfound = true;
            goto NPFOUND;
		};

		if (P == first(L)) {
            cout << "\nDokter " << info(P) << " telah dihapus.\n";
			deleteFirstParent(L, P);
		} else if (next(P) == NULL ) {
			deleteLastParent(L, P);
			cout << "\nDokter " << info(P) << " telah dihapus.\n";
		} else {
			address_parent Q;
			Q = first(L);
			while (next(Q) != P) {
				Q = next(Q);
			};
			deleteAfterParent(L, P, Q);
			cout << "\nDokter " << info(P) << " telah dihapus.\n";

		};
	};
	NPFOUND:if (NPfound != false) {
        cout << "\nData Dokter " << x << " tidak ditemukan.\n";
	};
};
