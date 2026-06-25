#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

bool visited[9][9];

int sol(int index, int i, int j, string &s){
    //base case
    if(i==7 && j==1){
        if(index==48) return 1;
        else return 0;
    }
    if(index==48) return 0;

    //vertically partitioned : Left and right unvisited parts are separated by vertical vertical line
    if(visited[i+1][j] && visited[i-1][j] && !visited[i][j-1] && !visited[i][j+1]){
        return 0;
    }

    //horizontally partitioned : Above and Below non-visited are separated by horizontal visited line
    if(visited[i][j-1] && visited[i][j+1] && !visited[i-1][j] && !visited[i+1][j]){
        return 0;
    }

    visited[i][j] = true;

    int ways = 0;
    if(s[index] == '?'){
        //4 possibilities
        int l = (j-1>=1 && !visited[i][j-1]) ? sol(index+1,i,j-1,s) : 0;
        int r = (j+1<=7 && !visited[i][j+1]) ? sol(index+1,i,j+1,s) : 0;
        int u = (i-1>=1 && !visited[i-1][j]) ? sol(index+1,i-1,j,s) : 0;
        int d = (i+1<=7 && !visited[i+1][j]) ? sol(index+1,i+1,j,s) : 0;
        ways = l+r+u+d;
    }
    else{
        int l = (s[index] == 'L' && j-1>=1 && !visited[i][j-1]) ? sol(index+1,i,j-1,s) : 0;
        int r = (s[index] == 'R' && j+1<=7 && !visited[i][j+1]) ? sol(index+1,i,j+1,s) : 0;
        int u = (s[index] == 'U' && i-1>=1 && !visited[i-1][j]) ? sol(index+1,i-1,j,s) : 0;
        int d = (s[index] == 'D' && i+1<=7 && !visited[i+1][j]) ? sol(index+1,i+1,j,s) : 0;
        ways = l+r+u+d;
    }
    visited[i][j] = false;
    return ways;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string path; cin >> path;

    for(int i=0; i<9; i++){
        visited[i][0] = visited[0][i] = true;
        visited[i][8] = visited[8][i] = true;
    }

    cout << sol(0,1,1,path);

    return 0;
}