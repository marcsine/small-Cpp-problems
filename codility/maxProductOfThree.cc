// you can use includes, for example:
#include <algorithm>
#include <vector>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int i1, i2, i3;
    i3 = A[A.size() - 1];
    if (i3 <= 0)
        return i3 * A[A.size() - 2] * A[A.size() - 3];
    else {
        int left = A[0]*A[1];
        int right = A[A.size()-2]*A[A.size()-3];
        left = max(left, right);
        return
            left * i3;
    }

}
