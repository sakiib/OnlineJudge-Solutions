#include<bits/stdc++.h>
using namespace std;

const int M=10000007;
int dp[10005];
int a,b,c,d,e,f,n;

void calc() {
    dp[0]=a%M,dp[1]=b%M,dp[2]=c%M,dp[3]=d%M,dp[4]=e%M,dp[5]=f%M;
    for(int i=6;i<=n;i++) {
        dp[i]=(dp[i-1]%M+dp[i-2]%M+dp[i-3]%M+dp[i-4]%M+dp[i-5]%M+dp[i-6]%M)%M;
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&n);
        calc();
        printf("Case %d: %d\n",tc,dp[n]);
    }
    return 0;
}
