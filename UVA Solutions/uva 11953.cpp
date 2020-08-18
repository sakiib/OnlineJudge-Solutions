#include<bits/stdc++.h>
using namespace std;

char str[105][105];
int n;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool visited[105][105];
int ans=0;

void dfs(int x,int y,int cur) {
    if(cur>(n/2)) return;
    visited[x][y]=true;
    for(int i=0;i<4;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!visited[nx][ny]&&nx>=0&&ny>=0&&nx<n&&ny<n&&
           (str[nx][ny]=='x'||str[nx][ny]=='@')) {
            dfs(nx,ny,cur+1);
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%s",str[i]);
        }
        ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
               if(!visited[i][j]&&str[i][j]=='x') {
                ans++;
                dfs(i,j,1);
               }
            }
        }
        memset(visited,false,sizeof(visited));
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
