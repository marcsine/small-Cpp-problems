// you can use includes, for example:
// #include <algorithm>
#include <vector>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    vector<bool> found(A.size());
    for (int i = 0; i < A.size(); i++)
        found[A[i] - 1] = true;
    for (int i = 0; i < found.size(); i++)
        if (not found[i])
            return i + 1;
}
