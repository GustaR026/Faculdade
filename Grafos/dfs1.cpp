#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, const vector<vector<int>>& adj, vector<bool>& visitado, vector<bool>& pilhaRec) {
    visitado[v] = true;
    pilhaRec[v] = true;

    for (int vizinho : adj[v]) {
        if (!visitado[vizinho] && dfs(vizinho, adj, visitado, pilhaRec)){
            return true;
        }else{
            if (pilhaRec[vizinho]){
                return true;
            }
        }
    }

    pilhaRec[v] = false;
    return false;
}

bool temCiclo(int V, const vector<vector<int>>& adj) {
    vector<bool> visitado(V, false);
    vector<bool> pilhaRec(V, false);

    for (int i = 0; i < V; i++) {
        if (!visitado[i]) {
            if (dfs(i, adj, visitado, pilhaRec))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Digite o numero de vertices e arestas: ";
    cin >> V >> E;
    vector<vector<int>> adj(V);

    cout << "Digite as arestas (origem destino):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (temCiclo(V, adj))
        cout << "O grafo tem um ciclo." << endl;
    else
        cout << "O grafo nao tem um ciclo." << endl;

    return 0;
}