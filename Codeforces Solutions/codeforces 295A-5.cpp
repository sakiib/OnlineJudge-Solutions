#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

LL n , m , k;
LL ara[ N ] , add[ N ] , Tree[ 4*N ] , Lazy[ 4*N ];

struct query {
    int l , r;
    LL val;
} Q[ N ];

void Propagate( int node , int b , int e ) {
    if( Lazy[node] != 0 ) {
        Tree[node] += ( Lazy[node]*(e-b+1) );
        if( b != e ) {
            Lazy[2*node] += Lazy[node];
            Lazy[2*node+1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}
void Update( int node , int b , int e , int i , int j , LL val ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return;
    if( i <= b && j >= e ) {
        Tree[node] += val;
        if( b != e ) {
            Lazy[2*node] += val;
            Lazy[2*node+1] += val;
        }
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Update( left , b , mid , i , j , val );
    Update( right , mid+1 , e , i , j , val );
    Tree[node] = Tree[left] + Tree[right];
}
LL Query( int node , int b , int e , int pos ) {
    Propagate( node , b , e );
    if( pos > e || pos < b ) return 0;
    if( b == e && b == pos ) return Tree[node];
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    LL q1 = Query( left , b , mid , pos );
    LL q2 = Query( right , mid+1 , e , pos );
    return q1+q2;
}
int main( int argc, char const *argv[] ) {
    cin >> n >> m >> k;
    for( int i = 1; i <= n; i++ ) cin >> ara[i];
    for( int i = 1; i <= m; i++ ) {
        cin >> Q[i].l >> Q[i].r >> Q[i].val;
    }
    for( int i = 1; i <= k; i++ ) {
        int x , y;
        cin >> x >> y;
        add[y+1] -- , add[x]++;
    }
    for( int i = 1; i <= N; i++ ) {
        add[i] += add[i-1];
    }
    for( int i = 1; i <= m; i++ ) {
        LL tot = Q[i].val*add[i];
        Update( 1 , 1 , n , Q[i].l , Q[i].r , tot );
    }
    for( int i = 1; i <= n; i++ ) {
        cout << Query( 1 , 1 , n , i ) + ara[i] << " ";
    }
    return 0;
}

