#include<bits/stdc++.h>

using namespace std;

int weight[1001];
int cost[1001];
int dp[1001][31];
int N;

int func(int i,int w,int MW)
{
    if(i==N+1)
        return 0;

    if(dp[i][w]!=-1)
       return dp[i][w];

    int profit1=0,profit2=0;

    if(w+weight[i]<=MW)
    profit1=cost[i]+func(i+1,w+weight[i],MW);
    profit2=func(i+1,w,MW);
    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=1;i<=N;i++)
        {
            cin>>cost[i]>>weight[i];
        }
        int sum=0;
        int G;
        cin>>G;
        for(int i=1;i<=G;i++)
        {
            int MW;
            cin>>MW;
            memset(dp,-1,sizeof(dp));
            int num=func(1,0,MW);
            sum+=num;
        }
        cout<<sum<<endl;
    }
    return 0;
}
