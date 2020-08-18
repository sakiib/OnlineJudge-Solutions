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

struct data {
        int node , w , len;
        data( ) {}
        data( int node , int w , int len ) : node(node) , w(w) , len(len) {}
        bool operator <( const data &q ) const {
                return w > q.w;
        }
};
int cost[ N ][ 2 ];
vector <pii> graph[ N ];

int dj( ) {
        for( int i = 1; i < N; i++ ) {
                for( int j = 0; j < 2; j++ ) {
                        cost[i][j] = inf;
                }
        }
        cost[1][0] = 0;
        priority_queue <data> Q;
        Q.push( data( 1 , 0 , 0 ) );
        while( !Q.empty() ) {
                data t = Q.top(); Q.pop();
                int node = t.node , w = t.w , len = t.len;
                for( auto x : graph[node] ) {
                        int ns = x.first , nc = x.second;
                        int curlen = len + 1;
                        if( cost[ns][curlen%2] == inf || cost[ns][curlen%2] > cost[node][len%2] + nc ) {
                                cost[ns][curlen%2] = cost[node][len%2] + nc;
                                Q.push( data( ns , cost[ns][curlen%2] , curlen%2 ) );
                        }
                }
        }
        return cost[n][0] == inf ? -1 : cost[n][0];
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        while( cin >> n >> m ) {
                for( int i = 1; i <= n; i++ ) graph[i].clear();
                for( int i = 1; i <= m; i++ ) {
                        int u , v , w;
                        cin >> u >> v >> w;
                        graph[u].push_back( { v , w } );
                        graph[v].push_back( { u , w } );
                }
                cout << dj() << endl;
        }
        return 0;
}








