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
int n;
LL d;

LL BS( int id ) {
    int pos = id , lo = min( id+2 , n ) , hi = n , ret = 0;
    while( lo <= hi ) {
        int mid = ( lo+hi ) >> 1;
        if( abs(ara[mid]-ara[pos]) <= d ) {
            ret = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    if( ret-pos+1 < 3 ) return -1;
    return ( ret-pos+1 );
}
int main( int argc, char const *argv[] ) {
    cin >> n >> d;
    for( int i = 1; i <= n; i++ ) cin >> ara[i];
    LL ans = 0;
    for( int i = 1; i <= n-2; i++ ) {
        LL x = BS( i );
        if( x == -1 ) continue;
        x--;
        ans += ( x*(x-1)/2 );
    }
    cout << ans << endl;
    return 0;
}

