#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

inline int In() {
	int x = 0,f = 1; char ch = getchar();
	for( ; ch<'0' || ch>'9' ; ch=getchar() ) if(ch=='-') f=-1;
	for( ; ch>='0' && ch<='9'; x=(x<<3)+(x<<1)+ch-'0', ch=getchar());
	return ( x*f );
}


int n , q , a[ 2*N ];
map <int,int> M;

struct query {
        int l , r , k;
        query(){
                l = 0 , r = 0 , k = 0;
        }
        query( int l , int r , int k ):l(l), r(r), k(l) {}
} Q[ 2*N ];

struct node {
        node *l , *r;
        int val;

        node( ) {
                l = nullptr , r = nullptr , val = 0;
        }
        node( node *l , node *r , int val ):l(l), r(r), val(val){}

        node* update( int b , int e , int pos , int v ) {
                if( b > e || pos > e || pos < b ) return this;
                if( b == e && b == pos ) {
                        node *ret = new node( l , r , val );
                        ret -> val += v;
                        return ret;
                }
                int mid = ( b + e ) >> 1;
                node *ret = new node();
                if( pos <= mid ) {
                        ret -> r = r;
                        ret -> l = l -> update( b , mid , pos , v );
                }
                else {
                        ret -> l = l;
                        ret -> r = r -> update( mid+1 , e , pos , v );
                }
                ret -> val = ( ret -> l -> val + ret -> r -> val );
                return ret;
        }

        int query( node *prev , int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return 0;
                if( i <= b && j >= e ) return val - prev -> val;
                int mid = ( b + e ) >> 1;
                int q1 = l -> query( prev -> l , b , mid , i , j );
                int q2 = r -> query( prev -> r , mid+1 , e , i , j );
                return q1 + q2;
        }

} *root[ 2*N ];


int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
                scanf("%d",&a[i]);
                M[ a[i] ];
        }
        scanf("%d",&q);
        for( int i = 1; i <= q; i++ ) {
                scanf("%d %d %d",&Q[i].l,&Q[i].r,&Q[i].k);
                M[ Q[i].k ];
        }

        int mx = 0;
        for( auto x : M ) M[ x.first ] = ++mx;
        //for( auto x : M ) cout << M[ x.first ] << " "; cout << endl;

        node *null = new node();
        null -> l = null -> r = null;
        root[0] = null;

        for( int i = 1; i <= n; i++ ) {
                root[i] = root[i-1] -> update( 1 , mx , M[ a[i] ] , +1 );
        }
        for( int i = 1; i <= q; i++ ) {
                int l = Q[i].l , r = Q[i].r , k = Q[i].k;
                //cout <<"Q : "<< l << " " << r << " " << k << endl;
                int ans = root[r] -> query( root[l-1] , 1 , mx , M[k]+1 , mx );
                printf("%d\n",ans);
        }
        return 0;
}






