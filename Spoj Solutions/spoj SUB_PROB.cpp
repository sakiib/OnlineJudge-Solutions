#include <bits/stdc++.h>
using namespace std;

struct aho_corasick {
        struct node {
                int next[ 65 ];
                node( ) { memset( next , -1 , sizeof( next ) ); }
        };

        static const int N = 2005 * 1005; /// total length of patterns
        int sz , len , root;
        node tree[ N ];
        int suffix[ N ] , path[ N ] , ff[ N ] , ed[ N ];

        int getid( char ch ) {
                if( ch >= 'a' && ch <='z' ) return ( ch - 'a' + 1 );
                else if( ch >= 'A' && ch <= 'Z' ) return 26 + (ch - 'A' + 1);
                else return 52 + ( ch - '0' );
        }
        void initialize( ) {
                root = sz = len = 0;
                tree[root] = node( );
                for( int i = 0; i < N; i++ ) suffix[i] = ff[i] = 0;
        }
        void add( char *s , int idx ) {
                int cur = root , l = strlen( s );
                for( int i = 0; i < l; i++ ) {
                        int id = getid( s[i] );
                        if( tree[cur].next[id] == -1 ) {
                                tree[cur].next[id] = ++sz; tree[sz] = node( );
                        }
                        cur = tree[cur].next[id];
                }
                ed[idx] = cur;
        }
        void reverse_link( ) {
                queue <int> Q;
                for( int i = 1; i <= 62; i++ ) {
                        if( ~tree[root].next[i] ) Q.push( tree[root].next[i] );
                        else tree[root].next[i] = root;
                }
                while( !Q.empty() ) {
                        int u = Q.front(); Q.pop();
                        for( int i = 1; i <= 62; i++ ) {
                                int v = tree[u].next[i];
                                if( v == -1 ) {
                                        tree[u].next[i] = tree[suffix[u]].next[i];
                                        continue;
                                }
                                suffix[v] = tree[ suffix[u] ].next[i];
                                Q.push( v );
                                path[len++] = v;
                        }
                }
        }
        void calc( char *s ) {
                int cur = root , l = strlen( s );
                for( int i = 0; i < l; i++ ) {
                        int id = getid( s[i] );
                        cur = tree[cur].next[id];
                        ff[cur]++;
                }
                for( int i = len - 1; i >= 0; i-- ) {
                        ff[ suffix[ path[i] ] ] += ff[ path[i] ];
                }
        }
} aho;

int q;
char txt[ 100005 ] , pat[ 2005 ];

int main( ) {
        //freopen( "input.txt" , "r" , stdin );
        aho.initialize();
        scanf("%s",txt);
        scanf("%d",&q);
        for( int i = 1; i <= q; i++ ) {
                scanf("%s",pat);
                aho.add( pat, i );
        }
        aho.reverse_link();
        aho.calc( txt );
        for( int i = 1; i <= q; i++ ) {
                if( aho.ff[ aho.ed[i] ] ) puts("Y");
                else puts("N");
        }
        return 0;
}







