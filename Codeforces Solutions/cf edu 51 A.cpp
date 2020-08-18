#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

int main( int argc , char const *argv[] ) {
        Fast_IO;
        int t;
        cin >> t;
        while( t-- ) {
                string s;
                cin >> s;
                int dig = 0 , low = 0 , up = 0;
                for( int i = 0; i < s.size(); i++ ) {
                        if( isdigit( s[i] ) ) dig++;
                        if( islower( s[i] ) ) low++;
                        if( isupper( s[i] ) ) up++;
                }
                for( int i = 0; i < s.size(); i++ ) {
                        if( dig == 0 ) {
                                if( islower( s[i] ) && low > 1 ) low-- , s[i] = '1' , dig++;
                                else if( isupper( s[i] ) && up > 1 ) up-- , s[i] = '1' , dig++;
                        }
                        else if( low == 0 ) {
                                if( isdigit( s[i] ) && dig > 1 ) dig-- , s[i] = 'a' , low++;
                                else if( isupper( s[i] ) && up > 1 ) up-- , s[i] = 'a' , low++;
                        }
                        else if( up == 0 ) {
                                if( islower( s[i] ) && low > 1 ) low-- , s[i] = 'A' , up++;
                                else if( isdigit( s[i] ) && dig > 1 ) dig-- , s[i] = 'A' , up++;
                        }
                }
                cout << s << endl;
        }
        return 0;
}






