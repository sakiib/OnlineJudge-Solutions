#include<bits/stdc++.h>
using namespace std;

const int N=55;

int r,c;
string grid[N];
bool found=false;
bool visited[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool possible(int nx,int ny,char color) {
    return (nx>=0&&nx<r&&ny>=0&&ny<c&&(grid[nx][ny]==color));
}
void dfs(int sx,int sy,int px,int py,char color) {
    if(visited[sx][sy]) {
        found=true;
        return;
    }
    visited[sx][sy]=true;
    for(int i=0;i<4;i++) {
        int nx=sx+dx[i];
        int ny=sy+dy[i];
        if(nx==px&&ny==py) continue;
        if(possible(nx,ny,color)) {
            dfs(nx,ny,sx,sy,color);
        }
    }
}

int main(int argc,char const *argv[]) {
    cin>>r>>c;
    for(int i=0;i<r;i++) {
        cin>>grid[i];
    }
    memset(visited,false,sizeof(visited));
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(!visited[i][j]) {
                dfs(i,j,-1,-1,grid[i][j]);
            }
            if(found) {
                //cerr<<"i - j : "<<i<< " " <<j<<endl;
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
