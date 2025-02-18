#include <iostream>
#include <vector>
using namespace std;

int n, d;

void printIfBalanced(const vector<int>& permut) {
    string buff = "(";
    int i = 0;
    for (i = 0; i < n - 1; i++) {
        if (i > 0) buff += ",";
        buff += to_string(permut[i] + 1);
    }
    if (i > 0)
        buff += ',';
    buff += to_string(permut[n - 1] + 1);
    buff += ")";
    cout << buff<< endl;
}

void reorder(vector<bool> &used, vector<int> &permut, int x)
{
    if (x == used.size()) {
        printIfBalanced(permut);
        return;
    }
    for (int i = 0; i < used.size(); i++) {
        if (!used[i] && (x == 0 || (abs(permut[x-1] - i) <= d)))
        {
            used[i] = true;
            permut[x] = i;
            reorder(used, permut, x + 1);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> n >> d;
    vector<bool> used(n, false);
    vector<int> permutation(n);
    reorder(used, permutation, 0);
}