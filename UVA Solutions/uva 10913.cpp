#include<bits/stdc++.h>
using namespace std;

int n,k;
int ara[100][100];
int dp[80][80][8][1001];
const int INF=100000000;

int solve(int x,int y,int m,int cur) {
    cerr<<"x - y - m - cur : "<<x<<" "<<y<<" "<<m<<" "<<cur<<endl;
    if(x==n&&y==n) return cur;
    if(x<1||x>n||y<1||y>n) return 0;
    if(m>k) return INF;
    if(dp[x][y][m][cur]!=-1) return dp[x][y][m][cur];
    int op1=0,op2=0,op3=0;
    if(ara[x][y-1]<0) op1=ara[x][y]+solve(x,y-1,m+1,cur+ara[x][y]);
    else if(ara[x][y-1]>=0) op1=ara[x][y]+solve(x,y-1,m,cur+ara[x][y]);
    if(ara[x][y+1]<0) op2=ara[x][y]+solve(x,y+1,m+1,cur+ara[x][y]);
    else if(ara[x][y+1]>=0) op2=ara[x][y]+solve(x,y+1,m,cur+ara[x][y]);
    if(ara[x+1][y]<0) op3=ara[x][y]+solve(x+1,y,m+1,cur+ara[x][y]);
    else if(ara[x+1][y]>=0) op3=ara[x][y]+solve(x+1,y,m,cur+ara[x][y]);
    dp[x][y][m][cur]=max(op1,max(op2,op3));
    return dp[x][y][m][cur];
}
int main(int argc,char const *argv[]) {
    int tc=1;
    while(cin>>n>>k) {
        if(n==0&&k==0) break;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cin>>ara[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=solve(1,1,0,0);
        if(ans==INF) printf("Case %d: impossible\n",tc);
        else printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
