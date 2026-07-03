#include <iostream>
#include<vector>
#include<climits>
#include<queue>
#define ll long long
#define mod 1000000007
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    vector<vector<pair<int,ll>>>adj(n+1);
    for(int i=0; i<m; i++){
        int a,b; 
        ll c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    priority_queue<pair<ll, int> , vector<pair<ll,int>> , greater<pair<ll,int>>> q;

    q.push({0,1});

    vector<ll>dist(n+1,LLONG_MAX);
    vector<bool>visited(n+1, false);
    dist[1] = 0;

    while (!q.empty())
    {
        pair<ll,int>p = q.top();
        int node = p.second;
        ll distToNode = p.first;
        q.pop();

        if(visited[node]) continue;

        visited[node] = true;

        for(pair<int, ll> &child:adj[node]){
            if(dist[child.first] > distToNode+child.second){
                dist[child.first] = distToNode+child.second;
                q.push({dist[child.first], child.first});
            }
        }

    }

    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    

    return 0;
}