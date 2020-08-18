#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int t , k;
string a , b , s;
int len;
LL dp[ 1005 ][ 2 ][ 1010 ][ 2 ];

LL go( int idx , int smaller , int last , int got ) {
        ///out << "jedg : " << idx << " " << got << endl;
        if( idx >= len ) {
                //cout << "got : "<< got << endl;
                return got;
        }
        //if( dp[idx][smaller][last+5][got] != -1 ) return dp[idx][smaller][last+5][got];
        LL ret = 0;
        if( smaller ) {
                for( int i = 0; i <= 9; i++ ) {
                        int clast = last;
                        if( i == 4 || i == 7 ) clast = i;
                        int cgot = got;
                        if( last != -1 && ( clast - last ) <= k ) cgot = 1;
                        ret += go( idx + 1 , 1 , clast , cgot );
                        ret %= MOD;
                }
        }
        else {
                //cout << "in " <<endl;
                for( int i = 0; i < ( s[idx] - '0' ); i++ ) {
                        int clast = last;
                        if( i == 4 || i == 7 ) clast = i;
                        int cgot = got;
                        if( last != -1 && ( clast - last ) <= k ) cgot = 1;
                        ret += go( idx + 1 , 1 , clast , cgot );
                        ret %= MOD;
                }
                int num = s[idx]-'0';
                int clast = last;
                if( num == 4 || num == 7 ) clast = idx;
                int cgot = got;
                if( last != -1 && ( clast - last ) <= k ) cgot = 1;
                ret += go( idx + 1 , 0 , clast , cgot );
                ret %= MOD;
        }
        return ret;
        //return dp[idx][smaller][last+5][got] = ret%MOD;
}
LL solve( string x ) {
        s = x;
        len = s.size();
        memset( dp , -1 , sizeof( dp ) );
        return go( 0 , 0 , -1 , 0 );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> t >> k;
        while( t-- ) {
                cin >> a >> b;
                LL ans = ( solve( b ) - solve( a ) + MOD )%MOD;
                cout << ans << endl;
        }
        return 0;
}











