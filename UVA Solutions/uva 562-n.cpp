#include<bits/stdc++.h>
using namespace std;

int n,sum,s;
int val[250100];
int dp[105][20100];

int solve(int i,int cur) {
    if(i==n+1) return 0;
    if(dp[i][cur]!=-1) return dp[i][cur];
    int op1=0,op2=0;
    if(cur+val[i]<=s) op1=val[i]+solve(i+1,cur+val[i]);
    op2=solve(i+1,cur);
    dp[i][cur]=max(op1,op2);
    return dp[i][cur];
}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        sum=0;
        for(int i=1;i<=n;i++) {
            cin>>val[i];
            sum+=val[i];
        }
        int rem;
        s=sum/2;
        if(n==1) {cout<<sum<<endl; continue;}
        memset(dp,-1,sizeof(dp));
        int ans=solve(1,0);
        //cout<<ans<<endl;
        cout<<(sum-2*ans)<<endl;
    }
    return 0;
}
