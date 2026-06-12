#include <iostream>
#include<vector>
#include<queue>
#define ll long long
#define mod 1000000007
using namespace std;

bool bfs(int node, vector<vector<int>>&adj, vector<int>&ans){
    queue<int>q;
    int type=1;
    q.push(node);
    q.push(-1);
    ans[node] = 1;
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(node==-1){
            if(q.empty()) continue;
            else q.push(-1);
            type = 3-type;
            continue;
        }
        for(int &child:adj[node]){
            if(ans[child]==-1){
                q.push(child);
                ans[child] = 3-type;
            }
            else if(ans[child]==type){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>ans(n+1, -1);
    queue<int>q;
    for(int i=1; i<=n; i++){
        if(ans[i]==-1){
            bool res = bfs(i,adj,ans);
            if(!res) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}