#include <bits/stdc++.h>

using namespace std ;

int longest_outside( string & line ) {
    int mx = 0 ;
    int cur = 0 ;

    int opening = 0 ;

    for( int i = 0 ; i < line.size() ; i ++ ) {
        if( line[ i ] == '(' ) {
            mx = max( mx , cur ) ;
            cur = 0 ;
            opening = 1 ;
        }
        else if( line[ i ] == ')' ) {
            opening = 0 ;
        }
        else if( line[ i ] == '_' ) {
            if( opening ) continue ;
            mx = max( mx , cur ) ;
            cur = 0 ;
        }
        else {
            if( opening ) continue ;
            cur ++ ;
        }
    }
    mx = max( mx , cur ) ;
    return mx ;
}

int count_inside( string & line ) {
    int tot = 0 ;

    int opening = 0 ;

    int cur = 0 ;

    for( int i = 0 ; i < line.size() ; i ++ ) {
        if( line[ i ] == '(' ) {
            opening = 1 ;
        }
        else if( line[ i ] == ')' ){
            opening = 0 ;
            if( cur > 0 ) tot ++ ;
            cur = 0 ;
        }
        else if( line[ i ] == '_' ) {
            if( opening ) {
                if( cur > 0 ) {
                    tot ++ ;
                    cur = 0 ;
                }
            }
        }
        else {
            if( opening ) cur ++ ;
        }
    }
    return tot ;

}

pair<int,int> solve( string line ) {
    pair<int,int> ret ;
    ret.first = longest_outside( line ) ;
    ret.second = count_inside( line ) ;

    return ret ;
}

int main() {

    int n ;

    cin >> n ;

    string line = "" ;

    cin >>  line ;

    pair<int,int> res = solve( line ) ;

    cout << res.first << " " << res.second << endl ;

    return 0 ;
}
