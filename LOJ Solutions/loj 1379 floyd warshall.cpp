#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL inf=1000000000;

LL ara[10005][10005];

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        LL n,m,s,e,p;

        scanf("%lld%lld%lld%lld%lld",&n,&m,&s,&e,&p);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i==j) ara[i][j]=0;
                else ara[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++) {
            LL u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            ara[u][v]=w;
        }
        for(int k=1;k<=n;k++) {
           for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                ara[i][j]=max(ara[i][j],max(ara[i][k],ara[k][j]));
             }
           }
        }
        printf("%lld\n",ara[s][e]);
    }
    return 0;
}
