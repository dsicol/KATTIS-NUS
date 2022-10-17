//A0237056E
//Leo Zheng Rui, Darren
//LAB 09
//Cai Jia Lin

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, Q; cin >> N >> Q;
    unordered_map<string, list<string>::iterator> couples;
    list<string> conga;
    list<string>::iterator mic;

    while (N--) {
        string first;
        string second; 
        cin >> first >> second;
        conga.push_back(first); 
        conga.push_back(second);
        auto mic = conga.end();
        couples[first] = --mic;
        couples[second] = --mic;
    }

    mic = conga.begin();

    while (Q--) {
        char token;
        cin >> token;

        if (token == 'F') {
            --mic;
        } else if (token == 'B') {
            ++mic;
        } else if (token == 'R') {
            if (mic == --conga.end()) {
                mic = conga.begin();
            } else {
                auto m = mic;
                auto n = mic;
                ++mic;
                conga.push_back(*m);
                conga.erase(n);
                couples[*couples[*m]] = --conga.end();
            }
        } else if (token == 'C') {
            auto m = mic;
            auto n = mic;
            auto pos = couples[*m];
            if (mic == --conga.end()) {
                mic = conga.begin();
                conga.insert (++pos, *m);
                couples[*couples[*m]] = --pos;
                conga.erase(n);
            } else {
                ++mic;
                if (pos != --conga.end()) {
                conga.insert (++pos, *m);
                couples[*couples[*m]] = --pos;
                conga.erase(n);
                } else {
                    conga.push_back(*m);
                    conga.erase(n);
                    couples[*couples[*m]] = --conga.end();
                }
            }
        } else if (token == 'P') {
            cout << *couples[*mic] << '\n';
        }   
        
        }
        for (auto const &c : conga) {
            cout << '\n' << c;
        }
        return 0;
    }