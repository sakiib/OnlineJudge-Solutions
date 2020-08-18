#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    map<string,string> M;
    while(cin>>a>>b){
        M[b]=a;
    }
    string c;
    while(cin>>c){
        map<string,string> :: iterator it=M.find(c);
        if(it==M.end()) puts("eh");
        else cout<<M[c]<<endl;
    }
    return 0;
}
