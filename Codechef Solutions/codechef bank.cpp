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


bool f;

struct Trie {

    struct Node {
        bool Endmark;
        Node* Next[ 26 ];
        Node ( ) {
            Endmark = false;
            for( int i = 0; i < 26; i++ ) Next[i] = NULL;
        }
    } *Root;

    void Init( ) { Root = new Node( ); }

    void Delete( Node* cur ) {
        for( int i = 0; i < 26; i++ ) {
            if( cur -> Next[i] ) Delete( cur -> Next[i] );
        }
        delete( cur );
    }

    void Insert( string str ) {
        Node* cur = Root;
        int len = str.size( );
        for( int i = 0; i < len; i++ ) {
            int id = str[i]-'a';
            if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node( );
            if( cur -> Endmark ) { f = false; }
            cur = cur -> Next[id];
        }
        cur -> Endmark = true;
    }

    void Search( string str ) {
        Node* cur = Root;
        int len = str.size( );
        for( int i = 0; i < len; i++ ) {
            int id = str[i]-'a';
            if( cur -> Next[id] == NULL ) return;
            cur = cur -> Next[id];
        }
        f = false;
    }

} trie;

int main( int argc, char const *argv[] ) {

    trie.Init( );

    f = true;

    int n;
    cin >> n;
    while( n-- ) {
        string str;
        cin >> str;
        trie.Search( str );
        trie.Insert( str );
    }
    if( f ) cout << "non vulnerable" << endl;
    else cout << "vulnerable" << endl;
    trie.Delete( trie.Root );
    return 0;
}

