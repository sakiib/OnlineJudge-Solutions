#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e6 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

vector <int> prefix_function( string &s ) {
        int n = (int)s.size();
        vector <int> pi( n );
        pi[0] = 0;
        for ( int i = 1; i < n; i++ ) {
                int j = pi[i-1];
                while ( j > 0 && s[i] != s[j] ) j = pi[j-1];
                if ( s[i] == s[j] ) j++;
                pi[i] = j;
        }
        return pi;
}
int KMP( string text , string pattern ) {
        int lt = text.size( ) , lp = pattern.size( );
        vector <int> pi = prefix_function( pattern );
        int i = 0 , j = 0 , ret = 0;
        while( i < lt ) {
                if( pattern[j] == text[i] ) i++ , j++;
                if( j == lp ) {
                        ret++;
                        j = pi[j-1];
                        //j++; /// for non overlapping substring
                }
                else if( i < lt && pattern[j] != text[i] ) {
                        if( j != 0 ) j = pi[j-1];
                        else i++;
                }
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                string text , pattern;
                cin >> text >> pattern;
                cout << "Case " << tc << ": " << KMP( text , pattern ) << endl;
        }
        return 0;
}







