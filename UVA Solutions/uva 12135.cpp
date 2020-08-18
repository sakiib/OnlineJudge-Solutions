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

int n , m;
int mask[ 50 ];
int state;
int cost[ ( 1 << 15 ) + 5 ];

void bfs( ) {
        queue <int> Q;
        memset( cost , -1 , sizeof( cost ) );
        cost[0] = 0;
        Q.push( 0 );
        while( !Q.empty() ) {
                int f = Q.front(); Q.pop();
                for( int i = 0; i < m; i++ ) {
                        if( cost[f ^ mask[i]] == -1 || cost[f ^ mask[i]] > cost[f] + 1 ) {
                                cost[f  ^mask[i]] = cost[f] + 1;
                                Q.push( f ^ mask[i] );
                        }
                }
        }
}
int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&m);
                for( int i = 0; i < m; i++ ) {
                        int k;
                        scanf("%d",&k);
                        int msk = 0;
                        for( int j = 1; j <= k; j++ ) {
                                int x;
                                scanf("%d",&x);
                                msk |= ( 1 << x );
                        }
                        mask[i] = msk;
                }
                printf("Case %d:\n",tc);
                bfs( );
                int q;
                scanf("%d",&q);
                while( q-- ) {
                        char s[20];
                        scanf("%s",s);
                        int l = strlen( s );
                        state = 0;
                        for( int i = l - 1 , j = 0; i >= 0; i-- , j++ ) {
                                if( s[i] == '1' ) state |= ( 1 << j );
                        }
                        printf("%d\n",cost[state]);
                }
                printf("\n");
        }
        return 0;
}








