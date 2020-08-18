#include<bits/stdc++.h>
using namespace std;

map<int,bool> gov;
vector<int> graph[100010];
map<pair<int,int>,bool> M;

int main(int argc,char const *argv[]) {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++) {
        int val;
        scanf("%d",&val);
        gov[val]=true;
    }
    for(int i=1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        M[{u,v}]=true;
        M[{v,u}]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(gov[i]&&gov[j]) continue;
            if(!M[{i,j}]&&!M[{j,i}]) {
                M[{i,j}]=true;
                M[{j,i}]=true;
                ans++;
                printf(" %d %d \n",i,j);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
