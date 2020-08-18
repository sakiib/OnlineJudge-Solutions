#include<bits/stdc++.h>
using namespace std;

const int inf=1000000;

int main(int argc,char const *argv[]) {
    int u,v;
    int tc=1;
    while(scanf("%d%d",&u,&v)) {
        int cost[105][105];

        for(int i=0;i<105;i++) {
            for(int j=0;j<105;j++) {
                if(i==j) cost[i][j]=0;
                else cost[i][j]=inf;
            }
        }

        if(u==0&&v==0) break;

        cost[u][v]=1;

        while(scanf("%d%d",&u,&v)) {
            if(u==0&&v==0) break;
            cost[u][v]=1;
        }
        for(int k=1;k<=100;k++) {
            for(int i=1;i<=100;i++) {
                for(int j=1;j<=100;j++) {
                   if(cost[i][j]>cost[i][k]+cost[k][j]) {
                    cost[i][j]=cost[i][k]+cost[k][j];
                   }
                }
            }
        }
        int cnt=0,tot=0;
        for(int i=1;i<=100;i++) {
            for(int j=1;j<=100;j++) {
                //printf("%d\n",cost[i][j]);
                if(cost[i][j]!=0&&cost[i][j]!=inf) cnt++,tot+=cost[i][j];
            }
        }
        double avg=(tot*1.0)/cnt;
        printf("Case %d: average length between pages = %0.3lf clicks\n",tc++,avg);
    }
    return 0;
}
