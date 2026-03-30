#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define lll __uint128_t
#define MOD 998244353
#define endl '\n'
 
void solve()
{
    ll n; cin >> n ;
    vector<int>a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
 
    ll i=0,j=0;
    ll ans=0;
    map<int,int>mp;
    mp[a[0]]++;
    while(i<n){
        while(j+1<n && mp.find(a[j+1])==mp.end()){
            mp[a[j+1]]++;
            j++;
        }
        ans += (j-i+1);
        mp[a[i]]--;
        if(mp[a[i]]==0) mp.erase(a[i]);
        // printf("i = %d, j = %d\n", i,j);
        i++;
    }
    cout << ans ;
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