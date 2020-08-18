#include<bits/stdc++.h>
using namespace std;

pair<int,int> PII;

string a,b;
int ix,iy,dx,dy,m,n;

int X[8]={-2,-1, 1, 2, 2,1,-1,-2};
int Y[8]={-1,-2,-2,-1, 1,2, 2, 1};

bool visited[100][100];
int val[100][100];

bool valid_move(int p,int q)
{
    if((p>=1&&p<=8)&&(q>=1&&q<=8)&&!(visited[p][q])) return true;
    else return false;
}
void BFS(int u,int v,int x,int y)
{
    queue<pair<int,int> > Q;

    Q.push(make_pair(u,v));

    visited[u][v]=true;
    val[u][v]=0;

    while(!Q.empty()){

        PII =Q.front();
        Q.pop();

        if(PII.first==x&&PII.second==y){
          //printf("To get from %s to %s takes %d knight moves.\n",a,b,val[PII.first][PII.second]);
            cout<<"To get from "<< a <<" to "<< b << " takes "<< val[PII.first][PII.second]<<" Knight moves."<<endl;
            return;
        }
        for(int i=0;i<8;i++){
            m=PII.first+X[i];
            n=PII.second+Y[i];
            if(valid_move(m,n)){
                visited[m][n]=true;
                Q.push(make_pair(m,n));
                val[m][n]=val[PII.first][PII.second]+1;
            }
        }
    }

   return;
}
int main()
{

    while(cin>>a>>b){
        ix=a[0]-96;
        iy=a[1]-'0';
        dx=b[0]-96;
        dy=b[1]-'0';

        memset(visited,false,sizeof(visited));
        memset(val,0,sizeof(val));

        BFS(ix,iy,dx,dy);
    }
    return 0;
}
