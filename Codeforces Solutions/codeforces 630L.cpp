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

inline LL BigMod ( LL a , LL p , LL m ) {
    LL res = 1%m , x = a%m;
    while( p ) {
        if(p&1) res = ( res*x )%m;
        x = ( x*x )%m;
        p >>= 1;
    }
    return res;
}
int Num( char x ) {
    return (x-'0');
}
int main( int argc, char const *argv[] ) {
    string str;
    cin >> str;
    LL n = Num( str[0] )*10000+Num( str[2] )*1000+Num( str[4] )*100
           +Num( str[3] )*10+Num( str[1] )*1;

    LL res = BigMod( n , 5LL , 100000LL );

    if( res == 0 ) cout << "00000"<< endl;
    else cout << res << endl;
    return 0;
}

