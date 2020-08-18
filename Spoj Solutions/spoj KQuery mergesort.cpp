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

const int sz = 30005;
int ara[ sz ];
vector <int> Tree[ 4*sz ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ){
        Tree[node].push_back( ara[b] );
        return;
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    merge( Tree[left].begin() , Tree[left].end() , Tree[right].begin() ,
          Tree[right].end() , back_inserter( Tree[node] ) );
}
int Query( int node , int b , int e , int i , int j , int val ) {
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) {
        int up = upper_bound(Tree[node].begin(),Tree[node].end(),val)-Tree[node].begin();
        return ( e-b+1-up );
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    return Query( left , b , mid , i , j , val )+Query( right , mid+1 , e , i , j , val );
}
int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) scanf("%d",&ara[i]);
    Build( 1 , 1 , n );
    int q;
    scanf("%d",&q);
    while( q-- ) {
        int l , r , val;
        scanf("%d %d %d",&l,&r,&val);
        printf("%d\n",Query( 1 , 1 , n , l , r , val ) );
    }
    return 0;
}

