#include <vector>
#include <limits>
#include <numeric>
#include <math.h>
using namespace std;


int solution(vector<int> &A)
{
    int left = 0, right = numeric_limits<int>::max();
    int result = right;
    vector<int> dif(A.size(), right);

    for (int i = 0; i < A.size(); i++) {
        left += A[0];
        right -= A[0];
        dif[i] = abs(left - right);
    }
    
    for (int i = 0; i < dif.size(); i++)
        if (dif[i] < result)
            result = dif[i];
}
