/**
 * Created by Sakib on 06/02/2018.
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

template < typename T >
using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const int N  = 100005;
orderset<int> V[ N ];
int n , q;

struct DSU {

    int Parent[ N ];

    inline void Makeset( int k ) {
        for( int i = 1; i <= k; i++ ) {
            Parent[ i ] = i;
        }
    }
    inline int Find( int x ) {
        if( Parent[ x ] == x ) return x;
        return Parent[ x ] = Find( Parent[ x ] );
    }
    inline void Union( int x , int y ) {
        int u = Find( x ) , v = Find( y );
        if(V[u].size() > V[v].size()) swap(u, v);
        if( u != v ){
           for( auto it : V[u] ) V[v].insert( it );
	       V[ u ].clear();
	       Parent[ u ] = v;
        }
    }
} dsu;

void solve( int x , int y ) {
    int u = dsu.Find( x );
    int v = dsu.Find( y );
    if( u != v ) {
       if( V[u].size() > V[v].size() ) swap( u , v );
       for( auto it : V[u] ) V[v].insert( it );
       V[ u ].clear();
       dsu.Union( x , y );
    }
}
int main( int argc, char const *argv[] ) {
    fast_io;
    int t;
    cin >> t;
    for( int tc = 1; tc <= t; tc++ ) {
        cin >> n >> q;

        dsu.Makeset( n );

        for( int i = 1; i <= n; i++ ) V[i].insert( i );

        cout << "Case " <<tc << ":\n";

        while( q-- ) {
            int op;
            cin >> op;
            if( op == 1 ) {
                int x , y;
                cin >> x >> y;
                dsu.Union( x , y );
            }
            else if( op == 2 ) {
                int x;
                cin >> x;
                int u = dsu.Find( x );
                int s = V[u].size();
                if( s%2 == 0 ) {
                    s /= 2;
                    int vala = *V[u].find_by_order( s-1 );
                    int valb = *V[u].find_by_order( s );
                    cout << vala+valb << endl;
                }
                else {
                    s /= 2;
                    int vala = *V[u].find_by_order( s );
                    cout << vala*2 << endl;
                }
            }
        }
        for( int i = 0; i < N; i++ ) V[i].clear();
    }
    return 0;
}
