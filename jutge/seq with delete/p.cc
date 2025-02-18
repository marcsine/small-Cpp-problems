#include<iostream>
#include<list>
using namespace std;

void recalc_minmax(list<int> &l, int &min, int &max) {
    list<int>::iterator it = l.begin();
    if (not l.empty())
        max = min = *it;
    while (it != l.end()) {
        if (*it <= min) min = *it;
        if (*it >= max) max = *it;
        it++;
    }
}

void esborra(list<int> &l, int num, int &suma, int &size, int &min, int &max) {
    list<int>::iterator it = l.begin();
    while (it != l.end()) {
        if (*it == num) {
            l.erase(it);
            suma -= num;
            size -= 1;
            if (min == num or max == num)
                recalc_minmax(l, min, max);
            return;
        }
        it++;
    }
}

void afegeix(list<int> &l, int num, int &suma, int &size, int &min, int &max) {
    size += 1;
    if (size == 1) {
        max = num;
        min = num;
    }
    l.push_back(num);
    suma += num;
    if (min > num or max < num)
        recalc_minmax(l, min, max);
}

int main() {
    pair<int,int> par;

    list<int> l;
    int suma, min, max, size;
    size = 0;

    cin >> par.first >> par.second;
    
    while (par.first != 0 or par.second != 0) {
        if (par.first == -1)
            afegeix(l, par.second, suma, size, min, max);
        else if (par.first == -2)
            esborra(l,par.second, suma, size, min, max);
        else
            cout << "el primero no es ni -1 ni -2" << endl;
        if (size == 0)
            cout << 0 << endl;
        else
            cout << min << ' ' << max << ' ' << double(suma)/size << endl;
        cin >> par.first >> par.second;
    }
}