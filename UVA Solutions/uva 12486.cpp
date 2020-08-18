#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long LL;
const LL INF = 9330720600916705819 + 20;
//const LL INF = 1000000;
vector <int> V;
int len;
LL dp[ 20 ][ 2 ][ 10 ][ 2 ];
int vis[ 20 ][ 2 ][ 10 ][ 2 ];
int TC;

LL go( int idx , int chk , int prev , int zero ) {
        if( idx >= len ) return !zero;
        if( vis[idx][chk][prev][zero] == TC ) return dp[idx][chk][prev][zero];
        vis[idx][chk][prev][zero] = TC;
        LL ret = 0;
        if( chk ) {
                for( int i = 0; i <= 9; i++ ) {
                        if( i != 4 && ( i != 3 || ( i == 3 && prev != 1 ) )  ) {
                                ret += go( idx + 1 , 1 , i , ( zero &&( i == 0 )) );
                        }
                }
        }
        else {
                for( int i = 0; i < V[idx]; i++ ) {
                        if( i != 4 && ( i != 3 || ( i == 3 && prev != 1 ) )  ) {
                                ret += go( idx + 1 , 1 , i , ( zero &&( i == 0 )) );
                        }
                }
                if( V[idx] != 4 && ( V[idx] != 3 || ( V[idx] == 3 && prev != 1 ) )  ) {
                        ret += go( idx + 1 , 0 , V[idx] , ( zero &&( V[idx] == 0 )) );
                }
        }
        return dp[idx][chk][prev][zero] = ret;
}
LL calc( LL val ) {
        V.clear();
        TC++;
        while( val ) V.push_back( val%10 ) , val /= 10;
        reverse( V.begin() , V.end() );
        len = V.size();
        return go( 0 , 0 , 0 , 1 );
}
LL solve( LL n ) {
        if( n == 1 ) return 1;
        LL lo = 1 , hi = INF , ret = -1;
        while( lo <= hi ) {
                __uint128_t l = lo , h = hi;
                __uint128_t mid = ( l + h )/2;
                //LL mid = ( lo + hi )/2;
                LL val = calc( mid );
                //cout << " mid : " << mid << " " << val << endl;
                if( val >= n ) ret = mid , hi = mid - 1;
                else lo = mid + 1;
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        //freopen( "input.txt" , "r", stdin );
        //freopen( "output.txt" , "w" , stdout );
        LL n;
        TC = 0;
        while( cin >> n ) {
                cout << solve( n ) << endl;
        }
        return 0;
}










