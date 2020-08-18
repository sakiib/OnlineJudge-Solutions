#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll ans,n;

ll calc(ll x) {
    ll tot=0;
    for(ll i=5;(x/i)>=1;i*=5) {
        tot+=(x/i);
    }
    return tot;
}
void solve(ll lo,ll hi) {
    ll mid;
    while(lo<=hi) {
        mid=(lo+hi)/2;
        ll val=calc(mid);
        if(val==n) {ans=mid;}
        if(val<n) lo=mid+1;
        else hi=mid-1;
        //cerr<<"mid == val : "<<" "<<mid<<" "<<val<<endl;
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%lld",&n);
        ans=-1;
        solve(1,INT_MAX);
        if(ans==-1) printf("Case %d: impossible\n",tc);
        else printf("Case %d: %lld\n",tc,ans);
    }
    return 0;
}
