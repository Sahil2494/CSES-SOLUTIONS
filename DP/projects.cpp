#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(pair<pair<int,int>,ll>&a, pair<pair<int,int>,ll>&b){
    int e1=a.first.first, e2=b.first.first;
    int s1=a.first.second, s2=b.first.second;
    if(e1<e2) return true;
    if(e1>e2) return false;
    if(s1<s2) return true;
    else return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<pair<pair<int,int>,ll>>v;
    map<int,int>mp;
    int k=1;
    {
        set<int>s;
        for(int i=0; i<n; i++){
            int start,end;
            ll profit;
            cin >> start >> end >> profit;
            s.insert(start);
            s.insert(end);
            v.push_back({{end,start},profit});
        }

        for(auto i:s){
            mp[i] = k++;
        }
    }
    for(int i=0; i<n; i++){
        v[i].first.first = mp[v[i].first.first];
        v[i].first.second = mp[v[i].first.second];
    }
    
    vector<vector<pair<int,ll>>>day(k+1);
    for(int i=0; i<n; i++){
        int start=v[i].first.second;
        int end = v[i].first.first;
        ll profit = v[i].second;
        day[end].push_back({start,profit});
    }

    vector<ll>dp(k+1,0);
    for(int i=1; i<k; i++){
        for(int j=0; j<day[i].size(); j++){
            int start = day[i][j].first, profit = day[i][j].second;
            dp[i] = max(dp[i], dp[start-1]+profit);
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    
    cout << dp[k-1];
}