#include<bits/stdc++.h>
using namespace std;

const int N=10;
const int INF=10000000;

int sx,sy,ex,ey;
int dist[N][N];
bool visited[N][N];

int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

struct cell {
    int x,y,d;
    bool operator<(const cell &a) const {
        return a.d<d;
    }
};
bool comp(cell a,cell b) {
    return (a.d<b.d);
}

bool valid(int nx,int ny) {
    return (nx>=0&&nx<8&&ny>=0&&ny<8);
}
void dijkstra() {
    priority_queue<cell> PQ;
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            dist[i][j]=INF;
        }
    }
    dist[sx][sy]=0;
    cell s;
    s.d=0;
    s.x=sx;
    s.y=sy;
    PQ.push(s);
    while(!PQ.empty()) {
        cell T=PQ.top();
        PQ.pop();
        int dis=T.d;
        int px=T.x;
        int py=T.y;
        for(int i=0;i<8;i++) {
            int nx=px+dx[i];
            int ny=py+dy[i];
            int cost=(px*nx)+(py*ny);
            if(valid(nx,ny)&&(!visited[nx][ny]||dist[nx][ny]>dist[px][py]+cost)) {
                dist[nx][ny]=dist[px][py]+cost;
                visited[nx][ny]=true;
                cell k;
                k.x=nx;
                k.y=ny;
                k.d=cost;
                PQ.push(k);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    while(scanf("%d%d%d%d",&sx,&sy,&ex,&ey)!=EOF) {
        memset(visited,false,sizeof(visited));
        dijkstra();
        if(dist[ex][ey]==INF) cout<<1<<endl;
        else cout<<dist[ex][ey]<<endl;
    }
    return 0;
}
