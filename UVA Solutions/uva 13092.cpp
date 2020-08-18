#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e6 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int x , y;
string s;

vector <int> ManacherEven( string s ) {
        vector <int> evenPal( s.size() );
        for( int i = 0 , l = 0 , r = -1; i < s.size(); i++ ) {
                int k = i > r ? 0 : min( evenPal[ r + l - i + 1 ] , r - i + 1 );
                while( 0 <= i - k - 1 && i + k < s.size() && s[ i - k - 1 ] == s[ i + k ] ) k++;
                evenPal[i] = k--;
                if( i + k  > r ) l = i - k - 1 , r = i + k;
        }
        return evenPal;
}
vector <int> ManacherOdd( string s ) {
        vector <int> oddPal( s.size() );
        for( int i = 0 , l = 0 , r = -1; i < s.size(); i++ ) {
                int k = i > r ? 1 : min( oddPal[ r + l - i ] , r - i );
                while( 0 <= i - k && i + k < s.size() && s[ i - k ] == s[ i + k ] ) k++;
                oddPal[i] = k--;
                if( i + k  > r ) l = i - k , r = i + k;
        }
        return oddPal;
}
int main( int argc , char const *argv[] ) {
        int t;
        cin >> t;
        while( t-- ) {
                cin >> x >> y >> s;
                vector <int> evenPal = ManacherEven( s );
                for( int i = 0; i < evenPal.size(); i++ ) cout << i << " " << evenPal[i] << endl;
                cout <<"************"<< endl;
                vector <int> oddPal = ManacherOdd( s );
                for( int i = 0; i < oddPal.size(); i++ ) cout << i << " " << oddPal[i] << endl;
        }
        return 0;
}






