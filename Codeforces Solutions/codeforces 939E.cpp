#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

LL a[ 2*N ];
int id;

double Ternary_Search( ) {
        int lo = 1 , hi = id;
        double res = -INF;
        int it = 300;
        while( it-- ) {

        }
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int q;
        cin >> q;
        while( q-- ) {
                int op;
                cin >> op;
                if( op == 1 ) {
                       LL val;
                       cin >> val;
                       a[++id] = a[id] + val;
                }
                else {
                        cout <<setprecision(10) << fixed << Ternary_Search( ) << endl;
                }
        }
        return 0;
}






