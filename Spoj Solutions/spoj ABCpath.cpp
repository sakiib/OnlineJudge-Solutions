#include<bits/stdc++.h>
using namespace std;

const int N=60;

int r,c;

char str[N][N];
int visited[N][N];

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

int mx,ans;

bool valid(int nx,int ny) {
    return (nx>=0&&ny>=0&&nx<r&&ny<c);
}
void dfs(int x,int y,char start) {
    //visited[x][y]++;
    ans=max(ans,mx);
    for(int i=0;i<8;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(valid(nx,ny)&&visited[nx][ny]==0&&str[nx][ny]==start) {
             mx++;
             if(mx==26) {ans=26; return;}
             visited[nx][ny]++;
             dfs(nx,ny,start+1);
             mx=1;
        }
    }
}
int main(int argc,char const *argv[]) {
    int tc=1;
    cin>>r>>c;
    while(r!=0&&c!=0) {
        if(r==0&&c==0) break;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>str[i][j];
            }
        }
        ans=1;
        memset(visited,0,sizeof(visited));
        bool found=false;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(str[i][j]=='A') {
                    mx=1;
                    found=true;
                    dfs(i,j,'B');
                }
            }
        }
        if(!found) cout<<"case "<<tc<<": "<<0<<endl;
        else cout<<"case "<<tc<<": "<<ans<<endl;
        tc++;
        cin>>r>>c;
    }
    return 0;
}
