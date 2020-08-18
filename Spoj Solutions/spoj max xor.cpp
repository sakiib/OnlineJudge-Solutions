#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll ara[100010];
ll dp[100010];

ll solve(int i) {
    if(i==n+1) return 0;
    if(dp[i]!=-1) return dp[i];
    ll op1=0,op2=0;
    op1=solve(i+1);
    op2=ara[i]^solve(i+1);
    dp[i]=max(op1,op2);
    return dp[i];
}
int main(int argc,char const *argv[]) {
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&ara[i]);
    }
    memset(dp,-1,sizeof(dp));
    ll ans=solve(1);
    printf("%lld \n",ans);
    return 0;
}
