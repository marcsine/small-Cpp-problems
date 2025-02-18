#include<stack>
#include <iostream>

int main() {
    char c;
    std::stack<char> s;
    int pos = 0;
    bool bError = false;
    while (!bError and std::cin >> c and c != '.') {
        pos++;
        if (c == '(' or c == '[')
            s.push(c);
        else
            if ((c == ')' and (s.empty() or s.top() != '(')) or 
                (c == ']' and (s.empty() or s.top() != '[')))
                bError = true;
            else
                s.pop();
    }
    if (bError or !s.empty())
        std::cout << "Incorrecte " << pos << std::endl;
    else
        std::cout << "Correcte" << std::endl;
}