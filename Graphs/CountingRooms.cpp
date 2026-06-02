#include<bits/stdc++.h>
using namespace std;

void dfs(vector<string>&grid, int i, int j){
    grid[i][j] = '#';
    if(i>0 && grid[i-1][j]=='.') dfs(grid,i-1,j);
    if(j>0 && grid[i][j-1]=='.') dfs(grid,i,j-1);
    if(i+1<grid.size() && grid[i+1][j]=='.') dfs(grid,i+1,j);
    if(j+1<grid[0].size() && grid[i][j+1]=='.') dfs(grid,i,j+1);
}

int main(){
    int n,m; cin >> n >> m;
    vector<string>v;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        v.push_back(s);
    }

    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]=='.'){
                cnt++;
                dfs(v,i,j);
            }
        }
    }

    cout << cnt ;
}