#include <bits/stdc++.h>
using namespace std;

int main( int argc, char const *argv[] ) {
    string str;
    cin >> str;
    int l = 0, u = 0;
    for( int i = 0; i < str.size(); i++ ) {
        if( str[i] >= 'a' && str[i] <= 'z' ) l++;
        else u++;
    }
    if(l>=u) {
        for(int i = 0; i < str.size(); i++ ) {
            if( str[i] >= 'a' && str[i] <= 'z' ) cout << str[i];
            else {
                str[i] -= 'A';
                str[i] += 'a';
                cout << str[i];
            }
        }
        return 0;
    }
    for(int i = 0; i < str.size(); i++ ) {
            if( str[i] >= 'A' && str[i] <= 'Z' ) cout << str[i];
            else {
                str[i] -= 'a';
                str[i] += 'A';
                cout << str[i];
            }
    }
    return 0;
}
