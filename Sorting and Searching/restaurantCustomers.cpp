#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    map<int,int>mp;
    vector<pair<int,int>>v;
    set<int>s;
    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        s.insert(a);
        s.insert(b);
        v.push_back({a,b});
    }
    int newtag = 1;
    for(auto i:s) mp[i] = newtag++;

    vector<int>numberLine(newtag+10,0);
    for(int i=0; i<n; i++){
        int num1 = mp[v[i].first], num2 = mp[v[i].second];
        numberLine[num1]++;
        numberLine[num2+1]--;
    }
    
    for(int i=1; i<numberLine.size(); i++){
        numberLine[i] += numberLine[i-1];
    }

    int ans = 0;
    for(int i=0; i<numberLine.size(); i++){
        ans = max(ans, numberLine[i]);
    }

    cout << ans ;
}