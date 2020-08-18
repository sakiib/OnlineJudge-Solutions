#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int ara[N],ans[N];
int k,n,q,l=0,r=-1,res=0;
unordered_map<int,int> cnt;

struct query {
    int L,R,ID;
    query(){}
    query(int _L,int _R,int _ID) {
        L=_L, R=_R, ID=_ID;
    }
    bool operator<(const query &q) const {
        int block_a=L/k; int block_b=q.L/k;
        if(block_a==block_b) return (R<q.R);
        return (block_a<block_b);
    }
} Q[N];
void add(int x) {
    if(cnt[ara[x]]==ara[x]) res--;
    cnt[ara[x]]++;
    if(cnt[ara[x]]==ara[x]) res++;
}
void rem(int x) {
    if(cnt[ara[x]]==ara[x]) res--;
    cnt[ara[x]]--;
    if(cnt[ara[x]]==ara[x]) res++;
}
void MO() {
    sort(Q,Q+q);
    for(int i=0;i<q;i++) {
        while(l<Q[i].L) rem(l++);
        while(r<Q[i].R) add(++r);
        while(l>Q[i].L) add(--l);
        while(r>Q[i].R) rem(r--);
        ans[Q[i].ID]=res;
    }
}
int main(int argc,char const *argv[]) {

    scanf("%d%d",&n,&q);
    k=sqrt(n);
    for(int i=0;i<n;i++) {
        scanf("%d",&ara[i]);
    }
    for(int i=0;i<q;i++) {
        scanf("%d%d",&Q[i].L,&Q[i].R);
        Q[i].L--; Q[i].R--;
        Q[i].ID=i;
    }
    MO();
    for(int i=0;i<q;i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
