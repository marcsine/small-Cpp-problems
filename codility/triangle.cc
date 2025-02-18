// you can use includes, for example:
#include <algorithm>
#include <vector>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());

    if (A.size() < 3) return 0;
    
    // log(2,147,483,648 * 2)/log(2) = 32, so A[i] + A[i+1] will cause overflow.
    // We cast to long long before the sum
    for (int i = 0; i < A.size() - 2; i++)
        if ((long long)A[i] + (long long)A[i+1]> A[i+2])
            return 1;
    return 0;
}
