#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000005;
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
    }
    return sum;
}
int main(int argc,char const *argv[]) {
    LL n,q;
    scanf("%lld%lld",&n,&q);
    memset(BIT,0,sizeof(BIT));
    for(int i=1;i<=q;i++) {
        char str[100];
        LL l,r;
        scanf("%s %lld%lld",str,&l,&r);
        if(strcmp(str,"add")==0) update(l,r);
        else printf("%lld\n",query(r)-query(l-1));
    }
    return 0;
}
