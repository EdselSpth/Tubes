#include <iostream>
#include "tubes.h"
using namespace std;

int main()
{
    string gedungAwal,gedungTujuan;
    string gedungToDelete;
    string gedungAsal, gedungTujuan, jalan;
    int jarak, waktu;
    int input;
    string gedungBaru;

    graph G;
    buildGraph(G);
    header();
    namaKelompok();
    footer();

    int pilihan = 999;
    while(pilihan != 0){
        header();
        menu();
        footer();
        cout << "Pilihan: ";
        cin >> pilihan;
        switch(pilihan){
            case 1:
                cout << "Menu 3" << endl;
                cout << "Print Seluruh Rute" << endl;
                printGraph(G);
            case 2:
                cout << "Menu 2" << endl;
                cout << "Cari Semua Rute" << endl;
                
                break;
            case 3:
                cout << "Menu 3" << endl;
                cout << "Mencari Rute Terpendek" << endl;
                
                findShortRoute(G, gedungAwal, gedungTujuan);
                break;
            case 4:
                cout << "Menu 4" << endl;
                cout << "Menginformasikan gedung Maintenance atau nonaktif" << endl;
                
                cout << "Masukkan nama gedung yang ingin dihapus: ";
                cin >> gedungToDelete;
                deleteVertex(G, gedungToDelete);
            case 5:
                cout << "Menu 5" << endl;
                cout << "Menambah gedung" << endl;
                cout << "1. Menambah Gedung"<<endl;
                cout << "2. Menambah Rute"<<endl;
                
                cin >> input;
                if(input == 1){
                    cout << "Masukkan nama gedung yang ingin ditambahkan: ";
                    cin >> gedungBaru;
                    addVertex(G, gedungBaru); 
                }
                if(input == 2){
                    
                    cout << "Masukkan nama gedung asal: ";
                    cin >> gedungAsal;
                    cout << "Masukkan nama gedung tujuan: ";
                    cin >> gedungTujuan;
                    cout << "Masukkan nama jalan: ";
                    cin >> jalan;
                    cout << "Masukkan waktu tempuh: ";
                    cin >> waktu;
                    cout << "Masukkan jarak (dalam km): ";
                    cin >> jarak;

                    addEdge(G, gedungAsal, gedungTujuan, jalan, waktu, jarak);
                }
            case 6:
                cout << "Menu 6" << endl;
                cout << "Menginformasikan gedung Maintenance atau nonaktif" << endl;

            case 0:
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilihan tidak Valid" << endl;

    }
}
}
