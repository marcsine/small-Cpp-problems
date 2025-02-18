
#include<vector>
#include<iostream>
using namespace std;

bool isForest(const vector<vector<int>>& adjList, vector<bool>& visited, int u, int prev) {
    for(int v : adjList[u]) {
        if (prev != v) {
        if (visited[v])
            return false;
        visited[v] = true;
        if (!isForest(adjList, visited, v, u))
            return false;
        }
    }
    return true;
}

bool isForest(const vector<vector<int>>& adjList, int& numCC) {
    vector<bool> visited(adjList.size(),false);
    numCC = 0;
    for(int i = 0; i < adjList.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            if (! isForest(adjList, visited, i, i))
                return false;
            numCC++;
        }
    }
    return true;
}

int main() {
    int n,m;
    while (cin>>n>>m) {
        vector<vector<int>> adjList(n);

        for(int i= 0;i<m;i++) {
            int x,y;
            cin >> x >> y;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        int NumConexComp;
        if (isForest(adjList, NumConexComp)) cout << NumConexComp << endl;
        else cout << "no" << endl;
        
    }
}