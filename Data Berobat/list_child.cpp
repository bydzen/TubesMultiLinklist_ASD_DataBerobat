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
        if(P == NULL){
            cout<<"Data Kosong";

        }else{
             cout << "Pasien: " << info(P) << endl;
            P = next(P);
        }
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

void deleteFirstChild(list_child &L, address_child &P) {
    // delete first pasien //
    P = first(L);
    first(L) = next(P);
    P = next(P);
    prev(P) = NULL;

};

void deleteAfterChild(list_child &L, address_child &P, address_child Q) {
    // delete after pasien //
	next(Q) = next(P);
	next(P) = NULL;
};

void deleteLastChild(list_child &L, address_child &P) {
    // delete last pasien //
	address_child  Q = first(L);
	while (next(Q) != P) {
		Q = next(Q);
	};
	next(Q) = NULL;
};

void removeChild(list_child &L, infotype_child x) {
    // delete pasien //
    if (first(L) == NULL) {
		cout << "\nData Pasien Kosong." << endl;

	} else {
		address_child P = first(L);

		while ((info(P) != x) && (next(P) != NULL)) {
			P = next(P);
		};

		if (P == first(L)) {
			deleteFirstChild(L, P);
			cout << "\nPasien " << info(P) << " telah dihapus.\n";
		} else if (next(P) == NULL ) {
			deleteLastChild(L, P);
			cout << "\nPasien " << info(P) << " telah dihapus.\n";
		}else {
			address_child Q;
			Q = first(L);
			while (next(Q) != P) {
				Q = next(Q);
			};
			deleteAfterChild(L, P, Q);
			cout << "\nPasien " << info(P) << " telah dihapus.\n";

		}
	}
}
