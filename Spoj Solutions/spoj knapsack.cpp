#include<bits/stdc++.h>
using namespace std;

const int N=2005;

int cap,n;
int wt[N],val[N];
int dp[N][N];

int solve(int i,int cur) {
    if(i==n+1) return 0;
    if(dp[i][cur]!=-1) return dp[i][cur];
    int op1=0,op2=0;
    if(cur+wt[i]<=cap) op1=val[i]+solve(i+1,cur+wt[i]);
    op2=solve(i+1,cur);
    dp[i][cur]=max(op1,op2);
    return dp[i][cur];
}
int main(int argc,char const *argv[]) {
    while(scanf("%d%d",&cap,&n)==2) {
        for(int i=1;i<=n;i++) {
            scanf("%d%d",&wt[i],&val[i]);
        }
        memset(dp,-1,sizeof(dp));
        int ans=solve(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
