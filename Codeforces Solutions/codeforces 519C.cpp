#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll ex,ll nb) {
    ll tot=0,mx=0;
    for(ll i=0;i<=nb;i++) {
        if(i*2>ex) break;
        ll team=i+min(ex-2*i,(nb-i)/2);
        mx=max(team,mx);
    }
    return mx;
}
int main(int argc,char const *argv[]) {
    ll ex,nb,ans;
    cin>>ex>>nb;
    ans=solve(ex,nb);
    cout<<ans<<endl;
    return 0;
}
