// #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_A;
int max_B;

inline int nailIndex(int pos) {
    return pos - min_A;
}

inline bool isNailed(const vector<int> &nailIds, int begPlank, int endPlank) {
    return (nailIds[nailIndex(endPlank)] != -1 and 
            (nailIndex(begPlank) == 0 or nailIds[nailIndex(endPlank)] != nailIds[nailIndex(begPlank - 1)]));
}

bool canNailAllPlanks(const vector<int> &A, const vector<int> &B, const vector<int> &C, int mid) {
    if (max_B < min_A)
        max_B = *max_element(B.begin(), B.end());

    vector<int> nailIds(max_B - min_A + 1, -1);
    for (int i = 0; i < mid; i++) {
        int i2 = nailIndex(C[i]);
        if (i2 >= 0 and i2 < nailIds.size())
            nailIds[i2] = i;
    }

    for (int i = 1; i < nailIds.size(); i++)
        if (nailIds[i] == -1)
            nailIds[i] = nailIds[i - 1];

    for (int i = 0; i < A.size(); i++)
        if (not isNailed(nailIds, A[i], B[i]))
            return false;

    return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int left, right = C.size(), result = -1;
    if (right >= 1)
        left = 1;

    // by default all nails are at the left of all planks, so the position of all extremes of the planks
    // is greater than the position of the nails
    min_A = *min_element(A.begin(), A.end());
    max_B = min_A - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canNailAllPlanks(A, B, C, mid)) {
            result = mid;
            right = mid - 1;
        } else
            left = mid + 1;
    }
    return result;
}

// int main()
// {
//     vector<int> A = {1, 4, 5, 8};
//     vector<int> B = {4, 5, 9, 10};
//     vector<int> C = {4, 6, 7, 10, 2};

//     cout << "Minimum number of nails: " << solution(A, B, C) << endl;
//     return 0;
// }
