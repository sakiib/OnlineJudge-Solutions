#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

LL n , k , s;
LL res;
vector <LL> ans;

bool ok( LL dist , LL move_rem , LL cur ) {
        if( (cur + dist <= n ) ) {
                LL rem = s - dist;
                if( rem >= move_rem ) return true;
        }
        if( ( cur - dist >= 1 ) ) {
                LL rem = s - dist;
                if( rem >= move_rem ) return true;
        }
        return false;
}
LL BS( LL cur , LL move_rem  ) {
        LL lo = 1 , hi = n-1 , ret = 0;
        while( lo <= hi ) {
                LL mid = (lo+hi)/2;
                if( ok( mid , move_rem , cur ) ) {
                        ret = mid;
                        lo = mid+1;
                }
                else hi = mid-1;
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> k >> s;
        if( s < k ) return cout << "NO" << endl,0;
        if( (n-1)*k < s ) return cout << "NO" << endl,0;
        LL cur = 1;
        for( LL i = 1; i <= k; i++ ) {
                LL next = BS( cur , k-i );
                if( cur + next <= n ) {
                        cur += next;
                        s -= next;
                        ans.push_back( cur );
                }
                else if( cur - next >= 1 ) {
                        cur -= next;
                        s -= next;
                        ans.push_back( cur );
                }
        }
        cout << "YES" << endl;
        for( auto x : ans ) cout << x << " ";
        cout << endl;
        return 0;
}






