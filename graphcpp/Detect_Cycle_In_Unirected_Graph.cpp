  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> isVstd(V, false);
        for(int i=0; i<V; i++){
            if(isVstd[i]){
                continue;
            }
            
            queue<pair<int, int>> nds;
            nds.push({i, -1});
            while(nds.size()){
                int currNode=nds.front().first;
                int currPar=nds.front().second;
                nds.pop();
                
                for(int neighNd: adj[currNode]){
                    if(neighNd==currPar){
                        continue;
                    }
                    
                    if(isVstd[neighNd]){
                        return true;
                    }
                    
                    isVstd[neighNd]=true;
                    nds.push({
                        neighNd,
                        currNode
                    });
                }
            }
        }
        
        return false;
    }
};
