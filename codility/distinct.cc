// you can use includes, for example:
// #include <algorithm>
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_set>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    unordered_set<int> nums;
    for (int i = 0; i < A.size(); i++)
        nums.insert(A[i]);
    return nums.size();  
}


int main()
{
    vector<int> v = {2, 1, 1, 2, 3, 1};
    cout << solution(v) << endl;
}