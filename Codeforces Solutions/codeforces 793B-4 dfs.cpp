#include<bits/stdc++.h>
using namespace std;

int n,m;
string grid[1010];
int visited[1010][1010];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

bool possible(int nx,int ny) {
    if(nx>=0&&ny<n&&ny>=0&&ny<m&&grid[nx][ny]!='*') return true;
    return false;
}
void dfs(int x,int y,int d=-1) {
    if(visited[x][y]>2) {
        cout<<"NO"<<endl;
        exit(0);
    }
    if(grid[x][y]=='T') {
        cout<<"YES"<<endl;
        exit(0);
    }
    for(int i=0;i<4;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        int add=1;
        if(d==-1||d==i) add=0;
        int best=visited[x][y]+add;
        if(possible(nx,ny)&&(visited[nx][ny]==-1||visited[nx][ny]>best)) {
            visited[nx][ny]=best;
            dfs(nx,ny,i);
        }
    }
}
int main(int argc,char const *argv[]) {
    cin>>n>>m;
    memset(visited,-1,sizeof(visited));
    for(int i=0;i<n;i++) cin>>grid[i];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]=='S') dfs(i,j);
        }
    }
    return 0;
}
