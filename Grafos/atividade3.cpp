#include <bits/stdc++.h>
using namespace std;

bool validarMatriz(int matriz[100][100], int n) {
    for (int i = 0; i < n; i++) {
        if (matriz[i][i] != 0) {
            cout << "A diagonal deve ser 0.\n";
            return false;
        }
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] != 0 && matriz[i][j] != 1) {
                cout << "A matriz deve conter apenas 0 ou 1.\n";
                return false;
            }
            if (matriz[i][j] != matriz[j][i]) {
                cout << "A matriz deve ser simétrica.\n";
                return false;
            }
        }
    }
    return true;
}
int main() {
    int n;
    int matriz[100][100];
    cout << "Digite o numero de vertices: ";
    cin >> n;
    if (n <= 0) {
        cout << "Numero de vertices invalido.\n";
        return 0;
    }
    cout << "Digite a matriz de adjacencia:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }
    if (!validarMatriz(matriz, n)) {
        return 0;
    }
    cout << "Grau de cada vertice:\n";
    for (int i = 0; i < n; i++) {
        int grau = 0;
        cout << "Vertice " << i << ": {";
        for (int j = 0; j < n; j++) {
            grau += matriz[i][j];
            cout << matriz[i][j];
            if (j < n-1) cout << " ";
        }
        cout << "} grau " << grau << '\n';
    }
    
    cout << "Lista de adjacencia:\n";
    vector<vector<int>> lista(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (matriz[i][j] == 1){
                lista[i].push_back(j+1);
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << "Vertice " << i + 1 << "-> ";
        for (int x : lista[i]) cout << x << " ";
        cout << '\n';
    }
}
