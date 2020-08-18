#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int r,c,k,sx,sy,ex,ey;
char str[N][N];
int dist[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int nx,int ny) {
    if(str[nx][ny]=='#') return false;
    if(nx>=0&&ny>=0&&nx<r&&ny<c&&str[nx][ny]=='.') return true;
    return false;
}
int bfs(int x,int y) {
    queue<pair<int,int> > Q;
    Q.push({x,y});
    dist[x][y]=0;
    while(!Q.empty()) {
        pair<int,int> F=Q.front();
        int ax=F.first; int ay=F.second;
        Q.pop();
        for(int i=0;i<4;i++) {
            int nx=ax,ny=ay;
            for(int j=1;j<=k;j++) {
                nx+=dx[i]; ny+=dy[i];
                if(nx==ex&&ny==ey) {
                    return dist[ax][ay]+1;
                }
                if(!valid(nx,ny)) break;
                if(dist[nx][ny]==-1||(dist[nx][ny]>dist[ax][ay]+1)) {
                    dist[nx][ny]=dist[ax][ay]+1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    return dist[ex][ey];
}
int main(int argc,char const *argv[]) {
    scanf("%d%d%d",&r,&c,&k);
    for(int i=0;i<r;i++) {
        scanf("%s",str[i]);
    }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    memset(dist,-1,sizeof(dist));
    ex--,ey--;
    int ans=bfs(sx-1,sy-1);

    printf("%d\n",ans);
    return 0;
}
