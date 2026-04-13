#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int s=0;

    for(int i=1; i<=n; i++){
        int x; cin >> x;
        s^=x;
    }

    if(s==0) cout << "second\n";
    else cout << "first\n";

}
int main(){
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}