#include<bits/stdc++.h>
using namespace std;
int main(){
    int dp[501][501];

    int a,b; cin >> a >> b;
    for(int i=0; i<=500; i++){
        for(int j=0; j<=500; j++){
            dp[i][j] = INT_MAX;
        }
    }
    for(int i=1; i<=500; i++){
        dp[i][1] = dp[1][i] = (i-1);
        dp[i][i] = 0;
    }

    for(int i=2; i<=a; i++){
        for(int j=2; j<=b; j++){
            //horizontal cuts
            for(int k=1; k<=i-1; k++){
                dp[i][j] = min(dp[i][j], 1+dp[i-k][j]+dp[k][j]);
            }
            for(int k=1; k<=j-1; k++) dp[i][j] = min(dp[i][j], 1+dp[i][j-k]+dp[i][k]);
        }
    }
    cout << dp[a][b];
}