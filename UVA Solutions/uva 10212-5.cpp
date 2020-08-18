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
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define mp          pake_pair
#define CLR(V)      V.clear()
#define All(V)      V.begin(),V.end()
#define SORT(V)     sort( V.begin(), V.end() )
#define REV(V)      sort( V.rbegin(), V.rend() )
#define MEM(a,x)    memset( a, x, sizeof(a) )
#define FOR(i,a,b)  for( int i = a; i <= b; i++ )
#define ROF(i,a,b)  for( int i = b; i >= a; i-- )
#define REP(i,a)    for( int i = 0; i < a; i++ )
#define debug(x)    cerr << "The value is "<< x << endl
#define Unique(a)   sort( All(a)), a.erase( unique( All(a) ), a.end())
#define UB(a,key)   upper_bound( a.begin(), a.end(), key )-a.begin()
#define LB(a,key)   lower_bound( a.begin(), a.end(), key )-a.begin()

map <LL,LL> M;

vector<bool> isprime( 100010, true );
vector<int> prime;

void sieve( ) {
    isprime[0] = false, isprime[1] = false;
    prime.push_back( 2 );
    for( int i = 4; i <= 100010; i += 2 ) {
        isprime[i] = false;
    }
    int sq = sqrt( 100010 );
    for( int i = 3; i <= sq; i += 2 ) {
        if( isprime[i] ) {
        for( int j = i*i; j <= 100010; j += 2*i ) {
        isprime[j] = false;
         }
       }
    }
    for( int i = 3; i <= 100010; i += 2 ) {
        if( isprime[i] ) prime.push_back( i );
    }
}
void PrimeFact( LL val ) {
    LL sq = sqrt( val );
    for( int i = 0; i < prime.size() && prime[i] <= sq ; i++ ) {
        if( val%prime[i] == 0 ) {
            val /= prime[i];
            M[ prime[i] ]++;
            while( val%prime[i] == 0 ) {
                val /= prime[i];
                M[ prime[i] ]++;
            }
            sq = sqrt( val );
        }
    }
    if( val > 1 ) M[ val ]++;
}
inline LL BigMod ( LL a , LL p , LL m ) {
    LL res = 1%m , x = a%m;
    while( p ) {
        if( p&1 )
        res = (res*x)%m;
        x = (x*x)%m;
        p >>= 1;
    }
    return res;
}
int main( int argc, char const *argv[] ) {
    LL n , r;
    sieve( );
    while( scanf("%lld %lld",&n,&r) != EOF ) {
        LL x = n;
        LL y = n-r;
        LL ans = 1;
        FOR( i , y+1 , x ) {
            LL val = i*1LL;
            PrimeFact( val );
        }
        LL bad = min( M[5] , M[2] );
        M[5] -= bad , M[2] -= bad;
        map <LL,LL> :: iterator it;
        for( it = M.begin() ; it != M.end(); it++ ) {
            ans = (ans%10*BigMod( it->F , it->S , 10)%10)%10;
        }
        printf("%lld\n",ans);
        M.clear( );
    }
    return 0;
}



