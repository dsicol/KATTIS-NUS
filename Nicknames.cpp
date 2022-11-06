#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);
    unordered_map<string, int> namesfreq;

    int A; cin >> A;

    while (A--) {

        string name; cin >> name;

        for (int i = 1; i <= name.size(); ++i) { // max size = 10
            ++namesfreq[name.substr(0,i)];
        }

    }

    int B; cin >> B;

    while (B--) {

        string nickname; cin >> nickname;

        if (namesfreq.count(nickname) != 0) cout << namesfreq[nickname] << '\n';
        else cout << 0 << '\n';

    }

    return 0;

}
