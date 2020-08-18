#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL GCD(LL a,LL b) {
    if(a>b) swap(a,b);
    while(b) {
        a=a%b;
        swap(a,b);
    }
    return a;
}
int main(int argc,char const *argv[]) {
    LL g,l;
    #ifdef LOCAL_TEST
    freopen("In_case","r",stdin);
    freopen("Out_case","w",stdout);
    #endif // LOCAL_TEST
    int t;
    scanf("%d",&t);
    while(t--) {
         bool found=false;
         scanf("%lld%lld",&g,&l);
    }
    return 0;
}
