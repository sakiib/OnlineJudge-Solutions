#include<bits/stdc++.h>
using namespace std;

string grid[1010];
int n,m;
int startx,starty,endx,endy;
int visited[1010][1010];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

bool possible(int nx,int ny) {
    if(nx>=0&&nx<n&&ny>=0&&ny<m&&(grid[nx][ny]!='*')) return true;
    else return false;
}
void dfs(int startx,int starty,int p) {
    for(int i=0;i<4;i++) {//new move in any 4 direction
        int nx=startx+dx[i];
        int ny=starty+dy[i];
        if(i==p) {//if in the same direction
            if(possible(nx,ny)&&(visited[nx][ny]==-1||visited[startx][starty]<visited[nx][ny])) {
                visited[nx][ny]=visited[startx][starty];//same value
                dfs(nx,ny,i);
            }
        }
        else {//new direction
            if(possible(nx,ny)&&visited[startx][starty]<2&&(visited[nx][ny]==-1||visited[startx][starty]+1<visited[nx][ny])) {
                visited[nx][ny]=visited[startx][starty]+1;//increament value by one
                dfs(nx,ny,i);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>grid[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]=='S') {
                startx=i,starty=j;
            }
            if(grid[i][j]=='T') {
                endx=i,endy=j;
            }
        }
    }
    for(int i=0;i<4;i++) {//initial move cal be any of the 4 side
        memset(visited,-1,sizeof(visited));
        visited[startx][starty]=0;
        dfs(startx,starty,i);//i is the initial direction
        if(visited[endx][endy]!=-1&&visited[endx][endy]<=2) {
            cout<<"YES"<<endl;//change in direction is less than 2
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
