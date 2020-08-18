#include<bits/stdc++.h>
using namespace std;

const int N=10;
const int INF=10000000;

#define pii  pair<int,int>
#define piii pair<int,pii>

int sx,sy,ex,ey;

int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

bool visited[N][N];
int dist[N][N];

bool valid(int nx,int ny) {
    return (nx>=0&&nx<8&&ny>=0&&ny<8);
}
void dijkstra() {
    priority_queue<piii,vector<piii>,greater<piii> > PQ;//Min heap,max heap can also be used
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            dist[i][j]=INF;
        }
    }
    dist[sx][sy]=0;
    PQ.push(piii{0,{sx,sy}});
    while(!PQ.empty()) {
      piii T=PQ.top();
      int d=T.first;
      pii P=T.second;
      int x=P.first;
      int y=P.second;
      PQ.pop();
      for(int i=0;i<8;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        int cost=x*nx+y*ny;
        if(valid(nx,ny)&&(!visited[nx][ny]||dist[nx][ny]>dist[x][y]+cost)) {
            if(dist[nx][ny]>dist[x][y]+cost) {
                dist[nx][ny]=dist[x][y]+cost;
                visited[nx][ny]=true;
                PQ.push(piii{dist[nx][ny],{nx,ny}});
            }
         }
      }
    }
}
int main(int argc,char const *argv[]) {
    while(scanf("%d%d%d%d",&sx,&sy,&ex,&ey)!=EOF) {
        memset(visited,false,sizeof(visited));
        dijkstra();
        if(dist[ex][ey]==INF) printf("-1\n");
        else printf("%d\n",dist[ex][ey]);
    }
    return 0;
}
