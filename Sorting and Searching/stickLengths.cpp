#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define lll __uint128_t
#define MOD 998244353
#define endl '\n'
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
namespace sahil{ll my_gcd(ll a, ll b){if(a==0 && b==0) return 0;if(a==0) return b;ll rem=b%a;return my_gcd(rem,a);}ll my_lcm(ll a, ll b){return (a/my_gcd(a,b))*b;}}
using namespace sahil;
const int mod=1e9+7;

void solve()
{
    int n; cin >> n;
    vector<ll>p(n);
    ll sum = 0;
    for(int i=0; i<n; i++) {
        cin >> p[i];
        sum += p[i];
    }
    sum /= n;
    ll cost = 0;
    for(int i=0; i<n; i++){
        cost += abs(sum-p[i]);
    }
    cout << 
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //sieve();
    ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}