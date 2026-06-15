#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

using Node=pair<ll,pair<int,int>>;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    vector<vector<pair<int,ll>>>adj(n+1);

    for(int i=1; i<=m; i++){
        int u,v; ll w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    priority_queue<Node, vector<Node>, greater<Node>>q;
    vector<vector<ll>>dist(n+1, vector<ll>(2, 1e17));

    q.push({0,{1,0}});

    while(!q.empty()){
        Node N = q.top();
        ll distanceUptoNode = N.first;
        int node = N.second.first;
        int taken = N.second.second;
        q.pop();

        if(dist[node][taken] < distanceUptoNode) continue;
        
        for(pair<int,ll>&neighbor:adj[node]){
            int nei = neighbor.first;
            ll w = neighbor.second;
            
            if(taken==0){
                if(dist[nei][0] > distanceUptoNode+w) {
                    dist[nei][0] = distanceUptoNode+w;
                    q.push({dist[nei][0],{nei,0}});
                }
                if(dist[nei][1] > distanceUptoNode+w/2){
                    dist[nei][1] = distanceUptoNode+w/2;
                    q.push({dist[nei][1],{nei,1}});
                }
            }
            else{
                if(dist[nei][1] > distanceUptoNode+w) {
                    dist[nei][1] = distanceUptoNode+w;
                    q.push({dist[nei][1],{nei, 1}});
                }
            }
        }
    }

    cout << dist[n][1];

    return 0;
}