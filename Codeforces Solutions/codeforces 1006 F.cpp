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

int n , m;
LL k;
int tot , half;
map <LL,LL> M[30][30];
LL a[30][30];
LL ans;

void yo( int x , int y , int mov , LL val ) {
        val ^= a[x][y];
        if( mov == half ) {
                M[x][y][val]++;
                return;
        }
        if( x+1 <= n ) yo( x+1 , y , mov+1 , val );
        if( y+1 <= m ) yo( x , y+1 , mov+1 , val );
}
void yoyo( int x , int y , int mov , LL val ) {
        if( mov == (tot-half) ) {
                ans += M[x][y][val^k];
                return;
        }
        if( x-1 >= 1 ) yoyo( x-1 , y , mov+1 , val^a[x][y] );
        if( y-1 >= 1 ) yoyo( x , y-1 , mov+1 , val^a[x][y] );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> m >> k;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= m; j++ ) {
                        cin >> a[i][j];
                }
        }
        tot = (n+m-2);
        half = tot/2;
        yo( 1 , 1 , 0  , 0 );
        yoyo( n , m , 0 , 0 );
        cout << ans << endl;
        return 0;
}





