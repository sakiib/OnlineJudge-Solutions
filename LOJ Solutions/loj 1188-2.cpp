#include<bits/stdc++.h>
using namespace std;

int k;
int l=0,r=-1;
int ara[100010];
int cnt[100010],ans=0;
int res[100010];

struct query {
    int l,r,id;
}Q[100010];
bool comp(query a,query b) {
    int block_a=a.l/k; int block_b=b.l/k;
    if(block_a==block_b) return a.r<b.r;
    return (block_a<block_b);
}

void add(int x) {
    int temp=ara[x];
    cnt[temp]++;
    if(cnt[temp]==1) ans++;
}
void rem(int x) {
    int temp=ara[x];
    cnt[temp]--;
    if(cnt[temp]==0) ans--;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        memset(cnt,0,sizeof(cnt));
        memset(res,0,sizeof(res));
        ans=0;
        int n,q;
        scanf("%d%d",&n,&q);
        k=(ceil)(sqrt(n));
        for(int i=0;i<n;i++) {
          scanf("%d",&ara[i]);
       }
       l=0,r=-1;
       for(int i=0;i<q;i++) {
        int le,ri;
        scanf("%d%d",&le,&ri);
        le--,ri--;
         Q[i].l=le, Q[i].r=ri; Q[i].id=i;
       }
       sort(Q,Q+q,comp);
       printf("Case %d:\n",tc);
       for(int i=0;i<q;i++) {
          while(r<Q[i].r) add(++r);
          while(r>Q[i].r) rem(r--);
          while(l>Q[i].l) add(--l);
          while(l<Q[i].l) rem(l++);
          res[Q[i].id]=ans;
       }
       for(int i=0;i<q;i++) {
        printf("%d\n",res[i]);
       }
    }
    return 0;
}
