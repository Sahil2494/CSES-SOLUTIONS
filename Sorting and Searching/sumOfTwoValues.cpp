#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x; cin >> n >> x;
    vector<int>a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    map<int,int>mp;
    for(int i=0; i<n; i++){
        if(mp.find(x-a[i])!=mp.end()){
            cout << mp[x-a[i]] << " " << i+1 ;
            return 0;
        }
        mp[a[i]] = i+1;
    }
    cout << "IMPOSSIBLE";
    return 0;
}