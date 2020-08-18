#include<bits/stdc++.h>
using namespace std;

const int N=110;

int r,c;
string str[N];
char s[]={'A','L','L','I','Z','Z','W','E','L','L'};
bool found;
bool visited[N][N];

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool valid(int nx,int ny,int ind) {
    return (nx>=0&&nx<r&&ny>=0&&ny<c&&(str[nx][ny]==s[ind+1]));
}
void dfs(int x,int y,int ind) {
    //visited[x][y]=true;
    //cerr<<str[x][y]<<endl;
    if(ind==9) {found=true; return;}
    for(int i=0;i<8;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        //cerr<<ind<<endl;
        if(!visited[nx][ny]&&valid(nx,ny,ind)) {
            visited[nx][ny]=true;
            dfs(nx,ny,ind+1);
            if(ind==9) {found=true; return;}
            visited[nx][ny]=false;
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++) {
        cin>>r>>c;
        for(int i=0;i<r;i++) {
            cin>>str[i];
        }
        found=false;
        for(int i=0;i<=r;i++) {
            for(int j=0;j<=c;j++) {
                visited[i][j]=false;
            }
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(str[i][j]=='A') {
                    visited[i][j]=true;;
                    dfs(i,j,0);
                    //visited[i][j]=false;
                    if(found) break;
                }
            }
            if(found) break;
        }
        if(found) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
