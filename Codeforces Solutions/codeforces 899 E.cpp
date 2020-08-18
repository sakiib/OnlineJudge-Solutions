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

int  n;
LL a[ 2*N ];
set < pair<LL,LL> > S1 , S2;

void see( ){
        cout << "set1 : ( -len   ,   start ) "<< endl;
        for( auto x : S1 ) cout <<x.first << " " << x.second << endl;
        cout << "set2 : ( start  ,   len ) "<< endl;
        for( auto x : S2 ) cout <<x.first << " " << x.second << endl;
        cout << " ====================  " << endl;
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i]; a[n+1] = INF;
        int len = 1 , st = 1;
        for( int i = 1; i <= n; i++ ) {
                if( a[i] == a[i+1] ) len++;
                else {
                        S1.insert( make_pair( -len , st ) );
                        S2.insert( make_pair( st , len ) );
                        len = 1 , st = i + 1;
                }
        }
        int ans = 0;
        while( !S2.empty() ) {
                ans++;
                auto it = *S1.begin();
                //cout << it.first << " " << it.second << endl;

                auto it1 = *S2.lower_bound( { it.second-1 , 0 } );
                auto it2 = *S2.lower_bound( { it.second+1 , 0 } );
                auto it3 = *S2.lower_bound( { it.second , 0 } );

                //cout << it1.first << " " << it1.second << endl;
                //cout << it2.first << " " << it2.second << endl;

                S1.erase( it );
                if( a[ it1.first ] == a[ it2.first] ) {
                        S1.insert( {-(it1.second+it2.second) , it1.first } );
                        S2.insert( {it1.first,(it1.second+it2.second)} );
                        S2.erase( it1 );
                        S2.erase( it2 );
                        S2.erase( it3 );
                }
                else S2.erase( it3 );

                see( );
        }
        cout << ans << endl;
        return 0;
}







