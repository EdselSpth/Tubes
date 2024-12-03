#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#define firstVertex(G) G.firstVertex
#define namaGedung(V) V->namaGedung
#define nextVertex(V) V->nextVertex
#define firstEdge(V) V->firstEdge
#define nextEdge(E) E->nextEdge
#define gedungTujuan(E) E->gedungTujuan
#define namaJalan(E) E->namaJalan
#define jarak(E) E->jarak
#define waktuTempuh(E) E->waktuTempuh
using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    string namaGedung;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge{
    string gedungTujuan;
    string namaJalan;
    int jarak;
    int waktuTempuh;
    adrEdge nextEdge;
};

struct graph {
    adrVertex firstVertex;
};

void createVertex(string namaGedung, adrVertex &V);
void createEdge(string gedungTujuan, string namaJalan, int jarak, int waktuTempuh, adrEdge &E);
void initGraph(graph &G);
void addVertex(graph &G, string namaGedung);
void addEdge(graph &G, string gedungTujuan, string namaJalan, int jarak, int waktuTempuh);
void buildGraph(graph &G);
adrVertex findVertex(graph G, string namaGedung);
adrEdge findEdge(adrVertex V, string namaJalan, string namaGedung);
void shortestPath(graph G, string gedungtertutup, string start, string destination);
void findShortRoute(graph G, string start, string end);
void printGraph(graph G);
int calculateTotalDistance(graph G);
int calculateTotalTime(graph G);
#endif // TUBES_H_INCLUDED
