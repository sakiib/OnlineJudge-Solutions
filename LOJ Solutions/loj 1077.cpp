#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]){
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        long long ax,ay,bx,by;
        scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
        long long x=(ax-bx);
        long long y=(ay-by);
        x=abs(x);
        y=abs(y);
        long long ans=__gcd(x,y)+1;
        printf("Case %d: %lld\n",tc,ans);
    }
    return 0;
}
