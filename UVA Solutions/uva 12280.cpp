#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100005;

string str[ 30 ];
vector < string > A , B;
vector < char > Ac , Bc;

string DecToBin( int num ) {
    string ret = "";
    while( num ) {
            ret += ( num%2 +'0' ) , num /= 2;
    }
    reverse( ret.begin() , ret.end() );
    return ret;
}
int calc( char ch ) {
    int num = ch;
    string bin = DecToBin( num );
    int z = 0 , o = 0;
    for( int i = 0; i < bin.size(); i++ ) {
            if( bin[i] == '0' ) z++;
            else o++;
    }
    return ( 500*o + 250*z );
}
int calc_cost( vector <string> V , int f ) {
    int cost = 0;
    for( int i = 0; i < V.size(); i++ ) {
            string s = V[i];
            for( int j = 0; j < s.size(); j++ ) {
                    if( s[j] >= 'A' && s[j] <= 'Z' ) {
                            if( f == 1 ) Ac.push_back( s[j] );
                            if( f == 2 ) Bc.push_back( s[j] );
                            cost += calc( s[j] );
                    }
            }
    }
    return cost;
}
bool ok( int left_pos , int right_pos , int costA , int costB ) {
    if( left_pos == right_pos && costA == costB ) return true;
    if( left_pos < right_pos && costA < costB ) return true;
    if( left_pos > right_pos && costA > costB ) return true;
    return false;
}
vector < string > getEq( ) {
    vector < string > ret;
    ret.push_back( "........" );
    ret.push_back( ".../\\..." );
    ret.push_back( "../..\\.." );
    ret.push_back( "./....\\." );
    ret.push_back( "/......\\" );
    ret.push_back( "\\______/" );
    ret.push_back( "........" );
    return ret;
}
vector < string > getSmall( ) {
    vector < string > ret;
    ret.push_back( ".../\\..." );
    ret.push_back( "../..\\.." );
    ret.push_back( "./....\\.");
    ret.push_back( "/......\\");
    ret.push_back( "\\______/" );
    ret.push_back( "........" );
    ret.push_back( "........" );
    return ret;
}
vector < string > getBig( ) {
    vector < string > ret;
    ret.push_back( "........" );
    ret.push_back( "........" );
    ret.push_back( ".../\\..." );
    ret.push_back( "../..\\.." );
    ret.push_back( "./....\\." );
    ret.push_back( "/......\\" );
    ret.push_back( "\\______/" );
    return ret;
}
int main( int argc , char const *argv[] ) {
    int t;
    cin >> t;
    for( int tc = 1; tc <= t; tc++ ) {
            for( int i = 0; i < 7; i++ ) {
                    cin >> str[i];
            }
            string s;
            cin >> s;
            int left_pos , right_pos;

            A.clear(); B.clear(); Ac.clear(); Bc.clear();

            for( int i = 0; i < 7; i++ ) {
                    string temp = "";
                    for( int j = 0; j < 9; j++ ) {
                            temp += str[i][j];
                            if( str[i][j] == '_' ) left_pos = i;
                    }
                    A.push_back( temp );
                    temp = "";
                    for( int j = 9; j < 18; j++ ) {
                            temp += str[i][j];
                            if( str[i][j] == '_' ) right_pos = i;
                    }
                    B.push_back( temp );
            }
            int costA = calc_cost( A , 1 );
            int costB = calc_cost( B , 2 );
            if( ok( left_pos , right_pos , costA , costB ) ) {
                    cout << "Case " << tc << ":" << endl;
                    cout << "The figure is correct." << endl;
                    continue;
            }
            cout << "Case " << tc << ":" << endl;
            if( costA == costB ) {
                vector < string > x , y;
                x = getEq( );
                y = getEq( );

                for( int i = 0; i < x.size(); i++ ) x[i] += '|';
                for( int i = 0; i < y.size(); i++ ) y[i] = '|'+y[i];

                int id = 1;
                for( int i = 0; i < Ac.size(); i++ ) {
                        x[4][id++] = Ac[i];
                }
                id = 2;
                for( int i = 0; i < Bc.size(); i++ ) {
                        y[4][id++] = Bc[i];
                }
                for( int i = 0; i < 7; i++ ) {
                        cout << x[i] << y[i] << endl;
                }
            }
            if( costA > costB ) {
                vector < string > x , y;
                x = getBig( );
                y = getSmall( );

                for( int i = 0; i < x.size(); i++ ) x[i] += '|';
                for( int i = 0; i < y.size(); i++ ) y[i] = '|'+y[i];

                int id = 1;
                for( int i = 0; i < Ac.size(); i++ ) {
                        x[5][id++] = Ac[i];
                }
                id = 2;
                for( int i = 0; i < Bc.size(); i++ ) {
                        y[3][id++] = Bc[i];
                }
                for( int i = 0; i < 7; i++ ) {
                        cout << x[i] << y[i] << endl;
                }
            }
            if( costA < costB ) {
                vector < string > x , y;
                x = getSmall( );
                y = getBig( );

                for( int i = 0; i < x.size(); i++ ) x[i] += '|';
                for( int i = 0; i < y.size(); i++ ) y[i] = '|'+y[i];

                int id = 1;
                for( int i = 0; i < Ac.size(); i++ ) {
                        x[3][id++] = Ac[i];
                }
                id = 2;
                for( int i = 0; i < Bc.size(); i++ ) {
                        y[5][id++] = Bc[i];
                }
                for( int i = 0; i < 7; i++ ) {
                        cout << x[i] << y[i] << endl;
                }
            }
        }
        return 0;
}
