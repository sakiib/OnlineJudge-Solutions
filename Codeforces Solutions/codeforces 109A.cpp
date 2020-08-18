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
    int n;
    cin >> n;
    int mn = inf;
    int F = 0 , S = 0;
    for( int i = 0; i <= n; i++ ) {
        int s = i;
        int f = ( n-s*7)/4;
        if( f < 0 ) continue;
        if( s*7+f*4 == n ) {
            mn = min( mn , f+s );
            if( s+f == mn ) F = f , S = s;
        }
    }
    string ans = "";
    while( F-- ) ans += "4";
    while( S-- ) ans += "7";
    cout << ( mn == inf ? "-1" : ans ) <<endl;
    return 0;
}

