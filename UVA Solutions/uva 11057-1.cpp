#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ara[100010];
ll n;
ll dif=100000000;
ll x=0,y=0;

bool found(int idx,int val) {
    ll lo=idx,hi=n;
    ll mid;
    while(lo<=hi) {
        mid=(lo+hi)/2;
        if(ara[mid]==val) return true;
        if(ara[mid]<val) {
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return false;
}
int main(int argc,char const *argv[]) {

    while(scanf("%lld",&n)!=EOF) {
        for(int i=1;i<=n;i++) {
            scanf("%lld",&ara[i]);
        }
        sort(ara+1,ara+n+1);
        ll tot;
        scanf("%lld",&tot);
        ll a,left;
        x=0,y=0;
        dif=100000000;
        for(int i=1;i<n;i++) {
             a=ara[i];
             left=tot-a;
            if(found(i+1,left)) {
                if(abs(a-left)<dif) {
                    x=a,y=left;
                    dif=abs(a-left);
                }
            }
        }
        printf("Peter should buy books whose prices are %lld and %lld.\n\n",x,y);
    }
    return 0;
}
