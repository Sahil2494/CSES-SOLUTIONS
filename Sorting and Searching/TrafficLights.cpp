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
    int n,x; cin >> x >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    set<pair<int,int>>s;
    multiset<int>values;
    values.insert(x);
    vector<int>ans;
    s.insert({0,x});
    for(int i=0; i<n; i++){
        int splitIdx = a[i];
        if(s.empty()){
            ans.push_back(0);
            continue;
        }
        auto it = s.lower_bound({splitIdx,splitIdx});
        it--;
        int start = (*it).first, end = (*it).second;
        values.erase(values.find(end-start));
        s.erase(it);
        if(splitIdx-start>0) {
            s.insert({start,splitIdx});
            values.insert(splitIdx-start);
        }
        if(end-splitIdx>0) {
            s.insert({splitIdx,end});
            values.insert(end-splitIdx);
        }
        if(s.empty()){
            ans.push_back(0);
            continue;
        }
        ans.push_back(*(values.rbegin()));
    }
    for(auto i:ans) cout << i << " ";
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