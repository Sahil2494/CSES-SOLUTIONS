#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
ll s(ll n){
    return n*(n+1)/2;
}

int sol(int i, int n, int sum, vector<vector<ll>>&dp){
    if(i>n) {
        if(sum==s(n)/2) return 1;
        else return 0;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    return dp[i][sum]=(sol(i+1,n,sum+i,dp)+sol(i+1,n,sum,dp))%mod;
}

int main(){
    int n; cin >> n;
    ll sum = s(n);
    if(sum&1){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<ll>>dp(n+1, vector<ll>(s(n)+1,-1));
    int ans = sol(2,n,1,dp);
    cout << ans << endl;
}