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

int main( int argc, char const *argv[] ) {
    int n , pos , l , r;
    cin >> n >> pos >> l >> r;
    if( l == 1 && r == n ) {
        cout << 0 << endl;
        return 0;
    }
    if( l == 1 ) {
        if( pos == r ) cout << 1 <<endl;
        else if( pos < r ) cout << r-pos+1 <<endl;
        else if( pos > r ) cout << pos-r+1<<endl;
        return 0;
    }
    if( r == n ){
        if( pos == l ) cout << 1 << endl;
        else if( pos < l ) cout << 1+l-pos <<endl;
        else if( pos > l ) cout << pos-l+1<<endl;
        return 0;
    }
    int ans1 = 0;
    if( pos <= l ) {
        if( pos == l ) ans1 = 1 , ans1 += (r-pos)+1;
        if( pos < l ){
            ans1 = 0;
            ans1 += (l-pos)+(r-pos)+( r < n);
        }
        cout << ans1 << endl;
        return 0;
    }
    int ans2 = 0;
    if( pos > l && pos < r ) {
        ans2 = pos-l+1;
        int k = l;
        ans2 += r-k+1;

        int temp = 0;
        temp = r-pos+1;
        int x = r;
        temp += x-l+1;

        cout << min( ans2 , temp ) << endl;
        return 0;
    }
    int ans3 = 0;
    if( pos >= r ) {
        if( pos == r ) ans3 = 1 , ans3 +=(r-l+1);
        if( pos > r ) {
            ans3 = 1;
            ans3 += (pos-r)+(r-l)+( l > 1);
        }
        cout << ans3 << endl;
    }
    return 0;
}

