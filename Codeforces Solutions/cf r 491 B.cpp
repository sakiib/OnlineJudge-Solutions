#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
char str[ 5 ][ 105 ];

int main( int argc , char const *argv[] ) {
        string a , b;
        cin >> a >> b;
        for( int i = 0; i < a.size(); i++ ) str[0][i] = a[i];
        for( int i = 0; i < b.size(); i++ ) str[1][i] = b[i];
        str[0][a.size()] = 'P' , str[1][a.size()] = 'P';
        int ans = 0;
        for( int i = 0; i < a.size(); i++ ) {
                if( str[0][i] == '0' && str[0][i+1] == '0' && str[1][i] == '0' ) {
                    str[0][i] = 'X' , str[0][i+1] = 'X' , str[1][i] = 'X';
                    ans++;
                }
                else if( str[0][i] == '0' && str[0][i+1] == '0' && str[1][i+1] == '0' ) {
                    str[0][i] = 'X' , str[0][i+1] = 'X' , str[1][i+1] = 'X';
                    ans++;
                }
                else if( str[1][i] == '0' && str[0][i+1] == '0' && str[1][i+1] == '0' ) {
                    str[1][i] = 'X' , str[0][i+1] = 'X' , str[1][i+1] = 'X';
                    ans++;
                }
                else if( str[0][i] == '0' && str[1][i] == '0' && str[1][i+1] == '0' ) {
                    str[0][i] = 'X' , str[1][i] = 'X' , str[1][i+1] = 'X';
                    ans++;
                }
        }
        cout << ans << endl;
        return 0;
}
