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

string s;

void solve( int l , int r , int k ) {
    --l , --r;
    int cycle = ( r-l+1 )%k;
    if( cycle == 0 ) return;
    string temp = s.substr( l , r-l+1 );
    cout << "sub : " << temp << endl;
    while( cycle-- ) {
        char last = temp[ temp.size()-1 ];
        temp = last + temp;
        temp.pop_back( );
    }
    for( int i = l , j = 0; i < r; i++ , j++ ) s[i] = temp[j];
}
int main( int argc, char const *argv[] ) {
    cin >> s;
    int q;
    cin >> q;
    while( q-- ) {
        int l , r , k;
        cin >> l >> r >> k;
        solve( l , r , k );
        cout <<"now : "<< s << endl;
    }
    cout << s << endl;
    return 0;
}





