#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    vector<ll>p(n+1,0);
    for(int i=1; i<=n; i++) {
        cin >> p[i];
    }
    if(n==1){
        cout << 0;
        return;
    }
    sort(p.begin(), p.end());
    ll med = p[n/2+1];
    ll cost = 0;
    for(int i=1; i<=n; i++) cost += abs(p[i]-med);
    cout << cost ;
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