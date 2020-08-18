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
    Node* Next[ 90 ];
    Node( ) {
        Endmark = false;
        cnt = 0;
        for( int i = 0; i < 90; i++ ) Next[i] = NULL;
    }
};

void Insert( Node* cur , string s ) {
    int len = s.size();
    for( int i = 0; i < len; i++ ) {
        int id = s[i]-'0';
        if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node( );
        cur = cur -> Next[id];
    }
    cur -> Endmark = true;
}
int Search( Node* cur , string s , int taken ) {
    int len = s.size();
    int ret = 0;
    for( int i = 0; i < len; i++ ) {
        int id = s[i]-'0';
        if( cur -> Next[id] == NULL ) return taken;
        cur = cur -> Next[id];
        ret += Search( cur , s , taken+1 );
    }
    return ret;
}
void Delete( Node* cur ) {
    for ( int i = 0; i <= 87; i++ ) {
        if ( cur -> Next[i] ) Delete( cur -> Next[i] );
    }
    delete ( cur );
}
int main( int argc, char const *argv[] ) {
    int n , tc = 0;
    while( scanf("%d",&n) ) {
        if( n == 0 ) break;
        vector < string > V;
        for( int i = 1; i <= n; i++ ) {
            string str;
            cin >> str; V.push_back( str );
        }
        LL ans = 0;
        for( int i = 0; i < V.size(); i++ ) {
            string str = V[i];
            Node* Root = new Node( );
            Insert( Root , str );
            for( int j = i+1; j < V.size(); j++ ) {
                string ss = V[j];
                ans += Search( Root , ss , 1 );
            }
            Delete( Root );
        }
        printf("Case %d: %lld\n",++tc,ans);
    }
    return 0;
}

