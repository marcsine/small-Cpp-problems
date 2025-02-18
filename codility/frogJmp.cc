// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    // Implement your solution here
    int dist = Y - X;
    if (dist % D == 0)
        return dist / D;
    else
        return dist / D + 1;
}
