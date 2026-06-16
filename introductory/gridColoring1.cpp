#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

void replace(char &loc, char c1, char c2){
    for(int i=0; i<4; i++){
        char letter = 'A'+i;
        if(letter!=loc && letter!=c1 && letter!=c2) {
            loc = letter;
            return;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    vector<string>v;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        v.push_back(s);
    }

    //handling first row
    for(int j=0; j<m; j++){
        if(j==0){
            v[0][0] = (v[0][0]=='A') ? 'B' : 'A';
        }
        else {
            replace(v[0][j], v[0][j-1], 'X');
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(j==0){
                replace(v[i][j], v[i-1][j], 'X');
            }
            else replace(v[i][j], v[i-1][j], v[i][j-1]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout << v[i][j];
        cout << '\n';
    }

    return 0;
}