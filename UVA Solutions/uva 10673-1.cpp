#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
       long long x,k;
       scanf("%lld%lld",&x,&k);
       long long f=(floor)(x*1.0/k);
       long long c=(ceil)(x*1.0/k);
       long long ans1,ans2;
       for(long long p=0;p*f<=x;p++) {
         if((x-p*f)%c==0) {
            ans1=p;
            ans2=(x-p*f)/c;
            break;
         }
       }
       printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}
