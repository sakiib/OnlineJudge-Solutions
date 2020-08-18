#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const LL MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

LL ara[ N ] , Tree[ 4*N ] , Lazy[ 4*N ];
string str;

void Build( LL node , LL b , LL e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = ara[b]%MOD;
        return;
    }
    LL left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = ( Tree[left]%MOD + Tree[right]%MOD )%MOD;
}
void Propagate( LL node , LL b , LL e ) {
    if( Lazy[node] != -1 ) {
        Tree[node] = Lazy[node];
        if( b != e ) {
            Lazy[2*node] = Lazy[node];
            Lazy[2*node+1] = Lazy[node];
        }
        Lazy[node] = -1;
    }
}
void Update( LL node , LL b , LL e , LL i , LL j , LL val ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return;
    if( i <= b && j >= e ) {
        Tree[node] = val%MOD;
        if( b != e ) {
            Lazy[2*node] = val;
            Lazy[2*node+1] = val;
        }
        return;
    }
    LL left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Update( left , b , mid , i , j , val );
    Update( right , mid+1 , e , i , j , val );
    Tree[node] = ( Tree[left]%MOD + Tree[right]%MOD )%MOD;
}
LL Query( LL node , LL b , LL e , LL i , LL j , LL k ) {

}
int main( int argc, char const *argv[] ) {
    LL n , q;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    Build( 1 , 1 , n );
    memset( Lazy , -1 , sizeof( Lazy ) );
    while( q-- ) {
        cin >> str;
        if( str[0] == '=' ) {
            LL l , r , val;
            cin >> l >> r >> val;
            Update( 1 , 1 , n , l , r , val );
        }
        else {
            LL l , r , k;
            cin >> l >> r >> k;
            LL ans = Query( 1 , 1 , n , l , r , k );
            cout << ans << endl;
        }
    }
    return 0;
}

