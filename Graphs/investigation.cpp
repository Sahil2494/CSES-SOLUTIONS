#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

void minimumPrice(vector<vector<pair<int,ll>>>&adj){
    int n = adj.size()-1;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
    pq.emplace(0,1);
    vector<ll>minDist(n+1, 1e15);

    vector<ll>dp(n+1, 0), minFlights(n+1, INT_MAX), maxFlights(n+1, 0);

    minDist[1] = 0;
    dp[1] = 1;
    minFlights[1] = maxFlights[1] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second; ll currDist = pq.top().first;
        pq.pop();

        if(currDist > minDist[node]) continue;

        for(auto i:adj[node]){
            if(minDist[i.first] > currDist+i.second){
                dp[i.first] = dp[node];
                minFlights[i.first] = minFlights[node]+1;
                maxFlights[i.first] = maxFlights[node]+1;
                minDist[i.first] = currDist+i.second;
                pq.emplace(minDist[i.first], i.first);
            }
            else if(currDist+i.second == minDist[i.first]){
                minFlights[i.first] = min(minFlights[i.first], minFlights[node]+1);
                maxFlights[i.first] = max(maxFlights[i.first], maxFlights[node]+1);
                dp[i.first] = (dp[i.first]+dp[node])%mod;
            }
        }
    }

    cout << minDist[n] << " " << dp[n] << " "
    << minFlights[n] << " " << maxFlights[n] << '\n';
    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    vector<vector<pair<int,ll>>>adj(n+1);

    for(int i=0; i<m; i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    minimumPrice(adj);

    return 0;
}