#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    
    vector<pair<pair<int,int>,ll>>edges;
    vector<ll>dist(n+1, LLONG_MIN);

    for(int i=0; i<m; i++){
        int u,v; ll w; cin >> u >> v >> w;
        edges.push_back({{u,v}, w});
    }

    dist[1] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            int u=edges[j].first.first, v = edges[j].first.second;
            ll w = edges[j].second;
            if(dist[u]!=LLONG_MIN && dist[u]+w>dist[v]) dist[v] = dist[u]+w;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            int u=edges[j].first.first, v = edges[j].first.second;
            ll w = edges[j].second;
            if(dist[u]==LLONG_MAX) {
                dist[v]=LLONG_MAX;
                continue;
            }
            if(dist[u]!=LLONG_MIN && dist[u]+w>dist[v]){
                dist[v] = LLONG_MAX;
            }
        }
    }

    if(dist[n]==LLONG_MAX) cout << -1 ;
    else cout << dist[n] ;


    return 0;
}