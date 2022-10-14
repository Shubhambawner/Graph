#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> isVstd(V, false);
        isVstd[0]=true;
        vector<int> res{0};
        int currIdx=0;
        while(currIdx<res.size()){
            int nd=res[currIdx];
            currIdx++;
            
            for(int othNd: adj[nd]){
                if(isVstd[othNd]){
                    continue;
                }
                
                isVstd[othNd]=true;
                res.push_back(othNd);
            }
        }
        
        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
