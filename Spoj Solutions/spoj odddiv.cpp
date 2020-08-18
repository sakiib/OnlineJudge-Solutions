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

vector < bool > isprime( N , true );
vector < LL > prime;

inline void sieve( ) {

    isprime[0] = isprime[1] = false;
    prime.push_back( 2 );
    LL sq = sqrt( N );
    for( LL i = 4; i <= N; i += 2 ) isprime[i] = false;
    for( LL i = 3; i <= sq; i += 2 ) {
        if( isprime[i] ) {
            for( LL j = i*i; j <= N; j += 2*j ) {
                isprime[j] = false;
            }
        }
    }
    for( LL i = 3; i <= N; i += 2 )
    if( isprime[i] ) prime.push_back( i );
}
vector < LL > V[ N ];

LL NOD( LL x ) {
    LL sq = sqrt( x );
    LL ret = 1;
    for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
        if( x%prime[i] == 0 ) {
            LL p = 0;
            while( x%prime[i] == 0 ) x /= prime[i] , p++;
            sq = sqrt( x );
            ret *= ( 2*p+1 );
        }
    }
    if( x != 1 ) ret *= 3;
    return ret;
}
void calc( ) {
    for( int i = 1; i <= N; i++ ) {
        LL num = i*1LL;
        LL nod = NOD( num );
        V[ nod ].push_back( num*num*1LL );
    }
}
int main( int argc, char const *argv[] ) {
    sieve( );
    calc( );
    int t;
    scanf("%d",&t);
    while( t-- ) {
        LL k , lo , hi;
        scanf("%lld %lld %lld",&k,&lo,&hi);
        if( V[k].size() == 0 ) {
            printf("0\n");
            continue;
        }
        LL u = upper_bound( V[k].begin() , V[k].end() , hi )-V[k].begin();
        LL l = lower_bound( V[k].begin() , V[k].end() , lo )-V[k].begin();
        printf("%lld\n",(u-l));
    }
    return 0;
}

