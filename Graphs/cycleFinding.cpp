#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

void bellmanFord(int n, int m, vector<vector<ll>>&edges){
    vector<ll>dist(n+1, 1e17);
    vector<int>parent(n+1, -1);

    for(int i=0; i<n-1; i++){
        for(int j=0; j<edges.size(); j++){
            ll u=edges[j][0], v=edges[j][1], w=edges[j][2];
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                parent[v] = u;
            }
        }
    }

    bool cycle = false;
    int x=-1;
    for(int j=0; j<edges.size(); j++){
        ll u=edges[j][0], v=edges[j][1], w=edges[j][2];
        if(dist[v] > dist[u]+w){
            x=v;
            parent[v] = u;
            cycle = true;
            break;
        }
    }

    if(!cycle){
        cout << "NO";
        return;
    }

    int N=n;
    while(N--){
        x = parent[x];
    }

    vector<int>ans;
    ans.push_back(x);
    x=parent[x];
    while(ans[0]!=x){
        ans.push_back(x);
        x=parent[x];
    }
    ans.push_back(ans[0]);

    cout << "YES\n";
    for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << " ";

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    vector<vector<ll>>edges;

    for(int i=1; i<=m; i++){
        ll u,v; ll w; cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    bellmanFord(n,m,edges);

    return 0;
}