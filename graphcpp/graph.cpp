#include <bits/stdc++>
using namespace std;

int main(){
 int n;
 cin>>n;
 
 vector<vector<int>> adjList(n);
 int m;
 cin>>m;
 
 for(int i=0; i<m; i++){
  int u, v;
  cin>>u>>v;
  
  adjList[u].push_back(v);
  adjList[v].push_back(u);
 }
 
 for(int i=0; i<n; i++){
  cout<<i<<" => ";
  for(int neigh : adjList[i]){
   cout<<neigh<<" "; 
  }
  cout<<endl;
 }
}
