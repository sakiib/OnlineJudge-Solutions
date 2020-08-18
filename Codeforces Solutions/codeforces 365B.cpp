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

LL ara[ N ];

int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    if( n <= 2 ) {
        cout << n << endl;
        return 0;
    }
    LL mx = 2 , res = 2;
    for( int i = 3; i <= n; i++ ) {
        if( ara[i] == ara[i-1]+ara[i-2] ) res++;
        else res = 2;
        mx = max( mx , res );
    }
    cout << mx << endl;
    return 0;
}

