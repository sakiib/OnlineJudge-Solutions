#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

bool valid(LL a,LL b,LL c) {
    if(a+b<=c||b+c<=a||a+c<=b) return false;
    else return true;
}
int main(int argc,char const *argv[]) {
    LL a,b,c;
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(!valid(a,b,c)) {
            printf("Case %d: Invalid\n",tc);
            continue;
        }
        if(a==b&&b==c&&a==c) {
            printf("Case %d: Equilateral\n",tc);
            continue;
        }
        if(a!=b&&b!=c&&a!=c) {
            printf("Case %d: Scalene\n",tc);
        }
        else printf("Case %d: Isosceles\n",tc);
    }
    return 0;
}
