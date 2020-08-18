#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>

const int M=30;
const int INF=1000000;

char grid[M][M];
int r,c;
int sx,sy,ex,ey;
int dist[M][M];
bool visited[M][M];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int nx,int ny) {
    return (nx>=0&&nx<r&&ny>=0&&ny<c&&(grid[nx][ny]!='X')&&(!visited[nx][ny]));
}
void dijkstra() {
    for(int i=0;i<=M;i++) {
        for(int j=0;j<=M;j++) {
            dist[i][j]=INF;
        }
    }
    //cerr<<"sx sy ex ey : "<<sx<<sy<<ex<<ey<<endl;
    dist[sx][sy]=0;
    priority_queue<piii,vector<piii>,greater<piii> > PQ;
    PQ.push(piii{0,{sx,sy}});
    while(!PQ.empty()) {
        //cerr<<"here "<<endl;
        piii T=PQ.top();
        PQ.pop();
        int c=T.first;
        pii P=T.second;
        int x=P.first;
        int y=P.second;
        //if(x==ex&&y==ey) return;
        for(int i=0;i<4;i++) {
            //cerr<<"in "<<endl;
            int nx=x+dx[i];
            int ny=y+dy[i];
            //if(visited[nx][ny]) continue;
            if(ex==nx&&ey==ny) {
                //cerr<<"done"<<endl; return ;
            }
            if(valid(nx,ny)) {
               //cerr<<"valid"<<endl;
              // cerr<<x<<" "<<y<<" "<<nx<< " "<<ny<<" "<<dist[nx][ny]<<" "<<dist[x][y]<<endl;
               int cost;
               if(grid[nx][ny]=='D') cost=0;
               else cost=grid[nx][ny]-'0';
               //cerr<<"cost :"<<cost<<endl;
               if(dist[nx][ny]>dist[x][y]+cost) {
                dist[nx][ny]=dist[x][y]+cost;
                PQ.push(piii{dist[nx][ny],{nx,ny}});
                //cerr<<"nx - ny : "<<nx<<ny<<endl;
               }
            }
        }
        visited[x][y]=true;
    }
}

int main(int argc,char const *argv[]) {
    while(scanf("%d%d",&c,&r)==2&&(r!=0&&c!=0)) {

        memset(visited,false,sizeof(visited));

        bool found_start=false;
        bool found_end=false;

        for(int i=0;i<r;i++) scanf("%s",grid[i]);

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j]=='S') {
                    sx=i,sy=j;
                    found_start=true;
                }
                if(grid[i][j]=='D') {
                    ex=i,ey=j;
                    found_end=true;
                }
            }
        }
        //cerr<<dist[sx][sy]<<endl;
        if(!found_start||!found_end) cout<<-1<<endl;

        else {
                dijkstra();
                printf("%d\n",dist[ex][ey]);
        }
        //getchar();
    }
    return 0;
}
