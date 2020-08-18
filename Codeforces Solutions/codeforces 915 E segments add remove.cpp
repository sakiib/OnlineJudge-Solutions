#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;
#define ff first
#define ss second
#define mp make_pair

int n , q;
int ans;
set < pair <int,int> > Active;

void see( ) {
        printf("### Set ###\n");
        for( auto it : Active ) printf("( %d , %d )\n",it.ff,it.ss);
        printf("### END ###\n");
}
void ON( int l , int r ) {
        auto it = Active.upper_bound( mp( l , r ) );
        if( it != Active.begin() ) --it;
        if( Active.empty() ) {
                ans += ( r - l + 1 );
                Active.insert( mp( l , r ) );
                return;
        }
        int ll = (*it).ff , rr = (*it).ss;
        if( l >= ll && r <= rr ) return;
        else if( l < ll && r > rr ) {
                Active.erase( mp( ll , rr ) );
                Active.insert( mp( l , ll-1 ) );
                Active.insert( mp( rr+1 , r ) );
                ans += ( ll - 1 - l + 1 );
                ans += ( r - ( rr + 1 ) + 1 );
        }
        else if( l == ll && r > rr ) {
                Active.erase( mp( ll , rr ) );
                Active.insert( mp( l , r ) );
                ans += ( r - ( rr + 1 ) + 1 );
        }
        else if( r == rr && l < ll ) {
                Active.erase( mp( ll , rr ) );
                Active.insert( mp( l , r ) );
                ans += ( ll - 1 - l + 1 );
        }
}
void OFF( int l , int r ) {
        auto it = Active.upper_bound( mp( l , r ) );
        if( it != Active.begin() ) --it;
        int ll = (*it).ff , rr = (*it).ss;
        cout << ll << " " << rr << endl;
        if( l >= ll && r <= rr ) {
                if( l == r ) {
                        Active.erase( mp( ll , rr ) );
                        Active.insert( mp( ll , l-1 ) );
                        Active.insert( mp( r+1 , rr ) );
                        ans --;
                }
                else if( l == ll && r == rr ) {
                        Active.erase( mp( ll , rr ) );
                        ans -= ( rr - ll + 1 );
                }
                else if( l == ll ) {
                        Active.erase( mp( ll , rr ) );
                        Active.insert( mp( r + 1 , rr ) );
                        ans -= ( r - l + 1 );
                }
                else if( r == rr ) {
                        Active.erase( mp( ll , rr ) );
                        Active.insert( mp( ll , l - 1 ) );
                        ans -= ( l - 1 - ll + 1 );
                }
                else {
                       cout << "this " << endl;
                       Active.erase( mp( ll , rr ) );
                       Active.insert( mp( l , ll-1 ) );
                       Active.insert( mp( rr+1 , r ) );
                       ans -= ( rr - ll + 1 );
                }
        }
        else if( l > ll && r > rr ) {
                Active.erase( mp( ll, rr ) );
                Active.insert( mp( ll , l-1 ) );
                ans -= ( r - rr + 1 );
        }
        else if( l < ll && r < rr ) {
                Active.erase( mp( ll , rr ) );
                Active.insert( mp( r+1 , rr ) );
                ans -= ( ll - 1 - l + 1 );
        }
        else if( l < ll && r > rr ) {
                Active.erase( mp( ll , rr ) );
                ans -= ( ll - 1 - l + 1 );
                ans -= ( r - ( rr + 1 ) + 1 );
        }
        else if( l == ll && r > rr ) {
                Active.erase( mp( ll , rr ) );
                ans -= ( r - ( rr + 1 ) + 1 );
        }
        else if( r == rr && l < ll ) {
                Active.erase( mp( ll , rr ) );
                ans -= ( ll - 1 - l + 1 );
        }
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        ans = n;
        Active.insert( mp( 1 , n ) );
        scanf("%d",&q);
        while( q-- ) {
                int l , r , k;
                scanf("%d %d %d",&l,&r,&k);
                if( k == 1 ) OFF( l , r );
                else ON( l , r );
                see( );
                printf("%d\n",ans);
        }
        return 0;
}







