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

LL A[ N ] , B[ N ];

struct segment {
    LL a , b;
} Tree[ 4*N ];

void Build( LL node , LL b , LL e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node].a = A[b];
        Tree[node].b = B[b];
        return;
    }
    LL left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node].a = Tree[left].a | Tree[right].a;
    Tree[node].b = Tree[left].b | Tree[right].b;
}
LL Query( LL node , LL b , LL e , LL i , LL j , LL f) {
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) {
        if( f ) return Tree[node].a;
        else return Tree[node].b;
    }
    LL left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    LL q1 = Query( left , b , mid , i , j , f );
    LL q2 = Query( right , mid+1 , e , i , j , f );
    return ( q1 | q2 );
}
int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> A[i];
    }
    for( int i = 1; i <= n ; i++ ) {
        cin >> B[i];
    }
    Build( 1 , 1 , n );
    cout << Query( 1 , 1 , n , 1 , n , 0 )+ Query( 1 , 1 , n , 1 , n , 1 ) << endl;
    return 0;
}

