#include "tubes.h"
#include <iostream>
using namespace std;

void createVertex(string namaGedung, adrVertex &V){
    V = new vertex;
    namaGedung(V) = namaGedung;
    nextVertex(V) = NULL;
    firstEdge(V) = NULL;
}

void createEdge(string gedungTujuan, string namaJalan, int jarak, int waktuTempuh, adrEdge &E){
    E = new edge;
    gedungTujuan(E) = gedungTujuan;
    namaJalan(E) = namaJalan;
    jarak(E) = jarak;
    waktuTempuh(E) = waktuTempuh;
    nextEdge(E) = NULL;
}

void initGraph(graph &G){
    firstVertex(G) = NULL;
}

void addVertex(graph &G, string namaGedung){
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
