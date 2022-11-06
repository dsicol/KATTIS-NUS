#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;

    cin.ignore();

    while (T--) {

        list<char> sentence;
        list<char>::iterator itr;

        string collection; 
        getline(cin, collection);
        
        itr = sentence.begin();

        for (char i : collection) {

            if (i == '<') {
                if (itr != sentence.begin()) itr = sentence.erase(--itr); 
                // if backspace when at front of the list, it should do nothing.
                // Erase: Erases current itr element and returns following itr pos.
                // Since itr is always pointing to next element, we decrement.
            } else if (i == '[') {
                itr = sentence.begin();
            } else if (i == ']') {
                if (sentence.empty()) itr == sentence.begin();
                else itr = sentence.end();
            } else {
                itr = sentence.insert(itr, i);
                // Insert: Inserts element before itr and returns itr pointing to the inserted element.
                // Since itr is always pointing to next element, we can insert and increment afterwards to maintain itr pos after referenced element.
                ++itr;
            }

        }

        for (char j : sentence) {
            cout << j;
        }

        cout << '\n';

    }

    return 0;

}    
