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


void check1( int l, int w, int a, int b, int c, int d ) {
    if( max(a,c) <= l && (b+d) <= w ) {
        cout << "YES" << endl;
        exit(0);
    }
    else if( (a+c) <= l && ( max(b,d) <= w ) ) {
        cout << "YES" << endl;
        exit(0);
    }
    return;
}
void check2( int l, int w, int a, int b, int c, int d ) {
    if( (a+d) <= l && max(b,c) <= w ) {
        cout << "YES" << endl;
        exit(0);
    }
    return;
}
void check3( int l, int w, int a, int b, int c, int d ) {
    if( (b+d) <= l && ( max(a,c) <= w ) ) {
        cout << "YES" << endl;
        exit(0);
    }
    return;
}
void check4( int l, int w, int a, int b, int c, int d ) {
    if( (a+d) <= l && ( max(c,b) <= w ) ) {
        cout << "YES" << endl;
        exit(0);
    }
    return;
}
int main(int argc,char const *argv[]) {
    int l , w;
    int a , b , c , d;
    cin >> l >> w;
    cin >> a >> b;
    cin >> c >> d;
    if( w > l) swap( l , w );
    if( b > a ) swap( a , b );
    if( d > c ) swap( c , d );
    check1( l , w , a , b , c , d );
    check2( l , w , a , b , c , d );
    check3( l , w , a , b , c , d );
    check4( l , w , a , b , c , d );
    cout << "NO" << endl;
    return 0;
}
