#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

vector<int> nextNode(100001);

int n;
int dfs(vector<int>&dp, int node, vector<vector<int>>&adj){
    //base case
    if(node==n) return 0;

    if(dp[node]!=INT_MIN) return dp[node];

    int maxSteps = INT_MIN;

    for(int &child:adj[node]){
        int furtherDist = 1+dfs(dp,child,adj);
        if(furtherDist > maxSteps) {
            maxSteps = furtherDist;
            nextNode[node] = child;
        }
    }

    return dp[node] = maxSteps;
    
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

    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int>dp(n+1, INT_MIN);

    for(int i=0; i<=n; i++) {
        nextNode[i] = 0;
    }

    dfs(dp,1,adj);

    //for(int i=1; i<=n; i++) cout << i << " child of " << parent[i] << '\n';

    if(dp[1] < 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    {
        int curr = 1;
        cout << dp[1] + 1 << '\n';
        while(curr!=0){
            cout << curr << " ";
            curr = nextNode[curr];
        }
    }
    return 0;
}