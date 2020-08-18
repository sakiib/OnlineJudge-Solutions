#include <bits/stdc++.h>
using namespace std;

struct ARTICULATION_POINT_BRIDGE {
        static const int MAXN = 1e5 + 5;

        int Time , St[ MAXN ] , Low[ MAXN ];
        bool Vis[ MAXN ] , markBridge[ MAXN ];
        vector <int> graph[ MAXN ];
        vector < pair<int,int> > Bridge;
        set <int> Point;

        void Initilize( ) {
                Time = 0;
                Point.clear(); Bridge.clear();
                memset( St , 0 , sizeof( St ) );
                memset( Low , 0 , sizeof( Low ) );
                memset( Vis , false , sizeof( Vis ) );
                memset( markBridge , false , sizeof( markBridge ) );
                for( int i = 0; i < MAXN; i++ ) graph[ i ].clear();
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v ); graph[ v ].push_back( u );
        }
        void Tarjan( int s , int p = -1 ) {
                St[ s ] = Low[ s ] = ++Time; Vis[ s ] = true; int Child = 0;
                for( int i = 0; i < graph[ s ].size(); i++ ) {
                        int x = graph[ s ][ i ];
                        if( x == p ) continue;
                        if( Vis[ x ] ) Low[ s ] = min( Low[ s ] , St[ x ] );
                        else {
                                Tarjan( x , s );
                                Low[ s ] = min( Low[ s ] , Low[ x ] );
                                if( Low[ x ] >= St[ s ] && p != -1 ) {
                                        Point.insert( s );
                                }
                                if( Low[ x ] > St[ s ] ) {
                                        Bridge.push_back( make_pair(s,x) );
                                        markBridge[ x ] = true;
                                        markBridge[ s ] = true;
                                }
                                Child++;
                        }
                }
                if( p == -1 && Child > 1 ) Point.insert( s );
        }
} apb;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                apb.Initilize();
                int n , m;
                scanf("%d %d",&n,&m);
                for( int i = 1; i <= m; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        apb.AddEdge( u , v );
                }
                apb.Tarjan( 1 );
                printf("Case %d: %d\n",tc,apb.Point.size());
        }
        return 0;
}





