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

LL l , sx , sy , ex , ey;
string str;
int ans = inf;

void solve( LL x , LL y , int c ) {
        cout <<x << " " <<y << " "<< c << endl;

        if( x == ex && y == ey ) {
            ans = min( ans , c );
            return;
        }
        if( c >= l ) return;
        int kx = 0 , ky = 0;
        if( str[c] == 'E' ) {
             kx = x+1;
             ky = y;
        }
        else if( str[c] == 'S' ) {
             kx = x;
             ky = y-1;
        }
        else if( str[c] == 'W' ) {
             kx = x-1;
             ky = y;
        }
        else {
             kx = x;
             ky = y+1;
        }
        solve( kx , ky , c+1 );
        solve( x , y , c+1 );
}
int main( int argc, char const *argv[] ) {
    cin >> l >> sx >> sy >> ex >> ey;
    cin >> str;
    solve( sx , sy , 0 );
    cout << ans << " " << -1 << endl;
    return 0;
}

