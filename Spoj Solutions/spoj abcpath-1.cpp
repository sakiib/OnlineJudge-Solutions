#include<bits/stdc++.h>
using namespace std;

const int N=60;

int r,c;
string str[N];
int mx;
int visited[N][N];

int dx[8] = {1, 1, 1, 0, 0, -1, -1,-1};
int dy[8] = {1,-1, 0, 1, -1, 1, -1, 0};


bool valid(int nx,int ny) {
    return (nx>=0&&ny<r&&ny>=0&&ny<c);
}
void dfs(int x,int y,int cnt) {
    visited[x][y]=1;
    if(cnt>mx) {
        cerr<<"cnt : "<<cnt<<endl;
        mx=cnt;
    }
    for(int i=0;i<8;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        //cout<<(char)(str[x][y]+1)<<endl;
        cerr<<nx<< " " <<ny<<" "<<str[nx][ny]<<" "<<visited[nx][ny]<<endl;
        if(valid(nx,ny)&&visited[nx][ny]==0&&(str[nx][ny]==str[x][y]+1)) {
            cout<<"here"<<endl;
            dfs(nx,ny,cnt+1);
        }
    }
}
int main(int argc,char const *ragv[]) {
    int tc=1;
    while(cin>>r>>c) {
        for(int i=0;i<r;i++) {
            cin>>str[i];
        }
        mx=0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                visited[i][j]=0;
            }
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(str[i][j]=='A') {
                    //cerr<<i<< " "<<j<<endl;
                    dfs(i,j,1);
                }
            }
        }
        printf("Case %d: %d\n",tc,mx);
        tc++;
    }
    return 0;
}
