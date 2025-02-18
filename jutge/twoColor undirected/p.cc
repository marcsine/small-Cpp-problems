#include<vector>
#include<iostream>
using namespace std;

typedef vector<vector<int>> adjList;

bool twoColRecursive(const adjList& G, int iClredVtx, vector<int>& COL) {
    for (int iNbr : G[iClredVtx]) //iNeighbour iColoredVertex
        if (COL[iNbr] == 0) {
            COL[iNbr] = (COL[iClredVtx] % 2) + 1;
            if (! twoColRecursive(G, iNbr, COL))
                return false;
        } else if (COL[iNbr] == COL[iClredVtx])
            return false;
    return true;
}

bool twoCol(const adjList& G) {
    vector<int> COL(G.size(), 0);
    for(int i = 0; i < G.size(); i++) {
        if (COL[i] == 0) {
            COL[i] = 1;
            if (! twoColRecursive(G,i,COL))
                return false;
        }
    }
    return true;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        adjList G(n);
        for (int i = 0; i < m; i++) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        if (twoCol(G)) cout << "yes" << endl;
        else cout << "no"<< endl;
    }
}