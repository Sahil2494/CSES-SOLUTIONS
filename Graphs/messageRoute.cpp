#include <iostream>
#include<vector>
#include<queue>
#define ll long long
#define mod 1000000007
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int>q;
    q.push(1);
    q.push(-1);

    vector<bool>added(n+1,false);
    added[1] = true;

    vector<int>parent(n+1);
    parent[0] = -1;
    parent[1] = 0;

    int distance = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node==-1){
            if(q.empty()) break;
            else q.push(-1);
            distance++;
            continue;
        }
        if(node==n){
            break;
        }
        for(auto i:adj[node]){
            if(!added[i]){
                q.push(i);
                parent[i] = node;
                added[i] = true;
            }
            
        }
    }

    if(!added[n]) cout << "IMPOSSIBLE";
    else{
        vector<int>path;
        int node = n;
        while(parent[node]!=-1){
            path.push_back(node);
            node = parent[node];
        }
        cout << path.size() << '\n';
        for(int i=path.size()-1; i>=0; i--){
            cout << path[i] << " ";
        }
    }
    return 0;
}