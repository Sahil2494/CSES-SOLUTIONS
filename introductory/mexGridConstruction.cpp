#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

void findMex(int r, int c, vector<vector<int>>&grid){
    vector<bool>found(200, false);

    for(int i=0; i<r; i++){
        found[grid[i][c]] = true;
    }
    for(int j=0; j<c; j++){
        found[grid[r][j]] = true;
    }

    for(int i=0; i<200; i++){
        if(!found[i]){
            grid[r][c] = i;
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

    int n; cin >> n;
    vector<vector<int>>grid(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            findMex(i,j,grid);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << grid[i][j] << " ";
        cout << '\n';
    }

    return 0;
}