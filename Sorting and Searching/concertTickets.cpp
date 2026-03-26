#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    multiset<int>s;
    vector<int>v(m);
    for(int i=0; i<n; i++){
        int x; cin >> x;
        s.insert(x);
    }
    for(int i=0; i<m; i++){
        cin >> v[i];
    }
    for(int i=0; i<m; i++){
        auto it = s.upper_bound(v[i]);
        if(it==s.begin()){
            cout << -1 << '\n';
            continue;
        }
        it--;
        cout << *it << '\n';
        s.erase(it);
    }
}