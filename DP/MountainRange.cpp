#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int n; cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    if(n==1){
        cout << "1\n";
        return;
    }
    stack<int>s; //stores index
    vector<int>dp(n,1);

    for(int i=0; i<n; i++){
        vector<int>popped;
        while(!s.empty() && a[s.top()]<a[i]){
            popped.push_back(s.top());
            s.pop();
        }
        for(int j=1; j<popped.size(); j++){
            if(a[popped[j]]>a[popped[j-1]])
                dp[popped[j]] = max(dp[popped[j]], 1+dp[popped[j-1]]);
            else {
                dp[popped[j]] = max(dp[popped[j]], dp[popped[j-1]]);
            }
        }
        if(popped.size()!=0){
            dp[i] = max(dp[i], 1+dp[popped[popped.size()-1]]);
        }
        s.push(i);
    }
    {
        if(!s.empty()){
            int idx = s.top();
            s.pop();
            while(!s.empty()){
                if(a[idx]<a[s.top()])
                    dp[s.top()] = max(dp[s.top()], 1+dp[idx]);
                else dp[s.top()] = max(dp[s.top()], dp[idx]);
                idx = s.top();
                s.pop();
            }
        }
    }
    
    int maxi = 0;
    for(auto i:dp) {
        // cout << i << " ";
        maxi=max(maxi,i);
    }
    cout << maxi ;
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