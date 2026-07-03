#include <iostream>
#include<vector>
#include<climits>
#define ll long long
#define mod 1000000007
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q; cin >> n >> m >> q;

    vector<vector<ll>>adj(n+1, vector<ll>(n+1, LLONG_MAX));

    for(int i=0; i<m; i++){
        int a,b; ll c; cin >> a >> b >> c;
        adj[a][b] = min(c, adj[a][b]);
        adj[b][a] = min(c, adj[b][a]);
    }

    for(int intermediate=1; intermediate<=n; intermediate++){
        for(int node2=1; node2<=n; node2++){
            for(int node1=1; node1<=n; node1++){
                if(node1==node2){
                    adj[node1][node1] = 0;
                    continue;
                }
                if(adj[node1][intermediate] != LLONG_MAX && adj[intermediate][node2] != LLONG_MAX){
                    if(adj[node1][node2] > adj[node1][intermediate] + adj[intermediate][node2]){
                        adj[node1][node2] = adj[node1][intermediate] + adj[intermediate][node2];
                        adj[node2][node1] = adj[node1][intermediate] + adj[intermediate][node2];
                    }
                }
            }
        }
    }

    for(int i=1; i<=q; i++){
        int node1, node2; cin >> node1 >> node2;
        if(adj[node1][node2]==LLONG_MAX) cout << -1 << '\n';
        else cout << adj[node1][node2] << '\n';
    }

    return 0;
}