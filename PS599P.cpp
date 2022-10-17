//A0237056E
//Leo Zheng Rui, Darren
//LAB 09
//Cai Jia Lin

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    map<ll, int> difficulties1;
    map<ll, int> difficulties2;

    int N, Q; cin >> N >> Q;

    while (N--) {
        ll D; cin >> D;
        ++difficulties1[D]; 
        ++difficulties2[-D];
    }

    while (Q--) {
        
        int T; ll D; cin >> T >> D;

        if (T == 1) {
            auto itr1 = difficulties1.upper_bound(D);
            if (itr1 == difficulties1.end()) {
                cout << "-1" << '\n';
            } else {
                    cout << itr1->first << '\n';
                    --difficulties2[-(itr1->first)];
                    --(itr1->second);
                    if (itr1->second == 0) {
                        difficulties1.erase(itr1);
                        difficulties2.erase(-(itr1->first));
                    }
            }
        } else {
                auto itr2 = difficulties2.lower_bound(-D);
                if (itr2 == difficulties2.end()) {
                    cout << "-1" << '\n';
                } else {
                        cout << -(itr2->first) << '\n';
                        --difficulties1[-(itr2->first)];
                        --(itr2->second);
                        if (itr2->second == 0) {
                            difficulties2.erase(itr2);
                            difficulties1.erase(-(itr2->first));
                        }
                }   
        } 
    } 
    return 0;
}