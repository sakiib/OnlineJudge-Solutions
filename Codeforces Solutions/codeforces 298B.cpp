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

int l , sx , sy , ex , ey;
string str;

int dist( int ax , int ay , int bx , int by ) {
    return abs(ax-bx)+abs(ay-by);
}
int main( int argc, char const *argv[] ) {
    cin >> l >> sx >> sy >> ex >> ey;
    cin >> str;
    int prev = dist( sx , sy , ex , ey );
    for( int i = 0; i < l; i++ ) {
        if( str[i] == 'E' ) {
            int kx = sx+1;
            int ky = sy;
            if( dist( kx , ky , ex , ey ) > prev ) continue;
            else sx = kx , sy = ky , prev = dist( kx , ky , ex , ey );
        }
        else if( str[i] == 'S' ) {
            int kx = sx;
            int ky = sy-1;
            if( dist( kx , ky , ex , ey ) > prev ) continue;
            else sx = kx , sy = ky , prev = dist( kx , ky , ex , ey );
        }
        else if( str[i] == 'W' ) {
            int kx = sx-1;
            int ky = sy;
            if( dist( kx , ky , ex , ey ) > prev ) continue;
            else sx = kx , sy = ky , prev = dist( kx , ky , ex , ey );
        }
        else {
            int kx = sx;
            int ky = sy+1;
            if( dist( kx , ky , ex , ey ) > prev ) continue;
            else sx = kx , sy = ky , prev = dist( kx , ky , ex , ey );
        }
        if( sx == ex && sy == ey ) {
            cout << i+1 <<endl;
            return 0;
        }
    }
    cout << -1 <<endl;
    return 0;
}

