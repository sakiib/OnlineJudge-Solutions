#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    if( n >= 1 && n <= 9 ) {
        cout << n << endl;
    }
    else if( n > 9 && n <= 99 ) {
        cout << 9+(n-9)*2 << endl;
    }
    else if( n > 99 && n <= 999 ) {
        cout << 9+(99-10+1)*2+(n-99)*3 << endl;
    }
    else if( n > 999 && n <= 9999 ) {
        cout << 9+(99-10+1)*2+(999-100+1)*3+(n-999)*4 << endl;
    }
    else if( n > 9999 && n <= 99999 ) {
        cout << 9+(99-10+1)*2+(999-100+1)*3+(9999-1000+1)*4+(n-9999)*5 << endl;
    }
    else if( n > 99999 && n <= 999999 ) {
       cout << 9+(99-10+1)*2+(999-100+1)*3+(9999-1000+1)*4+(99999-10000+1)*5+(n-99999)*6 << endl;
    }
    else if( n > 999999 && n <= 9999999 ) {
        cout << 9+(99-10+1)*2+(999-100+1)*3+(9999-1000+1)*4+(99999-10000+1)*5+(999999-100000+1)*6+(n-999999)*7 << endl;
    }
    else if( n > 9999999 && n <= 99999999 ) {
        cout << 9+(99-10+1)*2+(999-100+1)*3+(9999-1000+1)*4+(99999-10000+1)*5+(999999-100000+1)*6+(9999999-1000000+1)*7+(n-9999999)*8 << endl;
    }
    else if( n > 99999999 && n <= 999999999 ) {
           cout << 9+(99-10+1)*2+(999-100+1)*3+(9999-1000+1)*4+(99999-10000+1)*5+(999999-100000+1)*6+(9999999-1000000+1)*7+(99999999-10000000+1)*8+(n-99999999)*9 << endl;
    }
    else if( n > 999999999 && n < 9999999999 ) {
        cout << 9+(99-10+1)*2+(999-100+1)*3+(9999-1000+1)*4+(99999-10000+1)*5+(999999-100000+1)*6+(9999999-1000000+1)*7+(99999999-10000000+1)*8+(999999999-100000000+1)*9+(n-999999999)*10 << endl;
    }
    return 0;
}
