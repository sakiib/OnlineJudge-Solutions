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

int Failure[ N ];

void Failure_Function( string pattern , int lp ) {
        Failure[0] = Failure[1] = 0;
        int j;
        for( int i = 2; i <= lp; i++ ) {
                j = Failure[i-1];
                while( true ) {
                        if( pattern[j] == pattern[i-1] ) {
                                Failure[i] = j+1;
                                break;
                        }
                        if( j == 0 ) {
                                Failure[i] = 0;
                                break;
                        }
                        j = Failure[j];
                }
        }
        cout << j << endl;
}
bool KMP( string text , string pattern ) {
        int lt = text.size( ) , lp = pattern.size( );
        Failure_Function( pattern , lp );
        int i = 0 , j = 0;
        while( true ) {
                if( j == lt ) return false;
                if( text[j] == pattern[i] ) {
                        i++ , j++;
                        if( i == lp ) return true;
                }
                else {
                        if( i == 0 ) j++;
                        else i = Failure[i];
                }
        }
        return false;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        string text , pattern;
        cin >> text >> pattern;
        cout << ( KMP( text , pattern ) == 1 ? "YES" : "NO" )  << endl;
        return 0;
}







