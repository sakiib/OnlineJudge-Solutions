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

LL n;
LL ara[ 5*N ] , S[ 5*N ];

int main( int argc, char const *argv[] ) {
    cin >> n;
    LL sum = 0;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        sum += ara[i];
    }
    if( sum%3 != 0 || n < 3 ) {
        cout << 0 << endl;
        return 0;
    }
    LL f = sum/3;
    LL s= 2*f;
    LL ans = 0 , temp = 0;
    for( int i = 1; i < n; i++ ) {
        ara[i] += ara[i-1];
        if( ara[i] == s ) {
            ans += temp;
        }
        if( ara[i] == f ) {
            temp++;
        }
    }
    cout << ans << endl;
    return 0;
}

