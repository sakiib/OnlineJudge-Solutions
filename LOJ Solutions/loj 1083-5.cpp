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

int ara[ N ] , Tree[ 4*N ];
int n;

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = b;
        return;
    }
    int left = 2*node; int right = 2*node+1; int mid = ( b+e )/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    if( ara[ Tree[left] ] < ara[ Tree[right] ] ) Tree[node] = Tree[left];
    else Tree[node] = Tree[right];
}
int Query( int node , int b , int e , int  i , int j ) {
    if( i > e || j < b ) return inf;
    if( i <= b && j >= e ) return Tree[node];
    int left = 2*node; int right = 2*node+1; int mid = ( b+e )/2;
    int q1 = Query( left , b , mid , i, j );
    int q2 = Query( right , mid+1 , e , i , j );
    if( q1 == inf ) return q2;
    if( q2 == inf ) return q1;
    if( ara[q1] < ara[q2] ) return q1;
    else return q2;
}
int get_ans( int b , int e ) {
    if( b > e ) return 0;
    if( b == e ) return ara[b];
    int idx = Query( 1 , 1 , n , b , e );
    int ans = max( get_ans( b , idx-1 ),max(get_ans( idx+1 , e ),( e-b+1 )*ara[idx] ));
    return ans;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
            scanf("%d",&ara[i]);
        }
        Build( 1 , 1 , n );
        int ans = get_ans( 1 , n );
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}

