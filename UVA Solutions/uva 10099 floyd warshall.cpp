#include<bits/stdc++.h>
using namespace std;

const int inf=100000000;

int main(int argc,char const *argv[]) {
    int n,e,tc=1;
    while(scanf("%d%d",&n,&e)) {
        if(n==0&&e==0) break;
        int ara[105][105];

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                ara[i][j]=0;
            }
        }
        for(int i=1;i<=e;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ara[u][v]=--w;
            ara[v][u]=--w;
        }
        int st,en,tot;
        scanf("%d%d%d",&st,&en,&tot);

        for(int k=1;k<=n;k++) {
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    ara[i][j]=max(ara[i][j],min(ara[i][k],ara[k][j]));
                }
            }
        }
        int mn=ara[st][en];
        int ans=(tot/mn);
        if(tot%mn!=0) ans++;
        printf("Scenario #%d\n",tc++);
        printf("Minimum Number of Trips = %d\n",ans);
        printf("\n");
    }
    return 0;
}
