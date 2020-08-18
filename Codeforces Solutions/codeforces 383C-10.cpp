#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n , q;
vector <int> graph[ N ];
int val[ N ];
int Time , st[ N ] , en[ N ];
int lvl[ N ];

struct SegmentTree {
        static const int sz = N;
        int Tree[ 4*sz ] , Lazy[ 4*sz ];
        int ara[ sz ];

        inline void Init( ) {
                memset( Tree , 0 , sizeof( Tree ) );
                memset( Lazy , 0 , sizeof( Lazy ) );
        }
        inline void LazyPropagate( int node , int b , int e ) {
                if( Lazy[ node ] != 0 ) {
                        Tree[node] += ( Lazy[ node ] * ( e-b+1 ) );
                        if( b != e ) {
                                Lazy[ 2*node ] += Lazy[ node ];
                                Lazy[ 2*node+1 ] += Lazy[ node ];
                        }
                        Lazy[ node ] = 0;
                }
        }
        inline void Build( int node , int b , int e ) {
                if( b > e ) return;
                if( b == e ) { Tree[ node ] = ara[ b ]; return; }
                int left = node << 1 , right = left | 1 , mid = ( b + e ) >> 1;
                Build( left , b , mid );
                Build( right , mid+1 , e );
                Tree[ node ] = Tree[ left ] + Tree[ right ];
        }
        inline void Update( int node , int b , int e , int i , int j , int val ) {
                LazyPropagate( node , b , e );
                if( i > e || j < b || b > e ) return;
                if( i <= b && j >= e ) {
                        Tree[ node ] += ( val * ( e-b+1 ) );
                        if( b != e ) {
                                Lazy[ 2*node ] += val;
                                Lazy[ 2*node+1 ] += val;
                        } return;
                }
                int left = node << 1 , right = left | 1 , mid = ( b + e ) >> 1;
                Update( left , b , mid , i , j , val );
                Update( right , mid+1 , e , i , j , val );
                Tree[ node ] = Tree[ left ] + Tree[ right ];
        }
        inline int Query( int node , int b , int e , int pos ) {
                LazyPropagate( node , b , e );
                if( b > e || pos > e || pos < b ) return 0;
                if( b == e && b == pos ) return Tree[ node ];
                int left = node << 1 , right = left | 1 , mid = ( b + e ) >> 1;
                int Q1 = Query( left , b , mid , pos );
                int Q2 = Query( right , mid+1 , e , pos );
                return ( Q1 + Q2 );
        }

} segtree;

void flat_it( int s , int p ) {
        st[s] = ++Time;
        lvl[s] = lvl[p] + 1;
        for( auto x : graph[s] ) if( x != p ) flat_it( x , s );
        en[s] = Time;
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&val[i]);
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                scanf("%d %d",&u,&v);
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        flat_it( 1 , 0 );
        while( q-- ) {
                int type;
                scanf("%d",&type);
                if( type == 1 ) {
                        int node , val;
                        scanf("%d %d",&node,&val);
                        if( lvl[node]&1 ) segtree.Update( 1 , 1 , Time , st[node] , en[node] , - val );
                        else segtree.Update( 1 , 1 , Time , st[node] , en[node] , + val );

                }
                else {
                        int node;
                        scanf("%d",&node);
                        int x = segtree.Query( 1 , 1 , Time , st[node] );
                        if( lvl[node]&1 ) printf("%d\n",val[node]-x);
                        else printf("%d\n",val[node]+x);
                }
        }
        return 0;
}






