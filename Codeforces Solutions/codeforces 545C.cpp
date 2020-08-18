#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=100010;
pair<ll,ll> P[N];
ll dp[N];
ll n;

ll solve(ll cur,ll pos) {
    if(pos==n) return 1;
    if(dp[pos]!=-1) return dp[pos];
    ll val=0;
    if(P[pos].first-P[pos].second>cur) {
        val=1+solve(P[pos].first,pos+1);
    }
    else if(P[pos].first+P[pos].second<P[pos+1].first) {
        val=1+solve(P[pos].first+P[pos].second,pos+1);
    }
    else val=solve(P[pos].first,pos+1);
    dp[pos]=val;
    return dp[pos];
}
int main(int argc,char const *argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>P[i].first>>P[i].second;
    }
    memset(dp,-1,sizeof(dp));
    ll ans=(solve(P[1].first,2)+1);
    cout<<ans<<endl;
    return 0;
}
