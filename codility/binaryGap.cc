// you can use includes, for example:
// #include <algorithm>
#include <iostream>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    bool started = false;
    int count = 0;
    int max = 0;
    while (N != 0)
    {
        if (started and N % 2 == 0)
            count++;
        else
        {
            if (max < count)
                max = count;
            started = true;
            count = 0;
        }
        cout << "N =" << N << " started = " << started << endl;
        cout << "max = " << max << endl;
        N /= 2;
    }
    return max;
}

int main() {
    int N;
    cin >> N;
    cout << "Longest binary gap of lenght " << solution(N) << endl;
}