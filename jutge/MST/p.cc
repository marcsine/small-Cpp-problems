#include<queue>
#include<iostream>
#include<vector>
using namespace std;

int MST(const vector<vector<pair<int,int>>>& wAdjList) {
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push({0,0});
    vector<bool> visited(wAdjList.size(), false);
    int ret = 0, nodesVisited = 0;
    while (! Q.empty()) {
        pair<int,int> u = Q.top();Q.pop();
        if (! visited[u.second]) {
            visited[u.second] = true;
            ret += u.first; nodesVisited++;
            if (nodesVisited == wAdjList.size())
                return ret;
            for (pair<int,int> v : wAdjList[u.second]) { //quizas optimizable por dobles aristas
                Q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    int n,m;
    while (cin >> n>> m) {
        vector<vector<pair<int,int>>> wAdjList(n);
        for (int i = 0;i<m;i++) {
            int u,v,w;
            cin >> u>>v>>w;
            wAdjList[u-1].push_back({w,v-1});
            wAdjList[v-1].push_back({w,u-1});
        }
        cout << MST(wAdjList) << endl;
    }
}