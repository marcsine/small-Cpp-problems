#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQpairInt;

void ordenacio_topologica(vector<vector<int>> &tasques, PQpairInt &apuntados, vector<int> &vApuntados) {
    int n = tasques.size(), count = 0;
    bool firstDone = false;

    while (!apuntados.empty() && count < n) {
        // Obtener el nodo con el menor degree
        int u = apuntados.top().second;
        apuntados.pop();

        // Imprimir el nodo
        count++;
        if (!firstDone)
            firstDone = true;
        else
            cout << ' ';
        cout << u;

        // Reducir el grado de los vecinos y actualizar en la cola
        for (int v : tasques[u]) {
            vApuntados[v]--; // Reducir grado
            apuntados.push({vApuntados[v], v}); // Actualizar la prioridad
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> tasques(n);
        vector<int> vApuntados(n, 0);
        PQpairInt apuntados;

        // Leer las relaciones y calcular grados de entrada
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            tasques[u].push_back(v);
            vApuntados[v]++;
        }

        // Insertar nodos con grado de entrada inicial en la cola
        for (int i = 0; i < n; ++i) {
            if (vApuntados[i] == 0) {
                apuntados.push({0, i});
            }
        }

        ordenacio_topologica(tasques, apuntados, vApuntados);
        cout << endl;
    }
}
