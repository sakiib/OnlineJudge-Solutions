#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e3 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , m , q;

struct node {
        node *l , *r;
        int val;
        int lazy;
        node( ) {
                l = nullptr , r = nullptr;
                val = 0 , lazy = 0;
        }
        node( node *_l , node *_r , int _val , int _lazy ) {
                l = _l , r = _r , val = _val , lazy = _lazy;
        }
        typedef node* pnode;

        pnode pushdown( int b , int e ) {
                //if( lazy == 0 ) return this;
                pnode ret = new node( l , r , val , lazy );
                ret -> lazy ^= 1;
                ret -> val = ( e - b + 1 ) - ret -> val;
                lazy = 0;
                return ret;
        }
        void build( int b , int e ) {
                if( b > e ) return;
                if( b == e ) return;
                int m = ( b + e ) >> 1;
                l = new node();
                r = new node();
                l -> build( b , m );
                r -> build( m + 1 , e );
                val = l -> val + r -> val;
        }
        pnode update( int b , int e , int pos , int stat ) {
                if( pos > e || pos < b || b > e ) return this;
                if( b == e && b == pos ) {
                        pnode ret = new node( l , r , val , lazy );
                        ret -> val = stat;
                        return ret;
                }
                int m = ( b + e ) >> 1;
                if( !l ) l = new node();
                if( !r ) r = new node();
                pnode ret = new node();
                if( lazy ) {
                        ret -> l = l -> pushdown( b , m );
                        ret -> r = r -> pushdown( m + 1 , e );
                }
                ret -> l = l -> update( b , m , pos , stat );
                ret -> r = r -> update( m + 1 , e , pos , stat );
                if( ret -> l ) ret -> val += ret -> l -> val;
                if( ret -> r ) ret -> val += ret -> r -> val;
                return ret;
        }
        pnode Invert( int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return this;
                if( i <= b && j >= e ) {
                        pnode ret = new node( l , r , val , lazy );
                        ret -> val = ( e - b + 1 ) -  val;
                        ret -> lazy ^= 1;
                        return ret;
                }
                int m = ( b + e ) >> 1;
                if( !l ) l = new node();
                if( !r ) r = new node();
                pnode ret = new node();
                if( lazy ) {
                        ret -> l = l -> pushdown( b , m );
                        ret -> r = r -> pushdown( m + 1 , e );
                }
                ret -> l = l -> Invert( b , m , i , j );
                ret -> r = r -> Invert( m + 1 , e , i , j );
                if( ret -> l ) ret -> val += ret -> l -> val;
                if( ret -> r ) ret -> val += ret -> r -> val;
                return ret;
        }
        pnode Query( int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return this;
                if( i <= b && j >= e ) return this;
                int m = ( b + e ) >> 1;
                if( !l ) l = new node();
                if( !r ) r = new node();
                pnode ret = new node();
                if( lazy ) {
                        ret -> l = l -> pushdown( b , m );
                        ret -> r = r -> pushdown( m + 1 , e );
                }
                ret -> l = l -> Query( b , m , i , j );
                ret -> r = r -> Query( m + 1 , e , i , j );
                if( ret -> l ) ret -> val += ret -> l -> val;
                if( ret -> r ) ret -> val += ret -> r -> val;
                return ret;
        }

} *root[ 10*N*N ];

int main( int argc , char const *argv[] ) {
        scanf("%d %d %d",&n,&m,&q);
        root[0] = new node();
        for( int i = 1; i <= q; i++ ) {
                int type;
                scanf("%d",&type);
                if( type == 1 ) {
                        int shelf , pos;
                        scanf("%d %d",&shelf,&pos);
                        root[i] = root[i-1] -> update( 1 , n*m , (shelf-1)*m+pos , 1 );
                }
                else if( type == 2 ) {
                        int shelf , pos;
                        scanf("%d %d",&shelf,&pos);
                        root[i] = root[i-1] -> update( 1 , n*m , (shelf-1)*m+pos , 0 );
                }
                else if( type == 3 ) {
                        int shelf;
                        scanf("%d",&shelf);
                        root[i] = root[i-1] -> Invert( 1 , n*m , (shelf-1)*m+1 , shelf*m );
                }
                else if( type == 4 ) {
                        int pos;
                        scanf("%d",&pos);
                        root[i] = root[pos];
                }
                printf("%d\n", root[i] -> Query( 1 , n*m , 1 , n*m ) -> val);
        }
        return 0;
}







