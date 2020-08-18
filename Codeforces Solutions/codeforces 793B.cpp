#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005][5][5];
int row,col,mr,mc;
int X[4]={-1,1,0,0};
int Y[4]={0,0,1,-1};

void rec(int r,int c,int turn,int dir)
{
    if(turn>2) return;

    vis[r][c][turn][dir]=true;

    if(grid[r][c]=='T'){
        puts("YES");
        exit(0);
    }

    for(int i=0;i<4;i++){
        int u,v,ret;
        u=r+X[i];
        v=c+Y[i];

        ret=(dir)?(dir!=i+1):0;

        if((grid[u][v]=='.'||grid[u][v]=='T')&&!(vis[u][v][turn+ret][i+1])){
            rec(u,v,turn+ret,i+1);
            cout<<i<<" "<<turn<<" "<<turn+ret<<endl;
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

    vis[mr][mc][0][0]=true;

    rec(mr,mc,0,0);

    puts("NO");

    return 0;

}
