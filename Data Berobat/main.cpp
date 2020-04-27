// include needed //
#include <iostream>
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"
#define MAX_LOAD 1000
using namespace std;

int main() {
    // greeting author identity and purpose the program //
    cout << "-->> Program Relasi M-N (Dokter dan Pasien | Data Berobat) <<--\n\n\n";
    cout << "Program Name       : Data Berobat" << endl;
    cout << "Program Language   : C++" << endl;
    cout << "Created by         : Sultan Kautsar | Bagas Alfito Prismawan" << endl;
    cout << "Id Creator         : 1303194010     | 1303193027" << endl;
    cout << "Description        : Program data berobat pasien beserta relasinya" << endl;
    cout << "                     dibuat untuk memenuhi tugas besar matakuliah Algoritma dan Struktur Data.\n" << endl;
    system("TIMEOUT /T 7");
    system("CLS");

    // dictionary variable //
    // all list //
    list_parent LP;
    list_child LC;

    // all address //
    address_child C;
    address_parent P;
    address_relasi R;

    // all string //
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

    int k_max;

    int maksimum;

    maksimum = 5;

    // character //
    char authGit;

    // all integer //
    int choose = 1;
    int cntDok;
    int cntPas;
    int Rdpd;
    int stp = 0;
    int cStp;
    int mStp = 0;
    int mCtp = 0;
    int mCtpC;
    int cekJump = 0;

    // array //
    string stopDok [MAX_LOAD];
    string machDok [MAX_LOAD];

    // main algorithm started //
    createListParent(LP);
    createListChild(LC);

    // menu of program //
   while (true) {
        PROGMENU:cout << "Menu Program\n1. -->> Tambah Dokter.\n2. -->> Tambah Pasien.\n3. -->> Tambah relasi Dokter dengan Pasien.\n4. -->> Hapus Dokter.\n5. -->> Hapus Pasien.\n6. -->> Tampilkan seluruh data Dokter dan Pasien.\n7. -->> Tampilkan Dokter yang menangani Pasien.\n8. -->> Tampilkan Pasien yang ditangani Dokter.\n9. -->> Tampilkan status Dokter.\n99.-->> Ganti nama Pasien.\n0. -->> Exit (Program)\nPilih -->> ";
        cin >> choose;
        if (choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5 && choose != 6 && choose != 7 && choose != 8 && choose != 9 && choose != 99 && choose != 0) {
            system("CLS");
            choose = 1;
            goto PROGMENU;
        };

        // greeting and exiting program //
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

        // switch case of choosing menu //
        CHOOSEMENU:switch (choose) {
            case 1:
                // adding doctor //
                int i;
                int cntDok;

                whiledok:system("CLS");
                cout << "-->> Program penambah data Dokter <<--";
                cout << "\n-->> Input 0 to back <<--";
                cout << "\n\nBerapa Dokter? (1-6): ";


                while(!(cin >> cntDok)){
                    system("CLS");
                    cout<<"\nInvalid Input. Try Again!";
                    cin.clear();
                    cin.ignore(100, '\n');
                    system("TIMEOUT /T 7");
                    system("CLS");
                    goto whiledok;

                }

                if (cntDok > 6 ) {
                        cout << "Jumlah terlalu banyak, mohon ulangi." << endl;
                        system("TIMEOUT /T 4");
                        system("CLS");
                      //  choose = 1;
                        goto CHOOSEMENU;

                    }
                if (cntDok == 0) {
                    system("CLS");
                    goto PROGMENU;
                };

                for (i = 1; i <= cntDok; i++) {

                        system("CLS");
                        cout << "-->> Program penambah data Dokter <<--";
                        cout << "\n\nInput nama Dokter " << i << ": ";
                        cin >> nDok;
                        P = alokasi_parent("dr." + nDok);
                        insertFirstParent(LP, P);

                    };

                    system("CLS");
                    cout << "\n" << i - 1 << " Dokter telah ditambahkan.\n";
                    system("TIMEOUT /T 7");
                    system("CLS");

                break;
            case 2:
                // adding patient //
               int j;


                whilepas:system("CLS");
                cout << "-->> Program penambah data Pasien <<--";
                cout << "\n-->> Input 0 to back <<--";
                cout << "\n\nBerapa Pasien? (1-6): ";


                while(!(cin >> cntPas)){
                    system("CLS");
                    cout<<"\nInvalid Input. Try Again!";
                    cin.clear();
                    cin.ignore(100, '\n');
                    system("TIMEOUT /T 7");
                    system("CLS");
                    goto whilepas;

                }

                if (cntPas >= 6 ) {
                        cout << "Jumlah terlalu banyak, mohon ulangi." << endl;
                        system("TIMEOUT /T 4");
                        system("CLS");
                      //  choose = 1;
                        goto whilepas;

                    }
                if (cntDok == 0) {
                    system("CLS");
                    goto PROGMENU;
                };

                for (j = 1; j <= cntPas; j++) {

                        system("CLS");
                        cout << "-->> Program penambah data Pasien <<--";
                        cout << "\n\nInput nama Pasien " << j << ": ";
                        cin >> nPas;
                        C = alokasi_child("ps." + nPas);
                        insertFirstChild(LC, C);

                    };

                    system("CLS");
                    cout << "\n" << j - 1 << " Dokter telah ditambahkan.\n";
                    system("TIMEOUT /T 7");
                    system("CLS");

                    break;
            LOOPCASE3:case 3:
                // adding relation (reversing) //
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
                    if (P == NULL) {
                        system("CLS");
                        cout << "\nDokter dr." << nRelDoc << " tidak ditemukan.\n";
                        system("TIMEOUT /T 7");
                        system("CLS");
                        goto LOOPCASE3;
                    };
                    cout << "Input nama Pasien relasi: ";
                    cin >> nRelPas;
                    C = findElmChild(LC, "ps." + nRelPas);
                    if (C == NULL) {
                        system("CLS");
                        cout << "\nPasien ps." << nRelPas << " tidak ditemukan.\n";
                        system("TIMEOUT /T 7");
                        system("CLS");
                        goto LOOPCASE3;
                    };
                    stopDok[stp] = nRelPas;
                    stp++;
                    cStp = 0;
                    if (cekJump == 0) {
                        goto WHILE1;
                    } else {
                        goto IF1;
                    };
                    IF1:if (true) {
                        mCtpC = 0;
                        while (mCtpC <= MAX_LOAD) {
                            if (machDok[mCtpC] == nRelPas) {
                                system("CLS");
                                cout << "\nTerlalu banyak relasi!\n";
                                system("TIMEOUT /T 7");
                                system("CLS");
                                goto PROGMENU;
                            } else {
                                mCtpC++;
                            };
                        };
                    };
                    WHILE1:while (cStp <= MAX_LOAD) {
                        if (stopDok[cStp] == nRelPas) {
                            mStp++;
                            cStp++;
                            if (mStp > 15) {
                                machDok[mCtp] = nRelPas;
                                mCtp++;
                                stp = 0;
                                mStp = 0;
                                cekJump = 1;
                                nRelPas = "";
                                goto IF1;
                            };
                        } else {
                            cStp++;
                        };
                    };
                    R = alokasi(C);
                    insertFirst(child(P),R);
                    system("CLS");
                    cout << "\nDokter " << nRelDoc << " telah direlasikan dengan Pasien " << nRelPas << ".\n";
                } else if (Rdpd == 2) {
                    system("CLS");
                    cout << "-->> Program penambah relasi Pasien dengan Dokter <<--";
                    cout << "\n\nInput nama Pasien: ";
                    cin >> nRelPas;
                    C = findElmChild(LC, "ps." + nRelPas);



                    if(maxPasien(child(P), k_max) <= 5){
                        cout << "Input nama Dokter relasi: ";
                        cin >> nRelDoc;
                        P = findElmParent(LP, "dr." + nRelDoc);
                        R = alokasi(C);
                        insertFirst(child(P),R);
                        system("CLS");
                        cout << "\nPasien " << nRelPas << " telah direlasikan dengan Dokter " << nRelDoc << ".\n";
                    }else{
                        cout<<"List Penuh";
                    }
                    if (C == NULL) {
                        system("CLS");
                        cout << "\nPasien ps." << nRelPas << " tidak ditemukan.\n";
                        system("TIMEOUT /T 7");
                        system("CLS");
                        goto LOOPCASE3;
                    };
                    stopDok[stp] = nRelPas;
                    stp++;
                    cStp = 0;
                    if (cekJump == 0) {
                        goto WHILE2;
                    } else {
                        goto IF2;
                    };
                    IF2:if (true) {
                        mCtpC = 0;
                        while (mCtpC <= MAX_LOAD) {
                            if (machDok[mCtpC] == nRelPas) {
                                system("CLS");
                                cout << "\nTerlalu banyak relasi!\n";
                                system("TIMEOUT /T 7");
                                system("CLS");
                                goto PROGMENU;
                            } else {
                                mCtpC++;
                            };
                        };
                    };
                    WHILE2:while (cStp <= MAX_LOAD) {
                        if (stopDok[cStp] == nRelPas) {
                            mStp++;
                            cStp++;
                            if (mStp > 15) {
                                machDok[mCtp] = nRelPas;
                                mCtp++;
                                stp = 0;
                                mStp = 0;
                                cekJump = 1;
                                nRelPas = "";
                                goto IF2;
                            };
                        } else {
                            cStp++;
                        };
                    };
                    cout << "Input nama Dokter relasi: ";
                    cin >> nRelDoc;
                    P = findElmParent(LP, "dr." + nRelDoc);
                    if (P == NULL) {
                        system("CLS");
                        cout << "\nDokter dr." << nRelDoc << " tidak ditemukan.\n";
                        system("TIMEOUT /T 7");
                        system("CLS");
                        goto LOOPCASE3;
                    };
                    R = alokasi(C);
                    insertFirst(child(P),R);
                    system("CLS");
                    cout << "\nPasien " << nRelPas << " telah direlasikan dengan Dokter " << nRelDoc << ".\n";
                } else {
                    system("CLS");
                    choose = 3;
                    goto CHOOSEMENU;
                };

                system("TIMEOUT /T 7");
                system("CLS");

                break;
            case 4:
                // delete doctor //
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
            case 5:
                // delete patient //
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
                // view all data //
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
                // view relation of doctor to patient //
                system("CLS");
                cout << "-->> Program menampilkan relasi Dokter terhadap Pasien <<--";
                cout << "\n\n------DOKTER------\n" << endl;
                printInfoParent(LP);
                cout << "\n------------------\n" << endl;
                system("PAUSE");
                system("CLS");

                break;
            case 8:
                // view relation of patient to doctor //
                system("CLS");
                cout << "-->> Program menampilkan relasi Pasien terhadap Dokter <<--";
                cout << "\n\n------PASIEN------\n" << endl;
                printInfoCRel(LP);
                cout << "\n------------------\n" << endl;
                system("PAUSE");
                system("CLS");

                break;
            case 9:
                // view busy status of doctor //
                system("CLS");
                cout << "-->> Program menampilkan Dokter paling sibuk <<--";
                cout << "\n\n-------BUSY-------\n" << endl;
                printBusyParent(LP);
                cout << "\n------------------\n" << endl;
                system("PAUSE");
                system("CLS");

                break;
            case 99:
                // swipe patient (additional) //
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

    // program always be returned to 0 //
    return 0;
};
