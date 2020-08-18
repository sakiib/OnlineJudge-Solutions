#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 100005;

string s;
int len;
int mx;

bool pfsq( int x ) {
    int sq = sqrt(x);
    return ( sq*sq == x );
}
int calc( int x ) {
    int ret = 0;
    while( x ) {
        ret++;
        x /= 10;
    }
    return ret;
}
void solve( int ind , int tot , int taken ) {
    if( ind >= len ) {
        if( pfsq( tot ) && taken > 0 ) {
            mx = max( mx , calc( tot ) );
        }
        return;
    }
    if( pfsq( tot ) && taken > 0 ) mx = max( mx , calc( tot) );
    solve( ind+1 , tot*10+s[ind]-'0' , taken+1 );
    solve( ind+1 , tot , taken );
}
int main( int argc, char const *argv[] ) {
    cin >> s;
    len = s.size();
    solve( 0 , 0 , 0 );
    if( mx == 0 ) cout << -1 << endl;
    else cout << len-mx << endl;
    return 0;
}

