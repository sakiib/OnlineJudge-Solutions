#include<bits/stdc++.h>
using namespace std;

#define pii  pair<int,int>
#define piii pair<int,pii>


const int N=50;
const int INF=100000;

int r,c,sx,sy,ex,ey;
string str[N];

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int dist[N][N];
bool visited[N][N];

bool valid(int nx,int ny) {
    return (nx>=0&&ny>=0&&nx<r&&ny<c&&str[nx][ny]!='X'&&str[nx][ny]!='S'&&!visited[nx][ny]);
}
void dijkstra() {
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            dist[i][j]=INF;
        }
    }
    //cerr<<"he"<<endl;
    dist[sx][sy]=0;
    visited[sx][sy]=true;
    priority_queue<piii,vector<piii>,greater<piii> > PQ;
    PQ.push(piii(0,pii(sx,sy)));
    while(!PQ.empty()) {
        piii T=PQ.top();
        int d=T.first;
        pii P=T.second;
        int x=P.first;
        int y=P.second;
        PQ.pop();
        for(int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            int cost;
            if(nx==ex&&ny==ey) cost=0;
            else if(str[nx][ny]=='S') cost=0;
            else cost=(str[nx][ny]-'0');
            cout<<"cost : "<<cost<<endl;
            if(valid(nx,ny)&&(dist[nx][ny]==INF||(dist[nx][ny]>dist[x][y]+cost))) {
                dist[nx][ny]=dist[x][y]+cost;
                //cerr<<"here"<<endl;
                PQ.push(piii(dist[nx][ny],pii(nx,ny)));
                visited[nx][ny]=true;
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    while(scanf("%d%d",&c,&r)) {
        if(r==0&&c==0) break;
        for(int i=0;i<r;i++) {
            cin>>str[i];
        }
        memset(visited,false,sizeof(visited));
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(str[i][j]=='S') {
                    sx=i,sy=j;
                }
                if(str[i][j]=='D') {
                    ex=i,ey=j;
                }
            }
        }
        dijkstra();
        printf("%d\n",dist[ex][ey]);
    }
    return 0;
}
