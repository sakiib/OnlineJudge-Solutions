#include<bits/stdc++.h>
using namespace std;

int id[200005],cnt[200005],parent[200005];
long long sum[200005];
int temp;

void makeset(int n) {
    for(int i=1;i<=n;i++) {
        id[i]=i;
        sum[i]=i;
        parent[i]=i;
        cnt[i]=1;
    }
    temp=n;
}
int Find(int x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(id[a]);
    int v=Find(id[b]);
    if(u!=v) {
        parent[u]=v;
        sum[v]+=sum[u];
        cnt[v]+=cnt[u];
    }
}
void change(int x) { // ei set theke alada kore dilam
    int u=Find(id[x]);
    cnt[u]--; sum[u]-=x; // ei set er sum & cnt komaya dilam
    id[x]=++temp; // jake alada korlam tar new attributes
    sum[temp]=x; cnt[temp]=1; parent[temp]=temp;
}
int main(int argc,char const *argv[]) {
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF) {
        makeset(n);
        for(int i=1;i<=k;i++) {
            int op;
            scanf("%d",&op);
            int a,b;
            switch (op) {
                case 1: scanf("%d%d",&a,&b);
                if(Find(id[a])!=Find(id[b])) Union(a,b);
                break;
                case 2: scanf("%d%d",&a,&b);
                if(Find(id[a])!=Find(id[b])) change(a),Union(a,b);
                break; // ager set theke delete kore new set e add kortesi
                case 3: scanf("%d",&a);
                printf("%d %lld\n",cnt[Find(id[a])],sum[Find(id[a])]);
                break;
            }
        }
    }
    return 0;
}
