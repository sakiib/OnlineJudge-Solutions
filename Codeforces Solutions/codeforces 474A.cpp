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

string s[] = {"qwertyuiop" , "asdfghjkl;" , "zxcvbnm,./"};

int main( int argc, char const *argv[] ) {
    string a , str;
    cin >> a >> str;
    char c = a[0];
    for( int i = 0; i < str.size(); i++ ) {
        char rep = str[i];
        for( int j = 0 ; j < 3; j++ ) {
            string t = s[j];
            for( int k = 0 ; k < t.size(); k++ ) {
                if( t[k] == rep ) {
                    if( c == 'R' ) {
                       if( k == 0 ) continue;
                       else str[i] = t[k-1];
                    }
                    if( c == 'L' ) {
                       if( k == t.size()-1 ) continue;
                       else str[i] = t[k+1];
                    }
                }
            }
        }
    }
    cout << str << endl;
    return 0;
}

