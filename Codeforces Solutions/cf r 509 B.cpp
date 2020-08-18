#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e3 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

struct data {
        int a , b , c;
        data(){}
        data( int a , int b , int c ) : a(a),b(b),c(c){}
};
vector <data> ans;
int n , m;
char s[ N ][ N ];
int up[ N ][ N ] , down[ N ][ N ] , lft[ N ][ N ] , rght[ N ][ N ];
int hor[ N ][ N ] , vert[ N ][ N ];
bool used[ N ][ N ];


void calc_up( ) {
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= m; j++ ) {
                        if( s[i][j] == '*' ) up[i][j] = up[i-1][j]+1;
                        else up[i][j] = 0;
                }
        }
}
void calc_down( ) {
        for( int i = n; i >= 1; i-- ) {
                for( int j = 1; j <= m; j++ ) {
                        if( s[i][j] == '*' ) down[i][j] = down[i+1][j]+1;
                        else down[i][j] = 0;
                }
        }
}
void calc_left( ) {
        for( int j = 1; j <= m; j++ ) {
                for( int i = 1; i <= n; i++ ) {
                        if( s[i][j] == '*' ) lft[i][j] = lft[i][j-1]+1;
                        else lft[i][j] = 0;
                }
        }
}
void calc_right( ) {
        for( int j = m; j >= 1; j-- ) {
                for( int i = 1; i <= n; i++ ) {
                        if( s[i][j] == '*' ) rght[i][j] = rght[i][j+1]+1;
                        else rght[i][j] = 0;
                }
        }
}
void process( ) {
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= m; j++ ) {
                       int v = min( up[i][j] , down[i][j] );
                       int h = min( lft[i][j] , rght[i][j] );
                       int cur = min( v , h );
                       cur--;
                       if( cur <= 0 ) continue;
                       vert[ i-cur ][ j ] += 1;
                       vert[ i+cur+1 ][ j ] -= 1;
                       hor[ i ][ j-cur ] += 1;
                       hor[ i ][ j+cur+1 ] -= 1;
                       ans.push_back( data( i, j, cur ) );
                }
        }
}
void check( ) {
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= m; j++ ) {
                        vert[i][j] += vert[i-1][j];
                        if( vert[i][j] > 0 ) used[i][j] = true;
                }
        }
        for( int j = 1; j <= m; j++ ) {
                for( int i = 1; i <= n; i++ ) {
                        hor[i][j] += hor[i][j-1];
                        if( hor[i][j] > 0 ) used[i][j] = true;
                }
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= m; j++ ) {
                        if( s[i][j] == '*' && !used[i][j] ) {
                                cout << -1 << endl;
                                exit(0);
                        }
                }
        }
}
int main( int argc , char const *argv[] ) {
        //ios_base :: sync_with_stdio(false); cin.tie(NULL);
        freopen( "TXT.txt" , "r" , stdin );
        freopen( "TXTout.txt" , "w" , stdout );
        cin >> n >> m;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= m; j++ ) {
                        cin >> s[i][j];
                }
        }
        calc_up( );
        calc_down( );
        calc_left( );
        calc_right( );
        process( );
        check( );
        cout << ans.size() << endl;
        for( auto x : ans ) cout << x.a << " " << x.b << " " << x.c << endl;
        return 0;
}






