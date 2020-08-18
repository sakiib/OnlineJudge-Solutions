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

int n , q;
int a[ N ];
vector <int> V;
int id , idx[ N ];

struct Node {
        int val;
        Node *l , *r;
        Node(){}
        Node( Node *l , Node *r , int val ):l(l),r(r),val(val){}
} *Version[ N ];

void Build( Node* node , int b , int e ) {
        //cout << "Building" << endl;
        if( b > e ) return;
        if( b == e ) {
                node -> l = NULL , node -> r = NULL , node -> val = 0;
                return;
        }
        int mid = ( b + e ) >> 1;
        node -> l = new Node( NULL , NULL , 0 ) , node -> r = new Node( NULL , NULL , 0 );
        Build( node -> l , b , mid ) , Build( node -> r , mid+1 , e );
}
void update( Node *prev , Node *cur , int b , int e , int pos , int v ) {
        if( b > e || pos > e || pos < b ) return;
        if( b == e && b == pos ) {
                cur -> val += v;
                return;
        }
        int m = ( b + e ) >> 1;
        if( pos <= m ) {
                cur -> r = prev -> r;
                cur -> l = new Node( NULL , NULL , 0 );
                update( prev -> l , cur -> l , b , m , pos , v );
        }
        else {
                cur -> l = prev -> l;
                cur -> r = new Node( NULL , NULL , 0 );
                update( prev -> r , cur -> r , m+1 , e , pos , v );
        }
        cur -> val = ( cur -> l -> val + cur -> r -> val );
}
int query( Node *prev , Node *cur , int b , int e , int k ) {
        if( b > e || k > e || k < b ) return 0;
        if( b == e ) return b;
        int m = ( b + e ) >> 1;
        int tot = cur -> l -> val - prev -> l -> val;
        cout << "tot : " << tot << endl;
        if( k <= tot ) return query( prev -> l , cur -> l , b , m , k );
        else return query( prev -> r , cur -> r  , m+1 , e , k - tot );
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]) , V.push_back( a[i] );

        //sort( V.begin() , V.end() );
        //for( auto x : V ) idx[ x ] = ++id;

        Node *root = new Node( NULL , NULL , 0 );
        Build( root , 1 , n );
        Version[0] = root;

        for( int i = 1; i <= n; i++ ) {
                //a[i] = idx[ a[i] ];
                Version[ i ] = new Node( NULL , NULL , 0 );
                update( Version[ i-1 ] , Version[ i ] , 1 , n , a[i] , +1 );
                //cout << "Done : " << i << endl;
        }

        while( q-- ) {
                int l , r , k;
                scanf("%d %d %d",&l,&r,&k);
                int x = query( Version[ l-1 ] , Version[ r ] , 1 , n , k );
                cout << "X : " << x << endl;
                //printf("ans  = %d\n",V[x-1]);
        }
        return 0;
}






