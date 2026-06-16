#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

//constructive algorithms

bool isPossible(int limit, vector<int>&a){
    for(int i=0; i<26; i++){
        if(a[i]>limit) return false;
    }
    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();

    vector<int>cnt(26,0);
    for(int i=0; i<n; i++){
        cnt[s[i]-'A']++;
    }

    for(int i=0; i<n; i++){
        int limit = (n-i+1)/2;

        bool found = false;
        for(int j=0; j<26; j++){
            if(i>0 && s[i-1]=='A'+j) continue;
            if(cnt[j]>limit){
                cout << -1;
                return 0;
            }
            if(cnt[j]>0){
                cnt[j]--;
                if(isPossible((n-i)/2, cnt)){
                    s[i] = 'A'+j;
                    found = true;
                    break;
                }
                cnt[j]++;
            }
        }
        if(!found){
            cout << -1;
            return 0;
        }
    }

    cout << s ;

    return 0;
}