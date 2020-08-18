#include<bits/stdc++.h>
using namespace std;

int val[1010][1010];
bool visited[1010][1010];
int grid[1010][1010];
int sx,sy,ex,ey;
int r,c;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void see() {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout<<grid[i][j]<< " ";
        }
        cout<<endl;
    }
}

bool possible(int nx,int ny) {
    if(nx>=0&&ny>=0&&nx<r&&ny<c&&grid[nx][ny]!=-1&&!visited[nx][ny]) return true;
    return false;
}

void bfs(int sx,int sy) {
    queue<pair<int,int> > Q;
    Q.push({sx,sy});
    visited[sx][sy]=true;
    val[sx][sy]=0;
    while(!Q.empty()) {
        pair<int,int> p=Q.front();
        Q.pop();
        for(int i=0;i<4;i++) {
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];
            if(possible(nx,ny)) {
                Q.push({nx,ny});
                visited[nx][ny]=true;
                val[nx][ny]=val[p.first][p.second]+1;
                //cerr<<"here"<<endl;
            }
        }
    }
}

int main(int argc,char const *argv[]) {
    while(scanf("%d%d",&r,&c)&&(r!=0&&c!=0)) {
        memset(grid,0,sizeof(grid));
        memset(visited,false,sizeof(visited));
        memset(val,-1,sizeof(val));
        int n;
        scanf("%d",&n);
        while(n--) {
            int a,b,c;
            cin>>a>>b;
            while(b--) {
                cin>>c;
                grid[a][c]=-1;
            }
        }
        //see();
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        bfs(sx,sy);
        printf("%d\n",val[ex][ey]);
    }
    return 0;
}
