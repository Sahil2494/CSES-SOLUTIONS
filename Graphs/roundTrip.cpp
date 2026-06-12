#include <iostream>
#include<vector>
#define ll long long
#define mod 1000000007
using namespace std;

int cycleDetector(int node, int parent, vector<bool>&visited, vector<vector<int>>&adj){
    visited[node] = true;
    for(int &child:adj[node]){
        if(child!=parent){
            if(visited[child]) return node;
            int res = cycleDetector(child,node,visited,adj);
            if(res!=-1) return res;
        }
    }
    return -1;
}

bool getPath(int node, int parent, vector<bool>&visited, vector<vector<int>>&adj, vector<int>&ans, int cycleNode){
    visited[node] = true;
    ans.push_back(node);
    for(int &child:adj[node]){
        if(child!=parent){
            if(child==cycleNode){
                ans.push_back(cycleNode);
                return true;
            }
            if(visited[child]) continue;
            bool res = getPath(child,node,visited,adj,ans,cycleNode);
            if(res) return true;
        }
    }
    ans.pop_back();
    return false;
}

int main(){
    int n,e; cin >> n >> e;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<e; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>visited(n+1, false);

    int cycleNode = -1;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            int res = cycleDetector(i,0,visited,adj);
            if(res!=-1) {
                cycleNode = res;
                break;
            }
        }
    }

    if(cycleNode==-1){
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    for(int i=0; i<=n; i++) visited[i] = false;

    vector<int>ans;

    getPath(cycleNode,0,visited,adj,ans,cycleNode);

    cout << ans.size() << '\n';
    for(auto i:ans) cout << i << " ";


    return 0;
}