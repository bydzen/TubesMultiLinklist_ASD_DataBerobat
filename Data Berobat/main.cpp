#include <iostream>


using namespace std;
#include "list_child.h"
#include "list_parent.h"

int main() {
    // greeting identitas pembuat dan tujuan program //
    cout << "-->> Program Relasi M-N (Dokter dan Pasien | Data Berobat) <<--\n\n\n";
    cout << "Program Name       : Data Berobat" << endl;
    cout << "Program Language   : C++" << endl;
    cout << "Created by         : Sultan Kautsar | Bagas Alfito Prismawan" << endl;
    cout << "Id Creator         : 1303194010     | 1303193027" << endl;
    cout << "Description        : Program data berobat pasien beserta relasinya" << endl;
    cout << "                     dibuat untuk memenuhi tugas besar matakuliah Algoritma dan Struktur Data.\n" << endl;
    system("TIMEOUT /T 7");
    system("CLS");

    // kamus program //
    list_parent LP;
    list_child LC;
    address_child C;
    address_parent P;
    address_relasi R;

    string nDok;
    string nPas;
    string nRelDoc;
    string nRelPas;
    string yn;
    string ryn;
    string rPas;
    string rPasNew;
    string delDoc;
    string delPas;

    char authGit;

    int choose = 1;
    int cntDok;
    int cntPas;
    int Rdpd;

    // algoritma main //
    createListParent(LP);
    createListChild(LC);

    PROGMENU:while (choose != 0) {
        choose = 1;
        cout << "Menu Program\n1. -->> Tambah Dokter.\n2. -->> Tambah Pasien.\n3. -->> Tambah relasi Dokter dengan Pasien.\n4. -->> Hapus Dokter.\n5. -->> Hapus Pasien.\n6. -->> Tampilkan seluruh data Dokter dan Pasien.\n7. -->> Tampilkan Dokter yang menangani Pasien.\n8. -->> Tampilkan Pasien yang ditangani Dokter.\n9. -->> Tampilkan status Dokter.\n99.-->> Ganti nama Pasien.\n0. -->> Exit (Program)\nPilih -->> ";
        cin >> choose;
        if (choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5 && choose != 6 && choose != 7 && choose != 8 && choose != 9 && choose != 99 && choose != 0) {
            system("CLS");
            choose = 1;
            goto PROGMENU;
        }

        if (choose == 0) {
            system("CLS");
            cout << "-->> Greeting from Creators <<--";
            cout << "\n\nThank You for using this program!";
            cout << "\n\nProgram will be returned by zero (0x0)!\nPress: CTRL+C || CTRL+Fn+C || Press any key, to exit instantly.\n\nExiting in...";
            system("TIMEOUT /T 7");
            cout << "\nAre you want to visit out team on gitHub? (y/n): ";
            cin >> authGit;
            if (authGit == 'y' || authGit == 'Y') {
                system("start https://github.com/BagasMahier12a");
                system("start https://github.com/svzax");
                exit(0);
            } else if (authGit == 'n' || authGit == 'N') {
                exit(0);
            } else {
                exit(0);
            };
        };

        cout << endl;

        // pilih menu program //
        CHOOSEMENU:switch (choose) {
            case 1:
                int i;
                system("CLS");
                cout << "-->> Program penambah data Dokter <<--";
                cout << "\n-->> Input 0 to back <<--";
                cout << "\n\nBerapa Dokter? (1-6): ";
                cin >> cntDok;
                if (cntDok == 0) {
                    system("CLS");
                    goto PROGMENU;
                };
                for (i = 1; i <= cntDok; i++) {
                    if (cntDok > 6) {
                        cout << "Terlalu banyak, mohon ulangi." << endl;
                        system("TIMEOUT /T 4");
                        system("CLS");
                        choose = 1;
                        goto CHOOSEMENU;
                    } else {
                        system("CLS");
                        cout << "-->> Program penambah data Dokter <<--";
                        cout << "\n\nInput nama Dokter " << i << ": ";
                        cin >> nDok;
                        P = alokasi_parent("dr." + nDok);
                        insertFirstParent(LP, P);
                        };
                    };
                    system("CLS");
                    cout << "\n" << i - 1 << " Dokter telah ditambahkan.\n";
                    system("TIMEOUT /T 7");
                    system("CLS");
                break;
            case 2:
                system("CLS");
                cout << "-->> Program penambah data Pasien <<--";
                cout << "\n-->> Input 0 to back <<--";
                cout << "\n\nBerapa Pasien? (1-6): ";
                cin >> cntPas;
                if (cntPas == 0) {
                    system("CLS");
                    goto PROGMENU;
                };
                for (i = 1; i <= cntPas; i++) {
                    if (cntPas > 6) {
                        cout << "Terlalu banyak, mohon ulangi." << endl;
                        system("TIMEOUT /T 4");
                        system("CLS");
                        choose = 2;
                        goto CHOOSEMENU;
                    } else {
                        system("CLS");
                    cout << "-->> Program penambah data Pasien <<--";
                    cout << "\n\nInput nama Pasien " << i << ": ";
                    cin >> nPas;
                    C = alokasi_child("ps." + nPas);
                    insertFirstChild(LC, C);
                    };
                };
                system("CLS");
                cout << "\n" << i - 1 << " Pasien telah ditambahkan.\n";
                system("TIMEOUT /T 7");
                system("CLS");
                break;
            case 3:
                system("CLS");
                cout << "-->> Program penambah relasi Dokter dengan Pasien (dan sebaliknya) <<--";
                cout << "\n\n1. Dokter - Pasien\n2. Pasien - Dokter\n0. Back\nPilih -->> ";
                cin >> Rdpd;
                if (Rdpd == 0) {
                    system("CLS");
                    goto PROGMENU;
                };
                if (Rdpd == 1) {
                    system("CLS");
                    cout << "-->> Program penambah relasi Dokter dengan Pasien <<--";
                    cout << "\n\nInput nama Dokter: ";
                    cin >> nRelDoc;
                    P = findElmParent(LP, "dr." + nRelDoc);
                    cout << "Input nama Pasien relasi: ";
                    cin >> nRelPas;
                    C = findElmChild(LC, "ps." + nRelPas);
                    R = alokasi(C);
                    insertFirst(child(P),R);
                } else if (Rdpd == 2) {
                    system("CLS");
                    cout << "-->> Program penambah relasi Pasien dengan Dokter <<--";
                    cout << "\n\nInput nama Pasien: ";
                    cin >> nRelPas;
                    C = findElmChild(LC, "ps." + nRelPas);
                    cout << "Input nama Dokter relasi: ";
                    cin >> nRelDoc;
                    P = findElmParent(LP, "dr." + nRelDoc);
                    R = alokasi(C);
                    insertFirst(child(P),R);
                } else {
                    system("CLS");
                    choose = 3;
                    goto CHOOSEMENU;
                };
                system("CLS");
                cout << "\nDokter " << nRelDoc << " telah direlasikan dengan Pasien " << nRelPas << ".\n";
                system("TIMEOUT /T 7");
                system("CLS");
                break;
            case 4: //KURANG DELETE DOKTER
                system("CLS");
                cout << "-->> Program penghapus data Dokter <<--";
                cout << "\n-->> Input 0 to back <<--";
                cout << "\n\nInput nama Dokter: ";
                cin >> delDoc;
                if (delDoc == "0") {
                    system("CLS");
                    goto PROGMENU;
                };
                removeParent(LP, "dr." + delDoc);
                system("TIMEOUT /T 7");
                system("CLS");
                break;
            case 5: //KURANG DELETE PASIEN
                system("CLS");
                cout << "-->> Program penghapus data Pasien <<--";
                cout << "\n-->> Input 0 to back <<--";
                cout << "\n\nInput nama Pasien: ";
                cin >> delPas;
                if (delPas == "0") {
                    system("CLS");
                    goto PROGMENU;
                };
                removeChild(LC, "ps." + delPas);
                system("TIMEOUT /T 7");
                system("CLS");
                break;
            case 6:
                system("CLS");
                cout << "-->> Program menampilkan data Dokter dan Pasien <<--";
                cout << "\n\n------DOKTER------\n" << endl;
                printInfoParentOnly(LP);
                cout << "\n------------------\n" << endl;
                cout << "\n------PASIEN------\n" << endl;
                printInfoChild(LC);
                cout << "\n------------------\n" << endl;
                system("PAUSE");
                system("CLS");
                break;
            case 7:
                system("CLS");
                cout << "-->> Program menampilkan relasi Dokter terhadap Pasien <<--";
                cout << "\n\n------DOKTER------\n" << endl;
                printInfoParent(LP);
                cout << "\n------------------\n" << endl;
                system("PAUSE");
                system("CLS");
                break;
            case 8:
                system("CLS");
                cout << "-->> Program menampilkan relasi Pasien terhadap Dokter <<--";
                cout << "\n\n------PASIEN------\n" << endl;
                printInfoCRel(LP);
                cout << "\n------------------\n" << endl;
                system("PAUSE");
                system("CLS");
                break;
            case 9:
                system("CLS");
                cout << "-->> Program menampilkan Dokter paling sibuk <<--";
                cout << "\n\n------DOKTER------\n" << endl;
                printBusyParent(LP);
                cout << "\n------------------\n" << endl;
                system("PAUSE");
                system("CLS");
                break;
            case 99:
                // ganti pasien (penambahan fungsionalitas) //
                system("CLS");
                cout << "-->> Program Ganti Pasien dengan nama Pasien baru! <<--";
                cout << "\n-->> Input 0 to back <<--";
                cout << "\n\nInput nama Pasien: ";
                cin >> rPas;
                if (rPas == "0") {
                    system("CLS");
                    goto PROGMENU;
                };
                C = findElmChild(LC, "ps." + rPas);
                cout << "Input nama Pasien baru: ";
                cin >> rPasNew;
                info(C) = "ps." + rPasNew;
                system("CLS");
                cout << "Pasien " << rPas << "digantikan dengan Pasien " << rPasNew << ".\n\n";
                break;
        };
    };

    return 0;
};
