#include <bits/stdc++.h>
using namespace std;

map <string,int> M;

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    string ans = "";
    int mx = 0;
    for( int i = 1; i <= n ; i++ ) {
        string s;
        cin >> s;
        M[ s ] ++;
        if( M[ s ] > mx ) {
            mx = M[ s ];
            ans = s;
        }
    }
    cout << ans << endl;
    return 0;
}
