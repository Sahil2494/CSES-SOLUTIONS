#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n; cin >> n;
    vector<ll>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    ll currSum = 0, ans = a[0];
    for(int i=0; i<n; i++){
        currSum += a[i];
        if(currSum < 0){
            ans = max(ans, currSum);
            currSum = 0;
            continue;
        }
        ans = max(ans, currSum);
    }
    cout << ans ;
}