#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

bool visited[10][10];
int dist[10][10];
int sx,sy,ex,ey;

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
string dir[8]={"RU","R","RD","U","D","LU","L","LD"};

map<pii,pii> path;
vector<pii> V;

void get_ans() {
   //for(auto x:V) cout<<x.first<< " " <<x.second<<endl;
   for(int i=1;i<V.size();i++) {
     int tx=V[i].first;
     int ty=V[i].second;
     int bx=V[i-1].first;
     int by=V[i-1].second;
     for(int i=0;i<8;i++) {
       if(bx+dx[i]==tx&&by+dy[i]==ty) {
        cout<<dir[i]<<endl; break;
       }
     }
   }
}
void print_path(int ex,int ey,int sx,int sy) {
    pii P=path[{ex,ey}];
    if(P.first==0&&P.second==0) return;
    print_path(P.first,P.second,sx,sy);
    //cerr<<"A "<<P.first<<" "<<P.second<<endl;
    V.push_back({P.first,P.second});
}
bool valid(int nx,int ny) {
    return (nx>=1&&ny>=1&&nx<=8&&ny<=8);
}
void bfs() {
    queue<pii> Q;

    Q.push({sx,sy}); visited[sx][sy]=true;
    while(!Q.empty()) {
        pii F=Q.front(); int x=F.first; int y=F.second;
        Q.pop();
        for(int i=0;i<8;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(nx,ny)&&!visited[nx][ny]) {
               visited[nx][ny]=true;
               dist[nx][ny]=dist[x][y]+1;
               Q.push({nx,ny});
               path[{nx,ny}]={x,y};
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    string a,b;
    cin>>a>>b;
    sx=a[0]-'a'+1;
    sy=a[1]-'0';
    ex=b[0]-'a'+1;
    ey=b[1]-'0';
    //printf("%d %d %d %d\n",sx,sy,ex,ey);
    bfs();
    printf("%d\n",dist[ex][ey]);
    //pii K=path[{ex,ey}];

    print_path(ex,ey,sx,sy);
    //reverse(V.begin(),V.end());
    V.push_back({ex,ey});
    //for(auto x:V) cout<<x.first<<" "<<x.second<<endl;
    get_ans();

    return 0;
}
