#include <iostream>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

int main() {
    // greeting identitas pembuat dan tujuan program //
    cout << "-->> Program Relasi M-N (Pasien dengan Dokter) <<--\n\n\n";
    cout << "Program Name       : Data Berobat" << endl;
    cout << "Program Language   : C++" << endl;
    cout << "Created by         : Sultan Kautsar | Bagas Alfito Prismawan" << endl;
    cout << "Id Creator         : 1303194010     | 1303193027" << endl;
    cout << "Description        : Program data berobat pasien beserta relasinya" << endl;
    cout << "                     dibuat untuk memenuhi tugas besar matakuliah Algoritma dan Struktur Data.\n" << endl;
    system("TIMEOUT /T 7 /NOBREAK");
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
    int choose = 1;
    int cntDok;
    int cntPas;

    // algoritma main //
    createListParent(LP);
    createListChild(LC);

    while (choose != 0) {
        cout << "Menu Program\n1. -->> Tambah Dokter.\n2. -->> Tambah Pasien.\n3. -->> Tambah relasi Dokter dengan Pasien.\n4. -->> Hapus Dokter.\n5. -->> Hapus Pasien.\n6. -->> Tampilkan seluruh data Dokter dan Pasien.\n7. -->> Tampilkan Dokter yang menangani Pasien.\n8. -->> Tampilkan Pasien yang ditangani Dokter.\n9. -->> Tampilkan status Dokter.\n0. -->> Exit (Program)\nPilih -->> ";
        cin >> choose;

        if (choose == 0) {
            system("CLS");
            cout << "-->> Greeting from Creators <<--";
            cout << "\n\nThank You for using this program!";
            cout << "\n\nProgram will be returned by zero (0x0)!\nPress: CTRL+C || CTRL+Fn+C to exit instantly\n\nExiting in...";
            system("TIMEOUT /T 7 /NOBREAK");
            exit(0);
        };

        cout << endl;

        // pilih menu program //
        CHOOSEMENU:switch (choose) {
            case 1:
                int i;
                system("CLS");
                cout << "-->> Program penambah data Dokter <<--";
                cout << "\n\nBerapa Dokter? (1-6): ";
                cin >> cntDok;
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
                cout << "\n\nBerapa Pasien? (1-6): ";
                cin >> cntPas;
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
                    cout << "\n\nInput nama Pasien: ";
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
                cout << "-->> Program penambah relasi Dokter dengan Pasien <<--";
                cout << "\n\nInput nama Dokter: ";
                cin >> nRelDoc;
                P = findElmParent(LP, "dr." + nRelDoc);
                cout << "Input nama Pasien relasi: ";
                cin >> nRelPas;
                C = findElmChild(LC, "ps." + nRelPas);
                R = alokasi(C);
                insertFirst(child(P),R);
                system("CLS");
                cout << "\nDokter " << nRelDoc << " telah direlasikan dengan Pasien " << nRelPas << ".\n";
                system("TIMEOUT /T 7");
                system("CLS");
                break;
            case 4: //KURANG DELETE DOKTER
                system("CLS");
                cout << "-->> Program penghapus data Dokter <<--";
                cout << "\n\nInput nama Dokter: ";
                cin >> delDoc;
                system("CLS");
                cout << "\nDokter " << delDoc << " telah dihapus.\n";
                system("TIMEOUT /T 7");
                system("CLS");
                break;
            case 5: //KURANG DELETE PASIEN
                system("CLS");
                cout << "-->> Program penghapus data Dokter <<--";
                cout << "\n\nInput nama Pasien: ";
                cin >> delPas;
                system("CLS");
                cout << "\nPasien " << delPas << " telah dihapus.\n";
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
                printInfoParent(LP);
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
                system("CLS");
                cout << "-->> Program Ganti Pasien dengan nama Pasien baru! <<--";
                cout << "\n\nInput nama Pasien: ";
                cin >> rPas;
                C = findElmChild(LC, "ps." + rPas);
                cout << "Input nama Pasien baru: ";
                cin >> rPasNew;
                info(C) = "ps." + rPasNew;
                system("CLS");
                cout << "Pasien " << rPas << "digantikan dengan Pasien " << rPasNew << ".\n\n";
                break;
        };
    };

    // ganti pasien (penambahan fungsionalitas //
    cout << "-->> Ganti Pasien dengan nama Pasien baru! <<--\n";
    cout << "Input nama Pasien: ";
    cin >> rPas;
    C = findElmChild(LC, "ps." + rPas);
    cout << "Input nama Pasien baru: ";
    cin >> rPasNew;
    info(C) = "ps." + rPasNew;
    cout << "Ganti relasi pasien? (y/n): ";
    cin >> ryn;

    while (ryn == "y" || ryn == "Y") {
        cout << "\nMasukan kembali!\nInput nama Pasien: ";
        cin >> rPas;
        C = findElmChild(LC, "ps." + rPas);
        cout << "Input nama Pasien baru: ";
        cin >> rPasNew;
        info(C) = "ps." + rPasNew;
        cout << "Ganti relasi pasien? (y/n): ";
        cin >> ryn;
    };

    return 0;
}
