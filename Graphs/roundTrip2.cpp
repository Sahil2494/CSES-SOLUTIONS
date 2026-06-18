#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

bool dfs(int node, vector<vector<int>>&adj, vector<int>&visited, vector<int>&parent){
    //mark as 1 for visiting
    visited[node] = 1;

    for(int &child:adj[node]){
        if(visited[child]==0){
            parent[child] = node;
            bool res = dfs(child,adj,visited,parent);
            if(res) return true;
        }
        else if(visited[child]==1){
            //cycle detected
            int curr = node;
            stack<int>path;
            path.push(child);
            while(curr!=child){
                path.push(curr);
                curr = parent[curr];
            }
            path.push(child);

            //print the Mammla
            cout << path.size() << '\n';
            while(!path.empty()){
                cout << path.top() << " ";
                path.pop();
            }
            return true;
        }
    }

    //mark as visited
    visited[node]=2;
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    vector<vector<int>>adj(n+1);

    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }

    //standard 3 state DFS approach 

    vector<int>visited(n+1, 0),parent(n+1,-1);

    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            bool res = dfs(i,adj,visited,parent);
            if(res) return 0;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}