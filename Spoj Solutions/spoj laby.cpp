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
const int N = 1e3 + 5;

const int dx[] = { 1 , -1 , 0 , 0 };
const int dy[] = { 0 , 0 , 1 , -1 };

int r , c;
string s[ N ];
int ID[ N ][ N ];
vector <int> graph[ N * N ];
int dist[ N * N ];
bool vis[ N * N ];

bool valid( int nx , int ny ) {
        return nx >= 0 && ny >= 0 && nx < r && ny < c && s[nx][ny] == '.';
}
pair <int,int> dia( int s ) {
        memset( dist , -1 , sizeof(dist) );
        queue <int> Q;
        dist[s] = 0;
        Q.push( s );
        int mx_dist = 0 , last = 0;
        while( !Q.empty() ) {
                int f = Q.front(); Q.pop();
                vis[f] = true;
                for( auto x : graph[f] ) {
                        if( dist[x] == -1 || dist[x] > dist[f] + 1 ) {
                                dist[x] = dist[f] + 1;
                                if( dist[x] > mx_dist ) {
                                        mx_dist = dist[x];
                                        last = x;
                                }
                                Q.push( x );
                        }
                }
        }
        return make_pair( last , mx_dist );
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int t;
        cin >> t;
        while( t-- ) {
                cin >> r >> c;
                for( int i = 0; i < r; i++ ) cin >> s[i];
                for( int i = 0; i < N * N; i++ ) graph[i].clear(), vis[i] = false;
                int id = 0;
                for( int i = 0; i < r; i++ ) {
                        for( int j = 0; j < c; j++ ) {
                                if( s[i][j] == '.' ) {
                                        ID[i][j] = ++id;
                                }
                        }
                }
                for( int i = 0; i < r; i++ ) {
                        for( int j = 0; j < c; j++ ) {
                                if( s[i][j] == '#' ) continue;
                                for( int k = 0; k < 4; k++ ) {
                                        int x = i + dx[k];
                                        int y = j + dy[k];
                                        if( valid( x , y ) ) {
                                                 //trace( ID[i][j] , ID[x][y] );
                                                 graph[ ID[i][j] ].push_back( ID[x][y] );
                                                 graph[ ID[x][y] ].push_back( ID[i][j] );
                                        }
                                }
                        }
                }
                int mx = 0;
                for( int i = 0; i < r; i++ ) {
                        for( int j = 0; j < c; j++ ) {
                                if( s[i][j] == '#' ) continue;
                                if( vis[ ID[i][j] ] ) continue;
                                pair <int,int> p = dia( ID[i][j] );
                                int x = p.first;
                                pair <int,int> q = dia( p.first );
                                int y = q.first;
                                mx = max( mx , q.second );
                        }
                }
                assert( mx != -1 );
                cout << "Maximum rope length is " << mx << "." << endl;
        }
        return 0;
}








