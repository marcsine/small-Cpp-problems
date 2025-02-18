#include <limits.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        bool casAcabat = false;
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < m; i++) {
            int x, y, l;
            cin >> x >> y >> l;
            adjList[x].push_back({y, l});
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        Q.push({0, 0});
        while (!casAcabat && !Q.empty()) {
            int u = Q.top().second;
            if (u == 1) {
                cout << dist[1] << endl; // ACABA EL CAS
                casAcabat = true;
            }
            else {
                Q.pop();
                for (pair<int,int> p : adjList[u]) {
                    int v = p.first, l = p.second;
                    int maxDistRoute = max(l,dist[u]);
                    if (dist[v] > maxDistRoute) {
                        dist[v] = maxDistRoute;
                        Q.push({dist[v], v});
                    }
                }
            }
        }
    }
}