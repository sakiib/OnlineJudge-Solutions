#include<bits/stdc++.h>
using namespace std;

int inf=2222222222222;
int grid[10005][10005];
bool visited[10005][10005];
int cost[10005][10005];

int X[4]={-1,0,0,1};
int Y[4]={0,-1,1,0};

int row,col,pos,r_pos,n,c_pos,start_x,start_y,dest_x,dest_y;

void BFS(int ri,int ci)
{
    int fir,sec,af_fir,af_sec;
    queue<int> Q;

    Q.push(ri);
    Q.push(ci);

    visited[ri][ci]=true;
    cost[ri][ci]=0;

    while(!Q.empty()){

        fir=Q.front();
        Q.pop();
        sec=Q.front();
        Q.pop();

        for(int j=0;j<4;j++){

            af_fir=fir+X[j];
            af_sec=sec+Y[j];

            if((af_fir>=0&&af_fir<=row)&&(af_sec>=0&&af_sec<=col)&&(grid[af_fir][af_sec]==0)){
                if(!visited[af_fir][af_sec]&&!cost[af_fir][af_sec]){

                    visited[af_fir][af_sec]=true;

                    Q.push(af_fir);
                    Q.push(af_sec);

                    cost[af_fir][af_sec]=cost[fir][sec]+1;
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&row,&col)==2&&(row!=0&&col!=0)){

    memset(cost,0,sizeof(cost));
    memset(grid,0,sizeof(grid));
    memset(visited,false,sizeof(visited));

    int pos;
    scanf("%d",&pos);

    while(pos--){
        scanf("%d",&r_pos);
        scanf("%d",&n);

        while(n--){
            scanf("%d",&c_pos);
            grid[r_pos][c_pos]=inf;
        }
    }
    scanf("%d%d",&start_x,&start_y);

    BFS(start_x,start_y);

    scanf("%d%d",&dest_x,&dest_y);

    cout<<cost[dest_x][dest_y]<<endl;
    }
    return 0;
}
