#include <iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include <climits>
#define ll long long
#define mod 1000000007
using namespace std;

void bfs(vector<string>&grid, vector<vector<int>>&v){
    
    int n=grid.size(), m=grid[0].size();
    
    queue<pair<pair<int,int>,int>>q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='M'){
                q.push({{i,j},0});
                v[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        pair<pair<int,int>,int>p = q.front();
        q.pop();
        int i=p.first.first, j=p.first.second, l=p.second;
        
        if(i+1<n && v[i+1][j]>l+1) {
            q.push({{i+1,j}, l+1});
            v[i+1][j]=l+1;
        }

        if(i-1>=0 && v[i-1][j]>l+1){
            q.push({{i-1,j},l+1});
            v[i-1][j]=l+1;
        }

        if(j-1>=0 && v[i][j-1]>l+1){
            q.push({{i,j-1},l+1});
            v[i][j-1]=l+1;
        }

        if(j+1<m && v[i][j+1]>l+1){
            q.push({{i,j+1},l+1});
            v[i][j+1]=l+1;
        }
    }
}

void getPath(int x, int y, vector<vector<int>>&v){

    int n=v.size(),m=v[0].size();

    queue<pair<pair<int,int>,int>>q;
    q.push({{x,y},0});
    v[x][y]=-1;

    vector<vector<char>>path(n, vector<char>(m, 'T'));

    while(!q.empty()){
        pair<pair<int,int>,int>p = q.front();
        q.pop();

        int i=p.first.first, j=p.first.second, l=p.second;

        if(i+1<n && v[i+1][j]>l+1){
            q.push({{i+1,j},l+1});
            path[i+1][j] = 'U';
            v[i+1][j]=-1;
        }

        if(i-1>=0 && v[i-1][j]>l+1){
            q.push({{i-1,j},l+1});
            path[i-1][j]='D';
            v[i-1][j]=-1;
        }

        if(j-1>=0 && v[i][j-1]>l+1){
            q.push({{i,j-1},l+1});
            path[i][j-1]='R';
            v[i][j-1]=-1;
        }

        if(j+1<m && v[i][j+1]>l+1){
            q.push({{i,j+1},l+1});
            path[i][j+1]='L';
            v[i][j+1]=-1;
        }
    }

    int sti=-1,stj=-1;
    for(int i=0; i<n; i++){
        if(path[i][0]!='T'){
            sti=i,stj=0;
            break;
        }

        if(path[i][m-1]!='T'){
            sti=i,stj=m-1;
            break;
        }
    }

    for(int j=0; j<m; j++){
        if(path[0][j]!='T'){
            sti=0,stj=j;
            break;
        }
        if(path[n-1][j]!='T'){
            sti=n-1,stj=j;
            break;
        }
    }

    if(sti==-1){
        cout << "NO";
        return;
    }

    {
        string ans;
        int i = sti, j = stj;
        while(path[i][j] != 'T'){
            if(path[i][j]=='L'){
                ans.push_back('R');
                j--;
            }
            else if(path[i][j] == 'R'){
                ans.push_back('L');
                j++;
            }
            else if(path[i][j] == 'U'){
                ans.push_back('D');
                i--;
            }
            else if(path[i][j] == 'D'){
                ans.push_back('U');
                i++;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        cout << ans.size() << '\n';
        cout << ans << '\n';
    }
    
}

int main(){
    int n,m; cin >> n >> m;
    vector<string>grid;
    vector<vector<int>>v(n, vector<int>(m, INT_MAX));
    int sti=-1,stj=-1;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        grid.push_back(s);
        for(int j=0; j<m; j++){
            if(s[j]=='#'){
                v[i][j] = -1;
            }
            if(s[j]=='A'){
                sti=i,stj=j;
            }
        }
    }

    if(sti==0 || sti==n-1 || stj==0 || stj==m-1){
        cout << "YES\n";
        cout << 0 ;
        return 0;
    }

    bfs(grid,v);

    getPath(sti,stj,v);

    return 0;
}