#include<bits/stdc++.h>
using namespace std;

const int N=15;

int r,c,p;
string str[N];
int ara[N][N];
bool loop;
bool ex;
int cnt;
int m,n;

void dfs(int x,int y) {
    if(ara[x][y]>0) {
        m=x,n=y;
        loop=true; return;
    }
    else {
        //ara[x][y]++;
        cnt++;
        //ara[x][y]=cnt;
        if(str[x][y]=='W') y--;
        else if(str[x][y]=='N') x--;
        else if(str[x][y]=='S') x++;
        else y++;
        if(x<0||y<0||x>=r||y>=c) {ex=true; return;}
        ara[x][y]=cnt;
        dfs(x,y);
    }
}
int main(int argc,char const *argv[]) {
    while(scanf("%d%d%d",&r,&c,&p)==3&&(r!=0&&c!=0&&p!=0)) {
        for(int i=0;i<r;i++) {
            cin>>str[i];
        }
        memset(ara,0,sizeof(ara));
        loop=false;
        ex=false;
        p--;
        cnt=0;
        dfs(0,p);
        if(loop) cout<<ara[m][n]<<" step(s) before a loop of "<<cnt-ara[m][n]<<" step(s)"<<endl;
        else cout<<cnt<<" step(s) to exit"<<endl;
    }
    return 0;
}
