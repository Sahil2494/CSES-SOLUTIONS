#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<pair<int,int>>v;
    for(int i=0; i<n; i++){
        int start,end; cin >> start >> end;
        v.push_back({end,start});
    }
    sort(v.begin(), v.end());
    int engagedTime = -1;
    int cnt = 0;
    for(int i=0; i<n; i++){
        int start = v[i].second, end = v[i].first;
        if(engagedTime <= start){
            engagedTime = end;
            cnt++;
        }
    }
    cout << cnt;
}