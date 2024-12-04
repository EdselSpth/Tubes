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

void createEdge(string gedungTujuan, string namaJalan, int jarak, int waktuTempuh, adrEdge &E){
    //membuat edge (jalan)
    E = new edge;
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

void addEdge(graph &G, string gedungTujuan, string namaJalan, int jarak, int waktuTempuh){
    // menambahkan edge (jalan) ke graph
    int a = 1;
    adrVertex V = findVertex(G, gedungTujuan);
    adrEdge E;
    createEdge(gedungTujuan, namaJalan, jarak, waktuTempuh, E);
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

adrVertex findVertex(graph &G, string namaGedung){
    // mencari vertex (gedung) yang memiliki nama yang sama dengan input
    adrVertex P = firstVertex(G);
    while(P!= NULL && namaGedung(P)!= namaGedung){
        P = nextVertex(P);
    }
    return P;
}

void findShortRoute(graph G, string gedungtertutup, string start, string end){
    // Menemukan Rute Terpendek
    
}

void printGraph(graph G){
    // menampilkan graph

}

int calculateTotalDistance(graph G, string gedungAwal, string gedungTujuan){
    // menghitung total jarak

}

int calculateTotalTime(graph G, string gedungAwal, string gedungTujuan){
    // menghitung total waktu tempuh

}
