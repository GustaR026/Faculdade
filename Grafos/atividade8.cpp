#include <bits/stdc++.h>
using namespace std;

bool ehBipartito(const vector<vector<int>>& grafo, int V) {
    vector<int> color(V, -1); // -1: não colorido, 0 e 1: colorido

    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : grafo[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else {
                        if (color[v] == color[u]) {
                        return false; // cores iguais em vértices adjacentes
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int V, E;
    cout << "Digite o número de vértices e arestas: ";
    cin >> V >> E;

    vector<vector<int>> grafo(V);

    cout << "Digite as " << E << " arestas (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u); 
    }

    if (ehBipartito(grafo, V))
        cout << "O grafo eh bipartido.\n";
    else
        cout << "O grafo não eh bipartido.\n";

    return 0;
}