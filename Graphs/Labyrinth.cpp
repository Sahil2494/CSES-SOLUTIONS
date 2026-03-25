#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<string>v;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    int sx=-1,sy=-1,ex=-1,ey=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]=='A'){
                sx=i,sy=j;
            }
            if(v[i][j]=='B'){
                ex=i,ey=j;
            }
        }
    }
    
    vector<vector<char>>path(n, vector<char>(m,'#'));
    queue<pair<int,int>>q;
    q.push({ex,ey});
    v[ex][ey]='#';
    while(!q.empty()){
        pair<int,int>p = q.front();
        q.pop();
        auto [x,y] = p;
        if(x+1<n && v[x+1][y]!='#'){
            q.push({x+1,y});
            path[x+1][y] = 'U';
            v[x+1][y] = '#';
            if(x+1==sx && y==sy) break;
        }
        if(x-1>=0 && v[x-1][y]!='#'){
            q.push({x-1,y});
            path[x-1][y] = 'D';
            v[x-1][y] = '#';
            if((x-1==sx) && y==sy) break;
        }
        if(y+1<m && v[x][y+1]!='#'){
            q.push({x,y+1});
            path[x][y+1] = 'L';
            v[x][y+1] = '#';
            if(x==sx && (y+1)==sy) break;
        }
        if(y-1>=0 && v[x][y-1]!='#'){
            q.push({x,y-1});
            path[x][y-1] = 'R';
            v[x][y-1]='#';
            if(x==sx && (y-1)==sy) break;
        }
    }
    
    if(v[sx][sy]=='A'){
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    string ans;
    int i=sx,j=sy;
    while(path[i][j]!='#'){
        ans.push_back(path[i][j]);
        if(path[i][j]=='L') j--;
        else if(path[i][j]=='R') j++;
        else if(path[i][j]=='U') i--;
        else i++;
    }
    cout << ans.size() << '\n';
    cout << ans ;
    return 0;
}