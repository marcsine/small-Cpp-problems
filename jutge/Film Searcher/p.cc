#include <unordered_map>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<string>> keyboard;

struct Pos
{
    int x;
    int y;
    Pos operator+(pair<int, int> dir)
    {
        return Pos{x + dir.first, y + dir.second};
    }
};

vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isOk(Pos pos, const keyboard &kbrd)
{
    return (pos.y >= 0 && pos.y < kbrd.size() && pos.x >= 0 && pos.x < kbrd[0].size() && kbrd[pos.y][pos.x] != "*");
}


struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto h1 = hash<T1>()(p.first);  // Hash de la primera parte
            auto h2 = hash<T2>()(p.second); // Hash de la segunda parte
            return h1 ^ (h2 << 1);          // Combina los hashes con XOR y shift
        }
    };

int bfs(const keyboard &kbrd, const string &word, Pos &cursor, unordered_map<pair<string, string>, int, pair_hash>& calcDists)
{
    vector<vector<int>> dist(kbrd.size(), vector<int>(kbrd[0].size(), -1));
    dist[cursor.y][cursor.x] = 0;
    queue<Pos> Q;
    Q.push(cursor);
    while (!Q.empty())
    {
        Pos currPos = Q.front();
        Q.pop();
        int distCurr = dist[currPos.y][currPos.x];

        if (kbrd[currPos.y][currPos.x] == word)
        {
            // press OK adds 1
            calcDists[pair<string, string>(kbrd[cursor.y][cursor.x], word)] = distCurr + 1;
            calcDists[pair<string, string>(word, kbrd[cursor.y][cursor.x])] = distCurr + 1;
            cursor = currPos;
            return distCurr + 1;
        }

        for (auto d : dirs)
        {
            Pos newPos = currPos + d;
            if (isOk(newPos, kbrd) && dist[newPos.y][newPos.x] == -1)
            {
                Q.push(newPos);
                dist[newPos.y][newPos.x] = distCurr + 1;
            }
        }
    }
    calcDists[pair<string, string>(kbrd[cursor.y][cursor.x], word)] = -1;
    calcDists[pair<string, string>(word, kbrd[cursor.y][cursor.x])] = -1;
    return -1;
}


int countMovs(const keyboard &keyboard, const vector<string> &words)
{
    unordered_map<pair<string, string>, int, pair_hash> calcDists;

    int res = 0;
    Pos cursor = {0, 0};
    for (int i = 0; i < words.size(); i++)
    {
        int dist;
        auto it = calcDists.find({keyboard[cursor.y][cursor.x], words[i]});
        if (it != calcDists.end()) {
            dist = it->second;
        } else
            dist = bfs(keyboard, words[i], cursor, calcDists);
        
        if (dist != -1)
            res += dist;
        else
            return -1;
    }
    return res;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        keyboard keyboard(n, vector<string>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> keyboard[i][j];

        int p;
        cin >> p;
        vector<string> words(p);
        for (int i = 0; i < p; i++)
            cin >> words[i];

        // cout << "keyboard:" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //         cout << keyboard[i][j];
        //     cout << endl;
        // }
        // cout << "words:" << endl;
        // for (int i = 0; i < p; i++)
        //     cout << words[i];
        // cout << endl;

        int iMovs = countMovs(keyboard, words);
        if (iMovs != -1)
            cout << iMovs << endl;
        else
            cout << "impossible" << endl;
    }
}