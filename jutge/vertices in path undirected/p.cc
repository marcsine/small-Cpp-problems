#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>> &G, vector<bool> &reached, int orgnVtx)
{
    if (reached[orgnVtx])
        return;

    reached[orgnVtx] = true;
    for (int neighbr : G[orgnVtx])
        dfs(G, reached, neighbr);
}

int main()
{
    int n, u, v, m;
    while (cin >> n >> u >> v >> m)
    {
        vector<vector<int>> G(n), G_inv(n);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G_inv[y].push_back(x);
        }
        vector<bool> reached(n, false), reached_inv(n, false);

        dfs(G, reached, u);
        dfs(G_inv, reached_inv, v);

        // int debug = 0;
        // for (int b : reached)
        //     if (b) debug++;
        // cout << "en reached " << debug << " naciendo en " << u << endl;
        // debug = 0;
        // for (int b : reached_inv)
        //     if (b) debug++;
        // cout << "en reached_inv " << debug << " naciendo en " << v <<  endl;

        int res = 0;
        for (int i = 0; i < n; i++)
            if (i != u && i != v && reached[i] && reached_inv[i])
                res++;
        cout << res << endl;
    }
}