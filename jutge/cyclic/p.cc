#include<vector>
#include<iostream>
using namespace std;

bool hasCycles(const vector<vector<int>>& adjList, vector<bool>& encountered, vector<bool>& done, int u) {
    encountered[u] = true;
    done[u] = true;
    for (int v : adjList[u]) {
        if (encountered[v])
            return true;
        if (!done[v] &&  hasCycles(adjList, encountered, done, v))
            return true;
    }
    encountered[u] = false;
    return false;
}

bool hasCycles(const vector<vector<int>>& adjList) {
    vector<bool> encountered(adjList.size(), false);
    vector<bool> done(adjList.size(), false);
    for (int i = 0; i < adjList.size(); i++)
        if (! done[i] && hasCycles(adjList, encountered, done, i))
            return true;
    return false;
}

int main() {
    int n,m;
    while(cin >> n>> m) {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < m;i++) {
            int u,v;
            cin >> u>> v;
            adjList[u].push_back(v);
        }

        if (hasCycles(adjList)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}