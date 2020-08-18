#include<bits/stdc++.h>
using namespace std;

int X[4]={-1,1,0,0};
int Y[4]={0,0,1,-1};
bool visited[1005][1005][10][10];
char grid[1005][1005];

int row,col,mr,mc,dr,dc;

void BFS(int a,int b,int turn,int dir)
{
    if(turn>2) return;

    visited[a][b][0][0]=true;

    if(grid[a][b]=='T'){
        puts("YES");
        exit(0);
    }

    for(int i=0;i<4;i++){
        int p=a+X[i];
        int q=b+Y[i];

        if((grid[p][q]=='.'||grid[p][q]=='T')&&!visited[p][q][][]
            &&p>=1&&p<=row&&q>=1&&q<=col){

            // BFS(p,q,,);
        }
    }


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
            if(grid[i][j]=='T'){
                dr=i,dc=j;
            }
        }
    }
    memset(visited,false,sizeof(visited));

    BFS(mr,mc,0,0);

    puts("NO");

}
