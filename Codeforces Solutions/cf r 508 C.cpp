#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

struct DSU_ON_TREE {
        static const int MAXN = 1e5 + 5;
        typedef long long LL;

        int nodes;
        int SubTree[ MAXN ] , Color[ MAXN ] , Cnt[ MAXN ] , Level[ MAXN ];
        int Ans[ MAXN ] , MX , SUM;
        bool Heavy[ MAXN ];
        vector <int> graph[ MAXN ];
        vector < pair<int,int> > Query[ MAXN ];
        bool vis[ MAXN ];

        void Initialize( ) {
                memset( Cnt , 0 , sizeof( Cnt ) );
                memset( SubTree , 0 , sizeof( SubTree ) );
                for( int i = 0; i < MAXN; i++ ) graph[ i ].clear() , Query[i].clear();
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v ); graph[ v ].push_back( u );
        }
        void SubTreeSize( int s , int p , int lvl ) {
               SubTree[ s ] = 1;
               Level[ s ] = lvl;
               vis[ s ] = true;
               for( auto x : graph[ s ] ) {
                        if( x != p ) {
                                SubTreeSize( x , s , lvl+1 );
                                SubTree[ s ] += SubTree[ x ];
                        }
               }
        }
        void FindAns( int s ) {
                for( auto x : Query[ s ] ) {
                        int l = x.first , idx = x.second;
                        Ans[ idx ] = Cnt[ l ];
                }
        }

        void Add( int s , int p , int v ) {
                Cnt[ Level[s] ] += v;
                for( auto x : graph[ s ] ) if( x != p && !Heavy[ x ] ) Add( x , s , v );
        }
        void Remove( int s , int p , int v ) {
                Cnt[ Level[s] ] -= v;
                for( auto x : graph[ s ] ) if( x != p && !Heavy[ x ] ) Remove( x , s , v );
        }
        void DSU_DFS( int s , int p , bool keep ) {
                int mx = -1 , HeavyChild = -1;
                vis[ s ] = true;
                for( auto x : graph[ s ] ) {
                        if( x != p && SubTree[ x ] > mx ) {
                                mx = SubTree[ x ] , HeavyChild = x;
                        }
                }
                for( auto x : graph[ s ] ) {
                        if( x != p && x != HeavyChild ) DSU_DFS( x , s , false );
                }
                if( HeavyChild != -1 ) {
                        DSU_DFS( HeavyChild , s , true );
                        Heavy[ HeavyChild ] = true;
                }
                Add( s , p , +1 );
                FindAns( s );
                if( HeavyChild != -1 ) Heavy[ HeavyChild ] = false;
                if( !keep ) Remove( s , p , +1 );
        }

        int n , q;
        int par[ MAXN ][ 30 ];

        void Build_ST( ) {
                for( int i = 1; i <= 25; i++ ) {
                        for( int j = 1; j <= n; j++ ) {
                                if( !par[j][i-1] )
                                par[j][i] = par[ par[j][i-1] ][i-1];
                        }
                }
        }
        int KTH_parent( int v , int diff ) {
                for( int i = 25; i >= 0; i-- ) {
                        if( ( diff >> i )&1 ) v = par[v][i];
                }
                return v;
        }
        void solve( ) {
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) {
                        int x;
                        scanf("%d",&x);
                        par[i][0] = x;
                        if( x != 0 ) AddEdge( i , x );
                }
                Build_ST( );

                for( int i = 1; i <= n; i++ ) {
                        if( !vis[i] ) SubTreeSize( i , 0 , 0 );
                }
                scanf("%d",&q);
                for( int i = 1; i <= q; i++ ) {
                        int v , p;
                        scanf("%d %d",&v,&p);
                        int kth = KTH_parent( v , p );
                        if( kth <= 0 ) Ans[i] = 1;
                        else {
                                Query[ kth ].push_back( { Level[v] , i } );
                        }
                }
                memset( vis , false , sizeof(vis) );
                for( int i = 1; i <= n; i++ ) {
                        if( !vis[i] ) {
                                memset( Cnt , 0 , sizeof(Cnt) );
                                DSU_DFS( i , 0 , true );
                        }
                }
                for( int i = 1; i <= q; i++ ) printf("%d ",Ans[i]-1);
        }
} dsu;

int main( int argc , char const *argv[] ) {
        dsu.Initialize( );
        dsu.solve( );
        return 0;
}






