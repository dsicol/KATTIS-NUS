#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    stack<string> substrings;

    string s; cin >> s;
    reverse(s.begin(), s.end());
    int res = 0;
    int a = 0;
    int nest = 0;
    
    for (char&c : s) {
        if (c == 'X') {
            nest++;
        } else if (c == 'A') {
            a += nest;
        } 
        res = a;
    }
    cout << res;
}