#include<bits/stdc++.h>
using namespace std;

int n,m;
string grid[1010];
int visited[1010][1010];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int sx,sy,ex,ey;

struct cell {
    int x,y,dir;
};
bool possible(int nx,int ny,int d) {
    if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]!='*'&&visited[nx][ny]==-1) return true;
    return false;
}

void bfs(int sx,int sy,int dir) {
    queue<cell> Q;
    Q.push(cell{sx,sy,dir});
    visited[sx][sy]=0;
    /*for(int i=0;i<4;i++) {
        Q.push(cell{sx,sy,i});
    }*/
    while(!Q.empty()) {
        cell frnt=Q.front();
        Q.pop();
        for(int i=0;i<4;i++) {
            int nx=frnt.x+dx[i];
            int ny=frnt.y+dy[i];
            int d=frnt.dir;
            if(possible(nx,ny,d)) {
                visited[nx][ny]=visited[frnt.x][frnt.y];
                //cerr<<"here : "<<visited[frnt.x][frnt.y]<<endl;
                Q.push(cell{nx,ny,i});
            }
        }
    }
}

int main(int argc,char const *argv[]) {
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>grid[i];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]=='S') {
                sx=i,sy=j;
            }
            if(grid[i][j]=='T') {
                ex,i,ey=j;
            }
        }
    }
    for(int i=0;i<4;i++) {
        memset(visited,-1,sizeof(visited));
        bfs(sx,sy,i);
        //cerr<<visited[ex][ey]<<endl;
        if(visited[ex][ey]<=2&&visited[ex][ex]>=0) {
            cerr<<visited[ex][ey]<<endl;
            cout<<"YES"<<endl;
            //return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
