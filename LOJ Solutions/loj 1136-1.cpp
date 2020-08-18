#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL solve( LL val ) {
        LL lo = 1 , hi = 1000000000 , ret = 0;
        while( lo <= hi ) {
                LL mid = ( lo+hi )/2;
                LL res = 1+(mid-1)*3;
                if( res <= val ) {
                        ret = mid;
                        lo = mid+1;
                }
                else hi = mid-1;
        }
        return ret;
}
int main( int argc, char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                LL a , b;
                scanf("%lld %lld",&a,&b);
                LL tot = b-a+1;
                LL ans = tot - ( solve(b) - solve(a-1) );
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}






