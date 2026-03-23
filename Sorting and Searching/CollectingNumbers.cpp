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
 
ll binExp(ll a, ll b){
    ll value = a%MOD, ans = 1;
    while(b){
        if(b&1){ ans*=value; ans%=MOD; }
        b=b>>1; value*=value;value%=MOD;
    }
    return ans%MOD;
}
const int MAXN = 1e6;
bool Prime[MAXN];
void sieve(){
    memset(Prime, true, sizeof(Prime));
    Prime[0] = Prime[1] = false;
    for(int i=2; i*i<MAXN; i++){
        if(!Prime[i]) continue;
        for(ll j = 1LL * i * i; j < MAXN; j += i){
            Prime[j] = false;
        }
    }
}
 
void solve()
{
    int n; cin >> n;
    vector<int>a(n);
    map<int,int>mp;
    for(int i=0; i<n; i++){
        cin >> a[i];
        mp[a[i]] = i;    
    }
    int idx = -1;
    int rounds = 1;
    for(int i=1; i<=n; i++){
        if(mp[i]<idx){
            rounds++;
        }
        idx = mp[i];
    }
    
    cout << rounds;
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