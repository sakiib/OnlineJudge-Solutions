#include <bits/stdc++.h>
using namespace std;

int n;
bool used[ 100 ];
int ans[ 100 ];
vector < bool > isprime( 105 , true );

void sieve() {
    isprime[ 0 ] = false, isprime[ 1 ] = false;
    for ( int i = 4; i <= 105; i+=2 ) {
        isprime[ i ] = false;
    }
    int sq = 10;
    for ( int i = 3; i <= sq; i+=2 ) {
        if ( isprime[ i ] ){
            for( int j = i*i; j <= 105; j+=2*i ) {
                isprime[ j ] = false;
            }
        }
    }
}
bool Okay( int pos , int val ) {
    if( pos == n ) {
        if((isprime[val + ans[1]]) && (isprime[val+ans[pos-1]])) return true;
    }
    else {
        if( isprime[val+ans[pos-1]] ) return true;
    }
    return false;
}
void solve( int idx ) {
    if( idx > n ) {
        for( int i = 1; i <= n; i++ ) {
            if(i == 1 ) printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        }
        printf("\n");
        return;
    }
    for ( int i = 2; i <= n; i++ ) {
        if( !used[i] ) {
            if( Okay( idx , i ) ) {
                ans[ idx ] = i;
                used[ i ] = true;
                solve( idx+1 );
                used[ i ] = false;
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    int tc  = 1;
    sieve();
    while ( scanf("%d",&n) != EOF ) {
        memset( used, false, sizeof( used ) );
        if( tc != 1 ) printf("\n");
        printf("Case %d:\n",tc++);
        ans[ 1 ] = 1;
        used[ 1 ] = true;
        solve( 2 );
    }
    return 0;
}
