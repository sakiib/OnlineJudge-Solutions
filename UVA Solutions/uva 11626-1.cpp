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

struct point {
        LL x , y;
        point( ) { }
        point( LL _x , LL _y ) { x = _x , y = _y; }
        point operator + ( const point p ) { return point( x + p.x , y + p.y ); }
        point operator - ( const point p ) { return point( x - p.x , y - p.y ); }
        point operator * ( LL k ) { return point( x * k , y * k ); }
        point operator / ( LL k ) { return point( x / k , y / k ); }
        LL dot( const point p ) { return ( x * p.x + y * p.y ); }
        LL cross( const point p ) { return ( x * p.y - y * p.x ); }

} P;

int n;
point p[ N ];

bool cmp( point a , point b ) {
        return ( a - p[1] ).cross( b - p[1] ) >= 0;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%d",&n);
                int idx = 0;
                for( int i = 1; i <= n; i++ ) {
                        LL x , y;
                        char s[10];
                        scanf("%lld %lld %s",&x,&y,s);
                        if( s[0] == 'Y' ) p[++idx] = point( x , y );
                }
                sort( p+1 , p+idx+1 , cmp );
                printf("%d\n",idx);
                for( int i = 1; i <= idx; i++ )  {
                        printf("%lld %lld\n",p[i].x,p[i].y);
                }
        }
        return 0;
}
