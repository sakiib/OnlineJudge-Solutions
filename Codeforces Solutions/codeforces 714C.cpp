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

struct Node {
    bool Endmark;
    int cnt;
    Node* Child[ 2 ];
    Node( ) {
        cnt = 0;
        Endmark = false;
        Child[0] = Child[1] = NULL;
    }
} *Root;

const int mx = 20;

void Insert( LL val ) {
    int s[ 25 ];
    for( int i = mx; i >= 0; i-- ) {
        s[i] = ( val%10 )%2;
        val /= 10;
    }
    Node* cur = Root;
    for( int i = 0; i <= mx; i++ ) {
        if( cur -> Child[ s[i] ] == NULL ) cur -> Child[ s[i] ] = new Node( );
        cur = cur -> Child[ s[i] ];
        cur -> cnt++;
    }
}
void Remove( LL val ) {
    int s[ 25 ];
    for( int i = mx; i >= 0; i-- ) {
        s[i] = ( val%10 )%2;
        val /= 10;
    }
    Node* cur = Root;
    for( int i = 0; i <= mx; i++ ) {
        cur = cur -> Child[ s[i] ];
        cur -> cnt--;
    }
}
int Count( string s ) {
    int d = mx-(int)( s.size() )+1;
    string t = "";
    while( d-- ) t += "0";
    s = t+s;
    Node* cur = Root;
    for( int i = 0; i <= mx; i++ ) {
        int id = s[i]-'0';
        if( cur -> Child[id] == NULL ) return 0;
        cur = cur -> Child[id];
    }
    return ( cur -> cnt );
}
int main( int argc, char const *argv[] ) {

    Root = new Node( );

    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        string x;
        cin >> x;
        if( x[0] == '+' ) {
            LL val;
            cin >> val;
            Insert( val );
        }
        else if( x[0] == '-' ) {
            LL val;
            cin >> val;
            Remove( val );
        }
        else {
            string s;
            cin >> s;
            cout << Count( s ) << endl;
        }
    }
    return 0;
}

