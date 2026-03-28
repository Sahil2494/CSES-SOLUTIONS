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
    int n; cin >> n;
    multiset<int>s;
    for(int i=0; i<n; i++){
        int cube; cin >> cube;
        auto it = s.upper_bound(cube);
        if(it==s.end()){
            s.insert(cube);
        }
        else{
            s.erase(it);
            s.insert(cube);
        }
    }
    cout << s.size() << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //sieve();
    ll test=1;
    // cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}