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

bool ok( int val ) {
    while( val ) {
        int r = val%10;
        if( r == 7 ) return true;
        val /= 10;
    }
    return false;
}
bool check( int t ) {
    int hh = t/60;
    int mm = t%60;
    if( ok(hh) || ok(mm) ) return true;
    else return false;
}
int main( int argc, char const *argv[] ) {
    int x , h , m;
    cin >> x >> h >> m;
    if( ok(h) || ok(m) ) {
        cout << 0 << endl;
        return 0;
    }

    while( true ) {
        m -= x;
        cnt++;
        if( m < 0 )
    }
    return 0;
}
