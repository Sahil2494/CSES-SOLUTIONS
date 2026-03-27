#include <iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int l=0,r=0,ans=1;
    set<int>s;
    s.insert(a[0]);
    while(r+1<n){
        if(s.find(a[r+1])==s.end()){
            r++;
            s.insert(a[r]);
        }
        else{
            s.erase(a[l]);
            l++;
            if(r<l) {
                r=l;
                s.insert(a[r]);
            }
        }
        ans = max(ans, r-l+1);
    }
    cout << ans ;
    return 0;
}