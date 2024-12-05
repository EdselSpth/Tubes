#include <iostream>
#include "tubes.h"
using namespace std;

int main()
{
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
                cout << "Menu 1" << endl;
                break;
            case 2:
                cout << "Menu 2" << endl;
                break;
            case 3:
                cout << "Menu 3" << endl;
                break;
            case 0:
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilihan tidak Valid" << endl;
    
    }
}
