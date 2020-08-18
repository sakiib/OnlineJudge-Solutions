#include<bits/stdc++.h>
using namespace std;

const int inf=1000000000;

int main(int argc,char const *argv[]) {
    int n,e,tc=1;
    while(scanf("%d%d",&n,&e)) {
           if(n==0&&e==0) break;
           int grid[305][305];
           for(int i=1;i<=300;i++) {
            for(int j=1;j<=300;j++) {
             if(i==j) grid[i][j]=0;
             else grid[i][j]=inf;
            }
           }
           map<int,string> M;
           for(int i=1;i<=n;i++) {
            string str;
            cin>>str;
            M[i]=str;
           }
           for(int i=1;i<=e;i++) {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            if(grid[u][v]==0||grid[v][u]==inf||grid[v][u]==0||grid[u][v]==inf) grid[u][v]=c,grid[v][u]=c;
            else {grid[u][v]=min(grid[u][v],c); grid[v][u]=min(grid[v][u],c);}
           }
           for(int k=1;k<=n;k++) {
            for(int i=1;i<=n;i++) {
             for(int j=1;j<=n;j++) {
              if(grid[i][j]>grid[i][k]+grid[k][j]) {
                grid[i][j]=grid[i][k]+grid[k][j];
                //grid[j][i]=grid[j][k]+grid[k][i];
              }
             }
            }
           }
           int idx=-1,cost,mx=1000000000;
           for(int i=1;i<=n;i++) {
            cost=0;
            //bool f=false;
            for(int j=1;j<=n;j++) {
             //if(grid[i][j]==inf||grid[j][i]==inf) { f=true; break;}
             if(i!=j&&grid[i][j]!=inf&&grid[j][i]!=inf) cost+=grid[i][j];
            }
            //cout<<"cost : "<<i<<" "<<cost<<endl;
            if(cost<mx) {
              mx=cost;
              idx=i;
            }
           }
           printf("Case #%d : ",tc++);
           cout<<M[idx]<<endl;
           M.clear();
    }
    return 0;
}
