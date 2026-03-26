#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x; cin >> n >> x;
    vector<int>p(n);
    for(int i=0; i<n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int i=0,j=n-1,cnt=0;
    while(i<=j){
        if(p[j]+p[i]<=x){
            i++,j--;
        }
        else j--;
        cnt++;
    }
    cout << cnt;
}