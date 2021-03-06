#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int NOD[ N ];
int val[ N ];

void calc() {
    for ( int i = 1; i <= N; i++ ) {
        for ( int j = i; j <= N; j+=i ) {
            NOD[j] ++;
        }
    }
    val[0] = 1;
    for ( int i = 1; i <= N; i++ ) {
        val[ i ] = val[ i-1 ] + NOD[ val[ i-1 ] ];
    }
}
int upper( int num ) {
    int lo = 1, hi = N;
    while ( lo <= hi ) {
        int mid = ( lo+hi )/2;
        if ( val[ mid ] == num) return mid+1;
        else if ( val[ mid ] < num ) lo = mid+1;
        else hi = mid-1;
    }
    return lo;
}
int lower( int num ) {
    int lo = 1, hi = N;
    while ( lo <= hi ) {
        int mid = ( lo+hi )/2;
        if( val[ mid ] == num ) return mid;
        else if ( val[ mid ] < num ) lo = mid+1;
        else hi = mid-1;
    }
    return lo;
}
int main( int argc, char const *argv[] ) {
    int t;
    calc();
    scanf("%d",&t);
    for ( int tc  = 1; tc <= t; tc++ ) {
        int a, b;
        scanf("%d%d",&a,&b);
        int up = upper( b );
        int lo = lower( a );
        printf("Case %d: %d\n",tc,(up-lo+1));
    }
    return 0;
}

