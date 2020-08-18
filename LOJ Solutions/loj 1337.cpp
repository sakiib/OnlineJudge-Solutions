#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int r,c,q;
string str[505];
int sx,sy;
bool visited[505][505];
int ans[505][505];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int nx,int ny) {
    return (nx>=0&&ny>=0&&nx<r&&ny<c&&str[nx][ny]!='#');
}
void bfs(int sx,int sy) {
    queue<pii> Q;
    visited[sx][sy]=true;
    vector<pii> V;
    Q.push(pii(sx,sy));
    int cnt=0;
    while(!Q.empty()) {
        pii T=Q.front();
        int x=T.first;
        int y=T.second;
        Q.pop();
        V.push_back(pii(x,y));
        if(str[x][y]=='C') cnt++;
        for(int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(nx,ny)&&!visited[nx][ny]) {
                visited[nx][ny]=true;
                Q.push(pii(nx,ny));
            }
        }
    }
    for(int i=0;i<V.size();i++) {
        ans[V[i].first][V[i].second]=cnt;
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
        memset(visited,false,sizeof(visited));
        printf("Case %d:\n",tc);
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(!visited[i][j]&&str[i][j]!='#') {
                    bfs(i,j);
                }
            }
        }
        while(q--) {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",ans[x-1][y-1]);
        }
    }
    return 0;
}
