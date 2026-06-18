#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

using p = pair<ll,int>;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k; cin >> n >> m >> k;

    vector<vector<p>>adj(n+1);

    for(int i=0; i<m; i++){
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    vector<vector<ll>>dist(n+1);
    priority_queue<p, vector<p>, greater<p>>q;
    q.push({0,1});
    dist[1].push_back(0);

    while(!q.empty()){
        ll distance = q.top().first;
        int currNode = q.top().second;
        q.pop();
        
        if(dist[currNode].size()>=10) continue;

        dist[currNode].push_back(distance);

        if(currNode==n && dist[currNode].size()>=k) break;

        for(p &neighbor:adj[currNode]){
            int childNode = neighbor.second; ll w = neighbor.first;
            if(dist[childNode].size()>=k) continue;
            q.push({w+distance, childNode});
        }
    }

    for(int j=0; j<k; j++) cout << dist[n][j] << " ";
    return 0;
}