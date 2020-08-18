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

vector <pii> graph[ N ];
int n , m , col[ N ];

bool dfs( int s , int c , int we ) {
        col[s] = c;
        bool ret = true;
        for( auto x : graph[s] ) {
                if( x.second >= we ) continue;
                if( col[x.first] == c ) return false;
                else if( col[x.first] == -1 ) {
                        ret &= dfs( x.first , (c^1) , we );
                }
        }
        return ret;
}
bool ok( int x ) {
        memset( col , -1 , sizeof( col ) );
        bool ret = true;
        for( int i = 1; i <= n; i++ ) {
                if( col[i] == -1 ) ret &= dfs( i , 0 , x );
        }
        return ret;
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
            freopen( "output.txt" , "w" , stdout );
        #endif // LOCAL
        int t;
        cin >> t;
        while( t-- ) {
                cin >> n >> m;
                for( int i = 1; i <= n; i++ ) graph[i].clear();
                vector <int> W;
                for( int i = 1; i <= m; i++ ) {
                        int u , v , w;
                        cin >> u >> v >> w;
                        graph[u].push_back( { v , w } );
                        graph[v].push_back( { u , w } );
                        W.push_back( w );
                }
                if( ok( 2*inf ) ) {
                        cout << 0 << endl;
                        continue;
                }
                Unique( W );
                int lo = 0 , hi = W.size() - 1 , ret = W[0];
                while( lo <= hi ) {
                        int mid = ( lo + hi ) >> 1;
                        if( ok( W[mid] ) ) ret = W[mid] , lo = mid + 1;
                        else hi = mid - 1;
                }
                if( ret == W[0] ) cout << -1 << endl;
                else cout << ret << endl;
        }
        return 0;
}








