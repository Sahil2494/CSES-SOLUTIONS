#include <iostream>
#include<vector>
#include<queue>
#define ll long long
#define mod 1000000007
using namespace std;

void check(int i, int j, vector<vector<int>>&grid, int d, queue<pair<pair<int,int>,int>>&q){
    if(grid[i][j]==-1){
        grid[i][j] = d;
        q.push({{i,j},d});
    }
}

void updateGrid(int i, int j, vector<vector<int>>&grid, queue<pair<pair<int,int>,int>>&q, int d){

    int n=grid.size();

    if(i-2>=0){
        
        if(j-1>=0){
            check(i-2,j-1,grid,d,q);
        }
        
        if(j+1<n){
            check(i-2,j+1,grid,d,q);
        }

    }

    if(i-1>=0){

        if(j-2>=0){
            check(i-1,j-2,grid,d,q);
        }

        if(j+2<n){
            check(i-1,j+2,grid,d,q);
        }

    }

    if(i+1<n){

        if(j-2>=0){
            check(i+1,j-2,grid,d,q);
        }

        if(j+2<n){
            check(i+1,j+2,grid,d,q);
        }

    }

    if(i+2<n){

        if(j-1>=0){
            check(i+2,j-1,grid,d,q);
        }
        
        if(j+1<n){
            check(i+2,j+1,grid,d,q);
        }

    }
}

int main(){
    int n; cin >> n;
    vector<vector<int>>grid(n, vector<int>(n, -1));
    grid[0][0]=0;

    queue<pair<pair<int,int>,int>>q;

    q.push({{0,0},0});

    while(!q.empty()){

        int i = q.front().first.first, j = q.front().first.second, l = q.front().second;
        q.pop();

        updateGrid(i,j,grid,q,l+1);

    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}