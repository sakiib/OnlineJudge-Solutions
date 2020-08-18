#include <bits/stdc++.h>
using namespace std;

int main( int argc , char const *argv[] ) {
    string str;
    cin >> str;
    bool f = false;
    for ( int i = 0; i < str.size(); i++ ) {
        if( str[i] == '0' ) {
            str[i]='X';
            f = true;
            break;
        }
    }
    if( !f ) {
    for ( int i = 0; i < str.size(); i++ ) {
        if( str[i] == '1' ) {
            str[i]='X';
            f = true;
            break;
        }
      }
    }
    int idx = 0;
    for ( int i = 0; i < str.size(); i++ ) {
        if(str[i]=='1') {
            idx = i;
            break;
        }
    }
    for ( int i = idx; i < str.size(); i++ ) {
        if(str[i] != 'X') cout << str[i];
    }
    cout<<endl;
    return 0;
}
