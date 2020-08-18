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

LL BIT[ N ];

void Update( LL idx , LL val ) {
    for( ; idx < N; idx += ( idx & -idx ) ) {
        BIT[idx] += val;
    }
}
LL Query( LL idx ) {
    LL sum = 0;
    for( ; idx > 0; idx -= ( idx & -idx ) ) {
        sum += BIT[idx];
    }
    return sum;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ){
        LL n , u;
        scanf("%lld%lld",&n,&u);
        memset( BIT , 0 , sizeof(BIT) );
        while( u-- ) {
            LL l , r , v;
            scanf("%lld%lld%lld",&l,&r,&v);
            l++ , r++;
            Update( r+1 , -v );
            Update( l , +v );
        }
        int q;
        scanf("%d",&q);
        while( q-- ) {
            LL pos;
            scanf("%lld",&pos);
            printf("%lld\n",Query( pos+1 ) );
        }
    }
    return 0;
}

