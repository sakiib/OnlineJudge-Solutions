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


vector <LL> prime;
vector <bool> isprime( 10*N , true );

void sieve( ) {
    isprime[ 0 ] = isprime[ 1 ] = false;
    for( LL i = 4; i <= 10*N; i += 2 ) {
        isprime[ i ] = false;
    }
    prime.push_back( 2LL );
    LL sq = sqrt( 10*N );
    for( LL i = 3; i <= sq; i += 2 ) {
        if( isprime[ i ] ) {
            for( LL j = i*i; j <= 10*N; j += 2*i ) {
                isprime[ j ] = false;
            }
        }
    }
    for( LL i = 3; i <= 10*N; i += 2 ) {
        if( isprime[ i ] ) prime.push_back( i );
    }
}
LL PrimeFact( LL n ) {
    LL ans = 1LL , sq = sqrt( n );
    for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
        if( n%prime[i] == 0 ) {
            ans *= prime[i];
            n /= prime[i];
            while( n%prime[i] == 0 ) {
                n /= prime[i];
            }
            sq = sqrt( n );
        }
    }
    if( n > 1 ) ans *= n;
    return ans;
}
int main( int argc, char const *argv[] ) {
    sieve( );
    LL n;
    scanf("%lld",&n);
    printf("%lld\n",PrimeFact( n ) );
    return 0;
}

