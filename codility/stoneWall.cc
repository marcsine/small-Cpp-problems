// you can use includes, for example:
#include <vector>
#include <stack>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    stack<int> s;
    int blocks = 0;
    for (int h : H) {
        if (not s.empty() and s.top() > h)
            s.pop();

        if (s.empty() or s.top() < h) {
            s.push(h);
            blocks++;
        }
    }
    return blocks;
}
