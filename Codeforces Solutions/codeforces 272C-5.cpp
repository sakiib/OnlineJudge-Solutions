#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

LL ara[ 2*N ];
LL BIT[ 2*N ];
LL add[ 2*N ];

void Update( LL idx , LL val ) {
    for( ; idx <= 2*N; idx += ( idx & -idx ) ) {
        BIT[idx] += val;
    }
}
LL Query( LL idx ) {
    LL sum = 0;
    for( ; idx > 0 ; idx -= ( idx & -idx ) ) {
        sum += BIT[idx];
    }
    return sum;
}
int main( int argc, char const *argv[] ) {
    LL n , q;
    scanf("%lld%lld",&n,&q);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
    }
    while( q-- ) {
        LL l , r;
        scanf("%lld%lld",&l,&r);
        Update( l , +1 );
        Update( r+1 , -1 );
    }
    for( int i = 1; i <= n; i++ ) {
        add[i] = Query( i );
    }
    sort( add+1 , add+n+1 );
    sort( ara+1 , ara+n+1 );
    LL ans = 0;
    for( int i = 1; i <= n; i++ ) {
        ans += (add[i]*ara[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
