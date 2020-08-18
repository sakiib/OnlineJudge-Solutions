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

int Failure[ 10*N ];

void Failure_Function( string pattern , int lp ) {
        Failure[0] = Failure[1] = 0;
        for( int i = 2; i <= lp; i++ ) {
                int j = Failure[i-1];
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
}
void KMP( string text , string pattern ) {
        int lt = text.size( ) , lp = pattern.size( );
        Failure_Function( pattern , lp );
        int i = 0 , j = 0;
        vector <int> ans;
        while( true ) {
                if( j == lt ) break;
                if( text[j] == pattern[i] ) {
                        i++ , j++;
                        if( i == lp ) {
                                ans.push_back( j-lp+1 );
                        }
                }
                else {
                        if( i == 0 ) j++;
                        else i = Failure[i];
                }
        }
        if( ans.size() ) {
                cout << ans.size() << endl;
                for( int i = 0; i < ans.size(); i++ ) {
                        if( i == 0 ) cout << ans[i];
                        else cout << " " << ans[i];
                }
                cout << endl;
        }
        else cout << "Not Found" << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        while( t-- ) {
             string text , pattern;
             cin >> text >> pattern;
             KMP( text , pattern );
        }
        return 0;
}







