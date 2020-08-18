#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL nCr(LL n,LL r) {
    LL res=1;
    if(r>n-r) {
        r=n-r;
    }
    for(LL i=0;i<r;i++) {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int main(int argc,char const *argv[]){
    LL n,r;
    while(scanf("%lld%lld",&n,&r)) {
        if(n==0&&r==0) break;
        LL ans=nCr(n,r);
        printf("%lld things taken %lld at a time is %lld exactly.\n",n,r,ans);
    }
    return 0;
}
