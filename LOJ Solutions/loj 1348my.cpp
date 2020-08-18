#include <bits/stdc++.h>
using namespace std;

struct HeavyLightDecomposition {
        static const int N = 3e4 + 5;
        static const int lgN = 20;
        int n , Node;
        int cost[ N ];
        int A[ N ] , sub[ N ] , par[ N ] , depth[ N ];
        int chainNo , chainInd[ N ] , chainHead[ N ] , posInTree[ N ];
        vector <int> graph[ N ];
        int tree[ 4 * N ];
        void initialize( int _n ) {
                n = _n;
                memset( tree , 0 , sizeof(tree) );
                chainNo = 0 , Node = 1;
                for( int i = 0; i < N; i++ ) {
                        graph[i].clear();
                        A[i] = 0 , sub[i] = 0 , cost[i] = 0;
                        chainInd[i] = 0 , chainHead[i] = -1 , posInTree[i] = 0;
                }
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v ) , graph[ v ].push_back( u );
        }
        void dfs( int s , int p ) {
                par[s] = p;
                sub[s] = 1;
                depth[s] = depth[p] + 1;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p ) {
                                dfs( v , s );
                                sub[s] += sub[v];
                        }
                }
        }
        void HLD( int s , int p ) {
                if( chainHead[ chainNo ] == -1 ) chainHead[ chainNo ] = s;
                chainInd[ s ] = chainNo;
                posInTree[ s ] = Node;
                A[ Node++ ] = cost[ s ];
                int mxChild = -1;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p ) {
                                if( mxChild == -1 || sub[ mxChild ] < sub[ v ] ) {
                                        mxChild = v;
                                }
                        }
                }
                if( mxChild != -1 ) HLD( mxChild , s );
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p && v != mxChild ) {
                                chainNo++;
                                HLD( v , s );
                        }
                }
        }
        int LCA( int u , int v ) {
                while( 1 ) {
                        int pu = chainHead[ chainInd[u] ] , pv = chainHead[ chainInd[v] ];
                        if( pu == pv ) return ( depth[ u ] < depth[ v ] ? u : v );
                        if( depth[ pu ] < depth[ pv ] ) v = par[ pv ];
                        else u = par[ pu ];
                }
        }
        void Build( int node , int b , int e ) {
                if( b > e ) return;
                if( b == e ) {
                        tree[ node ] = A[ b ]; return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                Build( l , b , m );
                Build( r , m+1 , e );
                tree[ node ] = tree[ l ] + tree[ r ];
        }
        int Query( int node , int b , int e , int i , int j ) {
                if( b > e || i > e || j < b ) return 0;
                if( i <= b && j >= e ) return tree[ node ];
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                int q1 = Query( l , b , m , i , j );
                int q2 = Query( r , m+1 , e , i , j );
                return q1 + q2;
        }
        void Update( int node , int b , int e , int pos , int v ) {
                if( b > e || pos > e || pos < b ) return;
                if( b == e && b == pos ) {
                        tree[ node ] = v; return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                Update( l , b , m , pos , v );
                Update( r , m+1 , e , pos , v );
                tree[ node ] = tree[ l ] + tree[ r ];
        }
        void UpdateHLD( int pos , int v ) {
                Update( 1 , 1 , Node , posInTree[ pos ] , v );
        }
        int QueryUP( int u , int v ) {
                if( u == v ) return Query( 1 , 1 , Node , posInTree[ u ] , posInTree[ u ] );
                int uchain , vchain = chainInd[ v ];
                int ans = 0;
                while( 1 ) {
                        uchain = chainInd[ u ];
                        if( uchain == vchain ) {
                                int st = posInTree[ v ] , en = posInTree[ u ];
                                int ret = Query( 1 , 1 , Node , st , en );
                                ans = ans + ret;
                                break;
                        }
                        int st = posInTree[ chainHead[ uchain ] ] , en = posInTree[ u ];
                        int ret = Query( 1 , 1 , Node , st , en );
                        ans = ans + ret;
                        u = chainHead[ uchain ] , u = par[ u ];
                }
                return ans;
        }
        int QueryHLD( int u , int v ) {
                int lca = LCA( u , v );
                int x = QueryUP( u , lca ), y = QueryUP( v , lca ), z = QueryUP( lca , lca );
                return ( x + y - z );
        }

} hld;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n;
                scanf("%d",&n);
                hld.initialize( n );
                for( int i = 1; i <= n; i++ ) scanf("%d",&hld.cost[i] );
                for( int i = 1; i <= n-1; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        hld.AddEdge( ++u , ++v );
                }

                hld.dfs( 1 , 0 );
                hld.HLD( 1 , 0 );
                hld.Build( 1 , 1 , hld.Node );

                printf("Case %d:\n",tc);
                int q;
                scanf("%d",&q);
                for( int i = 1; i <= q; i++ ) {
                        int op;
                        scanf("%d",&op);
                        if( op == 0 ) {
                                int u , v;
                                scanf("%d %d",&u,&v);
                                printf("%d\n",hld.QueryHLD( ++u , ++v ) );
                        }
                        else {
                                int pos , val;
                                scanf("%d %d",&pos,&val);
                                hld.UpdateHLD( ++pos , val );
                        }
                }
        }
        return 0;
}
