#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100005;
const LL inf = 1e15;
LL ara[ N ];
vector < LL > oddpos, evenpos;

LL solve( vector< LL > &V ) {
    LL mx = -inf;
    LL sum = 0;
    for ( auto x: V ) {
        sum += x;
        mx = max( mx, sum );
        if( sum < 0) sum = 0;
    }
    return mx;
}
int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for ( int i = 1; i <= n; i++ ){
        scanf("%lld",&ara[i]);
    }
    for( int i = 1; i < n; i++ ) {
        LL val = abs( ara[i]-ara[i+1] );
        if( i%2 == 1) {
            oddpos.push_back( val );
            evenpos.push_back( -val );
        }
        else {
            evenpos.push_back( val );
            oddpos.push_back( -val );
        }
    }
    printf("%lld\n",max(solve( evenpos ),solve( oddpos )));
    return 0;
}

