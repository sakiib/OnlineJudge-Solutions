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

int Failure[ N ];

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
int KMP( string text , string pattern , int n , int m , int l , int r ) {
        int lt = n , lp = m;
        Failure_Function( pattern , lp );
        int i = 0 , j = l , ret = 0;
        while( true ) {
                if( j == r ) return ret;
                if( text[j] == pattern[i] ) {
                        i++ , j++;
                        if( i == lp ) ret++;
                }
                else {
                        if( i == 0 ) j++;
                        else i = Failure[i];
                }
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        int n , m , q;
        cin >> n >> m >> q;
        string text , pattern;
        cin >> text >> pattern;
        Failure_Function( pattern , m );
        while( q-- ) {
                int l , r;
                cin >> l >> r;
                cout << KMP( text , pattern , n , m , l-1 , r ) << endl;
        }
        return 0;
}







