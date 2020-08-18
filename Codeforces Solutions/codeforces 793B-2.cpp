#include<bits/stdc++.h>
using namespace std;

int row,col,mr,mc;

char grid[1005][1005];
bool vis[1005][1005][5][5];
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};

void BFS(int r,int c,int turn,int dir)
{
    if(turn>2) return;

    vis[r][c][turn][dir]=true;

    if(grid[r][c]=='T'){
        puts("YES");
        exit(0);
    }

    for(int i=0;i<4;i++){
        int N=r+X[i];
        int M=c+Y[i];
        int ret;
        if(dir!=i+1) ret=1;
        else ret=0;
        if(grid[N][M]=='.'||grid[N][M]=='T'&&!vis[N][M][turn+ret][i+1]){
            BFS(N,M,turn+ret,i+1);
        }
    }
    return;
}
int main()
{
    scanf("%d%d",&row,&col);

    for(int i=1;i<=row;i++){
            while(getchar()!='\n');
        for(int j=1;j<=col;j++){
            scanf("%c",&grid[i][j]);
            if(grid[i][j]=='S'){
                mr=i,mc=j;
            }
        }
    }
    memset(vis,false,sizeof(vis));

    vis[mr][mc][0][0];

    BFS(row,col,0,0);

    puts("NO");

    return 0;
}
