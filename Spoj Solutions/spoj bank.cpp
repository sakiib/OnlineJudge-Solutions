#include<bits/stdc++.h>
using namespace std;

int cap,n;
int wt[100010],val[10010];
int dp[200][10001];

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
    int t;
    cin>>t;
    while(t--) {
        cin>>cap>>n;
        for(int i=1;i<=n;i++) {
            cin>>wt[i]>>val[i];
        }
        memset(dp,-1,sizeof(dp));
        int ans=solve(1,0);
        cout<<"Hey stupid robber, you can get "<<ans<<"."<<endl;
    }
    return 0;
}
