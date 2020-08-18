#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ll t,a,b,x,y;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld%lld",&a,&b);
        x=(ceil)(1.0*a/b);
        y=(floor)(1.0*a/b);
        //printf("%lld %lld\n",x,y);
        ll p=1;
        a-=x;
        ll q=a/y;
        printf("%lld %lld\n",p,q);
    }
    return 0;
}
