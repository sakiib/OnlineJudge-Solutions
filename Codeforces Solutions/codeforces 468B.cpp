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

int a[ N ] , p[ N ] , ans[ N ];
map <int,int> M;
int used[ N ];

int Find( int x ) {
        return ( p[x] == x ? x : p[x] = Find( p[x] ) );
}
void Union( int x , int y ) {
        if( Find( x ) != Find( y ) ) {
                p[ Find(x) ] = Find( y );
        }
}
int main( int argc , char const *argv[] ) {
        int n , A , B;
        scanf("%d %d %d",&n,&A,&B);
        for( int i = 1; i <= n; i++ ) {
                scanf("%d",&a[i]);
                M[ a[i] ] = i , p[i] = i;
        }
        for( int i = 1; i <= n; i++ ) {
                if( M[ B - a[i] ] && M[ A - a[i] ] ) return printf("NO"),0;
                if( M[ B - a[i] ] ) {
                        Union( M[ B-a[i] ] , M[ a[i] ] );
                }
                if( M[ A - a[i] ] ) {
                        Union( M[ A-a[i] ] , M[ a[i] ] );
                }
        }
        int id = -1;
        for( int i = 1; i <= n; i++ ) {
                if( !used[ Find(i) ] ) used[ Find(i) ] = true , ans[ i ]  = ++id;
                else ans[ i ] = id;
        }
        if( id > 1 ) return printf("NO\n"),0;
        printf("YES\n");
        for( int i = 1; i <= n; i++ ) printf("%d ",ans[ i ] );
        return 0;
}






