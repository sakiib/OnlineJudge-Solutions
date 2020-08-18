#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int r,c,q;
string str[505];
int sx,sy;
int visited[505][505];
int ans[5050];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int cnt;
int V;

bool valid(int nx,int ny) {
    return (nx>=0&&ny>=0&&nx<r&&ny<c&&str[nx][ny]!='#');
}
void dfs(int sx,int sy) {
    visited[sx][sy]=V;
    if(str[sx][sy]=='C') cnt++;
    for(int i=0;i<4;i++) {
        int nx=sx+dx[i];
        int ny=sy+dy[i];
        if(valid(nx,ny)&&visited[nx][ny]==0) {
            dfs(nx,ny);
        }
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d%d%d",&r,&c,&q);
        for(int i=0;i<r;i++) {
            cin>>str[i];
        }
        memset(visited,0,sizeof(visited));
        printf("Case %d:\n",tc);
        V=1;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(visited[i][j]==0&&str[i][j]!='#') {
                    cnt=0;
                    dfs(i,j);
                    ans[V]=cnt;
                    V++;
                }
            }
        }
        while(q--) {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",ans[visited[x-1][y-1]]);
        }
    }
    return 0;
}

