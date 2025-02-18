#include<list>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;

void printLexicDAG(const vector<vector<int>>& adjList, vector<int>& numArcsTo) {
    priority_queue<int, vector<int>, greater<int>> Q;
    
    for (int i = 0; i<numArcsTo.size(); i++) {
        if (numArcsTo[i] == 0)
            Q.push(i);
    }
    bool firstDone = false;
    while (!Q.empty()) {
        int u = Q.top(); Q.pop();
        if (firstDone) cout << ' ';
        else firstDone = true;
        cout << u;
        for(int v : adjList[u]) {
            if (--numArcsTo[v] == 0)
                Q.push(v);
        }
    }
    if (firstDone) cout << endl;
}

int main() {
    int n,m;
    while (cin >> n >>m) {
        vector<vector<int>> adjList(n);
        vector<int> numArcsTo(n);
        for (int i = 0;i<m;i++) {
            int x,y;
            cin >> x >> y;
            adjList[x].push_back(y);
            numArcsTo[y]++;
        }
        printLexicDAG(adjList, numArcsTo);
    }
}