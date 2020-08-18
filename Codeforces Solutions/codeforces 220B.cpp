#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> M;
int n,q,l=0,r=-1,block=350,res=0;
int ara[100005],ans[100005];
struct query {
    int l,r,id;
    bool operator<(const query &q)const {
        int block_a=l/block;
        int block_b=q.l/block;
        if(block_a==block_b) return (r<q.r);
        return (block_a<block_b);
    }
}Q[100005];
void rem(int idx) {
    if(M[ara[idx]]==ara[idx]) res--;
    M[ara[idx]]--;
    if(M[ara[idx]]==ara[idx]) res++;
}
void add(int idx) {
    if(M[ara[idx]]==ara[idx]) res--;
    M[ara[idx]]++;
    if(M[ara[idx]]==ara[idx]) res++;
}
void MO() {
    sort(Q,Q+q);
    for(int i=0;i<q;i++) {
        while(r<Q[i].r) add(++r);
        while(l>Q[i].l) add(--l);
        while(r>Q[i].r) rem(r--);
        while(l<Q[i].l) rem(l++);
        ans[Q[i].id]=res;
    }
}
int main(int argc,char const *argv[]) {
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) {
        scanf("%d",&ara[i]);
    }
    for(int i=0;i<q;i++) {
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].l--; Q[i].r--;
        Q[i].id=i;
    }
    MO();
    for(int i=0;i<q;i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
