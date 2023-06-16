#include <bits/stdc++.h>
using namespace std;

int main() {
    // O(NlogN) solution
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    deque<pair<int, int>> cards;
    map<int, set<int>> majority;
    unordered_map<int,int> cardCount;

    while (N--) {
        string cmd; cin >> cmd;
        if (cmd == "PUT_TOP") {
            int X, Y; cin >> X >> Y;
            if (cards.empty()) {
                cards.push_front(make_pair(Y, X));
            } else if (cards.front().first != Y) {
                cards.push_front(make_pair(Y, X));
                if (cardCount[Y] != 0) {
                    majority[cardCount[Y]].erase(Y);
                    if (majority[cardCount[Y]].empty()) majority.erase(cardCount[Y]);
                }
            } else {
                cards.front().second += X;
                majority[cardCount[Y]].erase(Y);
                if (majority[cardCount[Y]].empty()) majority.erase(cardCount[Y]);
            }
            cardCount[Y] += X;
            majority[cardCount[Y]].insert(Y);
        } else if (cmd == "PUT_BOTTOM") {
            int X, Y; cin >> X >> Y;
            if (cards.empty()) {
                cards.push_back(make_pair(Y, X));
            } else if (cards.back().first != Y) {
                cards.push_back(make_pair(Y, X));
                if (cardCount[Y] != 0) {
                    majority[cardCount[Y]].erase(Y);
                    if (majority[cardCount[Y]].empty()) majority.erase(cardCount[Y]);
                }
            } else {
                cards.back().second += X;
                majority[cardCount[Y]].erase(Y);
                if (majority[cardCount[Y]].empty()) majority.erase(cardCount[Y]);
            }
            cardCount[Y] += X;
            majority[cardCount[Y]].insert(Y);
        } else if (cmd == "REMOVE_TOP") {
            int Z; cin >> Z;
            while (Z > 0) {
                if (Z <= cards.front().second) {
                    majority[cardCount[cards.front().first]].erase(cards.front().first);
                    if (majority[cardCount[cards.front().first]].empty()) majority.erase(cardCount[cards.front().first]);
                    cards.front().second -= Z;
                    cardCount[cards.front().first] -= Z;
                    Z = 0;
                } else {
                    majority[cardCount[cards.front().first]].erase(cards.front().first);
                    if (majority[cardCount[cards.front().first]].empty()) majority.erase(cardCount[cards.front().first]);
                    Z -= cards.front().second;
                    cardCount[cards.front().first] -= cards.front().second;
                    cards.front().second = 0;
                }
                if (cardCount[cards.front().first] != 0) majority[cardCount[cards.front().first]].insert(cards.front().first);
                if (cards.front().second == 0) cards.pop_front();
            }
        } else if (cmd == "REMOVE_BOTTOM") {
            int Z; cin >> Z;
            while (Z > 0) {
                if (Z <= cards.back().second) {
                    majority[cardCount[cards.back().first]].erase(cards.back().first);
                    if (majority[cardCount[cards.back().first]].empty()) majority.erase(cardCount[cards.back().first]);
                    cards.back().second -= Z;
                    cardCount[cards.back().first] -= Z;
                    Z = 0;
                } else {
                    majority[cardCount[cards.back().first]].erase(cards.back().first);
                    if (majority[cardCount[cards.back().first]].empty()) majority.erase(cardCount[cards.back().first]);
                    Z -= cards.back().second;
                    cardCount[cards.back().first] -= cards.back().second;
                    cards.back().second = 0;
                }
                if (cardCount[cards.back().first] != 0) majority[cardCount[cards.back().first]].insert(cards.back().first);
                if (cards.back().second == 0) cards.pop_back();
            }
        }
        cout << *majority.rbegin()->second.begin() << '\n';
    }
 }
