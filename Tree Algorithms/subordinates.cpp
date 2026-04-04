#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __uint128_t
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int mod=1e9+7;
ll my_gcd(ll a, ll b){
    if(a==0 && b==0) return 0;
    if(a==0) return b;
    ll rem=b%a;
    return my_gcd(rem,a);
}
 
int underMen[200001];
int subordinates(int node, int parent, vector<int>adj[]){
    underMen[node]=0;
    for(auto child:adj[node])
        if(parent!=child) underMen[node] += 1+subordinates(child,node,adj);
    return underMen[node];
}
 
void solve()
{
    int n; cin >> n;
 
    vector<int>adj[n+1];
    for(int emp1=2; emp1<=n; emp1++){
        int emp2; cin >> emp2;
        adj[emp1].push_back(emp2);
        adj[emp2].push_back(emp1);
    }
    subordinates(1,0,adj);
    for(int i=1; i<=n; i++) cout << underMen[i] << " ";
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