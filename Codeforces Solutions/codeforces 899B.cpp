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

string str="312931303130313130313031312831303130313130313031312831303130313130313031312831303130313130313031312931303130313130313031312831303130313130313031312831303130313130313031";

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    string res="";
    for( int i = 0; i < n; i++ ) {
        string s;
        cin >> s;
        res += s;
    }
    if( str.find( res ) != -1 ) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}




