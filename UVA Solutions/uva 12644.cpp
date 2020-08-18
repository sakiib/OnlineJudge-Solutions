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

int x[ 505 ][ 30 ];
int y[ 505 ][ 30 ];

struct bipartite_matchingHK {
        static const int N = 1e5 + 5;
        static const int inf = 2e9;
        vector <int> graph[ N ];
        int lcnt , rcnt , left[ N ] , right[ N ] , dist[ N ];
        void init( int l , int r ) {
                lcnt = l , rcnt = r;
                for( int i = 0; i < N; i++ ) graph[i].clear();
        }
        void add_edge( int u , int v ) {
                graph[u].push_back( v );
        }
        bool bfs( ) {
                queue <int> Q;
                for( int i = 1; i <= lcnt; i++ ) {
                        if( left[i] == 0 ) dist[i] = 0 , Q.push( i );
                        else dist[i] = inf;
                }
                dist[0] = inf;
                while( !Q.empty() ) {
                        int u = Q.front(); Q.pop();
                        if( u != 0 ) {
                                for( int i = 0; i < graph[u].size(); i++ ) {
                                        int v = graph[u][i];
                                        if( dist[right[v]] == inf ) {
                                                 dist[right[v]] = dist[u] + 1;
                                                 Q.push( right[v] );
                                        }
                                }
                        }
                }
                return dist[0] != inf;
        }
        bool dfs( int u ) {
                if( u == 0 ) return true;
                for( int i = 0; i < graph[u].size(); i++ ) {
                        int v = graph[u][i];
                        if( dist[right[v]] == dist[u] + 1 ) {
                                if( dfs( right[v] ) ) {
                                        right[v] = u;
                                        left[u] = v;
                                        return true;
                                }
                        }
                }
                dist[u] = inf;
                return false;
        }
        int maximum_match( ) {
                int match = 0;
                memset( left , 0 , sizeof( left ) );
                memset( right , 0 , sizeof( right ) );
                while( bfs() ) {
                        for( int i = 1; i <= lcnt; i++ ) {
                                if( left[i] == 0 && dfs( i ) ) match++;
                        }
                }
                return match;
        }
} hk;

int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int n , m;
        while( cin >> n >> m ) {
                memset( x , 0 , sizeof( x ) );
                memset( y , 0 , sizeof( y ) );
                for( int i = 1; i <= n; i++ ) {
                        string s;
                        cin >> s;
                        for( int j = 0; j < s.size(); j++ ) {
                                x[i][s[j] - 'a']++;
                        }
                }
                for( int i = 1; i <= m; i++ ) {
                        string s;
                        cin >> s;
                        for( int j = 0; j < s.size(); j++ ) {
                                y[i][s[j] - 'a']++;
                        }
                }
                hk.init( m , n );
                for( int i = 1; i <= n; i++ ) {
                        for( int j = 1; j <= m; j++ ) {
                                bool can = true;
                                for( int k = 0; k < 26; k++ ) {
                                        can &= ( x[i][k] >= y[j][k] );
                                }
                                if( can ) hk.add_edge( j , i );
                        }
                }
                cout << hk.maximum_match() << endl;
        }
        return 0;
}








