#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// returns whether its possible to divide in K blocs with max sum 'maxBlockSum'
bool check(const vector<int>& A, int K, int maxBlockSum) {
    int currentSum = 0;
    int blocksUsed = 1;
    
    for (int i = 0; i < A.size(); i++) {
        currentSum += A[i];
        if (currentSum > maxBlockSum) {
            blocksUsed++;
            currentSum = A[i];
        };        
        if (blocksUsed > K) return false;
    }
    
    return true;
}

int solution(int K, int M, vector<int> &A) {
    int left = *max_element(A.begin(), A.end());
    int right = accumulate(A.begin(), A.end(), 0);
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (check(A, K, mid)) { 
            result = mid;
            right = mid - 1;
        } else
            left = mid + 1;
    }

    return result;
}

int main() {
    vector<int> A = {2, 1, 5, 1, 2, 2, 2};
    int K = 3, M = 5;

    cout << "Minimal large sum: " << solution(K, M, A) << endl;
    return 0;
}
