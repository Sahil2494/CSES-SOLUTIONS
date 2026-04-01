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
 
bool compare(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
    if(a.first.first==b.first.first) return a.first.second > b.first.second;
    else return a.first.first < b.first.first;
}
 
void mergeSort(int s, int e, vector<pair<pair<int,int>,int>>&a, vector<bool>&inversions, vector<bool>&ans2){
    if(s>=e){
        return;
    }
    int mid = s+(e-s)/2;
    mergeSort(s,mid,a,inversions,ans2);
    mergeSort(mid+1,e,a,inversions,ans2);
 
    vector<pair<pair<int,int>,int>>merged(e-s+1);
    int left=s,right=mid+1,ptr=0;
    bool inversionFound=false;
    while(left<=mid && right<=e){
        if(a[left].first.second >= a[right].first.second){
            inversions[a[left].second] = true;
            ans2[a[right].second] = true;
            merged[ptr++] = a[right++];
            inversionFound=true;
        }
        else{
            if(inversionFound) inversions[a[left].second] = true;
            merged[ptr++] = a[left++];
        }
    }
    while(left<=mid){
        inversions[a[left].second] = true;
        merged[ptr++] = a[left++];
    }
    while(right<=e){
        merged[ptr++] = a[right++];
    }
    for(int i=s; i<=e; i++) a[i] = merged[i-s];
}
 
void solve()
{
    int n; cin >> n;
    vector<pair<pair<int,int>,int>>a;
    for(int i=0; i<n; i++){
        int x,y; cin >> x >> y;
        a.push_back({{x,y},i});
    }
    sort(a.begin(), a.end(), compare);
    vector<bool>ans1(n,false),ans2(n,false);
    mergeSort(0,n-1,a,ans1,ans2);
    for(auto i:ans1) cout << i << " " ;
    cout << endl;
    for(auto i:ans2) cout << i << " "; 
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