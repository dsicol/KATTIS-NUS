#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC; cin >> TC;

    while (TC--) {
        
        int V; cin >> V;
        vector<vii> AL(V, vii());
        
        for (int u = 0; u < V; ++u) {
            int X; cin >> X; // Edges
            while (X--) {
                int vertex, weight; cin >> vertex >> weight;
                AL[u].emplace_back(vertex, weight);
            }
            
        }

        int Q; cin >> Q;

        while (Q--) {

            int s, t, k; cin >> s >> t >> k;
            int INF = (int)1e9;

            vi dist(V, INF); dist[s] = 0;
            vi junctions(V,0); junctions[s] = 1;
                            
            for (int i = 0; i < V - 1; i++) {  
                bool modified = false; 
                for (int u = 0; u < V; u++) {
                    if (dist[u] != INF) {
                        for (auto &[v, w] : AL[u]) {       
                            if (dist[u] + w >= dist[v]) {
                                continue;   
                            }

                            int currjunction = 1 + junctions[u];

                            if (k == 1 && t != s) {
                                break;
                            } else if (currjunction < k || v == t) { // process k - 1 edges
                                dist[v] = dist[u] + w;  
                                junctions[v] = currjunction;
                                modified = true;    
                            }                           
                        }
                    }
                }  
                if (!modified) break;  
            }
            cout << ((dist[t] != INF) ? dist[t] : -1) << '\n';
            
        }

    }
    return 0;

}
