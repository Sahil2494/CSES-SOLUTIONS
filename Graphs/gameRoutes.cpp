#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n;
ll cntWays(int node, vector<vector<int>>&adj, vector<ll>&dp){
    if(node==1) return 1;

    if(dp[node] != -1) return dp[node];

    ll ways = 0;
    for(int &child:adj[node]){
        ways = (ways + cntWays(child,adj,dp))%mod;
    }

    return dp[node] = ways;

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> n >> m;

    vector<vector<int>>adj(n+1);
    vector<ll>dp(n+1, -1); //dp[x] -> number of ways of reaching x from 1

    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        adj[b].push_back(a);
    }

    ll ways = cntWays(n, adj, dp);

    cout << ways << '\n';

    return 0;
}