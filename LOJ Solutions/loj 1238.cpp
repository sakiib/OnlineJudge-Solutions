#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int r,c;
string str[30];
int ax,ay,bx,by,cx,cy,hx,hy;
bool visited[30][30];
int dist[30][30];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int nx,int ny) {
    return (nx>=0&&ny>=0&&nx<r&&ny<c&&str[nx][ny]!='#'&&str[nx][ny]!='m');
}
void bfs() {
    queue<pii> Q;
    visited[hx][hy]=true;
    dist[hx][hy]=0;
    Q.push(pii(hx,hy));
    while(!Q.empty()) {
        pii T=Q.front();
        int x=T.first; int y=T.second;
        Q.pop();
        for(int i=0;i<4;i++) {
            int nx=x+dx[i]; int ny=y+dy[i];
            if(!visited[nx][ny]&&valid(nx,ny)) {
                dist[nx][ny]=dist[x][y]+1;
                visited[nx][ny]=true;
                Q.push(pii(nx,ny));
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
        cin>>r>>c;
        for(int i=0;i<r;i++) {
            cin>>str[i];
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(str[i][j]=='a') {
                    ax=i,ay=j;
                }
                if(str[i][j]=='b') {
                    bx=i,by=j;
                }
                if(str[i][j]=='c') {
                    cx=i,cy=j;
                }
                if(str[i][j]=='h') {
                    hx=i,hy=j;
                }
            }
        }
        memset(visited,false,sizeof(visited));
        memset(dist,0,sizeof(dist));
        bfs();
        int ans=max(dist[ax][ay],max(dist[bx][by],dist[cx][cy]));
        //printf("%d %d %d\n",dist[ax][ay],dist[bx][by],dist[cx][cy]);
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
