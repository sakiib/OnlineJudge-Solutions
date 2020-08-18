#include<bits/stdc++.h>
using namespace std;

const int inf=100000000;
int ara[1005][1005];
int dp[1005][1005];

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int r,c;

        for(int i=0;i<=1001;i++) {
            for(int j=0;j<=10001;j++) {
               dp[i][j]=inf;
            }
        }

        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                scanf("%d",&ara[i][j]);
            }
        }

        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],min(dp[i+1][j],
                dp[i][j+1])))+ara[i][j];
            }
        }
        printf("%d\n",dp[r][c]);
    }
    return 0;
}
