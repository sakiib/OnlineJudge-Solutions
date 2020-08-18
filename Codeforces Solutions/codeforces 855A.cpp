#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    map<string,bool> M;
    while(n--) {
        string str;
        cin>>str;
        if(!M[str]) {cout<<"NO"<<endl; M[str]=true;}
        else cout<<"YES"<<endl;
    }
    return 0;
}
