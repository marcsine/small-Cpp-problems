#include<queue>
#include<iostream>
#include<vector>
using namespace std;

struct Pos {
    int r;
    int c;
    Pos operator+(pair<int,int> dir) {
        return {r+dir.first, c+dir.second};
    }};

vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

bool posOK(const Pos& pos, const vector<vector<char>>& map) {
    return pos.r >= 0 && pos.r < map.size() && pos.c >= 0 && pos.c < map[0].size() && map[pos.r][pos.c] != 'X';
}

int printMinStepsToFurthestTreasure(const vector<vector<char>>& map, int numTr, int r, int c) {
    if (numTr == 0)
        return 0;
    queue<Pos> q;
    int trFound = 0;
    q.push({r,c});
    int distLastTr = 0;
    vector<vector<int>> dist(map.size(), vector<int>(map[0].size(),-1));
    dist[r][c] = 0;
    while (! q.empty()) {
        Pos pos = q.front(); q.pop();
        if (map[pos.r][pos.c] == 't') {
            trFound++;
            distLastTr = dist[pos.r][pos.c];
        }
        if (trFound == numTr)
            return distLastTr;

        for(pair<int,int> d : dirs) {
            Pos next = pos + d;
            if (posOK(next, map)) {
                if (dist[next.r][next.c] == -1) {
                    q.push(next);
                    dist[next.r][next.c] = dist[pos.r][pos.c] + 1;
                }
            }
        }
    }
    return distLastTr;}

int main() {
    int n,m;
    cin >> n>>m;
    vector<vector<char>> map(n,vector<char>(m));
    int numTr = 0;
    for(int r = 0; r < n; r++)
        for(int c = 0; c < m; c++) {
            cin >> map[r][c];
            if (map[r][c] == 't')
                numTr++;}
    int r,c; cin >> r >> c;
    int steps = printMinStepsToFurthestTreasure(map, numTr, r - 1,c - 1);
    if (steps > 0) cout << "maximum distance: " << steps << endl;
    else cout << "no treasure can be reached" << endl;
}