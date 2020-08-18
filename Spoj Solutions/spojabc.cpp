#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N=100005;

LL ara[N],BIT[N];

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        LL n,u;
        scanf("%lld%lld",&n,&u);
        memset(BIT,0,sizeof(BIT));
        while(u--) {
           LL l,r,val;
           scanf("%lld%lld%lld",&l,&r,&val);
           l++, r++;
           BIT[l]+=val;
           BIT[r+1]-=val;
        }
        for(int i=1;i<=n;i++) {
            BIT[i]+=BIT[i-1];
        }
        LL q;
        scanf("%lld",&q);
        while(q--) {
           LL pos;
           scanf("%lld",&pos);
           printf("%lld\n",BIT[pos+1]);
        }
    }
    return 0;
}


