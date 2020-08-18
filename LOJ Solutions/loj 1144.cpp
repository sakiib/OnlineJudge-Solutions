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
const int N = 1e6 + 5;

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
                        isprime[i * prime[j]] = false;
                        if( i%prime[j] == 0 ) {
                                mobius[i * prime[j]] = 0;
                                break;
                        }
                        else mobius[i * prime[j]] -= mobius[i];
                }
        }
}

int main( ) {
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        mobiusCalc();
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n , m;
                scanf("%d %d",&n,&m);
                if( n > m ) swap( n , m );
                LL ans = 0;
                for( int i = 1; i <= n + 1; i++ ) {
                        ans += 1LL * mobius[i] * ( n / i ) * ( m / i );
                }
                if( n ) ans++;
                if( m ) ans++;
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}








