#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n; cin >> n;
    vector<string>grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];
    vector<vector<bool>>dp(n, vector<bool>(n, false));
    dp[0][0]=true;
    cout << grid[0][0];
    for(int i=0; i<=n-1; i++){
        char smallest = 'Z'+1;
        for(int j=i; i-j<n && j>=0; j--){
            if(dp[i-j][j]){
                if(i-j+1<n && grid[i-j+1][j]<smallest) smallest =  grid[i-j+1][j];
                if(j+1<n && grid[i-j][j+1]<smallest) smallest = grid[i-j][j+1];
            }
        }
        for(int j=i; i-j<n && j>=0; j--){
            if(dp[i-j][j]){
                if(i-j+1<n && grid[i-j+1][j]==smallest) dp[i-j+1][j]=true;
                if(j+1<n && grid[i-j][j+1]==smallest) dp[i-j][j+1]=true;
            }
        }
        if(smallest>'Z'){
            break;
        }
        cout << smallest;
    }

    for(int i=n; i<=2*n-2; i++){
        char smallest = 'Z'+1;
        for(int j=n-1; i-j<n && j>=0; j--){
            if(dp[i-j][j]){
                if(i-j+1<n && grid[i-j+1][j]<smallest) smallest =  grid[i-j+1][j];
                if(j+1<n && grid[i-j][j+1]<smallest) smallest = grid[i-j][j+1];
            }
        }
        for(int j=n-1; i-j<n && j>=0; j--){
            if(dp[i-j][j]){
                if(i-j+1<n && grid[i-j+1][j]==smallest) dp[i-j+1][j]=true;
                if(j+1<n && grid[i-j][j+1]==smallest) dp[i-j][j+1]=true;
            }
        }
        if(smallest>'Z'){
            break;
        }
        cout << smallest;
    }


    return 0;
}