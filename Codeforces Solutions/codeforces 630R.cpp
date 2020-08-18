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

int main( int argc, char const *argv[] ) {
    int n , a , b;
    cin >> n >> a >> b;
    bool f = false;
    if( a > b ) {
        bool f = true;
        swap( a , b );
    }
    int al = 0 , bo = 0;
    while( true ) {
        if( a+1 <= n && a+1 != b ) {
            a++;
        }
        else if( a-1 >= 1 ) {
            a--;
        }
        else {
            bo = 1;
            break;
        }
        if( b-1 >= 1 && b-1 != a ) {
            b--;
        }
        else if( b+1 <= n && b+1 != a ) {
            b++;
        }
        else {
            al = 1;
            break;
        }
    }
    if( f ) swap( al , bo );
    cout << ( al == 1 ? "Alice" : "Borys" )  << endl;
    return 0;
}

