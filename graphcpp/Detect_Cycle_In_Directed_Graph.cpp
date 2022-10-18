#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool recFn(int nd, vector<int>* adj, vector<bool>& isVstd, vector<bool>& recStk){
        if(recStk[nd]){
            return true;
        }
        
        if(isVstd[nd]){
            return false;
        }
        
        isVstd[nd]=true;
        recStk[nd]=true;
        for(int othNd: adj[nd]){
            if(recFn(othNd, adj, isVstd, recStk)){
                return true;
            }
        }
        recStk[nd]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> isVstd(V, false);
        vector<bool> recStk(V, false);
        
        for(int i=0; i<V; i++){
            if(isVstd[i]){
                continue;
            }
            
            if(recFn(i, &adj[0], isVstd, recStk)){
                return true;
            }
        }
        
        return false;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
