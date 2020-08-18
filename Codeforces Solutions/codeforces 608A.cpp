#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n,f;
    cin>>n>>f;
    vector<pair<int,int> > V;
    for(int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        V.push_back({x,y});
    }
    sort(V.rbegin(),V.rend());
    int prev=0;
    int ans=0;
    for(auto &x : V) {
       ans+=(f-x.first);
       if(ans<x.second) {
        int more=0;
        more=x.second-ans;
        ans+=more;
       }
       f=x.first;
    }
    ans+=(f);
    cout<<ans<<endl;
    return 0;
}
