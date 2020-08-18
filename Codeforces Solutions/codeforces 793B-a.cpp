#include<bits/stdc++.h>
using namespace std;

int n,m;
int sx,sy,ex,ey;
string grid[1010];
int visited[1010][1010];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool possible(int nx,int ny) {
    if (nx>=0&&nx<n&&ny>=0&&ny<m&&(grid[nx][ny]!='*')) return true;
    else return false;
}

void dfs(int x,int y,int dir) {
    for(int i=0;i<4;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(i==dir) {
            if(possible(nx,ny)&&(visited[nx][ny]==-1||visited[nx][ny]>visited[x][y])) {
                visited[nx][ny]=visited[x][y];
                dfs(nx,ny,i);
            }
        }
        else {
            if(possible(nx,ny)&&visited[x][y]<2&&(visited[nx][ny]==-1||visited[x][y]+1<visited[nx][ny])) {
                visited[nx][ny]=visited[x][y]+1;
                dfs(nx,ny,i);
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
                ex=i,ey=j;
            }
        }
    }
    for(int i=0;i<4;i++) {
        memset(visited,-1,sizeof(visited));
        visited[sx][sy]=0;
        //cerr<<"here"<<endl;
        //cerr<<"visited : "<<visited[ex][ey]<<endl;
        dfs(sx,sy,i);
        //cerr<<"visited : "<<visited[ex][ey]<<endl;
        if(visited[ex][ey]<=2&&visited[ex][ey]!=-1) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
