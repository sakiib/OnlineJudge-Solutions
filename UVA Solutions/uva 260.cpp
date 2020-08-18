#include<bits/stdc++.h>
using namespace std;

char grid[220][220];
int dx[]={-1,-1,0,0,1,1};
int dy[]={-1,0,-1,1,0,1};
bool flag;
int n;
bool visited[500][500];

bool valid(int nx,int ny) {
    return (grid[nx][ny]=='w'&&nx>=0&&ny>=0&&nx<=n-1&&ny<=n-1);
}
void dfs(int x,int y) {
    visited[x][y]=true;
    for(int i=0;i<6;i++) {
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        if(!visited[nx][ny]&&valid(nx,ny)&&!flag) {
        if(ny==(n-1)) {flag=true; return;}
        dfs(nx,ny);
        }
    }
}
int main(int argc,char const *argv[]) {
    int tc=1;
    #ifdef Local_Test
    freopen("uva260in.txt","r",stdin);
    freopen("uva260out.txt","w",stdout);
    #endif
    while(scanf("%d",&n)) {
        if(n==0) break;
        for(int i=0;i<n;i++) {
            scanf("%s",grid[i]);
        }
        flag=false;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++) {
                if(!visited[i][0]&&grid[i][0]=='w') {
                    dfs(i,0);
                    if(flag) break;
                }
        }
        if(flag) printf("%d W\n",tc);
        else printf("%d B\n",tc);
        tc++;
    }
    return 0;
}
