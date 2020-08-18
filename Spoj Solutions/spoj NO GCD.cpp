#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

int n , a[ N ];
int cnt[ N ];
bool isprime[ N ];
int prime[ N ];
int mobius[ N ] = { 0 , 1 };

void mobiusCalc( ) {
        memset( isprime , true , sizeof( isprime ) );
        int primecnt = 0;
        for( int i = 2; i < N; i++ ) {
                if( isprime[i] ) {
                        prime[ ++primecnt ] = i;
                        mobius[i] = -1;
                }
                for( int j = 1; i * prime[j] < N; j++ ) {
                        isprime[ i*prime[j] ] = false;
                        if( i%prime[j] == 0 ) {
                                mobius[ i*prime[j] ] = 0;
                                break;
                        }
                        else mobius[ i*prime[j] ] -= mobius[i];
                }
        }
}

LL nCr[ 10005 ][ 10 ];

void BinomCoeff( ) {
        for( int i = 0; i <= 10000; i++ ) nCr[i][0] = 1;
        for( int i = 1; i <= 10000; i++ ) {
                for( int j = 1; j <= 4; j++ ) {
                        nCr[i][j] = ( nCr[i-1][j] + nCr[i-1][j-1] );
                }
        }
}
int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        mobiusCalc();
        BinomCoeff();
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                memset( cnt , 0 , sizeof( cnt ) );
                for( int i = 1; i <= n; i++ ) {
                        for( int j = 1; j * j <= a[i]; j++ ) {
                                if( a[i]%j == 0 ) {
                                        cnt[j]++;
                                        if( a[i]/j != j ) cnt[a[i]/j]++;
                                }
                        }
                }
                LL tot = 2 * nCr[n][2];
                for( int i = 2; i <= 10000; i++ ) {
                        if( cnt[i] < 2 ) continue;
                        if( isprime[i] ) continue;
                        tot -= ( -mobius[i] * nCr[ cnt[i] ][2] );
                }
                printf("Case %d: %lld\n",tc,tot);
        }
        return 0;
}





