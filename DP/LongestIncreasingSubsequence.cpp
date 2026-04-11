#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int>endingElement(n,INT_MAX); //endingElement[i] stores last smallest possible element for a valid subsequence of length i+1 
    for(int i=0; i<n; i++){
        int lb = lower_bound(endingElement.begin(), endingElement.end(), arr[i])-endingElement.begin();
        endingElement[lb] = arr[i];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(endingElement[i]!=INT_MAX) ans++;
        else break;
    }
    cout << ans;
}