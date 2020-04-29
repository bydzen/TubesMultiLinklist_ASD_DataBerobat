// include needed //
#include "Header2.h"

void createListParent(list_parent& L) {
    // create new parent list //
    first(L) = NULL;
};

address_parent alokasi_parent(infotype_parent x) {
    // allocate parent list //
    address_parent P;

    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));

    return P;
};

void insertFirstParent(list_parent& L, address_parent P) {
    // insert first parent list //
    address_parent Q;

    if (first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    }
    else {
        Q = first(L);
        while (next(Q) != first(L)) {
            Q = next(Q);
        };
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    };
};

void printInfoParent(list_parent L) {
    // print info parent list //
    address_parent P = first(L);
    int z;

    if (first(L) != NULL) {
        do {
            if (info(P) == "") {
                goto DONTPRINTRPAR;
            };
            printInfoZeroChild(child(P), z);
            if (z == 0) {
                goto NORPAR;
            };
            cout << "Dokter: " << info(P);
            printInfoRChild(child(P));
        DONTPRINTRPAR:P = next(P);
        } while ((P) != first(L));
        if (info(P) == "") {
            goto NORPAR;
        };
    }
    else {
    NORPAR:cout << "Tidak ada Dokter dan relasi.\n";
        first(L) = NULL;
    };
};

void printInfoCRel(list_parent L) {
    // print info parent list with list child relation //
    address_parent P = first(L);
    int i = 0;
    int z;

    if (first(L) == NULL || first(child(P)) == NULL) {
    NORC:cout << "Tidak ada Pasien dan relasi.\n";
        first(L) = NULL;
        goto EXCCREL;
    }

    if (first(L) != NULL) {
        do {
            if (first(child(P)) != NULL) {
                if (info(P) == "") {
                    goto EXCCREL;
                }
                printInfoRFChild(child(P), z);
                if (z == 0) {
                    goto NORC;
                }
                if (info(P) != "") {
                    cout << "Dokter: " << info(P);
                    i++;
                    if (i > 4) {
                        goto MAXDOC;
                    };
                };
                cout << endl;
            }
            P = next(P);
        } while (P != first(L));
    };

    if (i == -1) {
    MAXDOC:
        cout << "\n\nAda Pasien yang telah mencapai limit dokter (5/5)!\nJika ingin menambah relasi, maka Dokter dan Pasien akan melepaskan relasi\ndan digantikan dengan relasi baru.\n";
        first(child(P)) = NULL;
    }
    else if (i == -9) {
    EXCCREL: cout << "";
    }
};

void printInfoParentOnly(list_parent L) {
    // print info parent list //
    address_parent P = first(L);

    if (first(L) != NULL) {
        do {
            if (info(P) != "") {
                cout << "Dokter: " << info(P) << endl;
            };
            P = next(P);
        } while ((P) != first(L));
        if (info(P) == "") {
            goto NOPAR;
        };
    }
    else {
    NOPAR:cout << "Tidak ada Dokter.\n";
        first(L) = NULL;
    };
};

void printBusyParent(list_parent L) {
    // print busy of parent list with list child relation //
    address_parent P = first(L);
    address_parent Q = NULL;
    int temp_max = 0;
    int k_max;
    int z;

    if (first(L) != NULL) {
        do {
            printBusy(child(P), k_max);
            if (temp_max < k_max) {
                temp_max = k_max;
                Q = P;
            };
            P = next(P);
        } while ((P) != first(L));

        if (temp_max == 0) {
            NOBUSY:cout << "Tidak ada dokter yang sibuk.\n";
            goto ENDBUSY;
        }
        if (info(Q) == "") {
            goto NOBUSY;
        }
        cout << "Dokter: " << info(Q);
        cout << "\nSibuk dengan: " << temp_max << " aksi.";
        printInfoRChild(child(Q));
    }
    else {
        cout << "Tidak ada dokter.\n";
    };
ENDBUSY:cout << "";
};

address_parent findElmParent(list_parent L, infotype_parent x) {
    // find the element of parent list //
    address_parent P = first(L);

    do {
        if (info(P) == x) {
            return P;
        };
        P = next(P);
    } while (P != first(L));

    return NULL;
};

void deleteFirstParent(list_parent& L, address_parent& P) {
    // delete first parent list //
    P = first(L);
    first(L) = next(P);
    info(P) = "";
    
};

void deleteAfterParent(list_parent& L, address_parent& P, address_parent Q) {
    // delete after parent list //
    next(Q) = next(P);
    next(P) = NULL;
};

void deleteLastParent(list_parent& L, address_parent& P) {
    // delete last parent list //
    address_parent  Q = first(L);

    while (next(Q) != P) {
        Q = next(Q);
    };
    next(Q) = NULL;
};

void removeParent(list_parent& L, infotype_parent x) {
    // remove parent list from element //
    bool NPfound = false;

    if (first(L) == NULL) {
        cout << "\nData Dokter kosong." << endl;
    }
    else {
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
        }
        else if (next(P) == NULL) {
            deleteLastParent(L, P);
            cout << "\nDokter " << info(P) << " telah dihapus.\n";
        }
        else {
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
