#include<bits/stdc++.h>
using namespace std;

const int INF=1000000;
char str[1005][1005];
int fx,fy,jx,jy;
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};
int dist[1005][1005];
bool visited[1005][1005];
int r,c;

bool can(int nx,int ny) {
    if(nx==0||ny==0||nx==(r-1)||ny==(c-1)) return true;
    return false;
}
bool valid(int nx,int ny) {
    return (nx>=0&&ny>=0&&nx<r&&ny<c&&str[nx][ny]!='#');
}
void fire_bfs() {
    queue<pair<int,int> > fire;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(str[i][j]=='F') {
                fire.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    while(!fire.empty()) {
        pair<int,int> f=fire.front();
        fire.pop();
        for(int i=0;i<4;i++) {
            int nx=dx[i]+f.first;
            int ny=dy[i]+f.second;
            if(valid(nx,ny)&&dist[nx][ny]>dist[f.first][f.second]+1) {
                dist[nx][ny]=dist[f.first][f.second]+1;
                fire.push({nx,ny});
            }
        }
    }
}
int joe_bfs() {
    queue<pair<int,int> > joe;
    if(can(jx,jy)) return 1;
    joe.push({jx,jy});
    dist[jx][jy]=0;
    while(!joe.empty()) {
        pair<int,int> f=joe.front();
        joe.pop();
        for(int i=0;i<4;i++) {
            int nx=dx[i]+f.first;
            int ny=dy[i]+f.second;
            if(valid(nx,ny)&&dist[nx][ny]>dist[f.first][f.second]+1) {
                dist[nx][ny]=dist[f.first][f.second]+1;
                if(can(nx,ny)) return (dist[nx][ny]+1);
                joe.push({nx,ny});
            }
        }
    }
    return -1;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
       scanf("%d%d",&r,&c);
       for(int i=0;i<r;i++) {
        scanf("%s",str[i]);
       }
       for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
         if(str[i][j]=='J') {
            jx=i,jy=j;
         }
         dist[i][j]=INF;
        }
       }
       fire_bfs();
       int ans=joe_bfs();
       if(ans<0) printf("IMPOSSIBLE\n");
       else printf("%d\n",ans);
    }
    return 0;
}
