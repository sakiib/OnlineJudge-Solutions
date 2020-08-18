#include<bits/stdc++.h>
using namespace std;

int x,y,n,m,k;
int temp=0,cnt=0;
char grid[505][505];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
map<pair<int,int>,bool> visited;

bool possible(int nx,int ny) {
    if((nx>=0&&nx<n)&&(ny>=0&&ny<m)&&(!visited[{nx,ny}])&&(grid[nx][ny]=='.'))
        return true;
    else return false;
}
void dfs(int x,int y) {
    visited[{x,y}]=true;
    grid[x][y]='X';
    cnt++;
    if(cnt==(temp-k)) return;
    for(int i=0;i<4;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(possible(nx,ny)) {
            if(cnt==(temp-k)) return;
            dfs(nx,ny);
        }
    }
}
int main(int argc,char const *argv[]) {
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='.') {
                temp++;
                x=i,y=j;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            visited[{i,j}]=false;
        }
    }
    dfs(x,y);
    //cerr<<cnt<<endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]=='#') cout<<'#';
            else if(grid[i][j]=='.') cout<<'X';
            else cout<<'.';
        }
        cout<<endl;
    }
    return 0;
}
