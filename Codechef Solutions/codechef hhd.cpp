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

int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        int len;
        cin >> len;
        string str;
        cin >> str;
        stack < pair<char,int> > S;
        vector < int > ans;
        S.push( {'X',0} );
        for( int i = 0; i < str.size(); i++ ) {
            if( str[i] == '4' ) S.push( {'4',i+1} );
            else {
                if( S.top().first == '4' ) {
                    ans.push_back( S.top().second );
                    S.pop();
                }
                else S.push( {'7',i+1} );
            }
        }
        LL sum = 0;
        for( int i = 0; i < ans.size(); i++ ) sum += ans[i];
        cout << sum << endl;
    }
    return 0;
}

