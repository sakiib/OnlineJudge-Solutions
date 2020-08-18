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
typedef pair <LL,LL> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 5e4 + 5;

int n , m , st , en;
LL p;
int u[ N ] , v[ N ];
LL w[ N ];
vector <pii> graph[ N ] , rgraph[ N ];
LL d1[ N ] , d2[ N ];

void dj1( int s ) {
        priority_queue <pii, vector <pii>, greater <pii> > Q;
        for( int i = 1; i <= n; i++ ) d1[i] = INF;
        d1[s] = 0;
        Q.push( pii( 0 , s ) );
        while( !Q.empty() ) {
                pii t = Q.top(); Q.pop();
                int ps = t.second;
                LL pc = t.first;
                for( int i = 0; i < graph[ps].size(); i++ ) {
                        pii nxt = graph[ps][i];
                        int ns = nxt.first;
                        LL nc = nxt.second;
                        if( d1[ns] == INF || d1[ns] > d1[ps] + nc ) {
                                d1[ns] = d1[ps] + nc;
                                Q.push( { d1[ns] , ns } );
                        }
                }
        }
}
void dj2( int s ) {
        priority_queue <pii, vector <pii>, greater <pii> > Q;
        for( int i = 1; i <= n; i++ ) d2[i] = INF;
        d2[s] = 0;
        Q.push( pii( 0 , s ) );
        while( !Q.empty() ) {
                pii t = Q.top(); Q.pop();
                int ps = t.second;
                LL pc = t.first;
                for( int i = 0; i < rgraph[ps].size(); i++ ) {
                        pii nxt = rgraph[ps][i];
                        int ns = nxt.first;
                        LL nc = nxt.second;
                        if( d2[ns] == INF || d2[ns] > d2[ps] + nc ) {
                                d2[ns] = d2[ps] + nc;
                                Q.push( { d2[ns] , ns } );
                        }
                }
        }
}
int main( ) {
        #ifdef LOCAL
            // freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d %d %d %lld",&n,&m,&st,&en,&p);
                for( int i = 1; i <= n; i++ ) graph[i].clear(), rgraph[i].clear();
                for( int i = 1; i <= m; i++ ) {
                        scanf("%d %d %lld",&u[i],&v[i],&w[i]);
                        graph[ u[i] ].push_back( { v[i],w[i] } );
                        rgraph[ v[i] ].push_back( { u[i],w[i] } );
                }
                dj1( st );
                dj2( en );
                LL mx = -1;
                for( int i = 1; i <= m; i++ ) {
                        //trace( d1[u[i]] , w[i] , d2[v[i]] );
                        if( d1[ u[i] ] + w[i] + d2[ v[i] ] <= p ) {
                                mx = max( mx , w[i] );
                        }
                }
                printf("Case %d: %lld\n",tc,mx);
        }
        return 0;
}








