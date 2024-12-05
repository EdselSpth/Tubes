#include <iostream>
#include "tubes.h"
using namespace std;

void createVertex(string namaGedung, adrVertex &V){
    // membuat vertex (gedung)
    V = new vertex;
    namaGedung(V) = namaGedung;
    nextVertex(V) = NULL;
    firstEdge(V) = NULL;
}

void createEdge(string gedungAwal,string gedungTujuan, string namaJalan, int jarak, int waktuTempuh, adrEdge &E){
    //membuat edge (jalan)
    E = new edge;
    gedungAwal(E) = gedungAwal;
    gedungTujuan(E) = gedungTujuan;
    namaJalan(E) = namaJalan;
    jarak(E) = jarak;
    waktuTempuh(E) = waktuTempuh;
    nextEdge(E) = NULL;
}

void initGraph(graph &G){
    // insiasi graph
    firstVertex(G) = NULL;
}

void addVertex(graph &G, string namaGedung){
    // menambahkan vertex (gedung) ke graph
    adrVertex V;
    createVertex(namaGedung, V);
    if(firstVertex(G) == NULL){
        firstVertex(G) = V;
    } else {
        adrVertex P = firstVertex(G);
        while(nextVertex(P)!= NULL){
            P = nextVertex(P);
        }
        nextVertex(P) = V;
    }
}

adrVertex findVertex(graph G, string namaGedung){
    // mencari vertex (gedung) yang memiliki nama yang sama dengan input
    adrVertex P = firstVertex(G);
    while(P!= NULL){
        if (namaGedung(P) == namaGedung){
            return P;
        }
        P = nextVertex(P);
    }
    return NULL;
}

void addEdge(graph &G, string gedungAwal, string gedungTujuan, string namaJalan, int jarak, int waktuTempuh){
    // menambahkan edge (jalan) ke graph
    adrVertex V = findVertex(G, gedungTujuan);
    adrEdge E;
    createEdge(gedungAwal,gedungTujuan, namaJalan, jarak, waktuTempuh, E);
    if(firstEdge(V) == NULL){
        firstEdge(V) = E;
    } else {
        adrEdge P = firstEdge(V);
        while(nextEdge(P)!= NULL){
            P = nextEdge(P);
        }
        nextEdge(P) = E;
    }
}

void buildGraph(graph &G){
    // membangun graph

}
    

void findShortRoute(graph G, string gedungtertutup, string start, string end){
    // Menemukan Rute Terpendek pakai BFS
    
}

void printGraph(graph G){
    // menampilkan graph
    
}

int calculateTotalDistance(graph G, string gedungAwal, string gedungTujuan){
    // menghitung total jarak
    int totalDistance = 0;
    adrVertex Pawal = findVertex(G, gedungAwal);
    if (Pawal == NULL){
        cout << "Gedung awal tidak ditemukan" << endl;
        return 0;
    }
    adrEdge Pedge = firstEdge(Pawal);
    while (Pedge != NULL){
        totalDistance += jarak(Pedge);
        if(gedungTujuan(Pedge) == gedungTujuan){
            return totalDistance;
        }
        Pedge = nextEdge(Pedge);
    }
    
    cout << "Tidak ditemukan rute dari gedung " << gedungAwal << "menuju " << gedungTujuan << endl;
    return 0;
}

int calculateTotalTime(graph G, string gedungAwal, string gedungTujuan){
    // menghitung total waktu tempuh
    int totalTime = 0;
    adrVertex Pawal = findVertex(G, gedungAwal);
    if (Pawal == NULL){
        cout << "Gedung awal tidak ditemukan" << endl;
        return 0;
    }
    adrEdge Pedge = firstEdge(Pawal);
    while (Pedge != NULL){
        totalTime += waktuTempuh(Pedge);
        if(gedungTujuan(Pedge) == gedungTujuan){
            return totalTime;
        }
        Pedge = nextEdge(Pedge);
    }
    
    cout << "Tidak ditemukan rute dari gedung " << gedungAwal << "menuju " << gedungTujuan << endl;
    return 0;
}

void printGraph(graph G){
    // menampilkan graph
    if (firstVertex(G) == NULL){
        cout << "Rute Gedung Sedang Maintanance" << endl;
    } else {
        cout << "Seluruh gedung dan rute : " << endl;
        adrVertex Pvertex = firstVertex(G);
        while(Pvertex!= NULL){
            cout << "Gedung : " << namaGedung(Pvertex) << endl;
            adrEdge Pedge = firstEdge(Pvertex);
            while(Pedge!= NULL){
                cout << "\tRute : " << namaJalan(Pedge) << " - " << gedungTujuan(Pedge) << "-" << " jarak : " << jarak(Pedge) << " km" << " waktu tempuh : " << waktuTempuh(Pedge) << endl;
                Pedge = nextEdge(Pedge);
            }
            cout << endl;
            Pvertex = nextVertex(Pvertex);
    
    }
}

void menu(){
    // menu program
    cout << "(1) Print Seluruh Graph" << endl;
    cout << "(2) Cari Semua Rute Menuju Gedung" << endl;
    cout << "(3) Cari Rute Terpendek Menuju Gedung" << endl;
    cout << "(4) Menginfokan Gedung Maintanance" << endl;
    cout << "(7) Mencari Gedung Maintenance atau Nonaktif" << endl;
    cout << "(5) Menghitung Total Waktu Tempuh Rute" << endl;
    cout << "(6) Menghitung Total Jarak Rute" << endl;
    cout << "(9) Tambah Gedung" << endl;
    cout << "(0) Keluar" << endl;
    cout << "Pilih menu: ";
}

void header(){
    // header program
    cout << "=======================================================================" << endl;
}

void footer(){
    // footer program
    cout << "=======================================================================" << endl;

}

void nama_kelompok(){
    cout  << "Edsel Septa Haryanto | 103022300016" << endl;
    cout << "Muhammad Fauzan | 103022300065" << endl;
}