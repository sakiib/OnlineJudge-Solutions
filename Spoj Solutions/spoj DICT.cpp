#include <bits/stdc++.h>
using namespace std;

int n;

struct Node {
        bool endMark;
        Node *Next[ 30 ];
        vector <string> V;
        Node( ) {
                endMark = false;
                vector <string> V;
                for( int i = 1; i <= 26; i++ ) Next[i] = NULL;
        }
} *root;

void Insert( string s ) {
        Node *cur = root;
        for( int i = 0; i < s.size(); i++ ) {
                int id = s[i] - 'a' + 1;
                if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node();
                cur -> V.push_back( s );
        }
}
vector <string> GetAns( string s ) {
        Node *cur = root;
        for( int i = 0; i < s.size() - 1; i++ ) {
                int id = s[i] - 'a' + 1;
                cur = cur -> Next[id];
                cout << "in"<<endl;
        }
        cout << "here" <<endl;
        return cur -> V;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        root = new Node( );
        cin >> n;
        for(int i = 1; i <= n; i++ ) {
                string s;
                cin >> s;
                Insert( s );
        }
        int q;
        cin >> q;
        while( q-- ) {
                string s;
                cin >> s;
                vector <string> ans = GetAns( s );
                for( auto x : ans ) cout << x << " "; cout << endl;
        }
        return 0;
}















