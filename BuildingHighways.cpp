#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll N; cin >> N;
    ll total = 0;
    ll least = (ll)1e9;

    for (ll i = 0; i < N; ++i) {

        ll Ai; cin >> Ai;
        total += Ai;
        least = min(Ai, least);

    }

    total += (N - 2) * least;

    cout << total << '\n';
    return 0;

}
