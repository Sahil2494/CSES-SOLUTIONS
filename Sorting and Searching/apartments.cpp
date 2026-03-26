#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k; cin >> n >> m >> k;
    vector<int>desired(n),actual(m);
    for(int i=0; i<n; i++) cin >> desired[i];
    for(int i=0; i<m; i++) cin >> actual[i];
    sort(desired.begin(), desired.end());
    sort(actual.begin(), actual.end());
    int i=0, j=0, cnt=0;
    while(i<n && j<m){
        if((desired[i]-k <= actual[j]) && (actual[j] <= desired[i]+k)){
            cnt++;
            i++,j++;
        }
        else if(actual[j]<desired[i]-k) j++;
        else i++;
    }
    cout << cnt ;
}