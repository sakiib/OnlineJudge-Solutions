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

string a , b;
int ans;

const int Base = 29;
uLL Hash[ N ][ 2 ];
uLL p[ N ];

void gen_power( ) {
        p[ 0 ] = 1;
        for( int i = 1; i < N; i++ ) p[ i ] = p[ i-1 ] * Base;
}
void Build_Hash( string s , int id ) {
        int len = s.size( );
        Hash[ 0 ][ id ];
        for( int i = 1; i <= len; i++ ) {
                Hash[ i ][ id ] = Hash[ i-1 ][ id ] * Base + s[ i-1 ];
        }
}
uLL get_Hash( int l , int r , int id ) {
        ++l , ++r;
        if( l == 1 ) return Hash[ r ][ id ];
        uLL res = Hash[ r ][ id ] - Hash[ l-1 ][ id ] * p[ r-l+1 ];
        return res;
}
vector <int> get_divisor( int x ) {
        int sq = sqrt( x );
        vector <int> ret;
        for( int i = 1; i <= sq; i++ ) {
                if( x%i == 0 ) {
                        ret.push_back( i );
                        if( x/i != i ) ret.push_back( x/i );
                }
        }
        return ret;
}
bool OK( string str , uLL hash_val , int len , int id ) {
        int l = 0 , r = len-1;
        //cout << "st : " <<id << " "<< l << " " << r << endl;
        while( r < str.size( ) ) {
                uLL cur = get_Hash( l , r , id );
                //cout << cur << " "<<"here : "<< l << " " << r <<" "<< len << endl;
                if( cur != hash_val ) return false;
                l += len , r += len;
        }
        return true;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        gen_power( );
        cin >> a >> b;
        if( (int)a.size() > (int)b.size() ) swap( a , b );
        vector <int> div = get_divisor( (int)a.size() );
        Build_Hash( a , 0 );
        Build_Hash( b , 1 );
        for( auto x : div ) {
                if( (int)b.size()%x != 0 ) continue;
                uLL hash_val = get_Hash( 0 , x-1 , 0 );
                //cout << "Main : " << hash_val << endl;
                if( OK( a , hash_val , x , 0 ) && OK( b , hash_val , x , 1 ) ) ans++;
        }
        cout << ans << endl;
        return 0;
}






