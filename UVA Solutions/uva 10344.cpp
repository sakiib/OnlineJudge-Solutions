#include<bits/stdc++.h>
using namespace std;

int ara[10];
bool done;
bool visited[10];

void dfs(int i,int sum) {
   if(i>5) return;
   if(sum==23&&i==5) {
    done=true;
    return;
   }
   else {for(int j=0;j<5;j++) {
    if(!visited[j]) {
        visited[j]=true;
        dfs(i+1,sum+ara[j]);
        dfs(i+1,sum-ara[j]);
        dfs(i+1,sum*ara[j]);
        visited[j]=false;
     }
    }
   }
}
int main(int argc,char const *argv[]) {
    while(scanf("%d%d%d%d%d",&ara[0],&ara[1],&ara[2],&ara[3],&ara[4])) {
        if(ara[0]==0&&ara[1]==0&&ara[2]==0&&ara[3]==0&&ara[4]==0) break;
        done=false;
        for(int i=0;i<5;i++) {
            visited[i]=true;
            dfs(1,ara[i]);
            visited[i]=false;
        }
        if(done) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
