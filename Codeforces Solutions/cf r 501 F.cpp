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

int rr , cc;
string s[ 1005 ];
bool used[ 1005 ][ 1005 ];

struct data {
        int a , b , c;
};

vector <data> V;

void go( int x , int y ) {
        int r = 0 , l = 0 , u = 0 , d = 0;
        for( int i = y+1; i < cc; i++ ) { /// r
                if( s[x][i] == '.' ) break;
                r++;
        }
        for( int i = y-1; i >= 0; i-- ) { /// l
                if( s[x][i] == '.' ) break;
                l++;
        }
        for( int i = x-1; i >= 0; i-- ) { /// u
                if( s[i][y] == '.' ) break;
                u++;
        }
        for( int i = x+1; i < rr; i++ ) { /// d
                if( s[i][y] == '.' ) break;
                d++;
        }
        int res = min( u , min( d , min( l , r ) ) );
        if( res <= 0 ) return;
        V.push_back( { x+1 , y+1 , res } );
        used[x][y] = true;

        int temp = res;

        for( int i = y+1; i < cc && temp > 0 ; i++ , temp-- ) { /// r
                used[x][i] = true;
        }
        temp = res;
        for( int i = y-1; i >= 0 && temp > 0; i-- , temp-- ) { /// l
                used[x][i] = true;
        }
        temp = res;
        for( int i = x-1; i >= 0 && temp > 0; i-- , temp-- ) { /// u
                used[i][y] = true;
        }
        temp = res;
        for( int i = x+1; i < rr && temp > 0; i++ , temp-- ) { /// d
                used[i][y] = true;
        }
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> rr >> cc;
        for( int i = 0; i < rr; i++ ) cin >> s[i];
        for( int i = 0; i < rr; i++ ) {
                for( int j = 0; j < cc; j++ ) {
                        if( s[i][j] == '*' ) go( i , j );
                }
        }
        for( int i = 0; i < rr; i++ ) {
                for( int j = 0; j < cc; j++ ) {
                        if( s[i][j] == '*' ) {
                                if( !used[i][j] ) return cout << -1 << endl,0;
                        }
                }
        }
        cout << V.size() << endl;
        for( auto x : V ) cout << x.a << " " << x.b << " " << x.c << endl;
        return 0;
}






