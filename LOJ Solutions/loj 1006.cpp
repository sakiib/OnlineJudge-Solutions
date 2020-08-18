#include<bits/stdc++.h>
using namespace std;

const int N=100005;
typedef long long LL;
const LL MOD=10000007;
LL a,b,c,d,e,f,n;
LL dp[N];

LL solve(LL n) {
    if(dp[n]!=-1) return dp[n]%MOD;
    if(n==0) return a%MOD;
    if(n==1) return b%MOD;
    if(n==2) return c%MOD;
    if(n==3) return d%MOD;
    if(n==4) return e%MOD;
    if(n==5) return f%MOD;
    else return dp[n]=((solve(n-1))+solve(n-2)+solve(n-3)+solve(n-4)+solve(n-5)+solve(n-6))%MOD;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        memset(dp,-1,sizeof(dp));
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&n);
        LL ans=solve(n);
        printf("Case %d: %lld\n",tc,ans%MOD);
    }
    return 0;
}
