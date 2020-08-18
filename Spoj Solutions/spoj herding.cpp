#include<bits/stdc++.h>
using namespace std;

char str[1005][1005];
int visited[1005][1005];
int n,m,ans,cnt;
bool valid(int nx,int ny) {
    return (nx>=0&&ny>=0&&nx<n&&ny<m&&!visited[nx][ny]);
}
void dfs(int x,int y) {
    visited[x][y]=cnt;
    int nx,ny;
    if(str[x][y]=='W') {
        nx=x;
        ny=y-1;
    }
    if(str[x][y]=='E') {
        nx=x;
        ny=y+1;
    }
    if(str[x][y]=='N') {
        nx=x-1;
        ny=y;
    }
    if(str[x][y]=='S') {
        nx=x+1;
        ny=y;
    }
    if(visited[nx][ny]==0) dfs(nx,ny);
    else if(visited[nx][ny]==cnt) {
        ans++;
    }
}
int main(int argc,char const *argv[]) {

    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i=0;i<n;i++) {
            scanf("%s",str[i]);
        }
        memset(visited,0,sizeof(visited));
        cnt=0,ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(visited[i][j]==0) {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
