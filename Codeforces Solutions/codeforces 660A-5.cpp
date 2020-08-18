#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int ara[ N ];
vector < int > V;

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> ara[i];
    if( n == 1 ) return cout <<0 <<"\n"<< ara[1] << endl,0;
    int tot = 0;
    for( int i = 1; i < n; i++ ) {
        if( __gcd( ara[i], ara[i+1] ) != 1 ) {
            tot++;
            V.push_back( ara[i] ) , V.push_back( 1 );
        }
        else V.push_back( ara[i] );
    }
    V.push_back( ara[n] );
    cout << tot << endl;
    for( auto x : V ) cout << x << " ";
    return 0;
}






