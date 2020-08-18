#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

char str[ 10*N ];

struct Node {
    int cnt;
    Node* Next[ 26 ];
    Node( ) {
        cnt = 0;
        for( int i = 0; i < 26; i++ ) Next[i] = NULL;
    }
} *Root;

void Insert( char *s ) {
    int len = strlen( s );
    Node* cur = Root;

    for( int i = 0; i < len; i++ ) {
        int id = s[i]-'a';
        if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node( );
        cur = cur -> Next[id];
        cur -> cnt++;
    }
}
int getans( char *s ) {
    int len = strlen( s );
    Node* cur = Root;
    for( int i = 0; i < len; i++ ) {
        int id = s[i]-'a';
        if( cur -> Next[id] == NULL ) return 0;
        cur = cur -> Next[id];
    }
    return cur -> cnt;
}
int main( int argc, char const *argv[] ) {

    Root = new Node( );

    int n , q;
    scanf("%d %d",&n,&q);
    for( int i = 1; i <= n; i++ ) {
        scanf("%s",str);
        Insert( str );
    }
    while( q-- ) {
        scanf("%s",str);
        printf("%d\n",getans( str ) );
    }
    return 0;
}

