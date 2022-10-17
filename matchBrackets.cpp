//A0237056E
//Leo Zheng Rui, Darren
//LAB 09
//Cai Jia Lin

#include <bits/stdc++.h>
using namespace std;

int main() {

    stack<char> brackets;
    int N; cin >> N;

    while (N--) {
        char token; cin >> token;
        if (token == ')' && !brackets.empty()) {
            if (brackets.top() == '(') {
                brackets.pop();
                continue; 
                }
            else {
                cout << "Invalid";
                return 0;
            }
        } else if (token == ']' && !brackets.empty()) {
            if (brackets.top() == '[') {
                brackets.pop();
                continue; 
                }
            else {
                cout << "Invalid";
                return 0;
            }
        } else if (token == '}' && !brackets.empty()) {
            if (brackets.top() == '{') {
                brackets.pop();
                continue; 
                }
            else {
                cout << "Invalid";
                return 0;
            }
        }
        brackets.push(token);
    }
    
    if (brackets.empty()) cout << "Valid";
    else cout << "Invalid";
    return 0;

}