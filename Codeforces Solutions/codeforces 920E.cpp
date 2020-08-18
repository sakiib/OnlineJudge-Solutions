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
set <int> List;
set <int> S[ N ];
vector <int> ans;

int dfs( int s ) {
        int ret = 1;
        set <int> :: iterator it;
        for( it = List.begin(); it != List.end(); ) {
                int val = *it;
                if( S[s].count( val ) == 0 ) {
                        List.erase( val );
                        ret += dfs( val );
                        it = List.lower_bound( val );
                }
                else it++;
        }
        return ret;
}
int main( ) {
        IO;
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> n >> m;
        for( int i = 1; i <= m; i++ ) {
                int u , v;
                cin >> u >> v;
                S[u].insert( v );
                S[v].insert( u );
        }
        for( int i = 1; i <= n; i++ ) List.insert( i );
        while( !List.empty( ) ) {
                int x = *List.begin();
                List.erase( x );
                ans.push_back( dfs(x) );
        }
        cout << ans.size() - 1 << endl;
        return 0;
}







