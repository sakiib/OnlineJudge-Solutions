#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL inf = 1000000000;
LL ara[ 100005 ];

int main( int argc, char const *argv[] ) {
    LL n;
    while ( scanf("%lld",&n) ) {
        if ( n==0 ) break;
        for ( int i = 1; i <= n; i++ ) {
            scanf("%lld",&ara[i]);
        }
        LL mx = -inf;
        LL sum = 0;
        for ( int i = 1; i <= n; i++ ) {
            if ( sum+ara[i] >= 0) {
                sum += ara[i];
                mx = max( mx, sum );
            }
            else sum = 0;
        }
        if ( mx <= 0 ) printf("Losing streak.\n");
        else printf("The maximum winning streak is %lld.\n",mx);
    }
    return 0;
}
