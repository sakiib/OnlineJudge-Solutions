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

bool ok( LL x ) {
    if( x%2 == 0 && x%3 == 0 && x%5 == 0 ) return true;
    return false;
}
void Bruteforce( ) {
    for( LL i = 1; i <= 1000; i++ ) {
        if( ok( i ) ) cout << i << endl;
    }
}
inline int String_Mod ( string &s , int m ) {
    int res=0;
    for(int i = 0; i < s.size(); i++ ) {
        res = (( res%m*10%m )%m+( s[i]-'0' )%m )%m;
    }
    return res;
}
int can( string &s , int d ) {
    int sum = 0;
    for( int i = 0; i < s.size(); i++ ) {
        sum += ( s[i]-'0' );
    }
    return sum%d;
}
int main( int argc, char const *argv[] ) {
    // Bruteforce( );
    int n;
    cin >> n;
    string str = "";
    bool f = false;
    for( int i = 1; i <= n; i++ ) {
        int d;
        cin >> d;
        if( d == 0 ) f = true;
        str += (d+'0');
    }
    if( !f ) {
        cout << -1 << endl;
        return 0;
    }
    sort( str.rbegin() , str.rend() );
    while( str.size() >= 1 ) {
        int rem = can( str , 3 );

        cout <<"In : "<< rem << " " << str << endl;

        if( rem == 1 ) {
            bool f = false;
            for( int i = str.size()-1; i >= 0 ; i-- ) {
                if( str[i] == '1' || str[i] == '4' || str[i] == '7' ) {
                    str.erase( i , 1 );
                    f = true;
                    break;
                }
            }
            if( !f ) break;
        }
        else if( rem == 2 ) {
            bool f = false;
            for( int i = str.size()-1; i >= 0 ; i-- ) {
                if( str[i] == '2' || str[i] == '5' || str[i] == '8' ) {
                    str.erase( i , 1 );
                    f = true;
                    break;
                }
            }
            if( !f ) break;
        }
        else break;
    }
    cout << "last " << str << endl;
    if( str.size() >= 1 && can( str , 3 ) == 0 ) cout << str << endl;
    else cout << -1 << endl;
    return 0;
}

