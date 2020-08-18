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
    LL n , q;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ ) cin >> ara[i];
    LL extra = 0;
    while( q-- ) {
       int op;
       cin >> op;
       if( op == 1 ) {
         int pos;
         LL val;
         cin >> pos >> val;
         ara[pos] = val-extra;
       }
       else if( op == 2 ) {
         LL add;
         cin >> add;
         extra += add;
       }
       else {
         int pos;
         cin >> pos;
         cout << ara[pos]+extra << endl;
       }
    }
    return 0;
}

