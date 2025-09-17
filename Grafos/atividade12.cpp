#include <bits/stdc++.h>
using namespace std;

// Função para multiplicar duas matrizes booleanas
vector<vector<int>> mult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            for(int k=0; k<n; ++k)
                C[i][j] |= (A[i][k] & B[k][j]);
    return C;
}

// Função para verificar se o grafo é desconexo
bool desconexo(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<vector<int>> reach = adj;
    // Soma as potências da matriz de adjacência
    for(int p=1; p<n-1; ++p) {
        reach = mult(reach, adj);
    }
    // Verifica se existe algum par de vértices sem caminho
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            if(i != j && reach[i][j] == 0)
                return true; // Desconexo
    return false; // Conexo
}

int main() {
    int n;
    cout << "Digite o número de vértices: ";
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Digite a matriz de adjacência (" << n << "x" << n << "):\n";
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> adj[i][j];
        }
    }
    if(desconexo(adj))
        cout << "O grafo é desconexo.\n";
    else
        cout << "O grafo é conexo.\n";
    return 0;
}