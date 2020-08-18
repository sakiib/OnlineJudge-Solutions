#include<bits/stdc++.h>
using namespace std;
int n,k;
int ara[100][100];
int dp[100][100];
int solve(int a,int b)
{
    if((a<1||a>n)||(b<1||b>n)) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    else
        dp[a][b]=ara[a][b]+max(solve(a+1,b),solve(a,b+1));
        return dp[a][b];
}
int main()
{
    int ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ara[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    ans=solve(1,1);
    cout<<ans<<endl;
    return 0;
}
