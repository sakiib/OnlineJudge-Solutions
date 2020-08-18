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
    int x = 0 , y = 0;
    bool f = true;
    for( int i = 1; i <= n; i++ ) {
        int t , a , b;
        cin >> t >> a >> b;
        int d = abs(a-x)+abs(b-y);
        if( d <= t && (d%2 == t%2) ) continue;
        else f = false;
        x = a , y = b;
    }
    if( f ) puts("Yes");
    else puts("No");
    return 0;
}

