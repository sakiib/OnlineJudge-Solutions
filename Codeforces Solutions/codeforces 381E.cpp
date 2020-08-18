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

string str;

struct segment {
    int open , close , sum;
    segment () { open = 0 , close = 0 , sum = 0; }
    segment( int open , int close , int sum ) {
        this -> open = open;
        this -> close = close;
        this -> sum = sum;
    }
} Tree[ 4*10*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        if( str[b] == '(' ) Tree[node]={1 , 0 , 0};
        else Tree[node] = {0 , 1 , 0};
        return;
    }
    int left = 2*node; int right = 2*node+1; int mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    int match = min( Tree[left].open , Tree[right].close );
    Tree[node].open = Tree[left].open + Tree[right].open - match;
    Tree[node].close = Tree[left].close + Tree[right].close - match;
    Tree[node].sum = Tree[left].sum + Tree[right].sum + match*2;
}
segment Query( int node , int b , int e , int i , int j ) {
    if( i > e || j < b ) return { 0 , 0 , 0 };
    if( i <= b && j >= e ) return Tree[node];
    int left = 2*node; int right = 2*node+1; int mid = (b+e)/2;
    segment Q1 = Query( left , b , mid , i , j );
    segment Q2 = Query( right , mid+1 , e , i ,j );
    segment ret = { 0 , 0 , 0 };
    int match = min( Q1.open , Q2.close );
    ret.sum = Q1.sum + Q2.sum + 2*match;
    ret.open = Q1.open + Q2.open - match;
    ret.close = Q1.close + Q2.close - match;
    return ret;
}
int main( int argc, char const *argv[] ) {
    cin >> str;
    int len = str.size()-1;
    Build( 1 , 0 , len );
    int q;
    cin >> q;
    while( q-- ) {
        int l , r;
        cin >> l >> r;
        l-- , r--;
        segment ans = Query( 1 , 0 , len , l , r );
        cout << ans.sum << endl;
    }
    return 0;
}




