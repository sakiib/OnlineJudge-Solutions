#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 3e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

int n , q;
int a[ N ] , mx[ 4*N ] , mn[ 4*N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                mx[node] = a[b];
                mn[node] = a[b];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r ,  m + 1 , e );
        mx[node] = max( mx[l] , mx[r] );
        mn[node] = min( mn[l] , mn[r] );
}

int res;
int done;

void go( int node , int b , int e , int val ) {
        if( b > e || mn[node] > val ) return;
        if( b == e ) {
                if( a[b] <= val ) res = max( res , a[b] );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( mn[l] <= val && mn[r] <= val ) {
                go( l , b , m , val );
                go( r , m + 1 , e , val );
        }
        else {
                if( mn[l] <= val ) go( l , b , m , val );
                if( mn[r] <= val ) go( r , m + 1 , e , val );
        }
}
void query( int node , int b , int e , int i , int j , int val ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                if( mn[node] > val ) {
                        return;
                }
                go( node , b , e , val );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        query( l , b , m , i , j , val );
        query( r , m + 1 , e , i , j , val );
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        build( 1 , 1 , n );
        while( q-- ) {
                int l , r , val;
                scanf("%d %d %d",&l,&r,&val);
                ++l , ++r;
                res = 0;
                done = 0;
                query( 1 , 1 , n , l , r , val );
                printf("%d\n",res);
        }
        return 0;
}

/**
9 8
1 5 9 11 9 7 6 2 1
1 6 4
1 6 10
0 8 97
0 8 4
1 4 5
2 6 8
2 8 5
3 3 12
*/












