#include<bits/stdc++.h>
using namespace std;

int taka[100005];
int sum[100005];
int parent[100005];

int Find(int x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u!=v) {
    //cout<<"parent of "<<u<<" is "<<v<<endl;
    parent[u]=v;
    }
}
void makeset(int n) {
    for(int i=0;i<n;i++) {
        parent[i]=i;
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        memset(sum,0,sizeof(sum));
        int n,m;
        scanf("%d%d",&n,&m);
        makeset(n);
        for(int i=0;i<n;i++) {
            scanf("%d",&taka[i]);
        }
        for(int i=1;i<=m;i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        for(int i=0;i<n;i++) {
            int k=Find(i);
            sum[k]+=taka[i];
            //cout<<i<<" er rep : "<<k<<" "<<sum[k]<<endl;
        }

        bool found=true;
        for(int i=0;i<n;i++) {
            //int k=Find(i); //same thing
            if(sum[i]!=0) {found=false; break;} //sum[k]
        }
        if(found) puts("POSSIBLE");
        else puts("IMPOSSIBLE");

    }
    return 0;
}
