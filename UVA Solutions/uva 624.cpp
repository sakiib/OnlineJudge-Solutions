#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int llu;
int n,i,capacity,ara[10000];
int dp[1000][1000];
int solve(int a,int b);
using namespace std;
int main()
{

    cin >> capacity;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> ara[i];
    }
   memset(dp,-1,sizeof(dp));
   printf("%d\n",solve(0,0));
   return 0;
}
int solve(int a,int b)
{
    int pro1,pro2;
    if(a<n){
        if(dp[a][b]!=-1){
         //   printf("dp\n");
            return dp[a][b];
        }
        else if(ara[a]+b<=capacity){
            pro1=ara[a]+solve(a,b+ara[a]);
            pro2=solve(a+1,b);
            dp[a][b]=max(pro1,pro2);
       // printf("Niche\n");
            return dp[a][b];
        }

    }
    return 0;
}


