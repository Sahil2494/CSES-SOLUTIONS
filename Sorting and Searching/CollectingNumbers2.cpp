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
    int n,queries; cin >> n >> queries;
    vector<int>a(n+1);
    vector<int>mp(n+1);
    for(int i=1; i<=n; i++){
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
    
    for(int i=1; i<=queries; i++){
        int p,q; cin >> p >> q;
        int x = a[p], y = a[q];
        set<pair<int,int>>s; 
        if(x!=1) s.insert({x-1,x});    
        if(y!=1) s.insert({y-1,y});
        if(x!=n) s.insert({x,x+1});
        if(y!=n) s.insert({y,y+1});
        for(auto j:s){
            int ele1 = j.first, ele2 = j.second;
            if(mp[ele1]>mp[ele2]) rounds--;    
        }
        mp[x]=q, mp[y]=p;
        swap(a[p],a[q]);
        for(auto j:s){
            int ele1 = j.first, ele2 = j.second;
            if(mp[ele1]>mp[ele2]) rounds++;
        }
        cout << rounds << '\n';
    }
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