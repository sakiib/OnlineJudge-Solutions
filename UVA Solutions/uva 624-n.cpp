#include<bits/stdc++.h>
using namespace std;

int cap,n;
int val[50];
int dp[50][1000];
int dir[50][1000];

int solve(int i,int cur) {
    if(i==n+1) return 0;
    if(dp[i][cur]!=-1) return dp[i][cur];
    int op1=0,op2=0;
    if(cur+val[i]<=cap) op1=val[i]+solve(i+1,cur+val[i]);
    op2=solve(i+1,cur);
    dir[i][cur]=(op1>op2);
    dp[i][cur]=max(op1,op2);
    return dp[i][cur];
}
void path() {
    vector<int> V;
    for(int i=1,j=0;i<=n;i++) {
        if(dir[i][j]) {
            V.push_back(i);
            j+=val[i];
        }
    }
    for(int i=0;i<V.size();i++) {
        printf("%d ",val[V[i]]);
    }
}
int main(int argc,char const *argv[]) {
    while(scanf("%d",&cap)==1) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&val[i]);
        }
        memset(dp,-1,sizeof(dp));
        memset(dir,false,sizeof(dir));
        int sum=solve(1,0);
        path();
        printf("sum:%d\n",sum);
    }
    return 0;
}
