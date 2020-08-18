#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int inf=1000000;
int r,c;
int grid[200][200];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int cost[200][200];

bool valid(int nx,int ny) {
    return (nx>=0&&ny>=0&&nx<r&&ny<c);
}
void bfs(int x,int y) {
    queue<pii> Q;
    Q.push({x,y});
    cost[x][y]=0;
    while(!Q.empty()) {
        pii p=Q.front(); Q.pop();
        int ax=p.first; int ay=p.second;
        for(int i=0;i<4;i++) {
          int nx=ax+dx[i];
          int ny=ay+dy[i];
          if(grid[nx][ny]==0&&(cost[nx][ny]>cost[ax][ay]+1||cost[nx][ny]==0)&&valid(nx,ny)) {
            cost[nx][ny]=cost[ax][ay]+1;
            Q.push({nx,ny});
          }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        for(int i=0;i<200;i++) {
        for(int j=0;j<200;j++) {
         cost[i][j]=0;
         grid[i][j]=0;
        }
       }

       scanf("%d%d",&r,&c);
       for(int i=0;i<r;i++) {
        char str[200];
        scanf("%s",str);
        for(int j=0;j<c;j++) {
         grid[i][j]=(str[j]-'0');
        }
       }
       /*for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
         printf("%d ",grid[i][j]);
        }
        printf("\n");
       }*/
       for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
         if(grid[i][j]==1) {
          bfs(i,j);
         }
        }
       }
       for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
         if(j==0) printf("%d",cost[i][j]);
         else printf(" %d",cost[i][j]);
        }
        printf("\n");
       }
    }
    return 0;
}
