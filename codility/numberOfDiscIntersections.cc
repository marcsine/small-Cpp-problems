#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int solution(vector<int> &A) {
    if (A.size() < 2) return 0;
    
    // since log(2,147,483,647) / log(2) = 31, int is OK. But right will be sum of 2, so we need
    // 32 bits. long long wound work but its wasted memory, so we use unsigned int

    vector<int> left(A.size());
    vector<unsigned int> right(A.size());
    
    for (size_t i = 0; i < A.size(); i++) {
        left[i] = i - A[i];
        right[i] = i + A[i];
    }
    
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    
    int count = 0, active = 0;
    size_t j = 0;
    
    for (size_t i = 0; i < A.size(); i++) {
        while (j < A.size() && left[j] <= (long long)right[i]) { // should cast before comparing
            active++;
            j++;
        }
        active--;
        count += active;
        if (count > 10000000) return -1;
    }
    
    return count;
}
