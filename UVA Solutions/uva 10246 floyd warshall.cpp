#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
int cost[85][85];
int a[10000];
void floyd_warshall(int n) {

    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(cost[i][j]>cost[i][k]+cost[k][j]) {
                    cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int n,k,e;
    while(scanf("%d%d%d",&n,&k,&e)) {
        if(n==0&&k==0&&e==0) break;
        for(int i=1;i<=85;i++) {
            for(int j=1;j<=85;j++) {
                if(i==j) cost[i][j]=0;
                else cost[i][j]=inf;
            }
        }
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=k;i++) {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            cost[u][v]=c;
            //cost[v][u]=c;
        }
        floyd_warshall(n);
        for(int i=1;i<=e;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",cost[u][v]);
        }
    }
    return 0;
}
