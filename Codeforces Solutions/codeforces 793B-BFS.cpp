#include<bits/stdc++.h>
using namespace std;

int X[4]={-1,1,0,0};
int Y[4]={0,0,1,-1};
bool visited[1005][1005];
char grid[1005][1005];

int row,col,mr,mc,dr,dc;

void BFS(int a,int b,int turn)
{
    queue<int> Q;

    Q.push(a);
    Q.push(b);
    visited[a][b]=true;

    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        int y=Q.front();
        Q.pop();
        if(grid[x][y]=='T'&&turn<=2){
            puts("YES");
           // cout<<turn<<endl;
            exit(0);
        }
        for(int i=0;i<4;i++){
            int m=x+X[i];
            int n=y+Y[i];

            if(m>=1&&m<=row&&n>=1&&n<=col&&!visited[m][n]&&
               (grid[m][n]=='.'||grid[m][n]=='T')){
                   visited[m][n]=true;
                   Q.push(m);
                   Q.push(n);
            }
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
            if(grid[i][j]=='T'){
                dr=i,dc=j;
            }
        }
    }
    memset(visited,false,sizeof(visited));

    BFS(mr,mc,0);

    puts("NO");

    return 0;
}
