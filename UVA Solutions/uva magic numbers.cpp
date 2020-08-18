#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

bool ok( LL num ) {
    LL cnt[ 10 ] = {0};
    while( num ){
        LL rem = num%10;
        cnt[ rem ]++;
        if( cnt[rem] > 1 ) return false;
        num /= 10;
    }
    return true;
}
void solve( LL n ) {
    vector < pair<LL,LL> > V;

    for ( LL i = 1; i*n <= 9876543210; i++ ) {
        if( ok( n*i ) && ok( i ) ) {
           V.push_back( {n*i,i} );
        }
    }
    for ( int i = 0; i < V.size(); i++ ) {
        printf("%lld / %lld = %lld\n",V[i].first,V[i].second,n);
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for ( int tc = 1; tc <= t; tc++ ) {
        LL n;
        scanf("%lld",&n);
        if( tc != 1 ) printf("\n");
        solve( n );
    }
    return 0;
}
