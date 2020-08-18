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

struct Edge {
        int u , v , w;
        Edge(){}
        Edge( int u , int v , int w ):u(u),v(v),w(w){}
        bool operator <( const Edge &q ) const {
                return w < q.w;
        }
};

vector <Edge> V;
int par[ 500 ];

void Makeset( ) {
        for( int i = 1; i <= n; i++ ) par[i] = i;
}
int Find( int x ) {
        return par[x] == x ? x : par[x] = Find( par[x] );
}
void Union( int x , int y ) {
        int u = Find( x ) , v = Find( y );
        if( u != v ) par[u] = v;
}
int Kruskal( ) {
        Makeset();
        sort( V.begin() , V.end() );
        vector <Edge> temp;
        int cost = 0 , taken = 0;
        for( auto x : V ) {
                int u = x.u , v = x.v , w = x.w;
                if( Find( u ) != Find( v ) ) {
                        cost += w , Union( u , v ) , taken++;
                        temp.push_back( Edge( u , v , w ) );
                }
        }
        V = temp;
        if( taken == n - 1 ) return cost;
        else return -1;
}
int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&m);
                printf("Case %d:\n",tc);
                for( int i = 1; i <= m; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        V.push_back( Edge( u , v , w ) );
                        printf("%d\n",Kruskal());
                }
                V.clear();
        }
        return 0;
}








