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

LL A[ N ] , B[ N ] , ATree[ 4*N ] , BTree[ 4*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        ATree[node] = A[b];
        BTree[node] = B[b];
        return;
    }
    int left = 2*node; int right = 2*node+1; int mid=(b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    ATree[node] = ATree[left] + ATree[right];
    BTree[node] = BTree[left] + BTree[right];
}
LL Query( int node , int b , int e , int i , int j , int f ) {
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) {
        if( !f ) return ATree[node];
        else return BTree[node];
    }
    int left = 2*node; int right = 2*node+1; int mid=(b+e)/2;
    LL q1 = Query( left , b , mid , i , j , f );
    LL q2 = Query( right , mid+1 , e , i, j , f );
    return (q1+q2);
}
int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort( B+1 , B+n+1 );
    Build( 1 , 1 , n );
    int q;
    cin >> q;
    while( q-- ) {
        int op , l , r;
        cin >> op >> l >> r;
        if( op == 1 ) cout << Query( 1 , 1 , n , l , r , 0 ) << endl;
        else cout << Query( 1 , 1 , n , l , r , 1 ) << endl;
    }
    return 0;
}

