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

string DecToBin( int x ) { string s = ""; while( x ) { s += (x%2)+'0'; x /= 2; } reverse( s.begin() , s.end() ); while( s.size() < 32 ) s = '0'+s; return s; }
template < typename T > inline T GCD( T a , T b ) { a = abs(a) , b = abs(b); return !b ? a : GCD(b, a % b); }
LL p , q , base;


LL solve( LL q ) {
    vector < LL > V;
    while( q ) {
        V.push_back( q%base );
        q /= base;
    }
    reverse( V.begin() , V.end() );
    LL num = 0;
    for( auto x : V ) {
        num = num*10+x;
    }
    //cout << num << endl;
    return num;
    //while( num%2 == 0 ) num /= 2;
    //while( num%5 == 0 ) num /= 5;
    //if( num > 1 ) cout << "Infinite" << endl;
    //else cout << "Finite" << endl;
}
int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        cin >> p >> q >> base;

        //if( p == 0 || q == 1 ) {
        //    cout << "Finite" << endl;
        //    continue;
        //}

        p = solve( p ) , q = solve( q );
        //LL g = GCD( p , q );
        //p /= g , q /= g;
        int t = 10000;
        if( p%q == 0 ) {
            cout << "Finite" << endl;
            continue;
        }
        p %= q;
        bool f = false;
        while( t-- ) {
            p *= 10;
            int x = p/q;
            if( x == 0 ) {
                cout << "Finite" << endl;
                f = true;
                break;
            }
            p %= q;
        }
        if( !f ) cout << "Infinite" << endl;
    }
    return 0;
}
