#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>adj[], vector<bool>&visited){
    visited[node] = true;
    for(int &child:adj[node]){
        if(!visited[child]) dfs(child,adj,visited);
    }
}
int main(){
    int n,m; cin >> n >> m;
    vector<int>adj[n+1];
    for(int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector<int>component;
    vector<bool>visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            component.push_back(i);
            dfs(i,adj,visited);
        }
    }
    cout << component.size()-1 << '\n';
    for(int i=1; i<component.size(); i++){
        cout << component[i] << " " << component[i-1] << '\n';
    }
}