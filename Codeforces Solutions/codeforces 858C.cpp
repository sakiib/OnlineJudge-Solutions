#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

string s = "aeiou";

bool con( char x ) {
    for( int i = 0; i < 5; i++ ) {
        if( s[i] == x ) return false;
    }
    return true;
}
int main( int argc, char const *argv[] ) {
    string str;
    cin >> str;
    str += 'a';
    int c = 0;
    for( int i = 0; i < str.size()-1; i++ ) {
        if( con( str[i] ) ) {
           c++;
           if( c == 2 && con( str[i+1] ) ) {
              cout << str[i];
              if( i != str.size()-3 ) cout << " ";
              c = 0;
           }
           else cout << str[i];
        }
        else {
            cout << str[i];
            c = 0;
        }
    }
    return 0;
}

