#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mx;
ll ara[100010];
ll val[100010]={0};
ll dp[100010];

ll solve(ll cur) {

    if(cur>mx) return 0;
    if(dp[cur]!=-1) return dp[cur];
    ll op1=(cur*val[cur])+solve(cur+2);
    ll op2=solve(cur+1);
    dp[cur]=max(op1,op2);
    return dp[cur];
}
int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        val[ara[i]]++;
        mx=max(mx,ara[i]);
    }
    memset(dp,-1,sizeof(dp));
    ll ans=solve(1);
    cout<<ans<<endl;
    return 0;
}
