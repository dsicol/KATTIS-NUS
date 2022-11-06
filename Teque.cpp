#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    deque<int> front;
    deque<int> back;
    deque<int>::iterator itr;

    int N; cin >> N;
    
    while (N--) {

        int num;
        string cmd; 
        cin >> cmd >> num;

        if (cmd == "push_front") {
            if (front.size() > back.size()) {
                back.push_front(front.back());
                front.pop_back();
            }
            front.push_front(num);
        } else if (cmd == "push_back") {
            back.push_back(num);
            if (front.size() < back.size()) {
                front.push_back(back.front());
                back.pop_front();
            }
        } else if (cmd == "push_middle") {
            if (back.size() < front.size()) back.push_front(num);
            else front.push_back(num);
        } else {
            if (num < front.size()) {
                cout << front[num] << '\n';
            } else {
                cout << back[num - front.size()] << '\n';
            }
        }
    
    }

    return 0;

}
