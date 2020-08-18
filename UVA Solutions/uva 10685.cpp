#include<bits/stdc++.h>
using namespace std;

int parent[100005];
int sum[100005];
int mx;
int Find(int x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u!=v) {
        parent[u]=v;
        sum[v]+=sum[u];
        mx=max(mx,sum[v]);
    }
}
int main(int argc,char const *argv[]) {
    int n,k;
    int tc=1;
    while(scanf("%d%d",&n,&k) ) {
        map<string,int> M;
        if(n==0&&k==0) break;
        memset(sum,0,sizeof(sum));
        mx=1;
        for(int i=1;i<=n;i++) {
            string str;
            cin>>str;
            M[str]=i;
            parent[M[str]]=i;
            sum[M[str]]=1;
        }
        for(int i=1;i<=k;i++) {
            string a,b;
            cin>>a>>b;
            Union(M[a],M[b]);
        }
        printf("%d\n",mx);
    }
    return 0;
}
