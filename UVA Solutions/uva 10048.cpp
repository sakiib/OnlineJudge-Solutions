#include<bits/stdc++.h>
using namespace std;

const int inf=100000000;

int main(int argc,char const *argv[]) {
    int n,e,q,tc=1;

    bool f=false;
    while(scanf("%d%d%d",&n,&e,&q)) {
        if(n==0&&e==0&&q==0) break;
        if(f) printf("\n"); f=true;
        int ara[105][105];

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
               if(i==j) ara[i][j]=0;
               else ara[i][j]=inf;
            }
        }
        for(int i=1;i<=e;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ara[u][v]=w, ara[v][u]=w;
        }
        for(int k=1;k<=n;k++) {
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    ara[i][j]=min(ara[i][j],max(ara[i][k],ara[k][j]));
                }
            }
        }
        printf("Case #%d\n",tc++);
        for(int i=1;i<=q;i++) {
            int st,en;
            scanf("%d%d",&st,&en);
            if(ara[st][en]==inf) printf("no path\n");
            else printf("%d\n",ara[st][en]);
        }

    }
    return 0;
}
