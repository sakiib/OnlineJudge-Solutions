#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
ll n;
ll ara[N];
ll dp[N][5];
ll need[5];

ll solve(int pos,int idx) {
    if(idx>1) return 1;
    if(pos>=n) return 0;
    if(dp[pos][idx]!=-1) return dp[pos][idx];
    ll ans=0;
    if(ara[pos]==need[idx]) {
        ans+=solve(pos+1,idx+1);
    }
    ans+=solve(pos+1,idx);
    dp[pos][idx]=ans;
    return dp[pos][idx];
}
int main(int argc,char const *argv[]) {
    cin>>n;
    ara[0]=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        ara[i]+=ara[i-1];
    }
    if(ara[n]%2!=0) {
        cout<<0<<endl;
        return 0;
    }
    need[1]=ara[n]/2;
    need[2]=need[1]*2;
    memset(dp,-1,sizeof(dp));
    ll ans=solve(1,1);
    cout<<ans<<endl;
    return 0;
}
