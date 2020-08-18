#include<bits/stdc++.h>
using namespace std;

const int INF=100000;
char str[20][20];
int n;
int sx=0,sy=0;
int cnt;
int dist[20][20];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int nx,int ny,char c) {
    return (nx>=0&&ny>=0&&nx<n&&ny<n&&(str[nx][ny]=='.'||str[nx][ny]!='#'&&str[nx][ny]<=c));
}
int bfs(int x,int y,char ch) {
    for(int i=0;i<20;i++) {
        for(int j=0;j<20;j++) {
            dist[i][j]=INF;
        }
    }
    queue<pair<int,int> > Q;
    Q.push({x,y});
    dist[x][y]=0;
    while(!Q.empty()) {
        pair<int,int> f=Q.front();
        Q.pop();
        if(str[f.first][f.second]==ch) {
            sx=f.first; sy=f.second;
            return (dist[sx][sy]);
        }
        for(int i=0;i<4;i++) {
            int nx=dx[i]+f.first; int ny=dy[i]+f.second;
            if(dist[nx][ny]>dist[f.first][f.second]&&valid(nx,ny,ch)) {
               Q.push({nx,ny});
               dist[nx][ny]=dist[f.first][f.second]+1;
            }
        }
    }
    return -1;
}
int main(int argc,char const *argv[]) {
    //#ifdef ONLINE_JUDGE
    //freopen("input","r",stdin);
    //freopen("output","w",stout);
    //#endif
    int t,tc;  scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%s",str[i]);
        }
        cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(str[i][j]=='A') {
                    sx=i,sy=j;
                }
                if(str[i][j]!='.'&&str[i][j]!='#') cnt++;
            }
        }
        int ans=0;

        for(int i=1;i<cnt;i++) {
            int res=bfs(sx,sy,(char)('A'+i));
            if(res==-1) {
                ans=-1; break;
            }
            ans+=res;
        }
        if(ans==-1) printf("Case %d: Impossible\n",tc);
        else printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
