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

int n;
vector <int> graph[ N ];
LL found , ans;

void dfs( int s , int p ) {
        found++;
        for( int i = 0; i < graph[s].size(); i++ ) {
                int nxt = graph[s][i];
                if( nxt != p ) dfs( nxt , s );
        }
        ans += ( n - found );
}
int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) graph[i].clear();
                for( int i = 1; i <= n - 1; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        graph[u].push_back( v );
                        graph[v].push_back( u );
                }
                printf("Case %d: ",tc);
                found = 0;
                ans = 0;
                dfs( 1 , 0 );
                printf("%d %lld\n",n - 1 , ans);
        }
        return 0;
}








