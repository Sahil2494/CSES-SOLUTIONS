#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k; cin >> n >> k;
    vector<int>moves(k);
    for(int i=0; i<k; i++) cin >> moves[i];

    vector<bool>dp(n+1,false);
    for(int i=1; i<=n; i++){
        for(int j=0; j<k; j++){
            if(moves[j]<=i){
                if(!dp[i-moves[j]]) {
                    dp[i]=true;
                    break;
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(dp[i]) cout << "W";
        else cout << "L";
    }
}