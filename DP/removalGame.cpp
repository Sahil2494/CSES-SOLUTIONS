#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[5001][5001][2];
ll scoreA(int l, int r, vector<ll>&nums, bool chance1st){
    if(l>r) return 0;
    if(dp[l][r][chance1st]!=LLONG_MAX) return dp[l][r][chance1st];
    if(chance1st){
        return dp[l][r][1]=max(nums[l]+scoreA(l+1,r,nums,false), nums[r]+scoreA(l,r-1,nums,false));
    }
    else{
        return dp[l][r][0]=min(scoreA(l+1,r,nums,true), scoreA(l,r-1,nums,true));
    }
}
int main(){
    int n; cin >> n;
    vector<ll>nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            dp[i][j][0]=LLONG_MAX;
            dp[i][j][1]=LLONG_MAX;
        }
    }
    cout << scoreA(0,n-1,nums,true);
}