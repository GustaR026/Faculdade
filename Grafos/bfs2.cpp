#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Informe o numero de vertices e arestas do grafo:\n";
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Informe as arestas do grafo (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // grafo não direcionado
    }

    cout << "Informe o vertice inicial e o vertice destino:\n";
    int start, target;
    cin >> start >> target;

    vector<int> dist(n, -1), parent(n, -1);
    queue<int> bfs;  // fila da BFS

    // inicia a busca no vértice inicial
    dist[start] = 0;
    bfs.push(start);

    // BFS
    while (!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) { // ainda não visitado
                dist[v] = dist[u] + 1;
                parent[v] = u;   // registra quem levou até v
                bfs.push(v);
            }
        }
    }

    if (dist[target] == -1) {
        cout << "Nao existe caminho entre " << start << " e " << target << "\n";
    } else {
        cout << "Distancia minima: " << dist[target] << "\n";

        // reconstruindo o caminho usando parent[]
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Caminho: ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i] << (i + 1 < path.size() ? " -> " : "\n");
        }
    }
}
