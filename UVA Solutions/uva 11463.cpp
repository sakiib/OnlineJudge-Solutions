#include<bits/stdc++.h>
using namespace std;

const int inf=100000000;

int main(int argc,char const *argv[]) {
    int t,tc=1;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int ara[105][105];

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) ara[i][j]=0;
                else ara[i][j]=inf;
            }
        }
        int e;
        scanf("%d",&e);
        for(int i=1;i<=e;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            ara[u][v]=1;
            ara[v][u]=1;
        }
        int st,en;
        int mx=0;
        scanf("%d%d",&st,&en);
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    ara[i][j]=min(ara[i][j],ara[i][k]+ara[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++) {
            mx=max(mx,ara[st][i]+ara[i][en]);
        }
        printf("Case %d: %d\n",tc,mx);
    }
    return 0;
}
