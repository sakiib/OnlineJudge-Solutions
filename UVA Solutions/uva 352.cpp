#include<bits/stdc++.h>
using namespace std;

int n;
char str[50][50];
bool visited[50][50];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool valid(int nx,int ny) {
    return (str[nx][ny]=='1'&&nx>=0&&ny>=0&&ny<n&&nx<n);
}
void dfs(int x,int y) {
    visited[x][y]=true;
    for(int i=0;i<8;i++) {
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        if(!visited[nx][ny]&&valid(nx,ny)) {
            dfs(nx,ny);
        }
    }
}
int main(int argc,char const *argv[]) {
    int tc=1;
    #ifdef Local_Test
    freopen("uva352in","r",stdin);
    freopen("uva352out","w",stdout);
    #endif // Online_Judge
    while(scanf("%d",&n)!=EOF) {
        for(int i=0;i<n;i++) {
            scanf("%s",str[i]);
        }
        int ans=0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(!visited[i][j]&&str[i][j]=='1') {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",tc,ans);
        tc++;
    }
    return 0;
}
