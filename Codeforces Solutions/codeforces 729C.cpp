#include <bits/stdc++.h>
using namespace std;

typedef long  long LL;
const int N = 100005;
int n , k;
LL s , t;

struct car {
        int id;
        LL price , capa;
        car(){}
        car( int id , LL price , LL capa ) : id(id),price(price),capa(capa){}
} a[ 2*N ];

int main( int argc, char const *argv[] ) {
        cin >> n >> k >> s >> t;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i].price >> a[i].capa , a[i].id = i;
        }

        return 0;
}






