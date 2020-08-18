#include<bits/stdc++.h>
using namespace std;

int n,k;
int ara[100010];
int dp[100+5][100010];

bool solve(int sum,int idx) {
    bool check=false;
    sum=((sum%k)+k)%k;
    if(idx==n+1) {
        if(sum==0) return true;
        else return false;
    }
    if(dp[sum][idx]!=-1) return dp[sum][idx];
    check=check|solve(sum+ara[idx],idx+1);
    check=check|solve(sum-ara[idx],idx+1);
    dp[sum][idx]=check;
    return dp[sum][idx];
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
       scanf("%d%d",&n,&k);
       for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
       }
       memset(dp,-1,sizeof(dp));
       bool ans=solve(ara[1],2);
       if(ans) printf("Divisible\n");
       else printf("Not divisible\n");
    }
    return 0;
}
