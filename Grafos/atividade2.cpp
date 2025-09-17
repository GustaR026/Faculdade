#include <iostream>
#include <vector>

using namespace std;

int main() {
    int v, a;
    cout << "Digite o numero de vertices: ";
    cin >> v;
    cout << "Digite o numero de arestas: ";
    cin >> a;

    int inc[v][a];
    cout << "Digite a matriz de incidencia:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < a; j++) {
            cin >> inc[i][j];
        }
    }

    cout << "\nGraus dos vertices:\n";
    for (int i = 0; i < v; i++) {
        int grauEntrada = 0, grauSaida = 0;
        for (int j = 0; j < a; j++) {
            if (inc[i][j] == -1) grauEntrada++;
            if (inc[i][j] == 1) grauSaida++;
        }
        cout << "Vertice " << i << ": Entrada = " << grauEntrada << ", Saida = " << grauSaida << endl;
    }
    
    int adj[v][v];
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }

    for (int j = 0; j < a; j++) {
        int origem = -1, destino = -1;
        for (int i = 0; i < v; i++) {
            if (inc[i][j] == 1) origem = i;
            if (inc[i][j] == -1) destino = i;
        }
        if (origem != -1 && destino != -1) {
            adj[origem][destino] = 1;
        }
    }

    cout << "\nMatriz de Adjacencia:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}