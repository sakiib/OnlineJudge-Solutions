#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e6 + 5;

vector <int> prime;
vector <bool> isprime( N , true );

void sieve( ) {
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        for( int i = 4; i <= N; i +=2 ) isprime[i] = false;
        int sq = sqrt( N );
        for( int i = 3; i <= sq; i += 2 ) {
                if( isprime[i] ) {
                        for( int j = i*i; j <= N; j += 2*i ) {
                                isprime[j] = false;
                        }
                }
        }
        for( int i = 3; i <= N; i += 2 ) {
                if( isprime[i] ) prime.push_back( i );
        }
}
vector <LL> PrimeFact( LL n ) {
        vector <LL> ret;
        LL sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                if( n%prime[i] == 0 ) {
                        ret.push_back( prime[i] );
                        n /= prime[i];
                        while( n%prime[i] == 0 ) {
                                ret.push_back( prime[i] );
                                n /= prime[i];
                        }
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) ret.push_back( n );
        return ret;
}
LL Power ( LL b , LL p ) {
        LL res = 1, x = b;
        while ( p ) {
                if ( p & 1 ) res = ( res * x );
                x = ( x * x ); p >>= 1;
        }
        return ( res );
}

#define all( V ) V.begin( ),V.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )

void solve( int tc ) {
        LL a , b , l;
        scanf("%lld %lld %lld",&a,&b,&l);
        if( l%a != 0 || l%b != 0 ) {
                printf("Case %d: impossible\n",tc);
                return;
        }
        vector <LL> A = PrimeFact( a );
        vector <LL> B = PrimeFact( b );
        vector <LL> L = PrimeFact( l );
        map <LL,LL> mA , mB , mL;
        for( auto x : A ) mA[x]++;
        for( auto x : B ) mB[x]++;
        for( auto x : L ) mL[x]++;
        LL ans = 1;
        for( auto x : mL ) {
                if( mA[x.first] < x.second && mB[x.first] < x.second ) {
                        ans *= Power( x.first , x.second );
                }
        }
        printf("Case %d: %lld\n",tc,ans);
}
int main( int argc , char const *argv[] ) {
        //freopen( "input.txt" , "r" , stdin );
        //freopen( "output.txt" , "w" , stdout );
        int t;
        sieve( );
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                solve( tc );
        }
        return 0;
}












