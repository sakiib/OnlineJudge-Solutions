/**
 * Created by Sakib on 5/30/2018
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int main( int argc, char const *argv[] ) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL x , y;
    cin >> x >> y;
    long double a = y*log(x);
    long double b = x*log(y);
    if( a+eps < b ) cout << "<" << endl;
    else if( a > b+eps ) cout << ">" <<endl;
    else cout << "=" << endl;
    return 0;
}
