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

char ara[ 25 ][ 25 ];
int r , c;
bool f;

void solve( int x , int y , int cnt ) {
    if( x < 0 || y < 0 || x >= r || y >= c ) return;
    if( cnt > 3 ) return;
    if( cnt == 3 && ara[x][y] == 'e' ) {
        f = true;
        return;
    }
    if( cnt == 2 && ara[x][y] != 'i' ) return;
    if( cnt == 2 && ara[x][y] == 'i' ) cnt++;

    solve( x+1 , y , cnt );
    solve( x-1 , y , cnt );
    solve( x , y+1 , cnt );
    solve( x , y-1 , cnt );
    solve( x+1 , y+1 , cnt );
    solve( x+1 , y-1 , cnt );
    solve( x-1 , y-1 , cnt );
    solve( x-1 , y+1 , cnt );
}
int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        cin >> r >> c;
        for( int i = 0; i < r; i++ ) {
            for( int j = 0; j < c; j++ ) {
                cin >> ara[i][j];
            }
        }
        f = false;
        for( int i = 0; i < r; i++ ) {
            for( int j = 0; j < c; j++ ) {
                if( ara[i][j] == 'p' ) {
                    solve( i , j , 1 );
                    if( f ) break;
                }
            }
        }
        if( f ) puts("Cutie Pie!");
        else puts("Sorry Man");
    }
    return 0;
}

