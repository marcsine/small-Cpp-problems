#include<iostream>
#include<vector>
using namespace std;

void writeSeqWithNoWells(vector<int>& perm, vector<bool>& used, int x) {
    if (x == used.size()) {
        bool firstDone = false;
        for(int i = 0; i < perm.size(); i++) {
            if (i != 0)
                if (i == 1)
                    cout << '(' << perm[i];
                else
                    cout << ',' << perm[i];
        }
        cout << ')' << endl;
    }
        

    for(int i = 1; i < used.size(); i++) {
        if (! used[i]) {
            if (x < 3 || (perm[x-2] + i <= 2*perm[x - 1])) {
                used[i] = true;
                perm[x] = i;
                writeSeqWithNoWells(perm, used, x+1);
                used[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<bool> used(n+1, false);
    vector<int> perm(n+1);
    writeSeqWithNoWells(perm, used, 1);
}