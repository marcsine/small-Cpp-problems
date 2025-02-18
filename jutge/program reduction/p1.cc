#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool applyOneRule(vector<char> &v, char follow) {
    int n = v.size();
    // v → E  no es pot aplicar si ve seguida de =
    if ((v[n-1] == 'n') or 
        (v[n-1] == 'v' and (follow != '='))) {
        
        v[n-1] = 'E';
        return true;
    }   
    // Reemplazo de E*E, E+E y E<E por E
    else if (n >= 3 and 
            ((v[n-3] == 'E' and v[n-2] == '*' and v[n-1] == 'E') or 
            (v[n-3] == 'E' and v[n-2] == '+' and v[n-1] == 'E' and follow != '*') or 
            (v[n-3] == 'E' and v[n-2] == '<' and v[n-1] == 'E' and follow != '*' and follow != '+'))) {
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('E');
        return true;
    }
    // v=E; → I
    else if (n >= 4 and v[n-4] == 'v' and v[n-3] == '=' and v[n-2] == 'E' and v[n-1] == ';') {
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('I');
        return true;
    } else if (n >= 3 and v[n-3] == '(' and v[n-2] == 'E' and v[n-1] == ')' and (n == 3 or (v[n-4] != 'i' and v[n-4] != 'w'))) {
        v.pop_back(); // Elimina ')'
        v.pop_back(); // Elimina 'E'
        v.pop_back(); // Elimina '('
        v.push_back('E'); // Añade 'E'
        return true;
    } else if (follow != 'e' and n >= 5 and v[n-5] == 'i' and v[n-4] == '(' 
                and v[n-3] == 'E' and v[n-2] == ')' and v[n-1] == 'I') {
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('I');
        return true;
    } else if (n >= 7 and v[n-7] == 'i' and v[n-6] == '(' and v[n-5] == 'E' and v[n-4] == ')' and v[n-3] == 'I'
                and v[n-2] == 'e' and v[n-1] == 'I') {
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('I');
        return true;
    }
    // w(E)I → I
    else if (n >= 5 and v[n-5] == 'w' and v[n-4] == '(' and v[n-3] == 'E' and v[n-2] == ')' and v[n-1] == 'I') {
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('I');
        return true;
    }
    // LI → L
    else if (n >= 2 and v[n-2] == 'L' and v[n-1] == 'I') {
        v.pop_back(); // Elimina 'I'
        // No se añade 'L' porque ya está al final de 'v'
        return true;
    } else if (v[n-1] == 'I' and (n == 1 or (v[n-2] != ')' and v[n-2] != 'L'))) {
        v[n-1] = 'L';
        return true;
    }
    // {L} → I
    else if (n >= 3 and v[n-3] == '{' and v[n-2] == 'L' and v[n-1] == '}') {
        v.pop_back(); // Elimina '}'
        v.pop_back(); // Elimina 'L'
        v.pop_back(); // Elimina '{'
        v.push_back('I'); // Añade 'I'
        return true;
    }
    return false;
}

int main()
{
    string s;
    while (cin >> s) {
        // cout << s << ':' << endl;
        vector<char> v;
        for (int i = 0; i < int(s.size()); i++) {
            
            v.push_back(s[i]);
            char follow = ' ';
            if (i+1 < int(s.size()))
                follow = s[i+1];
            while (applyOneRule(v, follow));
            // for (int j = 0; j < int(v.size()); j++) cout << v[j];
            // cout << endl;
        }
        if (v.size() == 1 and v[0] == 'L')
            v[0] = 'P';
        string sol;
        for (int i = 0; i < int(v.size()); i++)
            sol += v[i];
        cout << sol << endl;
    }
}
