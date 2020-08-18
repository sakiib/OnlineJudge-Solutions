#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using
Treap = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 2e4 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

LL a[ 3*N ] , Tree[ 3*4*N ];
int n , k;

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                Tree[node] = a[b];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m ) , build( r , m + 1 , e );
        Tree[node] = Tree[l] & Tree[r];
}
LL query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return ( 1LL << 31 ) - 1;
        if( i <= b && j >= e ) return Tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return query( l , b , m , i , j ) & query( r , m + 1 , e , i , j );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        //cout << bitset <31> ( (1LL << 31) - 1 ) << endl;
        int t;
        cin >> t;
        while( t-- ) {
                cin >> n >> k;
                k = min( n , k );
                for( int i = 1; i <= n; i++ ) cin >> a[i];
                for( int i = n + 1; i <= 2*n; i++ ) a[i] = a[i-n];
                for( int i = 2*n + 1; i <= 3*n; i++ ) a[i] = a[i-2*n];
                build( 1 , 1 , 3*n );
                for( int i = n+1; i <= 2*n; i++ ) {
                        if( i == n+1 ) {
                              cout << query( 1 , 1 , 3*n , max( 1 , i - k ) , min( 3*n , i + k ) );
                        }
                        else {
                              cout << " ";
                              cout << query( 1 , 1 , 3*n , max( 1 , i - k ) , min( 3*n , i + k ) );
                        }
                }
                cout << endl;
                memset( Tree , 0 , sizeof( Tree ) );
        }
        return 0;
}















