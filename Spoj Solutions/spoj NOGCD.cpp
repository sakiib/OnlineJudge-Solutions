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

vector <int> p = { 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23
                    , 29 , 31 , 37 , 41 , 43 , 47 , 49 };
int id[ 20 ];
int n;
int a[ N ] , dp[ ( 1 << 17 ) + 5 ];

int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        for( int i = 0; i < p.size(); i++ ) id[ p[i] ] = i;
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                memset( dp , 0 , sizeof( dp ) );
                memset( a , 0 , sizeof( a ) );
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) {
                        int val;
                        scanf("%d",&val);
                        int curmask = 0;
                        for( auto x : p ) if( val%x == 0 ) curmask |= ( 1 << id[x] );
                        a[i] = curmask;
                        dp[curmask]++;
                }
                for( int i = 0; i < 16; i++ ) {
                        for( int j = 0; j < ( 1 << 16 ); j++ ) {
                                if( j&( 1 << i ) ) {
                                        dp[j] += dp[ j ^ ( 1 << i ) ];
                                }
                        }
                }
                LL ans = 0;
                for( int i = 1; i <= n; i++ ) {
                        int remmask = ( 1 << 16 ) - a[i] - 1;
                        ans += dp[remmask];
                        for( int j = 0; j < 16; j++ ) {
                                if( a[i]&( 1 << j ) ) {
                                        remmask = ( 1 << 16 ) - a[i] - 1 + ( 1 << j );
                                        ans += dp[remmask] - dp[remmask - ( 1 << j )];
                                }
                        }
                }
                printf("%lld\n",ans);
        }
        return 0;
}








