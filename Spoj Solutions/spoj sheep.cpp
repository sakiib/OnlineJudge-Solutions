#include<bits/stdc++.h>
using namespace std;

char str[300][300];
int s,w;
bool visited[300][300];
int r,c;

void dfs(int x,int y) {
    visited[x][y]=true;
    if(str[x][y]=='#') return;
    if(str[x][y]=='k') s++;
    if(str[x][y]=='v') w++;
    if(x+1<r&&!visited[x+1][y]) dfs(x+1,y);
    if(x>0&&!visited[x-1][y])   dfs(x-1,y);
    if(y+1<c&&!visited[x][y+1]) dfs(x,y+1);
    if(y>0&&!visited[x][y-1])   dfs(x,y-1);
}
int main(int argc,char const *argv[]) {
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++) {
        scanf("%s",str[i]);
    }
    int sh=0,wo=0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(!visited[i][j]) {
                s=0,w=0;
                dfs(i,j);
                if(s>w) sh+=s;
                else wo+=w;
            }
        }
    } printf("%d %d\n",sh,wo);
    return 0;
}
