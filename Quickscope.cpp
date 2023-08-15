#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
  
    vector<unordered_set<string>> variables; // DS segmented by indices of scope to isolate multiple declarations.
    unordered_map<string, vector<string>> types; // DS to keep track of last declared variables irregardless of scope. The use of a vector is faster than using a Stack.
    unordered_set<string> st;
    
    variables.push_back(st);

    while (N--) {
        string token;
        cin >> token;

        if (token == "{") {
            variables.push_back(st);
            
        } else if (token == "}") {
            for (auto& i : variables.back()) {
                if (!types[i].empty()) types[i].pop_back(); // Avoid segmentation fault
            }
            variables.pop_back();
            
        } else if (token == "DECLARE") {
            string variable, type; cin >> variable >> type;
            if (variables.back().find(variable) != variables.back().end()) {
                cout << "MULTIPLE DECLARATION" << '\n';
                return 0;
            }
            variables.back().insert(variable); types[variable].push_back(type);
            
        } else {
            string variable;
            cin >> variable;
            (!types[variable].empty()) ? cout << types[variable].back() << '\n' : cout << "UNDECLARED" << '\n';
        }
    }
    return 0;
}
