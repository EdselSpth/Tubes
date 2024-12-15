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
    
void findShortRoute(graph G, string gedungAwal, string gedungTujuan){
    // Menemukan Rute Terpendek
    adrVertex startVertex = findVertex(G, gedungAwal);
    adrVertex targetVertex = findVertex(G, gedungTujuan);

    if (startVertex == NULL || targetVertex == NULL) {
        cout << "Gedung tidak ditemukan dalam graf." << endl;
        return;
    }

    int distances[100]; // Menyimpan jarak minimum ke setiap vertex
    string previous[100]; // Menyimpan vertex sebelumnya dalam rute terpendek
    bool visited[100] = {false}; // Menandai vertex yang sudah dikunjungi

    // Inisialisasi
    adrVertex temp = firstVertex(G);
    int index = 0;
    string vertices[100];
    while (temp != NULL) {
        vertices[index] = namaGedung(temp);
        distances[index] = 9999; // Jarak awal dianggap tak terbatas
        previous[index] = "";
        temp = nextVertex(temp);
        index++;
    }

    distances[0] = 0; // Jarak ke vertex awal adalah 0

    int vertexCount = index; // Total jumlah vertex
    int minIndex = -1;

    // Proses utama (algoritma Djikstra tanpa break)
    bool allVisited = false;
    while (!allVisited) {
        int minDistance = 9999;
        minIndex = -1;

        // Cari vertex dengan jarak terkecil yang belum dikunjungi
        int i = 0;
        while (i < vertexCount) {
            if (!visited[i] && distances[i] < minDistance) {
                minDistance = distances[i];
                minIndex = i;
            }
            i++;
        }

        // Jika tidak ada lagi vertex yang tersisa untuk dijelajahi
        allVisited = true;
        for (int j = 0; j < vertexCount; j++) {
            if (!visited[j]) {
                allVisited = false;
                break;
            }
        }

        if (allVisited) continue;

        visited[minIndex] = true;
        string currentVertex = vertices[minIndex];

        // Memperbarui jarak ke vertex tetangga
        adrVertex current = findVertex(G, currentVertex);
        adrEdge edge = firstEdge(current);
        while (edge != NULL) {
            int neighborIndex = -1;
            int k = 0;
            while (k < vertexCount) {
                if (vertices[k] == gedungTujuan(edge)) {
                    neighborIndex = k;
                    k = vertexCount; // Menghentikan loop tanpa break
                }
                k++;
            }

            if (neighborIndex != -1) {
                int newDistance = distances[minIndex] + jarak(edge);
                if (newDistance < distances[neighborIndex]) {
                    distances[neighborIndex] = newDistance;
                    previous[neighborIndex] = currentVertex;
                }
            }

            edge = nextEdge(edge);
        }
    }

    // Membangun rute terpendek
    string path[100];
    int pathIndex = 0;
    string currentVertex = gedungTujuan;
    while (currentVertex != "") {
        path[pathIndex] = currentVertex;
        pathIndex++;
        int idx = -1;
        int i = 0;
        while (i < vertexCount) {
            if (vertices[i] == currentVertex) {
                idx = i;
                i = vertexCount; // Menghentikan loop tanpa break
            }
            i++;
        }
        currentVertex = previous[idx];
    }

    // Menampilkan rute terpendek
    cout << "Rute terpendek dari " << gedungAwal << " ke " << gedungTujuan << ":" << endl;
    for (int i = pathIndex - 1; i >= 0; i--) {
        cout << path[i];
        if (i > 0) {
            cout << " -> ";
        }
    }
    cout << endl;

    // Menampilkan jarak total
    int endIndex = -1;
    int i = 0;
    while (i < vertexCount) {
        if (vertices[i] == gedungTujuan) {
            endIndex = i;
            i = vertexCount; // Menghentikan loop tanpa break
        }
        i++;
    }

    cout << "Jarak total: " << distances[endIndex] << " satuan." << endl;

}


void findShortRoute(graph G, string gedungtertutup, string start, string end){
    // Menemukan Rute Terpendek pakai BFS
    
}

void printGraph(graph G){
    // menampilkan graph
<<<<<<< HEAD
    addVertex(G, "Gedung A");
    addVertex(G, "Gedung B");
    addVertex(G, "Gedung C");
    addVertex(G, "Gedung D");
    addVertex(G, "Gedung E");
    addVertex(G, "Gedung F");
    addVertex(G, "Gedung G");
    addVertex(G, "Gedung H");
    addVertex(G, "Gedung I");
    addVertex(G, "Gedung J");

    // Menambahkan edge antara vertex
    addEdge(G, "Gedung B", "Jalan 1", 5, 10); // Gedung A -> Gedung B, 5 satuan jarak, 10 menit waktu
    addEdge(G, "Gedung C", "Jalan 2", 7, 12); // Gedung A -> Gedung C, 7 satuan jarak, 12 menit waktu
    addEdge(G, "Gedung D", "Jalan 3", 4, 8);  // Gedung B -> Gedung D, 4 satuan jarak, 8 menit waktu
    addEdge(G, "Gedung C", "Jalan 4", 3, 6);  // Gedung B -> Gedung C, 3 satuan jarak, 6 menit waktu
    addEdge(G, "Gedung D", "Jalan 5", 2, 5);  // Gedung C -> Gedung D, 2 satuan jarak, 5 menit waktu
    addEdge(G, "Gedung A", "Jalan 6", 6, 10); // Gedung D -> Gedung A, 6 satuan jarak, 10 menit waktu
    addEdge(G, "Gedung A", "Jalan 6", 6, 10);
    addEdge(G, "Gedung A", "Jalan 6", 6, 10);
    addEdge(G, "Gedung A", "Jalan 6", 6, 10);



=======
    
>>>>>>> b79731a5a43c4d6bd00eb38177aca424c7e26a2a
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