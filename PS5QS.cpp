//A0237056E
//Leo Zheng Rui, Darren
//LAB 09
//Cai Jia Lin

#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    int scope = 0;

    vector< unordered_map<string, vector<string>> > variables; // DS segmented by indices of scope to isolate multiple declarations.
    unordered_map<string, vector<string>> lastDeclared; // DS to keep track of last declared variables irregardless of scope. The use of a vector is faster than using a Stack.
    unordered_map<string, vector<string>> line;
    
    variables.push_back(line);

    while (N--) {
        string token;
        cin >> token;

        if (token == "{") {
            ++scope;
            variables.push_back(line);

        } else if (token == "}") {
            for (auto i : variables.back()) {
                if (!lastDeclared[i.first].empty()) lastDeclared[i.first].pop_back(); // Avoid segmentation fault
            }
            --scope;
            variables.pop_back();
            
        } else if (token == "DECLARE") {
            string variable, type; cin >> variable >> type;
            variables[scope][variable].push_back(type); lastDeclared[variable].push_back(type);

            if (variables[scope][variable].size() > 1) {
                cout << "MULTIPLE DECLARATION" << '\n';
                return 0;
            }

        } else if (token == "TYPEOF") {
            string variable;
            cin >> variable;

            (!lastDeclared[variable].empty()) ? cout << lastDeclared[variable].back() << '\n' : cout << "UNDECLARED" << '\n';
        }
    }
    return 0;
}