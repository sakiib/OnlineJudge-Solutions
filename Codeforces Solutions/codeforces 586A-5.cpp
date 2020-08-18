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

int ara[ 105 ];

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    int ans = 0 , z = 0;
    bool on = false;
    for( int i = 1; i <= n; i++ ) {
        if( ara[i] == 1 ) ans++ ,ans += z, z = 0, on = true;
        else if( ara[i] == 0 && on ) {
            z++;
            if( z >= 2 ) on = false , z = 0;
        }
    }
    cout << ans <<endl;
    return 0;
}

