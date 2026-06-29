#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;

    vector<int>inDegree(n+1, 0);
    vector<vector<int>>adj(n+1);

    for(int i=0; i<m; i++){
        //a --> b
        int a,b; cin >> a >> b;
        inDegree[b]++;
        adj[a].push_back(b);
    }

    queue<int>waitingQueue; //Elements with zero in-Degree

    for(int i=1; i<=n; i++){
        if(inDegree[i]==0) waitingQueue.push(i);
    }

    vector<int>processedNodes;
    while(!waitingQueue.empty()){
        int node = waitingQueue.front();
        waitingQueue.pop();

        for(int &child:adj[node]){
            inDegree[child]--;
            if(inDegree[child]==0) waitingQueue.push(child);
        }
        processedNodes.push_back(node);
    }

    //If Cycle exists
    if(processedNodes.size() < n){
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(auto i:processedNodes) cout << i << " ";

    return 0;
}