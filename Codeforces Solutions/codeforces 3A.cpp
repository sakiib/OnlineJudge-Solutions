#include<bits/stdc++.h>
using namespace std;

int grid[10][10];
int dx[9]={0,1,1,1,0,0,-1,-1,-1};
int dy[9]={0,1,0,-1,1,-1,1,0,-1};
bool done=false;
map<pair<int,int>,int> visited;
map<pair<int,int>,pair<int,int> > path;

void grid_see() {
    for(int i=0;i<=8;i++) {
        for(int j=0;j<=8;j++) {
            cout<<grid[i][j]<< " ";
        }
        cout<<endl;
    }
}
bool possible(int nx,int ny) {
    if(visited[make_pair(nx,ny)]==-1&&(nx>0&&nx<9)&&(ny>0&&ny<9))
    return true;
    else return false;
}
int BFS(int a,int b,int c,int d) {
    queue<pair<int,int> > Q;
    Q.push(make_pair(a,b));
    visited[make_pair(a,b)]=0;
    while(!Q.empty()) {
        pair<int,int> frnt=Q.front();
        Q.pop();
        if(frnt.first==c&&frnt.second==d) return visited[make_pair(frnt.first,frnt.second)];
        for(int i=0;i<8;i++) {
           int nx=frnt.first+dx[i];
           int ny=frnt.second+dy[i];
           if(possible(nx,ny)) {
             visited[make_pair(nx,ny)]=visited[make_pair(frnt.first,frnt.second)]+1;
             Q.push(make_pair(nx,ny));
             path[make_pair(nx,ny)]=make_pair(frnt.first,frnt.second);
           }
        }
    }
    return -1;
}
void print_path(int a,int b,int c,int d) {
    //cout<<"Now print the path of the King"<<endl;
    pair<int,int> ans=path[make_pair(c,d)];
    if(ans.first==a&&ans.second==b) done=true;
    cout<<ans.first<< " " <<ans.second<<endl;
    if(done) return;
    print_path(a,b,ans.first,ans.second);
}
int main(int argc,char const *argv[]) {

    memset(grid,0,sizeof(grid));
    for(int i=0;i<=8;i++) {
        for(int j=0;j<=8;j++) {
            visited[make_pair(i,j)]=-1;
        }
    }
    //grid_see();
    string start,en;
    cin>>start>>en;
    if(start==en) {
        cout<<0<<endl;
        return 0;
    }
    int a,b,c,d;
    a=(start[0]-'a'+1);
    b=(start[1]-'1'+1);
    c=(en[0]-'a'+1);
    d=(en[1]-'1'+1);
    //printf("%d %d %d %d\n",a,b,c,d);
    int moves=0;
    moves=BFS(a,b,c,d);
    printf("%d\n",moves);
    //V.push_back({c,d});
    print_path(a,b,c,d);
    return 0;
}
