#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(int argc,char const *argv[]) {
    LL g,l;
    int t;
    scanf("%d",&t);
    while(t--) {
         bool found=false;
         scanf("%lld%lld",&g,&l);
         if(l%g==0) found=true;
         if(!found) printf("-1\n");
         else printf("%lld %lld\n",g,l);
    }
    return 0;
}
