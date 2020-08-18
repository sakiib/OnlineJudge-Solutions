#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );

map < char , int > cnta , cntb , cntc;
string a , b , c;
int n;


void go( ) {

    int mxa = 0 , mxb = 0 , mxc = 0;

    int len = a.size( );

    for( int i = 0; i < len; i++ ) {
        cnta[ a[i] ]++ , mxa = max( mxa , cnta[ a[i] ] );
        cntb[ b[i] ]++ , mxb = max( mxb , cntb[ b[i] ] );
        cntc[ c[i] ]++ , mxc = max( mxc , cntc[ c[i] ] );
    }
    while( n-- ) {
        if( mxa < len ) mxa++;
        else if( mxa == len ) mxa--;
        if( mxb < len ) mxb++;
        else if( mxb == len ) mxb--;
        if( mxc < len ) mxc++;
        else if( mxc == len ) mxc--;
    }
    int mx = max( mxa , max( mxb , mxc ) );
    int k = 0;
    if( mx == mxa ) k++;
    if( mx == mxb ) k++;
    if( mx == mxc ) k++;
    if( k > 1 ) {
        cout << "Draw" << endl;
        exit( 0 );
    }
    if( mxa == mx ) cout << "Kuro" << endl;
    else if( mxb == mx ) cout << "Shiro" << endl;
    else cout << "Katie" << endl;

}
int main( int argc, char const *argv[] ) {

    cin >> n;
    cin >> a >> b >> c;


    return 0;
}






