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

struct Point {
        int x , y;
        Point( ) {}
        Point( int x , int y ) : x(x) , y(y) {}
};
/// Line of form : ax + by + c = 0; ( Ray actually )
struct Line {
        int a , b , c;
        Line( ) {}
        Line( int a , int b , int c ) : a(a) , b(b) , c(c) {}
        int Orientation( Point p ) {
                LL val = 1LL * a * p.x + 1LL * b * p.y + c;
                if( val == 0 ) return 0; /// point p is coLinear
                if( val > 0 ) return 1; /// above the Line
                else return -1; ///below the line
        }
} L;
vector <Line > V;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        Point a , b;
        cin >> a.x >> a.y >> b.x >> b.y;
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                int a , b , c;
                cin >> a >>b >> c;
                V.push_back( Line( a , b , c ) );
        }
        int ans = 0;
        for( auto x : V ) {
                int X = x.Orientation( a );
                int Y = x.Orientation( b );
                if( X != Y ) ans++;
        }
        cout << ans << endl;
        return 0;
}











