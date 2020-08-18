#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n ,q;
int a[ N ] , b[ N ];
map <int,int> M , Ans;

struct node {
        node *l , *r;
        int val;
        node( ) {
                l = nullptr , r = nullptr , val = 0;
        }
        node( node *l , node *r , int val ):l(l), r(r), val(val){}

} *root[ 10*N ];

typedef node* pnode;

void update( pnode &cur , pnode &prev , int b , int e , int pos , int v ) {
        if( pos > e || pos < b || b > e ) return;
        if( !cur ) cur = new node();
        if( pos == b && b == e ) {
                cur -> val += v;
                return;
        }
        int mid = ( b + e ) >> 1;
        update( )
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) {
                scanf("%d",&a[i]);
                M[ a[i] ];
        }
        int mx = 0;
        for( auto x : M ) {
                M[ x.first ] = ++mx;
                Ans[ mx ] = x.first;
        }
        root[0] = new node();
        for( int i = 1; i <= n; i++ ) {
                update( root[i] , root[i-1] , 1 , mx , M[a[i]] , +1 );
        }
        return 0;
}











