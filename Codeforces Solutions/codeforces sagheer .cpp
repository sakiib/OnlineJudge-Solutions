#include <bits/stdc++.h>
using namespace std;

const int N  = 100005;
typedef long long LL;
LL ara[ N ];
LL n , s;

LL cost( int k ) {
    vector < LL > V;
    for ( LL i = 1; i <= n; i++ ) {
        V.push_back( ara[i]+i*k );
    }
    sort( V.begin(), V.end() );
    LL c = 0;
    for ( int i = 0; i < k; i++ ) {
        c += V[i];
    }
    return c;
}
int main( int argc, char const *argv[] ) {
    scanf("%lld%lld",&n,&s);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
    }
    LL lo = 0 , hi  = n;
    LL buy = 0;
    LL total = 0;
    while ( lo <= hi ) {
        LL mid = ( lo+hi )/2;
        LL taka = cost( mid );
        if ( taka <= s ) {
            buy = mid;
            lo  = mid+1;
        }
        else hi  = mid-1;
    }
    printf("%lld %lld\n",buy,cost( buy ));
    return 0;
}
