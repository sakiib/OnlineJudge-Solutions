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

vector < LL > divi , d;
LL a , b;

void Divisor( LL x ) {
    LL sq = sqrt( x );
    for( LL i = 1; i <= sq; i++ ) {
        if( a%i == 0 ) {
            divi.push_back( i );
            if( a/i != i ) divi.push_back( a/i );
        }
    }
    for( int i = 0; i < divi.size(); i++ ) {
        if( b%divi[i] == 0 ) d.push_back( divi[i] );
    }
    sort( d.begin() , d.end() );
}
int main( int argc, char const *argv[] ) {
    scanf("%lld%lld",&a,&b);
    if( a > b ) swap( a , b );
    Divisor( a );
    int q;
    scanf("%d",&q);
    while( q-- ) {
        LL l , r;
        scanf("%lld%lld",&l,&r);
        LL up = upper_bound( d.begin() , d.end(),r)-d.begin();
        up--;
        if( d[up] >= l ) printf("%lld\n",d[up]);
        else printf("-1\n");
    }
    return 0;
}

