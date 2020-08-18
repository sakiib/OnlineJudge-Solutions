#include<bits/stdc++.h>
using namespace std;

#define pii  pair<int,int>
#define piii pair<int,pii>

const int N=1000;
const int INF=100000;
int r,c;
int ara[N][N];
int dist[N][N];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int nx,int ny) {
    return (nx>=0&&nx<r&&ny>=0&ny<c);
}
void dijkstra() {
    priority_queue<piii,vector<piii>,greater<piii> > Q;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            dist[i][j]=INF;
        }
    }
    dist[0][0]=ara[0][0];
    Q.push(piii(dist[0][0],pii(0,0)));
    while(!Q.empty()) {
        piii T=Q.top();
        Q.pop();
        int d=T.first;
        pii P=T.second;
        int x=P.first;
        int y=P.second;
        for(int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            int cost=ara[nx][ny];
            if(valid(nx,ny)&&(dist[nx][ny]==INF||dist[nx][ny]>dist[x][y]+cost)) {
                dist[nx][ny]=dist[x][y]+cost;
                Q.push(piii(dist[nx][ny],pii(nx,ny)));
            }
        }
    }

}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++) {
        cin>>r>>c;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>ara[i][j];
            }
        }
        dijkstra();
        cout<<dist[r-1][c-1]<<endl;
    }
    return 0;
}
