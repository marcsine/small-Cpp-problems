#include <iostream>
#include <vector>
#include <queue>
#include <list>
 
#define DEBUG 0
 
using namespace std;
 
 
void ordenacio_topologica(vector< priority_queue<int,vector<int>,greater<int>>> & tasques, vector<int> &apuntados) {
    int n = tasques.size();
    queue<int> cola_prioridad;
 
    for (int i = 0; i < n; i++)
        if (apuntados[i] == 0) cola_prioridad.push(i);
 
    list<int> lista;
    while (not cola_prioridad.empty()) {
        int u = cola_prioridad.front();
        lista.push_back(u);
        cola_prioridad.pop();
        int m = tasques[u].size();
        while (!tasques[u].empty()) {
            int v = tasques[u].top();
            tasques[u].pop();
            if (--apuntados[v] == 0) cola_prioridad.push(v);
        }
    }
 
    if (not lista.empty()) {
		cout << lista.front(); 
		lista.pop_front();
	}
    while (not lista.empty()) {
        cout << ' ' << lista.front();
        lista.pop_front();
    }
}
 
int main() {
    int n, m;
    while (cin >> n >> m) {
        vector< priority_queue<int,vector<int>,greater<int>>> tasques(n);
        vector<int> apuntados(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            tasques[u].push(v);
            apuntados[v]++;
        }
        ordenacio_topologica(tasques, apuntados);
        cout << endl;
    }
}