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

int n , sum;
LL dp[ 30 ][ 200 ];

LL solve( int idx , int s ) {
        if( s >= sum ) return 1;
        if( idx > n ) return 0;
        if( dp[idx][s] != -1 ) return dp[idx][s];
        LL ret = 0;
        for( int i = 1; i <= 6; i++ ) {
                ret += solve( idx + 1 , s + i );
        }
        return dp[idx][s] = ret;
}
int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&sum);
                memset( dp , -1 , sizeof( dp ) );
                LL tot = 1;
                for( int i = 1; i <= n; i++ ) tot *= 6LL;
                LL ways = solve( 1 , 0 );
                LL g = __gcd( ways , tot );
                ways /= g , tot /= g;
                printf("Case %d: %lld/%lld\n",tc,ways,tot);
        }
        return 0;
}








