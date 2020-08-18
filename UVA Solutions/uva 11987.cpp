#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL parent[100005];

void make_set(LL n) {
    for(LL i=1;i<=n;i++) {
        parent[i]=i;
    }
}
LL Find(LL x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(LL a,LL b) {
    LL u=Find(a);
    LL v=Find(b);
    if(u==v) return;
    parent[u]=v;
}
int main(int argc,char const *argv[]) {
    LL n;
    while(scanf("%lld",&n)!=EOF) {
        make_set(n);
        int op;
        scanf("%d",&op);
        if(op==1) {
            LL a,b;
            scanf("%lld%lld",&a,&b);
            Union(a,b);
        }
        else if(op==2) {

        }
        else if(op==3) {

        }
    }
    return 0;
}
