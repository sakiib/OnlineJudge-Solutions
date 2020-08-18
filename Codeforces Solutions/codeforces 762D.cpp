#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int ara[100][1000];
int n,i,j;
int dp[1000][1000];
int solve(int a,int b);
int main()
{

    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=n;j++)
        {
           cin >> ara[i][j];
        }
    }
    printf("%d\n",solve(1,1));
    return 0;
}
int solve(int a,int b)
{
    if(a>=1&&a<=3&&b>=1&&b<=n)
    {
      if(dp[a][b]!=-1)
        return dp[a][b];
      else
        {
          dp[a][b]=
        }
    }
}
