#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define piii pair<pii,int>
const int inf=100000000;
int n,e,sx,sy,ex,ey;
string str[50];
int ara[50][50];
int dist[50][50];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int nx,int ny) {
    if(ara[nx][ny]!=-1&&(nx>=0&&nx<e&&ny>=0&&ny<n)) return true;
    else return false;
}
void dijkstra(int sx,int sy) {
    for(int i=0;i<30;i++) {
        for(int j=0;j<30;j++) {
            dist[i][j]=inf;
        }
    }
    dist[sx][sy]=0;
    priority_queue<piii,vector<piii>,greater<piii> > Q;
    Q.push(piii(pii(sx,sy),dist[sx][sy]));
    while(!Q.empty()) {
        piii t=Q.top();
        pii p=t.first;
        int d=t.second;
        int px=p.first;
        int py=p.second;
        Q.pop();
        for(int i=0;i<4;i++) {
            int nx=dx[i]+px;
            int ny=dy[i]+py;
            if(valid(nx,ny)&&(dist[nx][ny]==inf||(dist[nx][ny]>dist[px][py]+ara[nx][ny]))) {
                dist[nx][ny]=dist[px][py]+ara[nx][ny];
                Q.push(piii(pii(nx,ny),dist[nx][ny]));
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    while(scanf("%d%d",&n,&e)) {
        if(n==0&&e==0) break;
        for(int i=0;i<e;i++) {
            cin>>str[i];
        }
        for(int i=0;i<e;i++) {
            for(int j=0;j<n;j++) {
                if(str[i][j]=='S') {
                    sx=i,sy=j;
                    ara[i][j]=0;
                    continue;
                }
                if(str[i][j]=='D') {
                    ex=i,ey=j;
                    ara[i][j]=0;
                    continue;
                }
                if(str[i][j]=='X') ara[i][j]=-1;
                else {
                    ara[i][j]=str[i][j]-'0';
                }
            }
        }
        dijkstra(sx,sy);
        printf("%d\n",dist[ex][ey]);
    }
    return 0;
}
