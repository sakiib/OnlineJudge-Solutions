#include<bits/stdc++.h>
using namespace std;

map<char,int> M;

int main(int argc,char const *argv[]) {
    #ifdef Local_Test
    freopen("cf600Cin","r",stdin);
    freopen("cf600Cout","w",stdout);
    #endif
    string str;
    cin>>str;
    for(auto c:str){
        M[c]++;
    }

    return 0;
}
