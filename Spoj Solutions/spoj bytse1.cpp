#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define piii pair<int,pii>

const int inf=1e9;
int ara[205][205];
int r,c;
int px,py;
int cost[205][205];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int nx,int ny) {
    return (nx>=1&&ny>=1&&nx<=r&&ny<=c);
}
void dijkstra() {
    for(int i=1;i<=200;i++) {
        for(int j=1;j<=200;j++) {
           cost[i][j]=inf;
        }
    }
    cost[1][1]=ara[1][1];
    priority_queue<piii,vector<piii>,greater<piii> > Q;
    Q.push(piii(cost[1][1],pii(1,1)));
    while(!Q.empty()) {
        piii T=Q.top();
        Q.pop();
        pii P=T.second;
        int sx=P.first;
        int sy=P.second;
        for(int i=0;i<4;i++) {
            int nx=sx+dx[i];
            int ny=sy+dy[i];
            if(valid(nx,ny)&&(cost[nx][ny]==inf||(cost[nx][ny]>cost[sx][sy]+ara[nx][ny]))) {
                cost[nx][ny]=cost[sx][sy]+ara[nx][ny];
                Q.push(piii(cost[nx][ny],pii(nx,ny)));
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                scanf("%d",&ara[i][j]);
            }
        }
        int time;
        scanf("%d%d%d",&px,&py,&time);
        dijkstra();
        if(cost[px][py]>time) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
            printf("%d\n",time-cost[px][py]);
        }
    }
    return 0;
}
