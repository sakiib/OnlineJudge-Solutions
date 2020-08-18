#include<bits/stdc++.h>
using namespace std;

const int N=1000005;
typedef long long LL;

LL BIT[N];

void update(LL idx,LL val) {
    while(idx<=N) {
        BIT[idx]+=val;
        idx+=(idx & -idx);
    }
}
LL query(LL idx) {
    LL sum=0;
    while(idx>0) {
        sum+=BIT[idx];
        idx-=(idx & -idx);
    } return sum;
}
int main(int argc,char const *argv[]) {
    LL n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        LL val;
        scanf("%lld",&val);
        update(i,val);
    }
    LL q;
    scanf("%lld",&q);
    for(int i=1;i<=q;i++) {
        char str[10];
        LL l,r;
        scanf("%s %lld%lld",str,&l,&r);
        if(str[0]=='u') update(l,r);
        else printf("%lld\n",query(r)-query(l-1));
    }
    return 0;
}
