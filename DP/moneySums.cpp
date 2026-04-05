#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int>coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    vector<bool>dp(1e5+1,false);
    dp[0]=true;
    for(int i=0; i<n; i++){
        vector<bool>next = dp;
        for(int sum=1; sum<=int(1e5); sum++){
            if(sum-coins[i]>=0 && dp[sum-coins[i]]) next[sum]=true;
        }
        dp = next;
    }

    vector<int>ans;
    for(int i=1; i<=int(1e5); i++){
        if(dp[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(auto i:ans) cout << i << " ";
}