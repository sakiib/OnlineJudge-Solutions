#include <bits/stdc++.h>
using namespace std;

vector < int > isprime( 100005,true );
vector < int > prime;

void sieve(){
    isprime[ 0 ] = false , isprime[ 1 ] = false;
    for ( int i = 2; i <= 100005; i += 2 ) {
        isprime[ i ] = false;
    }
    prime.push_back( 2 );
    int sq = sqrt( 100005 );
    for( int i = 3; i<= sq; i += 2 ) {
        if ( isprime[ i ] ) {
            for ( int j = i*i; j <= 100005; j += 2*i ) {
                isprime [ j ] = false;
            }
        }
    }
    for ( int i = 3; i <= 100005; i += 2 ) {
        if ( isprime[ i ] ) prime.push_back( i );
    }
}
int n;
int ara[ 100005 ];
map <int , int> M;

void factorize( int val ) {
    int sq = sqrt( val );
    for ( int i = 0; i < prime[ i ] && prime[ i ] <= sq; i++) {
        if ( val % prime[ i ] == 0) {
            M[ prime[ i ] ] ++;
            val /= prime[ i ];
            while ( val % prime[ i ] == 0 ) {
                val /= prime[ i ];
            }
        }
    }
    if ( val > 1) M[ val ] ++;
}
int main(int argc , char const *argv[]) {
    sieve();
    scanf("%d",&n);
    for ( int i = 1; i <= n; i ++ ) {
        scanf("%d",&ara[i]);
    }
    for ( int i = 1; i <= n ; i ++ ) {
         factorize( ara[ i ] );
    }
    int mx = 1;
    for ( auto x : M ) {
        mx = max( mx , x.second );
    }
    printf("%d\n",mx);
    return 0;
}
