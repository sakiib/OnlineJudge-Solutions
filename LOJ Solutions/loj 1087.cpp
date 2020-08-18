#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100005+50005;
LL ara[N+50005],tree[4*N+50005];

void update(LL node,LL b,LL e,LL pos,LL val) {
    if(pos<b||pos>e) return;
    if(b==e&&b==pos) {
        tree[node]+=val;
        return;
    }
    LL left=2*node; LL right=2*node+1;
    LL mid=(b+e)/2;
    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);
    tree[node]=tree[left]+tree[right];
}
LL query(LL node,LL b,LL e,LL x) {
    if(b==e) return e;
    LL left=2*node; LL right=2*node+1;
    LL mid=(b+e)/2;
    if(tree[left]>=x) return query(left,b,mid,x);
    else return query(right,mid+1,e,x-tree[left]);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
       LL n,q;
       scanf("%lld%lld",&n,&q);
       for(LL i=1;i<=n;i++) {
        scanf("%lld",&ara[i]);
        update(1,1,N,ara[i],1);
       }
       printf("Case %d:\n",tc);
       LL tot=n;
       char str[10];
       LL x;
       while(q--) {
        scanf("%s %lld",str,&x);
        if(str[0]=='c') {
         if(x>tot) {
          printf("none\n");
          continue;
         }
         LL id=query(1,1,N,x);
         printf("ID : %lld\n",id);
         printf("%lld\n",ara[id]);
         update(1,1,N,id,-1);
         tot--;
        }
        if(str[0]=='a') {
         ara[++n]=x;
         update(1,1,N,n,1);
         tot++;
        }
       }
       memset(tree,0,sizeof(tree));
       memset(ara,0,sizeof(0));
    }
    return 0;
}
