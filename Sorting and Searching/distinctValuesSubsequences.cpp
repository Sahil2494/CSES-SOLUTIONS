#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define lll __uint128_t
#define MOD 998244353
#define endl '\n'
const int mod=1e9+7;

void solve()
{
    ll n; cin >> n ;
    vector<int>a(n);
    unordered_map<int,ll>mp;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
 
    ll ans = 1;
    for(auto i:mp){
        ll cnt = i.second;
        ans = (ans * (cnt+1)) % mod;
    }
    cout << ans-1 ;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll test=1;
    // cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}