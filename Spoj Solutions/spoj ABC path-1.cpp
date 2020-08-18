#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define piii pair<pii,char>

const int N=100;

int r,c;
string str[N];
int visited[N][N];
int dist[N][N];
int ans=1,mx=0;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool valid(int nx,int ny,char c) {
    return (nx>=0&&nx<r&&ny>=0&&ny<c&&str[nx][ny]==c);
}
void bfs(int x,int y,char ch) {
    queue<piii> Q;
    Q.push(piii({{x,y},ch}));
    visited[x][y]++;
    while(!Q.empty()) {
        piii T=Q.front();
        Q.pop();
        pii P=T.first;
        char c=T.second;
        int px=P.first;
        int py=P.second;
        for(int i=0;i<8;i++) {
            int nx=px+dx[i];
            int ny=py+dy[i];
            if(valid(nx,ny,c)&&visited[nx][ny]<8) {
               //ans++;
               dist[nx][ny]=dist[px][py]+1;
               visited[nx][ny]++;
               mx=max(mx,dist[nx][ny]);
               //if(mx>=26) return;
               cerr<<"EKHANE"<<" "<<nx<<" "<<ny<<endl;
               Q.push(piii({{nx,ny},c+1}));
            }
        }
    }
    //ans+=mx;
    //cerr<<"out"<<endl;
}
int main(int argc,char const *argv[]) {
    int tc=1;
    cin>>r>>c;
    while(r!=0&&c!=0) {
        for(int i=0;i<r;i++) {
            cin>>str[i];
        }
        mx=0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(str[i][j]=='A') {
                    mx=1;
                    //memset(dist,0,sizeof(dist));
                    dist[i][j]=1;
                    bfs(i,j,'B');
                   // cerr<<"here"<<endl;
                }
            }
        }
        // cout<<"mx : "<<mx<<endl;
       // if(mx>26) mx=26;
        printf("Case %d: %d\n",tc,mx);
        cin>>r>>c;
        tc++;
    }
    return 0;
}
