#include<bits/stdc++.h>
using namespace std;

int cost[1005][1005];
int grid[1005][1005];
bool visited[1005][1005];
int X[4]={-1,1,0,0};
int Y[4]={0,0,1,-1};

int row,col,n,r,t,c,mr,mc,dr,dc,new_m,new_n;

void BFS(int a,int b)
{
    queue<int> Q;
    Q.push(a);
    Q.push(b);
    cost[a][b]=0;
    visited[a][b]=true;
    while(!Q.empty()){
        int m,n;
        m=Q.front();
        Q.pop();
        n=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            new_m=m+X[i];
            new_n=n+Y[i];
            if(new_m>=0&&new_m<=row&&new_n>=0&&new_n<=col&&grid[new_m][new_n]){
               if(!visited[new_m][new_n]){
               Q.push(new_m);
               Q.push(new_n);
               visited[new_m][new_n]=true;
               cost[new_m][new_n]=cost[m][n]+1;
               }
            }
        }
    }

}
int main()
{
    while(scanf("%d%d",&row,&col)==2&&(row!=0&&col!=0)){
        memset(grid,1,sizeof(grid));
        memset(visited,false,sizeof(visited));
        memset(cost,0,sizeof(cost));
        scanf("%d",&n);
        while(n--){
            scanf("%d",&r);
            scanf("%d",&t);
            while(t--){
                scanf("%d",&c);
                grid[r][c]=0;
            }
        }
        scanf("%d%d",&mr,&mc);
        BFS(mr,mc);
        scanf("%d%d",&dr,&dc);
        printf("%d\n",cost[dr][dc]);
    }
    return 0;
}
