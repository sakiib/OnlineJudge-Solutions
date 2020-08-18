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

LL ara[ 2*N ];
vector < LL > sq , nsq;

bool psq( LL val ) {
    LL sq = sqrt( val );
    return ( sq*sq == val );
}
int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        if(psq( ara[i] )) sq.push_back( ara[i] );
        else nsq.push_back( ara[i] );
    }
    if( sq.size() == nsq.size() ) {
        cout << 0 << endl;
        return 0;
    }
    if( sq.size() > nsq.size() ) {
        LL ache = nsq.size();
        LL lagbe = sq.size();
        LL ans = 0;
        sort( sq.rbegin(), sq.rend() );
        for( auto x: sq ) {
            if( ache == lagbe ) break;
            if( x != 0 ) ans ++;
            else ans += 2;
            ache ++;
            lagbe --;
        }
      cout << ans << endl;
      return 0;
    }
    vector < LL > cost;
    for( int i = 0; i < nsq.size(); i++ ) {
        LL cur = nsq[i];
        LL sq = sqrt( cur );
        LL need1 = (sq+1)*(sq+1);
        LL need2 = (sq)*(sq);
        cost.push_back( min(abs( need1-cur),abs(need2-cur) ) );
    }
    sort( cost.begin(), cost.end() );
    LL ache = sq.size();
    LL lagbe = nsq.size();
    LL ans = 0;
    for( auto x : cost ) {
        if( ache == lagbe ) break;
        ans += x;
        lagbe-- , ache ++;
    }
    cout << ans << endl;
    return 0;
}




