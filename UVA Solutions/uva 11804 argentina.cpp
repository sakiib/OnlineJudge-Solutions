#include <bits/stdc++.h>
using namespace std;

struct data {
    string name;
    int att , deff;
    data(){}
    data( string name , int att , int deff ):name(name),att(att),deff(deff){}
    bool operator <( const data &q ) const {
        if( att != q.att ) return ( att > q.att );
        if( att == q.att ) {
                if( deff != q.deff ) return ( deff < q.deff );
        }
        if( att == q.att && deff == q.deff ) {
                return ( name < q.name );
        }
    }
};
vector < data > V;

int main( int argc , char const *argv[] ) {
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                for( int i = 1; i <= 10; i++ ) {
                        string name;
                        int att , deff;
                        cin >> name >> att >> deff;
                        V.push_back( data(name,att,deff) );
                }
                sort( V.begin() , V.end() );
                cout << "Case " << tc << ":" << endl;
                vector < string > temp;
                for( int i = 0; i < 5; i++ ) temp.push_back( V[i].name );
                sort( temp.begin() , temp.end() );
                cout << "(";
                for( int i = 0; i < temp.size(); i++ ) {
                        if( i == 0 ) cout << temp[i];
                        else cout << ", " << temp[i];
                }
                cout <<")"<< endl;
                temp.clear();

                for( int i = 5; i < 10; i++ ) temp.push_back( V[i].name );
                sort( temp.begin() , temp.end() );
                cout << "(";
                for( int i = 0; i < temp.size(); i++ ) {
                        if( i == 0 ) cout << temp[i];
                        else cout << ", " << temp[i];
                }
                cout <<")"<< endl;

                V.clear();
        }
        return 0;
}
