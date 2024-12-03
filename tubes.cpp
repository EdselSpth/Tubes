#include "tubes.h"
#include <iostream>
using namespace std;

void createVertex(string namaGedung, adrVertex &V){
    V = new vertex;
    namaGedung(V) = namaGedung;
    nextVertex(V) = NULL;
    firstEdge(V) = NULL;
}