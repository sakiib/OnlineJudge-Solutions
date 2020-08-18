#include<bits/stdc++.h>
using namespace std;

const int N=105;
int n,ara[N],dp[N][5];
int none=0,gym=1,con=2,both=3,rest=5;

int solve(int idx,int prev) {
    if(idx==n+1) return 0;

    int res=0,res1=0,res2=0,res3=0;

    if(dp[idx][prev]!=-1) return dp[idx][prev];

    if(ara[idx]==none){
        res=solve(idx+1,rest);
    }
    else if(ara[idx]==gym) {
        if(prev!=gym) res1=solve(idx+1,gym)+1;
        res2=solve(idx+1,rest);
        res=max(res1,res2);
    }
    else if(ara[idx]==con) {
        if(prev!=con) res1=solve(idx+1,con)+1;
        res2=solve(idx+1,rest);
        res=max(res1,res2);
    }
    else if(ara[idx]==both) {
        if(prev!=gym) res1=solve(idx+1,gym)+1;
        if(prev!=con) res2=solve(idx+1,con)+1;
        res3=solve(idx+1,rest);
        res=max(res1,max(res2,res3));
    }
    return dp[idx][prev]=res;
}
int main(int argc,char const *argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    memset(dp,-1,sizeof(dp));
    int workday=solve(1,rest);
    printf("%d\n",n-workday);
    return 0;
}

