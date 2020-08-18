#include<bits/stdc++.h>
using namespace std;

int r,c;
string grid[110];
bool visited[110][110];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool possible(int nx,int ny) {
    return(nx>=0&&nx<r&&ny>=0&&ny<c&&grid[nx][ny]=='@'&&(!visited[nx][ny]));
}
void dfs(int x,int y) {
    visited[x][y]=true;
    for(int i=0;i<8;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(possible(nx,ny)) {
            dfs(nx,ny);
        }
    }
}
int main(int argc,char const *argv[]) {
    while(scanf("%d%d",&r,&c)&&(r!=0&&c!=0)) {
        for(int i=0;i<r;i++) {
            cin>>grid[i];
        }
        memset(visited,false,sizeof(visited));
        int cnt=0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(!visited[i][j]&&grid[i][j]=='@') {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
