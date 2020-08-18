#include <bits/stdc++.h>
using namespace std;

int target = 0;
int ara[ 10 ];

void solve( int idx , int sum , int taken ) {
    if( idx > 6 || taken > 3 || sum > target ) return;
    if( sum == target && taken == 3 ) {
        cout << "YES\n";
        exit(0);
    }
    solve( idx+1 , sum+ara[idx] , taken+1 );
    solve( idx+1 , sum ,taken );
}
int main( int argc, char const *argv[] ) {
    int sum = 0;
    for( int i = 1; i <= 6; i++ ) {
        cin >> ara[i];
        sum += ara[i];
    }
    if( sum%2 == 1 ) {
        cout << "NO\n";
        return 0;
    }
    target  = sum/2;
    solve( 1 , 0 , 0);
    cout << "NO\n" ;
    return 0;
}
