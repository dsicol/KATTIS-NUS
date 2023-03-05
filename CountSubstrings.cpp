#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    string s; cin >> s;
    reverse(s.begin(), s.end());
    int subStrings = 0;
    int countOfA = 0;
    
    // Linear time solution
    for (char&c : s) {
        if (c == 'X') {
            countOfA++;
        } else if (c == 'A') {
            subStrings += countOfA;
        } 
    }
    cout << subStrings;
    return 0;

}
